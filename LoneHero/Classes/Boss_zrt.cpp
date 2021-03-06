#include "Boss_zrt.h"
#include "SimpleAudioEngine.h"
#include "math.h"
#include <cstdlib>
#include <ctime>
#include "Bullet.h"
#define RANGE 120
USING_NS_CC;

Boss_zrt* Boss_zrt::create(int b, int s, const std::string& filename, Hero* he,Vec2 pos) {
	Boss_zrt*p = new(std::nothrow)Boss_zrt;
	p->init(b, s, 2.0f,filename, he,pos);
	srand(time(NULL));
	return p;
}

void Boss_zrt::Attack(float dt) {
	this->unschedule(schedule_selector(Boss_zrt::Attack));
	int random = rand() % 3;
	if (random == 1) {
		this->Attack_luoxuanshengtian();
		this->schedule(schedule_selector(Boss_zrt::Attack), 2.0f);
	}
	else if(random==2){
		this->Attack_tiannvsanhua();
		this->schedule(schedule_selector(Boss_zrt::Attack), 2.0f);
	}
	else {
		this->Attack_huajichongzhuang();
		this->schedule(schedule_selector(Boss_zrt::Attack), 2.0f);
	}
}

void Boss_zrt::directionChange(float dt) {
	double x1, y1, x2, y2;
	x1 = enemy->getPositionX(), y1 = enemy->getPositionY(), x2 = hero->getPositionX(), y2 = hero->getPositionY();
	if ((x1 != x2) || (y1 != y2)) {
		if (x1 <= x2)
			direction = asin((y2 - y1) / sqrt(pow((y2 - y1), 2) + pow((x2 - x1), 2)));
		else
			direction = 3.14159 - asin((y2 - y1) / sqrt(pow((y2 - y1), 2) + pow((x2 - x1), 2)));
	}
}

void Boss_zrt::Move(float dt) {
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

void Boss_zrt::Attack_tiannvsanhua() {
	this->schedule(schedule_selector(Boss_zrt::CircleBullet), 0.5f, 3, 0.0f);
}

void Boss_zrt::Attack_luoxuanshengtian() {
	this->schedule(schedule_selector(Boss_zrt::StraightBullet), 0.05f, 40, 0.0f);
}

void Boss_zrt::Attack_huajichongzhuang() {
	this->schedule(schedule_selector(Boss_zrt::HuajiBullet), 0.05f, 40, 0.0f);
}

void Boss_zrt::StraightBullet(float dt) {
	angle += 0.314;
	auto bullet = Bullet::create(7, angle, 5, "redbullet.png",_hero);
	auto body = PhysicsBody::createEdgeBox(bullet->getBullet()->getContentSize());
	bullet->getBullet()->setPhysicsBody(body);
	bullet->getBullet()->setPosition(Vec2(enemy->getPosition()));
	this->addChild(bullet->getBullet());
	this->addChild(bullet);
}

void Boss_zrt::CircleBullet(float dt) {
	double angle = 0;
	for (angle = 0;angle < 6.28;angle += 0.5) {
		auto bullet = Bullet::create(4, angle, 5, "purplebullet.png",_hero);
		auto body = PhysicsBody::createEdgeBox(bullet->getBullet()->getContentSize());
		bullet->getBullet()->setPhysicsBody(body);
		bullet->getBullet()->setPosition(Vec2(enemy->getPosition()));
		this->addChild(bullet->getBullet());
		this->addChild(bullet);
	}
}

void Boss_zrt::HuajiBullet(float dt) {
	double angle = 0;
	angle = rand() % 629;
	angle = angle * 0.01;
	auto bullet = Bullet::create(4, angle, 5, "orangebullet.png",_hero);
	auto body = PhysicsBody::createEdgeBox(bullet->getBullet()->getContentSize());
	bullet->getBullet()->setPhysicsBody(body);
	bullet->getBullet()->setPosition(Vec2(enemy->getPosition()));
	this->addChild(bullet->getBullet());
	this->addChild(bullet);
}


