#ifndef __BULLET_H__
#define __BULLET_H__

#include"cocos2d.h"
class Bullet :public cocos2d::Node
{
private:
	cocos2d::Sprite*bullet;
	int speed;//�ӵ������ٶ�
	int angle;//�ӵ���ˮƽ����н�
	int hurt;//�ӵ����˺�
public:
	static Bullet*create(int, int, int, const std::string& filename);
	bool init(int, int, int, const std::string& filename);
	virtual void update(float dt);
	cocos2d::Sprite* getBullet();
};
#endif
