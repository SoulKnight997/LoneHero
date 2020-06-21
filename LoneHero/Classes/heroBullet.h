#ifndef __HEROBULLET_H__
#define __HEROBULLET_H__

#include"cocos2d.h"

class HeroBullet :public cocos2d::Node
{
private:
	cocos2d::Sprite*bullet;
	int speed;//�ӵ������ٶ�
	double angle;//�ӵ���ˮƽ����н�
	int hurt;//�ӵ����˺�
public:
	static HeroBullet*create(int, double, int, const std::string& filename);
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
};
#endif
