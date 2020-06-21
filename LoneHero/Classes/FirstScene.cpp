#include "FirstScene.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Weapon_machinegun.h"
#include "Weapon_poorgun.h"
#include "Weapon_shotgun.h"
#include "Enemy_easy.h"
#include "Boss_zrt.h"
#include "Weapon_shotgun.h"
#include "Enemy_normal.h"
#include "Enemy_hard.h"
#include "Enemy_hard_magic.h"
#include "Knife.h"
#include "SimpleAudioEngine.h"

#define PLAYER_LIFE 5
#define MY_BAR 128
#define BLOOD_BAR 7

USING_NS_CC;

using namespace CocosDenshion;
int _weapon_type = 0;
Scene* First::createScene(int weapon_type)
{
	_weapon_type = weapon_type;
	// 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();

	// 'layer' is an autorelease object
	auto layer = First::create();
	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool First::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	initMap();
	initHero();
	initWeapon();
	/*log("fuck");
	_tileMap = CCTMXTiledMap::create("map/IceMap.tmx");
	_tileMap->setAnchorPoint(Vec2(0, 0));
	log("fuck");
	addChild(_tileMap, 0, 1000000);

	TMXObjectGroup* group = _tileMap->getObjectGroup("objects");
	ValueMap spwanPoint = group->getObject("hero");
	float hero_x = spwanPoint["x"].asFloat();
	float hero_y = spwanPoint["y"].asFloat();

	//log("%f,%f", hero_x, hero_y);
	auto hero = Hero::create(PLAYER_LIFE, 5, 200, "heropositive.png");
	hero->getHero()->setPosition(Vec2(hero_x, hero_y));
	auto body = PhysicsBody::createEdgeBox(hero->getHero()->getContentSize());
	hero->getHero()->setPhysicsBody(body);
	this->addChild(hero);
	this->addChild(hero->getHero());//里面的类

	_role = hero;
	if (_weapon_type = 1)
	{
		auto weapon = Weapon_machinegun::create(0.2, 5, 0, "poorgun.png", hero->getHero(), vec_bullet);
		auto bod = PhysicsBody::createEdgeBox(weapon->getWeapon()->getContentSize());
		weapon->getWeapon()->setPhysicsBody(bod);
		weapon->getWeapon()->setPosition(hero->getHero()->getPositionX(),
			hero->getHero()->getPositionY());
		this->addChild(weapon);
		this->addChild(weapon->getWeapon());
		_machinegun = weapon;
	}
	else if (_weapon_type = 2)
	{
		auto weapon = Weapon_shotgun::create(0.2, 5, 0, "machinegun.png", hero->getHero(), vec_bullet);
		auto bod = PhysicsBody::createEdgeBox(weapon->getWeapon()->getContentSize());
		weapon->getWeapon()->setPhysicsBody(bod);
		weapon->getWeapon()->setPosition(hero->getHero()->getPositionX(),
			hero->getHero()->getPositionY());
		this->addChild(weapon);
		this->addChild(weapon->getWeapon());
		_shotgun = weapon;
	}*/
	TMXObjectGroup* group = _tileMap->getObjectGroup("objects");
	ValueMap spwanPoint1 = group->getObject("enemy2");
	float enemy_x = spwanPoint1["x"].asFloat();
	float enemy_y = spwanPoint1["y"].asFloat();
	auto enemy = Enemy_easy::create(50, 1, 4.0f, "enemy.png", _role,Vec2(enemy_x,enemy_y));
	enemy->getEnemy()->setPosition(Vec2(enemy_x,enemy_y));
	vec_enemy.push_back(enemy->getEnemy());
	_easy = enemy;
	this->addChild(enemy);
	this->addChild(enemy->getEnemy());

	auto enemy1 = Enemy_normal::create(50, 1, 4.0f, "snowpositive.png", _role,Vec2(enemy_x,enemy_y));
	enemy1->getEnemy()->setPosition(Vec2(enemy_x,enemy_y));
	vec_enemy.push_back(enemy1->getEnemy());
	_normal = enemy1;
	this->addChild(enemy1);
	this->addChild(enemy1->getEnemy());

	/*ValueMap spwanPoint2 = group->getObject("boss");
	float boss_x = spwanPoint2["x"].asFloat();
	float boss_y = spwanPoint2["y"].asFloat();
	auto boss = Boss_zrt::create(100, 2, "huaji.png", hero,Vec2(boss_x,boss_y));
	boss->getEnemy()->setPosition(Vec2(boss_x,boss_y));
	vec_enemy.push_back(boss->getEnemy());
	this->addChild(boss);
	this->addChild(boss->getEnemy());*/

	/*_collidable = _tileMap->getLayer("collision");
	_enemyDoor = _tileMap->getLayer("enemydoor");
	_bossDoor = _tileMap->getLayer("bossdoor");
	//_collidable->setVisible(false);

	/*MenuItemFont::setFontName("Times New Roman");
	MenuItemFont::setFontSize(12);
	MenuItemFont *item_pause = MenuItemFont::create("Pause",
		CC_CALLBACK_1(First::MenuItemPauseCallback, this));
	auto pauseMenu = Menu::create(item_pause, NULL);
	pauseMenu->setPosition(Vec2(origin.x + 15, origin.y + visibleSize.height - 15));
	this->addChild(pauseMenu, 20, 999);*/

	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(First::Press, this);
	listener->onKeyReleased = CC_CALLBACK_2(First::Released, this);
	EventDispatcher*eve = Director::getInstance()->getEventDispatcher();
	eve->addEventListenerWithSceneGraphPriority(listener, _role);

	auto bar = Sprite::create("BloodBar.png");//创建进度框
	bar->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - 2));
	bar->setTag(MY_BAR);
	this->addChild(bar);
	auto Blood = Sprite::create("Blood.png");//创建血条
	ProgressTimer * progress = ProgressTimer::create(Blood);//创建progress对象
	progress->setType(ProgressTimer::Type::BAR);
	progress->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - 2));
	progress->setMidpoint(Point(0, 0.5));//从右到左减少血量
	progress->setBarChangeRate(Point(1, 0));
	progress->setTag(BLOOD_BAR);//做一个标记

	this->addChild(progress);
	this->schedule(schedule_selector(First::scheduleBlood), 0.1f);

	/*MenuItemFont::setFontName("Times New Roman");
	MenuItemFont::setFontSize(12);
	MenuItemFont *item_pause = MenuItemFont::create("Pause",
		CC_CALLBACK_1(First::MenuItemPauseCallback, this));
	auto pauseMenu = Menu::create(item_pause, NULL);*/
	this->scheduleUpdate();

	return true;
}

