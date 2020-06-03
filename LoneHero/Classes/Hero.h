#ifndef __HERO_H__
#define __HERO_H__

#include"cocos2d.h"
#include"Weapon.h"

class Hero : public cocos2d::Node {
private:
	cocos2d::Sprite*hero;
	int blood, shield, blue;
public:
	static Hero*create(int, int, int, const std::string& filename);
	bool init(int, int, int, const std::string& filename);
	int getBlood();//返回血量
	int getShield();//返回护盾值
	int getBlue();//返回蓝量
	cocos2d::Sprite* getHero();//返回指向精灵hero的指针
	virtual void update(float dt);
	void setBlood(int);//设置血量
	void setShield(int);//设置护盾值
	void setBlue(int);//设置蓝量
	void setHero(const std::string& filename);//设置精灵图片
	void Press(cocos2d::EventKeyboard::KeyCode code, cocos2d::Event*event);
	void Released(cocos2d::EventKeyboard::KeyCode code, cocos2d::Event*event);
};
#endif
