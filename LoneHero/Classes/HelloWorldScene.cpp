#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Hero.h"
#include "Weapon_poorgun.h"
#include "Enemy_easy.h"
#include "Boss_zrt.h"
#include "Weapon_shotgun.h"
#include "HelpScene.h"

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

	auto visiblesize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Sprite *start_background = Sprite::create("Scene/Startbackground.jfif");
	start_background->setPosition(Vec2(origin.x + visiblesize.width / 2,
										origin.y + visiblesize.height / 2));
	this->addChild(start_background);

	MenuItemFont::setFontName("Times New Roman");
	MenuItemFont::setFontSize(32);
	MenuItemFont *item_start = MenuItemFont::create("Start", 
							CC_CALLBACK_1(HelloWorld::MenuItemStartCallback, this));
	MenuItemFont *item_help = MenuItemFont::create("Help",
							CC_CALLBACK_1(HelloWorld::MenuItemHelpCallback, this));
	MenuItemFont *item_settings = MenuItemFont::create("Settings",
							CC_CALLBACK_1(HelloWorld::MenuItemSettingsCallback, this));


	Menu *start_menu = Menu::create(item_start, item_help, item_settings, NULL);
	start_menu->alignItemsVertically();//将菜单项垂直对齐
	this->addChild(start_menu);




 //   /////////////////////////////
 //   // 2. add a menu item with "X" image, which is clicked to quit the program
 //   //    you may modify it.

 //   // add a "close" icon to exit the progress. it's an autorelease object
 //   auto closeItem = MenuItemImage::create(
 //                                          "CloseNormal.png",
 //                                          "CloseSelected.png",
 //                                          CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
 //   
 //   closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
 //                               origin.y + closeItem->getContentSize().height/2));

 //   // create menu, it's an autorelease object

 //   auto menu = Menu::create(closeItem, NULL);
 //   menu->setPosition(Vec2::ZERO);
 //   this->addChild(menu, 1);

	//auto hero = Hero::create(5, 5, 200, "hero.png");
	//hero->getHero()->setPosition(Vec2(origin.x + visibleSize.width / 2,
	//	origin.y + visibleSize.height / 2));
	//auto body = PhysicsBody::createEdgeBox(hero->getHero()->getContentSize());
	//hero->getHero()->setPhysicsBody(body);
	//this->addChild(hero);
	//this->addChild(hero->getHero());
	//
	//auto weapon = Weapon_shotgun::create(1, 5, 0, "poorgun.png",hero->getHero());
	//auto bod = PhysicsBody::createEdgeBox(weapon->getWeapon()->getContentSize());
	//weapon->getWeapon()->setPhysicsBody(bod);
	//weapon->getWeapon()->setPosition(Vec2(origin.x + visibleSize.width / 2,
	//	origin.y + visibleSize.height / 2));
	//this->addChild(weapon);
	//this->addChild(weapon->getWeapon());

	//auto enemy = Enemy_easy::create(12, 1, "enemy.png",hero->getHero());
	//enemy->getEnemy()->setPosition(Vec2(origin.x + visibleSize.width / 2 - 50,
	//	origin.y + visibleSize.height / 2 - 50));
	//this->addChild(enemy);
	//this->addChild(enemy->getEnemy());

	//auto boss = Boss_zrt::create(100, 2, "huaji.png", hero->getHero());
	//boss->getEnemy()->setPosition(Vec2(origin.x + visibleSize.width / 2 + 50,
	//	origin.y + visibleSize.height / 2 + 50));
	//this->addChild(boss);
	//this->addChild(boss->getEnemy());
	return true;
}

void HelloWorld::MenuItemStartCallback(Ref *pSender) {
	MenuItem *start_item = (MenuItem*)pSender;
	log("Touch Start Menu Item %p", start_item);
}

void HelloWorld::MenuItemHelpCallback(Ref *pSender) {
	MenuItem *help_item = (MenuItem*)pSender;
	log("Touch Help Menu Item %p", help_item);

	auto help_scene = Help::createScene();
	Director::getInstance()->pushScene(help_scene);

}

void HelloWorld::MenuItemSettingsCallback(Ref *pSender) {
	MenuItem *settings_item = (MenuItem*)pSender;
	log("Touch Settings Menu Item %p", settings_item);
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
