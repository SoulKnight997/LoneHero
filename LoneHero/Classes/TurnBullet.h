#ifndef __TURNBULLET_H__
#define __TURNBULLET_H__

#include"cocos2d.h"
#include"Hero.h"
class TurnBullet :public cocos2d::Node
{
private:
	cocos2d::Sprite*bullet;
	Hero*hero;//Ӣ��λ��
	int speed;//�ӵ������ٶ�
	double angle;//�ӵ���ˮƽ����н�
	int hurt;//�ӵ����˺�
	int number = 0;
public:
	static TurnBullet*create(int, double, int, const std::string& filename, Hero*);
	bool init(int, double, int, const std::string& filename, Hero*);
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
