#ifndef __ENEMY_HARD_MAGIC_H__
#define __ENEMY_HARD_MAGIC_H__

#include"cocos2d.h"
#include "Enemy.h"
class Enemy_hard_magic :public Enemy
{
public:
	static Enemy_hard_magic* create(int, int, float, const std::string&, Hero*, vector<HeroBullet*>);
	void directionChange(float dt);
	void Move(float dt);
	void Attack(float dt);
};
#endif
