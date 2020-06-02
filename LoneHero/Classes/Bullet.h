#ifndef __BULLET_H__
#define __BULLET_H__

#include"cocos2d.h"
class Bullet :public cocos2d::Node
{
private:
	cocos2d::Sprite*bullet;
	int speed;//�ӵ������ٶ�
	float angle;//�ӵ���ˮƽ����н�
	int hurt;//�ӵ����˺�
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
