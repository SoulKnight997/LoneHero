#ifndef __ENEMY_NORMAL_H__
#define __ENEMY_NORMAL_H__

#include"cocos2d.h"
#include "Enemy.h"
class Enemy_normal :public Enemy
{
public:
	static Enemy_normal* create(int, int,float, const std::string&, Hero*,cocos2d::Vec2);
	void directionChange(float dt);
	void Move(float dt);
	void Attack(float dt);
};
#endif
