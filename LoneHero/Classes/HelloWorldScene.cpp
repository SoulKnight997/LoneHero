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
	("LoneHero", "ËÎÌו", 20);
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


	auto hero = Hero::create(5, 5, 200, "heropositive.png");
	hero->getHero()->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2));
	auto body = PhysicsBody::createEdgeBox(hero->getHero()->getContentSize());
	hero->getHero()->setPhysicsBody(body);
	this->addChild(hero);
	this->addChild(hero->getHero());
	
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
