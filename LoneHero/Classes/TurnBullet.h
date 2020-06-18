#ifndef __TURNBULLET_H__
#define __TURNBULLET_H__

#include"cocos2d.h"
class TurnBullet :public cocos2d::Node
{
private:
	cocos2d::Sprite*bullet;
	int speed;//子弹飞行速度
	double angle;//子弹与水平方向夹角
	int hurt;//子弹的伤害
	cocos2d::Sprite*hero;
public:
	static TurnBullet*create(int, double, int, const std::string& ,cocos2d::Sprite*);
	bool init(int, double, int, const std::string& ,cocos2d::Sprite*);
	virtual void update(float dt);
	cocos2d::Sprite* getBullet();
	int getSpeed();
	float getAngle();
	int getHurt();
	void setBullet(const std::string& filename);
	void setAngle(float);
	void setSpeed(int);
	void setHurt(int);
	virtual void Turn(float dt);
};
#endif
