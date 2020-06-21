#ifndef __BULLET_H__
#define __BULLET_H__

#include "cocos2d.h"
#include <vector>
using namespace std;


class Bullet :public cocos2d::Node
{
private:
	int num = 0;
	cocos2d::Sprite*bullet;
	int speed;//�ӵ������ٶ�
	double angle;//�ӵ���ˮƽ����н�
	int hurt;//�ӵ����˺�
public:
	static Bullet*create(int, double, int, const std::string& filename);
	bool init(int, double, int, const std::string& filename);
	virtual void update(float dt);
	cocos2d::Sprite* getBullet();
	int getSpeed();
	float getAngle();
	int getHurt();
	void setBullet(const std::string& filename);
	void setAngle(float);
	void setSpeed(int);
	void setHurt(int);

	//cocos2d::Vec2 tileCoordFromPosition(cocos2d::Vec2 position);
	//void stopBullet();
	//bool isContact(cocos2d::Vec2 position);

};

#endif

