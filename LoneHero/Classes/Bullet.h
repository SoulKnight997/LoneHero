#ifndef __BULLET_H__
#define __BULLET_H__

#include"cocos2d.h"
class Bullet :public cocos2d::Node
{
private:
	cocos2d::Sprite*bullet;
	int speed;//子弹飞行速度
	float angle;//子弹与水平方向夹角
	int hurt;//子弹的伤害
public:
	static Bullet*create(int, float, int, const std::string& filename);
	bool init(int, float, int, const std::string& filename);
	virtual void update(float dt);
	cocos2d::Sprite* getBullet();
	int getSpeed();
	float getAngle();
	int getHurt();
	void setBullet(const std::string& filename);
	void setAngle(float);
	void setSpeed(int);
	void setHurt(int);
};
#endif
