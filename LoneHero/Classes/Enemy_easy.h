#ifndef __ENEMY_EASY_H__
#define __ENEMY_EASY_H__

#include"cocos2d.h"
#include "Enemy.h"
class Enemy_easy :public Enemy
{
public:
	static Enemy_easy* create(int, int, const std::string&,cocos2d::Sprite*);
	void directionChange(float dt);
	void Move(float dt);
	void Attack(float dt);
};
#endif
