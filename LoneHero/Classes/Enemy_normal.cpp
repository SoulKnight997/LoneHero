#include "Enemy_normal.h"
#include "SimpleAudioEngine.h"
#include "math.h"
#include <cstdlib>
#include <ctime>
#include "Bullet.h"

USING_NS_CC;

Enemy_normal* Enemy_normal::create(int b, int s, float i,const std::string& filename, Hero* he, vector<HeroBullet*>bullet) {
	Enemy_normal*p = new(std::nothrow)Enemy_normal;
	p->init(b, s,i, filename, he,bullet);
	srand(time(NULL));
	return p;
}

void Enemy_normal::directionChange(float dt) {
	direction = rand() % 629;
	direction = direction * 0.01;
	if ((direction < 1.57) || (direction > 4.71))
		enemy->setTexture("snowpositive.png");
	else
		enemy->setTexture("snowcounter.png");
}

void Enemy_normal::Move(float dt) {
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

void Enemy_normal::Attack(float dt) {
	double angle = 0;
	for (angle = 0;angle < 6.28;angle += 0.5) {
		auto bullet = Bullet::create(7, angle, 5, "redbullet.png",_hero);
		auto body = PhysicsBody::createEdgeBox(bullet->getBullet()->getContentSize());
		bullet->getBullet()->setPhysicsBody(body);
		bullet->getBullet()->setPosition(Vec2(enemy->getPosition()));
		this->addChild(bullet->getBullet());
		this->addChild(bullet);
	}
}