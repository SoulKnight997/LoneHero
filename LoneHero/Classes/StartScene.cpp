#include "StartScene.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Weapon_poorgun.h"
#include "Enemy_easy.h"
#include "Boss_zrt.h"
#include "Weapon_shotgun.h"
#include "Enemy_normal.h"
#include "Enemy_hard.h"

USING_NS_CC;

Scene* Start::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();

	// 'layer' is an autorelease object
	auto layer = Start::create();
	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool Start::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	
	auto GameOn_label = LabelTTF::create("Game On", "Arial", 24);
	GameOn_label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + 4 * visibleSize.height / 5));
	this->addChild(GameOn_label, 1);

	log("fuck");
	_tileMap = CCTMXTiledMap::create("map/SnowMap.tmx");
	_tileMap ->setAnchorPoint(Vec2(0, 0));
	log("fuck");
	addChild(_tileMap, 0, 1000000);

	TMXObjectGroup* group = _tileMap->getObjectGroup("objects");
	ValueMap spwanPoint = group->getObject("hero");
	float hero_x = spwanPoint["x"].asFloat();
	float hero_y = spwanPoint["y"].asFloat();

	//log("%f,%f", hero_x, hero_y);
	auto hero = Hero::create(5, 5, 200, "heropositive.png");
	hero->getHero()->setPosition(Vec2(hero_x, hero_y));
	auto body = PhysicsBody::createEdgeBox(hero->getHero()->getContentSize());
	hero->getHero()->setPhysicsBody(body);
	this->addChild(hero);
	this->addChild(hero->getHero());//里面的类

	_role = hero;

	auto weapon = Weapon_shotgun::create(1, 5, 0, "poorgun.png", hero->getHero());
	auto bod = PhysicsBody::createEdgeBox(weapon->getWeapon()->getContentSize());
	weapon->getWeapon()->setPhysicsBody(bod);
	weapon->getWeapon()->setPosition(hero->getHero()->getPositionX()+320,
		hero->getHero()->getPositionY());
	this->addChild(weapon);
	this->addChild(weapon->getWeapon());

	auto enemy = Enemy_hard::create(50, 1, 4.0f, "jiangshi.png", hero->getHero());
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
	//this->addChild(_collidable, 0, 10000000);
	//if (_collidable == NULL)
		//log("too fuck");
	//_collidable->setVisible(false);

	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(Start::Press, this);
	listener->onKeyReleased = CC_CALLBACK_2(Start::Released, this);
	EventDispatcher*eve = Director::getInstance()->getEventDispatcher();
	eve->addEventListenerWithSceneGraphPriority(listener, _role);

	this->scheduleUpdate();

	return true;
}


int right = 0, left = 0, up = 0, down = 0;
void Start::update(float dt) {
	this->setViewpointCenter(_role->getHero()->getPosition());
	//this->setRolePosition(_role->getHero()->getPosition());
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto hero = _role->getHero();

	Vec2 pos = hero->getPosition();
	float pos_x = hero->getPositionX();
	float pos_y = hero->getPositionY();

	if (right == 1)
		if (setRolePosition(Vec2(pos_x + 1, pos_y)))
			hero->setPosition(Vec2(hero->getPositionX() + 1, hero->getPositionY())), hero->setTexture("heropositive.png");
	if (left == 1)
		if (setRolePosition(Vec2(pos_x - 1, pos_y)))
			hero->setPosition(Vec2(hero->getPositionX() - 1, hero->getPositionY())), hero->setTexture("herocounter.png");
	if (up == 1)
		if(setRolePosition(Vec2(pos_x,pos_y+1)))
		hero->setPosition(Vec2(hero->getPositionX(), hero->getPositionY() + 1));
	if (down == 1)
		if(setRolePosition(Vec2(pos_x,pos_y-1)))
		hero->setPosition(Vec2(hero->getPositionX(), hero->getPositionY() - 1));
}


void Start::setViewpointCenter(Vec2 position)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	int x = MAX(position.x, visibleSize.width / 2);
	int y = MAX(position.y, visibleSize.height / 2);
	x = MIN(x, (_tileMap->getMapSize().width*_tileMap->getTileSize().width)
		- visibleSize.width / 2);
	y = MIN(y, (_tileMap->getMapSize().height*_tileMap->getTileSize().height)
		- visibleSize.height / 2);
	//屏幕中心点
	Vec2 pointA = Vec2(visibleSize.width / 2, visibleSize.height / 2);
	//是英雄处于屏幕中心，移动地图目标位置
	Vec2 pointB = Vec2(x, y);

	//地图移动偏移量
	Vec2 offset = pointA - pointB;
	this->setPosition(offset);
}


void Start::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

}
//移动精灵和检测碰撞
bool Start::setRolePosition(Vec2 position)
{
	//从像素点坐标转化为瓦片点坐标
	Vec2 tileCoord = this->tileCoordFromPosition(position);
	//log("%f,%f",tileCoord.x,tileCoord.y);
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
			return 0;
		}
	}
	return 1;
}
//坐标问题，
Vec2 Start::tileCoordFromPosition(Vec2 pos)
{
	log("%f,%f",pos.x, pos.y);
	int x = (pos.x *4.25)/ _tileMap->getTileSize().width;
	int y = ((_tileMap->getMapSize().height*_tileMap->getTileSize().height/4.2) - pos.y) /
		(_tileMap->getTileSize().height/4.2);
	return Vec2(x, y);
}

void Start::Press(EventKeyboard::KeyCode code, Event*event) {
	auto target = event->getCurrentTarget();
	switch (code) {
	case EventKeyboard::KeyCode::KEY_A:left = 1; break;
	case EventKeyboard::KeyCode::KEY_S:down = 1; break;
	case EventKeyboard::KeyCode::KEY_D:right = 1; break;
	case EventKeyboard::KeyCode::KEY_W:up = 1; break;
	case EventKeyboard::KeyCode::KEY_K: {
		/*if ((frequency == 0) || (clock() - time >= 20)) {
			time = clock();
			frequency += 1;
			buff = 1;
		}*/
		log("%f", _role->getPositionX());
	}
	}
}

void Start::Released(EventKeyboard::KeyCode code, Event*event) {
	switch (code) {
	case EventKeyboard::KeyCode::KEY_A:left = 0; break;
	case EventKeyboard::KeyCode::KEY_S:down = 0; break;
	case EventKeyboard::KeyCode::KEY_D:right = 0; break;
	case EventKeyboard::KeyCode::KEY_W:up = 0; break;
	}
}