void First::initMap()
{
	//log("fuck");
	_tileMap = CCTMXTiledMap::create("map/IceMap.tmx");
	_tileMap->setAnchorPoint(Vec2(0, 0));
	addChild(_tileMap, 0, 1000000);
	_collidable = _tileMap->getLayer("collision");
	_enemyDoor = _tileMap->getLayer("enemydoor");
	_bossDoor = _tileMap->getLayer("bossdoor");
	_collidable->setVisible(false);
}

void First::initHero()
{
	TMXObjectGroup* group = _tileMap->getObjectGroup("objects");
	ValueMap spwanPoint = group->getObject("hero");
	float hero_x = spwanPoint["x"].asFloat();
	float hero_y = spwanPoint["y"].asFloat();

	//log("%f,%f", hero_x, hero_y);
	auto hero = Hero::create(PLAYER_LIFE, 5, 200, "heropositive.png");
	hero->getHero()->setPosition(Vec2(hero_x, hero_y));
	auto body = PhysicsBody::createEdgeBox(hero->getHero()->getContentSize());
	hero->getHero()->setPhysicsBody(body);
	this->addChild(hero);
	this->addChild(hero->getHero());//里面的类

	_role = hero;
}
void First::initWeapon()
{
	if (_weapon_type == 1)
	{
		auto weapon = Weapon_machinegun::create(0.2, 5, 0, "poorgun.png",_role->getHero(), vec_bullet);
		auto bod = PhysicsBody::createEdgeBox(weapon->getWeapon()->getContentSize());
		weapon->getWeapon()->setPhysicsBody(bod);
		weapon->getWeapon()->setPosition(_role->getHero()->getPositionX(),
			_role->getHero()->getPositionY());
		this->addChild(weapon);
		this->addChild(weapon->getWeapon());
		gun = weapon;
	}
	else if (_weapon_type == 2)
	{
		auto weapon = Weapon_shotgun::create(0.2, 5, 0, "machinegun.png", _role->getHero(), vec_bullet);
		auto bod = PhysicsBody::createEdgeBox(weapon->getWeapon()->getContentSize());
		weapon->getWeapon()->setPhysicsBody(bod);
		weapon->getWeapon()->setPosition(_role->getHero()->getPositionX(),
			_role->getHero()->getPositionY());
		this->addChild(weapon);
		this->addChild(weapon->getWeapon());
		_shotgun = weapon;
	}
	else if (_weapon_type == 3)
	{
		auto weapon = Weapon_poorgun::create(0.2, 5, 0, "machinegun.png", _role->getHero(), vec_bullet);
		auto bod = PhysicsBody::createEdgeBox(weapon->getWeapon()->getContentSize());
		weapon->getWeapon()->setPhysicsBody(bod);
		weapon->getWeapon()->setPosition(_role->getHero()->getPositionX(),
			_role->getHero()->getPositionY());
		this->addChild(weapon);
		this->addChild(weapon->getWeapon());
		_poorgun = weapon;
	}
	else if (_weapon_type == 4)
	{
		auto weapon = Knife::create(0.2, 5, 0, "machinegun.png", _role->getHero());
		auto bod = PhysicsBody::createEdgeBox(weapon->getWeapon()->getContentSize());
		weapon->getWeapon()->setPhysicsBody(bod);
		weapon->getWeapon()->setPosition(_role->getHero()->getPositionX(),
			_role->getHero()->getPositionY());
		this->addChild(weapon);
		this->addChild(weapon->getWeapon());
		_knife= weapon;
	}
}
void First::scheduleBlood(float delta)
{
	auto progress = (ProgressTimer*)this->getChildByTag(BLOOD_BAR);
	auto bar = (Sprite*)this->getChildByTag(MY_BAR);
	float existLife = _role->getBlood();
	progress->setPercentage(((float)existLife /PLAYER_LIFE) * 100);

	progress->setPosition(Vec2(_role->getHero()->getPositionX(),
		_role->getHero()->getPositionY() + 32));
	bar->setPosition(Vec2(_role->getHero()->getPositionX(),
		_role->getHero()->getPositionY() + 32));

//

	if (progress->getPercentage() < 0)
	{
		this->unschedule(schedule_selector(First::scheduleBlood));
	}
}

