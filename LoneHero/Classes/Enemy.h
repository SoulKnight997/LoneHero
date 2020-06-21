#ifndef __ENEMY_H__
#define __ENEMY_H__

#include"cocos2d.h"
#include"Hero.h"
#include"heroBullet.h"
#include<vector>

using namespace std;
class Enemy :public cocos2d::Node
{
protected:
	int blood;
	double direction;
	int speed;
	cocos2d::Sprite* enemy;
	cocos2d::Sprite* hero;
	Hero* _hero;
	double angle;
	float interval;
	cocos2d::Vec2 origin_pos;
	vector<HeroBullet*>bullet;
public:
	bool init(int, int,float, const std::string&,Hero*,cocos2d::Vec2);
	cocos2d::Sprite* getEnemy();
	int getBlood();
	float getDirection();
	int getSpeed();
	void setEnemy(const std::string& filename);
	void setBlood(int);
	void setDirection(float);
	void setSpeed(int);
	void setVector(vector<HeroBullet*>);
	virtual void directionChange(float dt);
	virtual void Move(float dt);
	virtual void Attack(float dt);
	void Hit(float dt);
};
#endif
