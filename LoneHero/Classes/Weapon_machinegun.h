#ifndef __WEAPON_MACHINEGUN_H__
#define __WEAPON_MACHINEGUN_H__

#include"cocos2d.h"
#include "Weapon.h"
class Weapon_machinegun :public Weapon
{
public:
	static Weapon_machinegun* create(float, int, int, const std::string&, cocos2d::Sprite*);
	void Attack(float dt);
};
#endif
