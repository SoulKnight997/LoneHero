#include "Enemy_hard_magic.h"
#include "SimpleAudioEngine.h"
#include "math.h"
#include <cstdlib>
#include <ctime>
#include "TurnBullet.h"

USING_NS_CC;

Enemy_hard_magic* Enemy_hard_magic::create(int b, int s, float i, const std::string& filename, Hero* he) {
	Enemy_hard_magic*p = new(std::nothrow)Enemy_hard_magic;
	p->init(b, s, i, filename, he);
	srand(time(NULL));
	return p;
}

void Enemy_hard_magic::directionChange(float dt) {
	direction = rand() % 629;
	direction = direction * 0.01;
}

void Enemy_hard_magic::Move(float dt) {
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

void Enemy_hard_magic::Attack(float dt) {
	double angle = 0;
	for (angle = 0;angle < 6.28;angle += 0.5) {
		auto bullet = TurnBullet::create(4, angle, 5, "purplebullet.png", hero);
		auto body = PhysicsBody::createEdgeBox(bullet->getBullet()->getContentSize());
		bullet->getBullet()->setPhysicsBody(body);
		bullet->getBullet()->setPosition(Vec2(enemy->getPosition()));
		this->addChild(bullet->getBullet());
		this->addChild(bullet);
	}
}