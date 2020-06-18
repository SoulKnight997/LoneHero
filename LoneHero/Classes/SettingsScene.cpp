#include "SettingsScene.h"

USING_NS_CC;
using namespace CocosDenshion;

Scene* Settings::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();

	// 'layer' is an autorelease object
	auto layer = Settings::create();
	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool Settings::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	auto visiblesize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Sprite *start_background = Sprite::create("Scene/Startbackground.jfif");
	start_background->setPosition(Vec2(origin.x + visiblesize.width / 2,
		origin.y + visiblesize.height / 2));
	this->addChild(start_background);

	MenuItemFont::setFontName("Times New Roman");
	MenuItemFont::setFontSize(32);
	MenuItemFont *item_on = MenuItemFont::create("Music On",
		CC_CALLBACK_1(Settings::MenuItemOnCallback, this));
	MenuItemFont *item_off = MenuItemFont::create("Music Off",
		CC_CALLBACK_1(Settings::MenuItemOffCallback, this));
	MenuItemFont *item_ok = MenuItemFont::create("OK",
		CC_CALLBACK_1(Settings::MenuItemOkCallback, this));
	Menu* settings_menu = Menu::create(item_on, item_off, item_ok, NULL);
	settings_menu->alignItemsVertically();
	this->addChild(settings_menu);



	return true;
}

void Settings::MenuItemOnCallback(Ref *pSender) {
	MenuItem *on_item = (MenuItem*)pSender;
	log("Touch On Menu Item %p", on_item);
	SimpleAudioEngine::getInstance()->playEffect("Music/Button.mp3");

	SimpleAudioEngine::getInstance()->playBackgroundMusic("Music/Firstbgm.mp3", true);
}

void Settings::MenuItemOffCallback(Ref *pSender) {
	MenuItem *off_item = (MenuItem*)pSender;
	log("Touch Off Menu Item %p", off_item);
	SimpleAudioEngine::getInstance()->playEffect("Music/Button.mp3");

	SimpleAudioEngine::getInstance()->stopBackgroundMusic("Music/Firstbgm.mp3");
}

void Settings::MenuItemOkCallback(Ref *pSender) {
	MenuItem *ok_item = (MenuItem*)pSender;
	log("Touch OK Menu Item %p", ok_item);
	SimpleAudioEngine::getInstance()->playEffect("Music/Button.mp3");

	Director::getInstance()->popScene();
}

void Settings::menuCloseCallback(Ref* pSender)
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
