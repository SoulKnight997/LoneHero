#include "Enemy_hard.h"
#include "SimpleAudioEngine.h"
#include "math.h"
#include <cstdlib>
#include <ctime>
#include "Bullet.h"
#define RANGE 60
USING_NS_CC;

Enemy_hard* Enemy_hard::create(int b, int s, float i, const std::string& filename, Hero* he,Vec2 pos) {
	Enemy_hard*p = new(std::nothrow)Enemy_hard;
	p->init(b, s, i, filename, he,pos);
	srand(time(NULL));
	return p;
}

void Enemy_hard::directionChange(float dt) {
	direction = rand() % 629;
	direction = direction * 0.01;
}

void Enemy_hard::Move(float dt) {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	if ((enemy->getPositionX() >= origin_pos.x - RANGE) && (enemy->getPositionY() >= origin_pos.y - RANGE) && (enemy->getPositionX() <= origin_pos.x + RANGE) && (enemy->getPositionY() <= origin_pos.y + RANGE))
		enemy->setPosition(enemy->getPositionX() + speed * cos(direction), enemy->getPositionY() + speed * sin(direction));
	else {
		if (enemy->getPositionX() < origin_pos.x - RANGE)
			enemy->setPositionX(origin_pos.x - RANGE);
		else if (enemy->getPositionY() < origin_pos.y - RANGE)
			enemy->setPositionY(origin_pos.y - RANGE);
		else if (enemy->getPositionX() > origin_pos.x + RANGE)
			enemy->setPositionX(origin_pos.x + RANGE);
		else if (enemy->getPositionY() > origin_pos.y + RANGE)
			enemy->setPositionY(origin_pos.y + RANGE);
	}
}

void Enemy_hard::Strightbullet(float dt) {
	double a = rand() % 156;
	a = a * 0.01;
	a = a - 0.78;
	auto bullet = Bullet::create(4, 0, 5, "magic.png",_hero);
	double x1, y1, x2, y2;
	x1 = enemy->getPositionX(), y1 = enemy->getPositionY(), x2 = hero->getPositionX(), y2 = hero->getPositionY();
	if ((x1 != x2) || (y1 != y2)) {
		if (x1 <= x2)
			bullet->setAngle(asin((y2 - y1) / sqrt(pow((y2 - y1), 2) + pow((x2 - x1), 2)))+a);
		else
			bullet->setAngle(3.14159 - asin((y2 - y1) / sqrt(pow((y2 - y1), 2) + pow((x2 - x1), 2)))+a);
	}
	auto body = PhysicsBody::createEdgeBox(bullet->getBullet()->getContentSize());
	bullet->getBullet()->setPhysicsBody(body);
	bullet->getBullet()->setPosition(Vec2(enemy->getPosition()));
	this->addChild(bullet->getBullet());
	this->addChild(bullet);
}

void Enemy_hard::Attack(float dt) {
	this->schedule(schedule_selector(Enemy_hard::Strightbullet), 0.05f, 40, 0.01f);
}