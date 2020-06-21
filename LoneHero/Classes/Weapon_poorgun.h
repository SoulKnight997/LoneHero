#ifndef __WEAPON_POORGUN_H__
#define __WEAPON_POORGUN_H__

#include"cocos2d.h"
#include "Weapon.h"
class Weapon_poorgun :public Weapon
{
public:
	static Weapon_poorgun* create(float, int, int, const std::string&,cocos2d::Sprite*,vector<HeroBullet*>);
	void Attack(float dt);
};
#endif
