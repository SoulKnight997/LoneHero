#include "StartScene.h"
#include "FirstScene.h"
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

	

	auto gameon_label = LabelTTF::create("Game On", "Arial", 24);
	gameon_label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + 4 * visibleSize.height / 5));
	this->addChild(gameon_label, 1);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(Start::gameTouchBegan, this);
	Director::getInstance()->getEventDispatcher()->
		addEventListenerWithSceneGraphPriority(listener, gameon_label);

	return true;
}

bool Start::gameTouchBegan(cocos2d::Touch*, cocos2d::Event*) {
	auto first_scene = First::createScene();
	Director::getInstance()->pushScene(first_scene);

	return false;
};

void Start::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

}