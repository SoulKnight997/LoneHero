#include "Bullet.h"
#include "SimpleAudioEngine.h"
#include "math.h"

USING_NS_CC;

Bullet* Bullet::create(int s, double a, int h, const std::string& filename,Hero*he) {
	Bullet*p = new(std::nothrow)Bullet;
	p->init(s, a, h, filename,he);
	return p;
}

bool Bullet::init(int s, double a, int h, const std::string& filename,Hero*he) {
	speed = s, angle = a, hurt = h;
	hero = he;
	bullet = cocos2d::Sprite::create(filename);
	auto listener = EventListenerKeyboard::create();
	this->scheduleUpdate();
	return true;
}

cocos2d::Sprite* Bullet::getBullet() {
	return bullet;
}

void Bullet::update(float dt) {
	number++;
	bullet->setPosition(bullet->getPositionX() + speed * cos(angle), bullet->getPositionY() + speed * sin(angle));
	if (bullet->getBoundingBox().intersectsRect(hero->getHero()->getBoundingBox())){
		this->unscheduleUpdate();
		bullet->removeFromParent();
	}
	if (number >= 60) {
		this->unscheduleUpdate();
		bullet->removeFromParent();
	}
}

int Bullet::getSpeed() {
	return speed;
}

float Bullet::getAngle() {
	return angle;
}

int Bullet::getHurt() {
	return hurt;
}

void Bullet::setBullet(const std::string& filename) {
	bullet = cocos2d::Sprite::create(filename);
}

void Bullet::setSpeed(int s) {
	speed = s;
}

void Bullet::setAngle(float a) {
	angle = a;
}

void Bullet::setHurt(int h) {
	hurt = h;
}