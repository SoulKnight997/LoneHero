#include "Bullet.h"
#include "SimpleAudioEngine.h"
#include "math.h"

USING_NS_CC;

Bullet* Bullet::create(int s, float a, int h, const std::string& filename) {
	Bullet*p = new(std::nothrow)Bullet;
	p->init(s, a, h, filename);
	return p;
}

bool Bullet::init(int s, float a, int h, const std::string& filename) {
	speed = s, angle = a, hurt = h;
	bullet = cocos2d::Sprite::create(filename);
	auto listener = EventListenerKeyboard::create();
	this->scheduleUpdate();
	return true;
}

cocos2d::Sprite* Bullet::getBullet() {
	return bullet;
}

void Bullet::update(float dt) {
	bullet->setPosition(bullet->getPositionX() + speed * cos(angle), bullet->getPositionY() + speed * sin(angle));
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