#include "HelpScene.h"

USING_NS_CC;
using namespace CocosDenshion;

Scene* Help::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();

	// 'layer' is an autorelease object
	auto layer = Help::create();
	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool Help::init()
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

	auto help_title_label = LabelTTF::create("Game Key Distribution", "Arial", 16);
	help_title_label->setPosition(Vec2(origin.x + visiblesize.width / 2,
		origin.y + 4 * visiblesize.height / 5));
	this->addChild(help_title_label, 1);

	auto help_label = LabelTTF::create("WASD: Move  J: Attack  K: Buff","Arial",12);
	help_label->setPosition(Vec2(origin.x + visiblesize.width / 2,
									origin.y + 2 * visiblesize.height / 3));
	this->addChild(help_label, 1);

	MenuItemFont::setFontName("Times New Roman");
	MenuItemFont::setFontSize(32);
	MenuItemFont *item_back = MenuItemFont::create("Back",
		CC_CALLBACK_1(Help::MenuItemBackCallback, this));
	Menu* back_menu = Menu::create(item_back, NULL);
	this->addChild(back_menu);

	

	return true;
}

void Help::MenuItemBackCallback(Ref *pSender) {
	MenuItem *start_item = (MenuItem*)pSender;
	log("Touch Back Menu Item %p", start_item);
	SimpleAudioEngine::getInstance()->playEffect("Music/Button.mp3");

	Director::getInstance()->popScene();
}

void Help::menuCloseCallback(Ref* pSender)
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
