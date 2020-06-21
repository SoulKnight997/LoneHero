#ifndef __ENEMY_HARD_H__
#define __ENEMY_HARD_H__

#include"cocos2d.h"
#include "Enemy.h"
class Enemy_hard :public Enemy
{
public:
	static Enemy_hard* create(int, int, float, const std::string&, Hero*,cocos2d::Vec2);
	void directionChange(float dt);
	void Move(float dt);
	void Attack(float dt);
	void Strightbullet(float dt);
};
#endif
