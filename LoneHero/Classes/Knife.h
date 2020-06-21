#ifndef __KNIFE_H__
#define __KNIFE_H__

#include"cocos2d.h"
#include <time.h>

class Knife:public cocos2d::Node
{
protected:
	float attack_interval;
	int hurt;
	int blue_consume;
	cocos2d::Sprite* weapon;
	cocos2d::Sprite* hero;
	clock_t time;
public:
	static Knife* create(float, int, int, const std::string&, cocos2d::Sprite*);
	bool init(float, int, int, const std::string& filename, cocos2d::Sprite*);
	cocos2d::Sprite* getWeapon();
	float getAttackInterval();
	int getHurt();
	int getBlueConsume();
	void setWeapon(const std::string& filename);
	void setAttackIterval(float);
	void setHurt(int);
	void setBlueConsume(int);
	void FollowMyHero(float dt);
	void Attack(float dt);
};
#endif
