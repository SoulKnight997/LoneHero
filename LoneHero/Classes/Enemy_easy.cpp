#include "Enemy_easy.h"
#include "SimpleAudioEngine.h"
#include "math.h"
#include <cstdlib>
#include <ctime>
#include "Bullet.h"

USING_NS_CC;

Enemy_easy* Enemy_easy::create(int b,int s, const std::string& filename) {
	Enemy_easy*p = new(std::nothrow)Enemy_easy;
	p->init(b, s, filename);
	srand(time(NULL));
	return p;
}

void Enemy_easy::directionChange(float dt) {
	direction = rand() % 629;
	direction = direction * 0.01;
}

void Enemy_easy::Move(float dt) {
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

void Enemy_easy::Attack(float dt) {
	auto bullet = Bullet::create(7, 0, 5, "redbullet.png");
	auto body = PhysicsBody::createEdgeBox(bullet->getBullet()->getContentSize());
	bullet->getBullet()->setPhysicsBody(body);
	bullet->getBullet()->setPosition(Vec2(enemy->getPosition()));
	this->addChild(bullet->getBullet());
	this->addChild(bullet);
}