/*void First::MenuItemPauseCallback(Ref *pSender) {
	MenuItem *item_pause = (MenuItem*)pSender;
	log("Touch Pause Menu Item %p", item_pause);
	SimpleAudioEngine::getInstance()->playEffect("Music/Button.mp3");

	auto first_scene = First::createScene();
	Director::getInstance()->pushScene(first_scene);
}*/

void First::update(float dt) {
	this->settheVectorsame();
	this->setViewpointCenter(_role->getHero()->getPosition());
	//this->setRolePosition(_role->getHero()->getPosition());
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto hero = _role->getHero();

	Vec2 pos = hero->getPosition();
	float pos_x = hero->getPositionX();
	float pos_y = hero->getPositionY();

	if (Right == 1)
		if (setRolePosition(Vec2(pos_x + 2, pos_y)))
			hero->setPosition(Vec2(hero->getPositionX() + 2, hero->getPositionY())), hero->setTexture("heropositive.png");
	if (Left == 1)
		if (setRolePosition(Vec2(pos_x - 2, pos_y)))
			hero->setPosition(Vec2(hero->getPositionX() - 2, hero->getPositionY())), hero->setTexture("herocounter.png");
	if (up == 1)
		if (setRolePosition(Vec2(pos_x, pos_y + 2)))
			hero->setPosition(Vec2(hero->getPositionX(), hero->getPositionY() + 2));
	if (down == 1)
		if (setRolePosition(Vec2(pos_x, pos_y - 2)))
			hero->setPosition(Vec2(hero->getPositionX(), hero->getPositionY() - 2));
	long distance = 1000000;
	double x1, y1, x2, y2;
	int i = vec_enemy.size();
	i = i - 1;
	while (i >= 0) {
		if (vec_enemy[i] != NULL) {
			if ((pow((vec_enemy[i]->getPositionX() - gun->getWeapon()->getPositionX()), 2) + pow((vec_enemy[i]->getPositionY() - gun->getWeapon()->getPositionY()), 2)) < distance) {
				distance = (pow((vec_enemy[i]->getPositionX() - gun->getWeapon()->getPositionX()), 2) + pow((vec_enemy[i]->getPositionY() - gun->getWeapon()->getPositionY()), 2));
				x1 = gun->getWeapon()->getPositionX(), y1 = gun->getWeapon()->getPositionY(), x2 = vec_enemy[i]->getPositionX(), y2 = vec_enemy[i]->getPositionY();
				if ((x1 != x2) || (y1 != y2)) {
					if (x1 <= x2)
						gun->setAngle(asin((y2 - y1) / sqrt(pow((y2 - y1), 2) + pow((x2 - x1), 2))));
					else
						gun->setAngle(3.14159 - asin((y2 - y1) / sqrt(pow((y2 - y1), 2) + pow((x2 - x1), 2))));
				}
			}
		}
		i = i - 1;
	}
	//生成怪和BOSS
	if (hasEnemy == 0)
	{
		if (initEnemy())
		{
			hasEnemy = 1;
		}
	}
	if (hasBoss == 0)
	{
		if (initBoss())
		{
			hasBoss = 1;
		}
	}
}

