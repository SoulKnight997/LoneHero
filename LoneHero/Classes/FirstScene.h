#ifndef __FIRST_SCENE_H__
#define __FIRST_SCENE_H__

#include "cocos2d.h"
#include "Hero.h"
#include <vector>
#include "Weapon_machinegun.h"
#include "Weapon_poorgun.h"
#include "Weapon_shotgun.h"
#include "heroBullet.h"
#include "Knife.h"
#include "Enemy_hard_magic.h"
#include "Enemy_hard.h"
#include "Enemy_easy.h"
#include "Enemy_normal.h"
#include "Enemy_normal_1.h"
#include "Boss_zrt.h"

using namespace std;

class First : public cocos2d::Layer
{
private:
	int Right = 0, Left = 0, up = 0, down = 0;
	int hasEnemy = 0; int hasBoss = 0;
	cocos2d::TMXLayer* _collidable;
	cocos2d::TMXLayer* _enemyDoor;
	cocos2d::TMXLayer* _bossDoor;
	cocos2d::TMXTiledMap* _tileMap;
	Hero* _role;
	Weapon_shotgun* _shotgun;
	Weapon_machinegun* gun;
	Weapon_poorgun* _poorgun;
	Knife* _knife;
	vector<cocos2d::Sprite*>vec_enemy;
	vector<HeroBullet*>vec_bullet;
	Enemy_hard_magic*_magic;
	Enemy_hard* _hard;
	Enemy_easy* _easy;
	Enemy_normal* _normal;
	Enemy_normal_1* _normal_1;
	Boss_zrt* _boss;
public:
	
	static cocos2d::Scene* createScene(int weapon_type);
	void settheVectorsame();
	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
	void setViewpointCenter(cocos2d::Vec2 position);
	void update(float dt);
	bool setRolePosition(cocos2d::Vec2 position);
	cocos2d::Vec2 tileCoordFromPosition(cocos2d::Vec2);
	void Press(cocos2d::EventKeyboard::KeyCode code, cocos2d::Event*event);
	void Released(cocos2d::EventKeyboard::KeyCode code, cocos2d::Event*event);
	
	bool initEnemy();
	bool initBoss();
	bool setEnemy(cocos2d::Vec2 posotion);
	bool setBoss(cocos2d::Vec2 position);

	void initMap();
	void initHero();
	void initWeapon();
	//void MenuItemPauseCallback(cocos2d::Ref *pSender);
	
	void scheduleBlood(float delta);
	// implement the "static create()" method manually
	CREATE_FUNC(First);
};

#endif // __HELLOWORLD_SCENE_H__
