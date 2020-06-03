#ifndef __WEAPON_H__
#define __WEAPON_H__

#include"cocos2d.h"
class Weapon :public cocos2d::Node
{
protected:
	float attack_interval;
	int hurt;
	int blue_consume;
	cocos2d::Sprite* weapon;
	cocos2d::Sprite* hero;
public:
	bool init(float, int, int, const std::string& filename,cocos2d::Sprite*);
	cocos2d::Sprite* getWeapon();
	float getAttackInterval();
	int getHurt();
	int getBlueConsume();
	void setWeapon(const std::string& filename);
	void setAttackIterval(float);
	void setHurt(int);
	void setBlueConsume(int);
	void FollowMyHero(float dt);
	virtual void Attack(float dt);
};
#endif
