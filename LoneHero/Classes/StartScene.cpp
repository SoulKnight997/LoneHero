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

	_role = hero;

	auto weapon = Weapon_shotgun::create(1, 5, 0, "poorgun.png", hero->getHero());
	auto bod = PhysicsBody::createEdgeBox(weapon->getWeapon()->getContentSize());
	weapon->getWeapon()->setPhysicsBody(bod);
	weapon->getWeapon()->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2));
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

	this->scheduleUpdate();
	return true;
}



void Start::update(float dt) {
	this->setViewpointCenter(_role->getHero()->getPosition());
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
	//��Ļ���ĵ�
	Vec2 pointA = Vec2(visibleSize.width / 2, visibleSize.height / 2);
	//��Ӣ�۴�����Ļ���ģ��ƶ���ͼĿ��λ��
	Vec2 pointB = Vec2(x, y);

	//��ͼ�ƶ�ƫ����
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
