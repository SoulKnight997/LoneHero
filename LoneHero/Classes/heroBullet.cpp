#include "heroBullet.h"
#include "SimpleAudioEngine.h"
#include "math.h"

USING_NS_CC;

HeroBullet* HeroBullet::create(int s, double a, int h, const std::string& filename) {
	HeroBullet*p = new(std::nothrow)HeroBullet;
	p->init(s, a, h, filename);
	return p;
}

bool HeroBullet::init(int s, double a, int h, const std::string& filename) {
	speed = s, angle = a, hurt = h;
	bullet = cocos2d::Sprite::create(filename);
	auto listener = EventListenerKeyboard::create();
	this->scheduleUpdate();
	return true;
}

cocos2d::Sprite* HeroBullet::getBullet() {
	return bullet;
}

void HeroBullet::update(float dt) {
	bullet->setPosition(bullet->getPositionX() + speed * cos(angle), bullet->getPositionY() + speed * sin(angle));
}

int HeroBullet::getSpeed() {
	return speed;
}

float HeroBullet::getAngle() {
	return angle;
}

int HeroBullet::getHurt() {
	return hurt;
}

void HeroBullet::setBullet(const std::string& filename) {
	bullet = cocos2d::Sprite::create(filename);
}

void HeroBullet::setSpeed(int s) {
	speed = s;
}

void HeroBullet::setAngle(float a) {
	angle = a;
}

void HeroBullet::setHurt(int h) {
	hurt = h;
}