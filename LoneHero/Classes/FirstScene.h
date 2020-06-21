#ifndef __FIRST_SCENE_H__
#define __FIRST_SCENE_H__

#include "cocos2d.h"
#include "Hero.h"
#include <vector>
#include "Weapon_machinegun.h"
#include "heroBullet.h"
#include "Knife.h"
#include "Enemy_hard_magic.h"
using namespace std;

class First : public cocos2d::Layer
{
private:
	cocos2d::TMXLayer* _collidable;
	cocos2d::TMXLayer* _enemyDoor;
	cocos2d::TMXLayer* _bossDoor;
	cocos2d::TMXTiledMap* _tileMap;
	Hero* _role;
	Weapon_machinegun*gun;
	vector<cocos2d::Sprite*>vec_enemy;
	vector<HeroBullet*>vec_bullet;
	Enemy_hard_magic*magic;
public:
	static cocos2d::Scene* createScene();

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
	
	void scheduleBlood(float delta);
	// implement the "static create()" method manually
	CREATE_FUNC(First);
};

#endif // __HELLOWORLD_SCENE_H__
