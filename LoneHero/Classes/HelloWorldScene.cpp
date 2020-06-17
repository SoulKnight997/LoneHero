#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Hero.h"
#include "Weapon_poorgun.h"
#include "Enemy_easy.h"
#include "Boss_zrt.h"
#include "Weapon_shotgun.h"
#include "Enemy_normal.h"
#include "Enemy_hard.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();
	
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);


	//practice
	
/*

	TextFieldTTF *tf = TextFieldTTF::textFieldWithPlaceHolder
	("LoneHero", "宋体", 20);
	tf->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	addChild(tf);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [tf](Touch *t, Event *event) {
		if (tf->getBoundingBox().containsPoint(t->getLocation())) {
			tf->attachWithIME();
		}
		else {
			tf->detachWithIME();
		}

		return false;
	};
	Director::getInstance()->getEventDispatcher()->
		addEventListenerWithSceneGraphPriority(listener, tf);


*/


	//
	log("fuck");
	_tileMap = CCTMXTiledMap::create("map/SnowMap.tmx");
	log("fuck");
	addChild(_tileMap, -1, 1000);

	TMXObjectGroup* group = _tileMap->getObjectGroup("objects");
	ValueMap spwanPoint = group->getObject("hero");
	float hero_x = spwanPoint["x"].asFloat();
	float hero_y = spwanPoint["y"].asFloat();

	auto hero = Hero::create(5, 5, 200, "heropositive.png");
	hero->getHero()->setPosition(Vec2(hero_x, hero_y));
	auto body = PhysicsBody::createEdgeBox(hero->getHero()->getContentSize());
	hero->getHero()->setPhysicsBody(body);
	this->addChild(hero);
	this->addChild(hero->getHero());
	
	_role = hero->getHero();

	auto weapon = Weapon_shotgun::create(1, 5, 0, "poorgun.png",hero->getHero());
	auto bod = PhysicsBody::createEdgeBox(weapon->getWeapon()->getContentSize());
	weapon->getWeapon()->setPhysicsBody(bod);
	weapon->getWeapon()->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2));
	this->addChild(weapon);
	this->addChild(weapon->getWeapon());

	auto enemy = Enemy_hard::create(50, 1, 4.0f,"jiangshi.png",hero->getHero());
	enemy->getEnemy()->setPosition(Vec2(origin.x + visibleSize.width / 2 - 50,
		origin.y + visibleSize.height / 2 - 50));
	this->addChild(enemy);
	this->addChild(enemy->getEnemy());

	auto boss = Boss_zrt::create(100, 2, "huaji.png", hero->getHero());
	boss->getEnemy()->setPosition(Vec2(origin.x + visibleSize.width / 2 + 50,
		origin.y + visibleSize.height / 2 + 50));
	this->addChild(boss);
	this->addChild(boss->getEnemy());

	_collidable = _tileMap->getLayer("collision");
	setTouchEnabled(true);
	//单点触摸
	setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
}
bool HelloWorld::onTouchBegan(Touch* touch, Event* event)
{
	log("onTouchBegan");
	return true;
}
void HelloWorld::onTouchMoved(Touch* touch, Event* event)
{
	log("onTouchMoved");
}
void HelloWorld::onTouchEnded(Touch* touch, Event* event)
{
	log("onTouchEnded");
	//获得OpenGL坐标
	Vec2 touchLocation = touch->getLocation();
	Vec2 rolePos = _role->getPosition();
	Vec2 diff = touchLocation - rolePos;
	if (abs(diff.x) > abs((diff.y)))
	{
		if (diff.x > 0)
		{
			rolePos.x+=_tileMap->getTileSize().width;
			_role->runAction(FlipX::create(true));           
		}
		else
		{
			rolePos.x-=_tileMap->getTileSize().width;
			_role->runAction(FlipX::create(true));
		}
	}
	else
	{
		if (diff.y > 0)
		{
			rolePos.y += _tileMap->getTileSize().height;
		}
		else
		{
			rolePos.y -= _tileMap->getTileSize().height;
		}
	}
	this->setRolePosition(rolePos);
}
//移动精灵和检测碰撞
void HelloWorld::setRolePosition(Vec2 position)
{
	//从像素点坐标转化为瓦片点坐标
	Vec2 tileCoord = this->tileCoordFromPosition(position);
	//获得瓦片的GID
	int tileGid = _collidable->getTileGIDAt(tileCoord);
	if (tileGid > 0)
	{
		Value prop = _tileMap->getPropertiesForGID(tileGid);
		ValueMap propValueMap = prop.asValueMap();
		std::string collision = propValueMap["Collidable"].asString();

		if (collision == "true")//碰撞检测成功
		{
			log("collision is true");
			return;
		}
	}
	_role->setPosition(position);
}
Vec2 HelloWorld::tileCoordFromPosition(Vec2 pos)
{
	int x = pos.x / _tileMap->getTileSize().width;
	int y = ((_tileMap->getMapSize().height*_tileMap->getTileSize().height) - pos.y) /
		_tileMap->getTileSize().height;
	return Vec2(x, y);
}
void HelloWorld::setViewpointCenter(Vec2 position)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	int x = MAX(position.x, visibleSize.width / 2);
	int y = MAX(position.y, visibleSize.height / 2);
	x = MIN(x, (_tileMap->getMapSize().width*_tileMap->getTileSize().width)
		- visibleSize.width / 2);
	y = MIN(y, (_tileMap->getMapSize().height*_tileMap->getTileSize().height)
		- visibleSize.height / 2);
	//屏幕中心点
	Vec2 pointA =Vec2(visibleSize.width / 2, visibleSize.height / 2);
	//是英雄处于屏幕中心，移动地图目标位置
	Vec2 pointB = Vec2(x, y);
	log("目标位置（%f,%f)", pointB.x, pointB.y);

	//地图移动偏移量
	Vec2 offset = pointA - pointB;
	log("offset(%f,%f)", offset.x, offset.y);
	this->setPosition(offset);

}