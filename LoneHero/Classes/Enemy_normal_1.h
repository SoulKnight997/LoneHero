#ifndef __ENEMY_NORMAL_1_H__
#define __ENEMY_NORMAL_1_H__

#include"cocos2d.h"
#include "Enemy.h"
class Enemy_normal_1 :public Enemy
{
public:
	static Enemy_normal_1* create(int, int, float, const std::string&, cocos2d::Sprite*);
	void directionChange(float dt);
	void Move(float dt);
	void Attack(float dt);
	void Strightbullet(float dt);
};
#endif
