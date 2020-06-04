#ifndef __BOSS_ZRT_H__
#define __BOSS_ZRT_H__

#include"cocos2d.h"
#include "Enemy.h"

class Boss_zrt :public Enemy
{
public:
	static Boss_zrt* create(int, int, const std::string&, cocos2d::Sprite*);
	void directionChange(float dt);
	void Move(float dt);
	void Attack(float dt);
};
#endif

