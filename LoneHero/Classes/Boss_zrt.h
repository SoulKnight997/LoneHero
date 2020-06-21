#ifndef __BOSS_ZRT_H__
#define __BOSS_ZRT_H__

#include"cocos2d.h"
#include "Enemy.h"

class Boss_zrt :public Enemy
{
public:
	static Boss_zrt* create(int, int, const std::string&, Hero*);
	void directionChange(float dt);
	void Move(float dt);
	void Attack(float dt);
	void Attack_tiannvsanhua();
	void Attack_luoxuanshengtian();
	void Attack_huajichongzhuang();
	void StraightBullet(float dt);
	void CircleBullet(float dt);
	void HuajiBullet(float dt);
};
#endif

