#include "StartScene.h"
#include "FirstScene.h"
#include "SecondScene.h"
#include "ThirdScene.h"
#include "FourthScene.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Weapon_poorgun.h"
#include "Enemy_easy.h"
#include "Boss_zrt.h"
#include "Weapon_shotgun.h"
#include "Enemy_normal.h"
#include "Enemy_hard.h"

USING_NS_CC;

using namespace CocosDenshion;

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

	_safeMap = CCTMXTiledMap::create("map/SafeMap.tmx");
	_safeMap->setAnchorPoint(Vec2(0, 0));
	addChild(_safeMap, 0, 1000000);

	MenuItemFont::setFontName("Times New Roman");
	MenuItemFont::setFontSize(32);
	MenuItemFont *item_weapon1 = MenuItemFont::create("Weapon1",
		CC_CALLBACK_1(Start::MenuItemWeapon1Callback, this));
	MenuItemFont *item_weapon2 = MenuItemFont::create("Weapon2",
		CC_CALLBACK_1(Start::MenuItemWeapon2Callback, this));
	MenuItemFont *item_weapon3 = MenuItemFont::create("Weapon3",
		CC_CALLBACK_1(Start::MenuItemWeapon3Callback, this));
	MenuItemFont *item_weapon4 = MenuItemFont::create("Weapon4",
		CC_CALLBACK_1(Start::MenuItemWeapon4Callback, this));

	MenuItemFont *item_back = MenuItemFont::create("Back",
		CC_CALLBACK_1(Start::MenuItemBackCallback, this));


	Menu *weapon_menu = Menu::create(item_weapon1, item_weapon2, item_weapon3, item_weapon4, item_back, NULL);
	weapon_menu->alignItemsVertically();//将菜单项垂直对齐
	this->addChild(weapon_menu);

	/*auto gameon_label = LabelTTF::create("Game On", "Arial", 24);
	gameon_label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + 4 * visibleSize.height / 5));
	this->addChild(gameon_label, 1);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(Start::gameTouchBegan, this);
	Director::getInstance()->getEventDispatcher()->
		addEventListenerWithSceneGraphPriority(listener, gameon_label);*/

	return true;
}

void Start::MenuItemWeapon1Callback(Ref *pSender) {
	MenuItem *item_weapon1 = (MenuItem*)pSender;
	log("Touch Weapon1 Menu Item %p", item_weapon1);
	SimpleAudioEngine::getInstance()->playEffect("Music/Button.mp3");

	auto first_scene = First::createScene();
	Director::getInstance()->pushScene(first_scene);
}

void Start::MenuItemWeapon2Callback(Ref *pSender) {
	MenuItem *item_weapon2 = (MenuItem*)pSender;
	log("Touch Weapon2 Menu Item %p", item_weapon2);
	SimpleAudioEngine::getInstance()->playEffect("Music/Button.mp3");

	auto second_scene = Second::createScene();
	Director::getInstance()->pushScene(second_scene);
}

void Start::MenuItemWeapon3Callback(Ref *pSender) {
	MenuItem *item_weapon3 = (MenuItem*)pSender;
	log("Touch Weapon3 Menu Item %p", item_weapon3);
	SimpleAudioEngine::getInstance()->playEffect("Music/Button.mp3");

	auto third_scene = Third::createScene();
	Director::getInstance()->pushScene(third_scene);
}

void Start::MenuItemWeapon4Callback(Ref *pSender) {
	MenuItem *item_weapon4 = (MenuItem*)pSender;
	log("Touch Weapon4 Menu Item %p", item_weapon4);
	SimpleAudioEngine::getInstance()->playEffect("Music/Button.mp3");

	auto fourth_scene = Fourth::createScene();
	Director::getInstance()->pushScene(fourth_scene);
}

void Start::MenuItemBackCallback(Ref *pSender) {
	MenuItem *back_item = (MenuItem*)pSender;
	log("Touch Back Menu Item %p", back_item);
	SimpleAudioEngine::getInstance()->playEffect("Music/Button.mp3");

	Director::getInstance()->popScene();
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