bool First::initEnemy()
{
	if (setEnemy(_role->getHero()->getPosition()))
	{
		TMXObjectGroup* group = _tileMap->getObjectGroup("objects");
		ValueMap spwanPoint1 = group->getObject("enemy");
		float enemy_x = spwanPoint1["x"].asFloat();
		float enemy_y = spwanPoint1["y"].asFloat();
		auto enemy = Enemy_hard_magic::create(50, 1, 2.0f, "jiangshi.png", _role, Vec2(enemy_x, enemy_y));
		enemy->getEnemy()->setPosition(Vec2(enemy_x, enemy_y));
		vec_enemy.push_back(enemy->getEnemy());
		_magic = enemy;
		this->addChild(enemy);
		this->addChild(enemy->getEnemy());

		auto enemy1 = Enemy_normal_1::create(50, 1, 4.0f, "jiangshi.png", _role, Vec2(enemy_x-5, enemy_y+5));
		enemy1->getEnemy()->setPosition(Vec2(enemy_x - 5, enemy_y + 5));
		vec_enemy.push_back(enemy1->getEnemy());
		_normal_1 = enemy1;
		this->addChild(enemy1);
		this->addChild(enemy1->getEnemy());



		//hasEnemy = 1;
		return 1;
	}
	return 0;
}

