#include "Enemy_normal.h"
#include "SimpleAudioEngine.h"
#include "math.h"
#include <cstdlib>
#include <ctime>
#include "Bullet.h"
#define RANGE 60
USING_NS_CC;

Enemy_normal* Enemy_normal::create(int b, int s, float i,const std::string& filename, Hero* he,Vec2 pos) {
	Enemy_normal*p = new(std::nothrow)Enemy_normal;
	p->init(b, s,i, filename, he,pos);
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

void Enemy_normal::Attack(float dt) {
	double angle = 0;
	for (angle = 0;angle < 6.28;angle += 0.5) {
		auto bullet = Bullet::create(4, angle, 5, "orangebullet.png",_hero);
		auto body = PhysicsBody::createEdgeBox(bullet->getBullet()->getContentSize());
		bullet->getBullet()->setPhysicsBody(body);
		bullet->getBullet()->setPosition(Vec2(enemy->getPosition()));
		this->addChild(bullet->getBullet());
		this->addChild(bullet);
	}
}