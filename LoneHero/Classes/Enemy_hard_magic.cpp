#include "Enemy_hard_magic.h"
#include "SimpleAudioEngine.h"
#include "math.h"
#include <cstdlib>
#include <ctime>
#include "TurnBullet.h"
#define RANGE 60
USING_NS_CC;

Enemy_hard_magic* Enemy_hard_magic::create(int b, int s, float i, const std::string& filename, Hero* he,Vec2 pos) {
	Enemy_hard_magic*p = new(std::nothrow)Enemy_hard_magic;
	p->init(b, s, i, filename, he,pos);
	srand(time(NULL));
	return p;
}

void Enemy_hard_magic::directionChange(float dt) {
	direction = rand() % 629;
	direction = direction * 0.01;
}

void Enemy_hard_magic::Move(float dt) {
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

void Enemy_hard_magic::Attack(float dt) {
	double angle = 0;
	for (angle = 0;angle < 6.28;angle += 0.5) {
		auto bullet = TurnBullet::create(4, angle, 5, "purplebullet.png", _hero);
		auto body = PhysicsBody::createEdgeBox(bullet->getBullet()->getContentSize());
		bullet->getBullet()->setPhysicsBody(body);
		bullet->getBullet()->setPosition(Vec2(enemy->getPosition()));
		this->addChild(bullet->getBullet());
		this->addChild(bullet);
	}
}