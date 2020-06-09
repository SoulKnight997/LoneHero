#ifndef __WEAPON_SHOTGUN_H__
#define __WEAPON_SHOTGUN_H__

#include"cocos2d.h"
#include "Weapon.h"
class Weapon_shotgun :public Weapon
{
public:
	static Weapon_shotgun* create(float, int, int, const std::string&,cocos2d::Sprite*);
	void Attack(float dt);
};
#endif