bool First::initBoss()
{
	if (setBoss(_role->getHero()->getPosition()))
	{
		TMXObjectGroup* group = _tileMap->getObjectGroup("objects");
		ValueMap spwanPoint2 = group->getObject("boss");
		float boss_x = spwanPoint2["x"].asFloat();
		float boss_y = spwanPoint2["y"].asFloat();
		auto boss = Enemy_hard::create(50, 1, 4.0f,"jiangshi.png", _role, Vec2(boss_x, boss_y));
		boss->getEnemy()->setPosition(Vec2(boss_x, boss_y));
		vec_enemy.push_back(boss->getEnemy());
		_hard = boss;
		this->addChild(boss);
		this->addChild(boss->getEnemy());

		//hasBoss = 1;
		return 1;
	}
	return 0;
}
void First::setViewpointCenter(Vec2 position)
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


void First::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

}

//移动精灵和检测碰撞
bool First::setRolePosition(Vec2 position)
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
			//log("collision is true");
			return 0;
		}
	}
	return 1;
}

Vec2 First::tileCoordFromPosition(Vec2 pos)
{
	//log("%f,%f", pos.x, pos.y);
	int x = (pos.x *4.25) / _tileMap->getTileSize().width;
	int y = ((_tileMap->getMapSize().height*_tileMap->getTileSize().height / 4.25) - pos.y) /
		(_tileMap->getTileSize().height / 4.25);
	return Vec2(x, y);
}

//当人物走到相应的门时，再生成怪物而不是让怪一直生成
//检测第一个门，生成小怪
bool First::setEnemy(Vec2 position)
{
	Vec2 tileCoord = this->tileCoordFromPosition(position);
	int tileGid = _enemyDoor->getTileGIDAt(tileCoord);
	if (tileGid > 0)
	{
		Value prop = _tileMap->getPropertiesForGID(tileGid);
		ValueMap propValueMap = prop.asValueMap();
		std::string enemydoor = propValueMap["EnemyDoor"].asString();
		if (enemydoor == "true")//碰撞检测成功
		{
			log("create enemy");
			return 1;
		}
	}
	return 0;
}
//检测第二个门，生成大boss
bool First::setBoss(Vec2 position)
{
	Vec2 tileCoord = this->tileCoordFromPosition(position);
	int tileGid = _bossDoor->getTileGIDAt(tileCoord);
	if (tileGid > 0)
	{
		Value prop = _tileMap->getPropertiesForGID(tileGid);
		ValueMap propValueMap = prop.asValueMap();
		std::string bossdoor = propValueMap["BossDoor"].asString();
		if (bossdoor == "true")//碰撞检测成功
		{
			log("create boss");
			return 1;
		}
	}
	return 0;
}
void First::Press(EventKeyboard::KeyCode code, Event*event) {
	auto target = event->getCurrentTarget();
	switch (code) {
	case EventKeyboard::KeyCode::KEY_A:Left = 1; break;
	case EventKeyboard::KeyCode::KEY_S:down = 1; break;
	case EventKeyboard::KeyCode::KEY_D:Right = 1; break;
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

void First::Released(EventKeyboard::KeyCode code, Event*event) {
	switch (code) {
	case EventKeyboard::KeyCode::KEY_A:Left = 0; break;
	case EventKeyboard::KeyCode::KEY_S:down = 0; break;
	case EventKeyboard::KeyCode::KEY_D:Right = 0; break;
	case EventKeyboard::KeyCode::KEY_W:up = 0; break;
	}
}

void First::settheVectorsame() {
	if (_magic) {
		_magic->setVector(gun->getVector());
	}
	if (_easy) {
		_easy->setVector(gun->getVector());
	}
	if (_normal) {
		_normal->setVector(gun->getVector());
	}
	if (_normal_1) {
		_normal_1->setVector(gun->getVector());
	}
	if (_hard) {
		_hard->setVector(gun->getVector());
	}
	if (_boss) {
		_boss->setVector(gun->getVector());
	}
}
