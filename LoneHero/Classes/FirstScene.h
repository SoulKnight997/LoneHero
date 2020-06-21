#pragma once
#ifndef __FIRST_SCENE_H__
#define __FIRST_SCENE_H__


#include "cocos2d.h"
#include "Hero.h"
#include "Bullet.h"
class First : public cocos2d::Layer
{
private:
	Hero* _role;
public:

	cocos2d::TMXLayer* _collidable;
	cocos2d::TMXTiledMap* _tileMap;

	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
	void setViewpointCenter(cocos2d::Vec2 position);
	void update(float dt);
	//void updateBullet();
	bool setRolePosition(cocos2d::Vec2 position);
	cocos2d::Vec2 tileCoordFromPosition(cocos2d::Vec2);
	//cocos2d::Vec2 tileCoordForPosition(const Vec2&);
	void Press(cocos2d::EventKeyboard::KeyCode code, cocos2d::Event*event);
	void Released(cocos2d::EventKeyboard::KeyCode code, cocos2d::Event*event);

	


	// implement the "static create()" method manually
	CREATE_FUNC(First);
};

#endif 

