#ifndef __ENEMY_H__
#define __ENEMY_H__

#include"cocos2d.h"

class Enemy :public cocos2d::Node
{
protected:
	int blood;
	double direction;
	int speed;
	cocos2d::Sprite* enemy;
	cocos2d::Sprite* hero;
	double angle;
public:
	bool init(int, int, const std::string&,cocos2d::Sprite*);
	cocos2d::Sprite* getEnemy();
	int getBlood();
	float getDirection();
	int getSpeed();
	void setEnemy(const std::string& filename);
	void setBlood(int);
	void setDirection(float);
	void setSpeed(int);
	virtual void directionChange(float dt);
	virtual void Move(float dt);
	virtual void Attack(float dt);
};
#endif
