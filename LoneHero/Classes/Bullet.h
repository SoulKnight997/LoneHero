#ifndef __BULLET_H__
#define __BULLET_H__

#include"cocos2d.h"
class Bullet :public cocos2d::Node
{
private:
	cocos2d::Sprite*bullet;
	int speed;//子弹飞行速度
	int angle;//子弹与水平方向夹角
	int hurt;//子弹的伤害
public:
	static Bullet*create(int, int, int, const std::string& filename);
	bool init(int, int, int, const std::string& filename);
	virtual void update(float dt);
	cocos2d::Sprite* getBullet();
};
#endif
