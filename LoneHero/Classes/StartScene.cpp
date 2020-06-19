#include "StartScene.h"
#include "Hero.h"
#include "Enemy_hard_magic.h"
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

	auto visiblesize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto hero = Hero::create(7, 200, 6, "heropositive.png");
	hero->getHero()->setPosition(100, 100);
	auto hbody = PhysicsBody::createEdgeBox(hero->getHero()->getContentSize());
	hero->getHero()->setPhysicsBody(hbody);
	this->addChild(hero);
	this->addChild(hero->getHero(),1);

	auto enemy = Enemy_hard_magic::create(50, 2, 2.0f, "jiangshi.png",hero->getHero());
	enemy->getEnemy()->setPosition(200, 200);
	auto ebody = PhysicsBody::createEdgeBox(enemy->getEnemy()->getContentSize());
	enemy->getEnemy()->setPhysicsBody(ebody);
	this->addChild(enemy);
	this->addChild(enemy->getEnemy());

	auto enemy1 = Enemy_hard::create(50, 2, 2.0f, "jiangshi.png", hero->getHero());
	enemy1->getEnemy()->setPosition(300, 300);
	auto ebody1 = PhysicsBody::createEdgeBox(enemy1->getEnemy()->getContentSize());
	enemy1->getEnemy()->setPhysicsBody(ebody1);
	this->addChild(enemy1);
	this->addChild(enemy1->getEnemy());

	return true;
}


void Start::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

}
