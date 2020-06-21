#include "TurnBullet.h"
#include "SimpleAudioEngine.h"
#include "math.h"

USING_NS_CC;

TurnBullet* TurnBullet::create(int s, double a, int h, const std::string& filename,Hero*he) {
	TurnBullet*p = new(std::nothrow)TurnBullet;
	p->init(s, a, h, filename,he);
	return p;
}

bool TurnBullet::init(int s, double a, int h, const std::string& filename,Hero*he) {
	speed = s, angle = a, hurt = h;
	hero = he;
	bullet = cocos2d::Sprite::create(filename);
	auto listener = EventListenerKeyboard::create();
	this->scheduleUpdate();
	this->scheduleOnce(schedule_selector(TurnBullet::Turn), 0.2f);
	return true;
}

cocos2d::Sprite* TurnBullet::getBullet() {
	return bullet;
}

void TurnBullet::update(float dt) {
	number++;
	bullet->setPosition(bullet->getPositionX() + speed * cos(angle), bullet->getPositionY() + speed * sin(angle));
	if (bullet) {
		if (bullet->getBoundingBox().intersectsRect(hero->getHero()->getBoundingBox())) {
			this->unscheduleUpdate();
			this->unschedule(schedule_selector(TurnBullet::Turn));
			this->removeFromParent();
			bullet->removeFromParent();
			bullet = NULL;
		}
	}
	if (bullet) {
		if (number*speed >= 240) {
			this->unscheduleUpdate();
			this->removeFromParent();
			bullet->removeFromParent();
			bullet = NULL;
		}
	}
	

	
}

int TurnBullet::getSpeed() {
	return speed;
}

float TurnBullet::getAngle() {
	return angle;
}

int TurnBullet::getHurt() {
	return hurt;
}

void TurnBullet::setBullet(const std::string& filename) {
	bullet = cocos2d::Sprite::create(filename);
}

void TurnBullet::setSpeed(int s) {
	speed = s;
}

void TurnBullet::setAngle(float a) {
	angle = a;
}

void TurnBullet::setHurt(int h) {
	hurt = h;
}

void TurnBullet::Turn(float dt) {
	double x1, y1, x2, y2;
	if (bullet) {
		x1 = bullet->getPositionX(), y1 = bullet->getPositionY(), x2 = hero->getHero()->getPositionX(), y2 = hero->getHero()->getPositionY();
		if ((x1 != x2) || (y1 != y2)) {
			if (x1 <= x2)
				this->setAngle(asin((y2 - y1) / sqrt(pow((y2 - y1), 2) + pow((x2 - x1), 2))));
			else
				this->setAngle(3.14159 - asin((y2 - y1) / sqrt(pow((y2 - y1), 2) + pow((x2 - x1), 2))));
		}
	}
	
}