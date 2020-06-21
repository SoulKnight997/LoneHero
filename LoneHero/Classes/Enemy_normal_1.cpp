#include "Enemy_normal_1.h"
#include "SimpleAudioEngine.h"
#include "math.h"
#include <cstdlib>
#include <ctime>
#include "Bullet.h"
#define RANGE 
USING_NS_CC;

Enemy_normal_1* Enemy_normal_1::create(int b, int s, float i, const std::string& filename, Hero* he,Vec2 pos) {
	Enemy_normal_1*p = new(std::nothrow)Enemy_normal_1;
	p->init(b, s, i, filename, he,pos);
	srand(time(NULL));
	return p;
}

void Enemy_normal_1::directionChange(float dt) {
	direction = rand() % 629;
	direction = direction * 0.01;
}

void Enemy_normal_1::Move(float dt) {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	if ((enemy->getPositionX() >= 0) && (enemy->getPositionY() >= 0) && (enemy->getPositionX() <= visibleSize.width) && (enemy->getPositionY() <= visibleSize.height))
		enemy->setPosition(enemy->getPositionX() + speed * cos(direction), enemy->getPositionY() + speed * sin(direction));
	else {
		if (enemy->getPositionX() < 0)
			enemy->setPositionX(0);
		else if (enemy->getPositionY() < 0)
			enemy->setPositionY(0);
		else if (enemy->getPositionX() > visibleSize.width)
			enemy->setPositionX(visibleSize.width);
		else if (enemy->getPositionY() > visibleSize.height)
			enemy->setPositionY(visibleSize.height);
	}
}

void Enemy_normal_1::Strightbullet(float dt) {
	double x1, y1, x2, y2;
	double angle;
	x1 = enemy->getPositionX(), y1 = enemy->getPositionY(), x2 = hero->getPositionX(), y2 = hero->getPositionY();
	if ((x1 != x2) || (y1 != y2)) {
		if (x1 <= x2)
			angle = asin((y2 - y1) / sqrt(pow((y2 - y1), 2) + pow((x2 - x1), 2)));
		else
			angle = 3.14159 - asin((y2 - y1) / sqrt(pow((y2 - y1), 2) + pow((x2 - x1), 2)));
	}
	auto bullet1 = Bullet::create(5, 0, 5, "magic.png",_hero);
	auto body1 = PhysicsBody::createEdgeBox(bullet1->getBullet()->getContentSize());
	bullet1->getBullet()->setPhysicsBody(body1);
	bullet1->getBullet()->setPosition(Vec2(enemy->getPosition()));
	bullet1->setAngle(angle);
	this->addChild(bullet1->getBullet());
	this->addChild(bullet1);
	auto bullet2 = Bullet::create(5, 0, 5, "magic.png",_hero);
	auto body2 = PhysicsBody::createEdgeBox(bullet2->getBullet()->getContentSize());
	bullet2->getBullet()->setPhysicsBody(body2);
	bullet2->getBullet()->setPosition(Vec2(enemy->getPosition())-Vec2(0,5));
	bullet2->setAngle(angle);
	this->addChild(bullet2->getBullet());
	this->addChild(bullet2);
}

void Enemy_normal_1::Attack(float dt) {
	this->schedule(schedule_selector(Enemy_normal_1::Strightbullet), 0.2f, 5, 0.01f);
}