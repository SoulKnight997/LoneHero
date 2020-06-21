#include "Knife.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Knife* Knife::create(float a, int h, int b, const std::string& filename, cocos2d::Sprite* he) {
	Knife* p = new(std::nothrow)Knife;
	p->init(a, h, b, filename, he);
	return p;
}

bool Knife::init(float a, int h, int b, const std::string& filename, cocos2d::Sprite* he) {
	attack_interval = a, hurt = h, blue_consume = b;
	hero = he;
	time = clock();
	weapon = cocos2d::Sprite::create(filename);
	weapon->setAnchorPoint(Vec2(0.5, 1));
	this->schedule(schedule_selector(Knife::FollowMyHero), 0.01f);
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = [=](EventKeyboard::KeyCode keycode, Event*event) {
		if (keycode == EventKeyboard::KeyCode::KEY_J) {
			if (clock() - time >= attack_interval * 1000) {
				Attack(0.1f);
				time = clock();
			}
			this->schedule(schedule_selector(Knife::Attack), attack_interval);
		}
	};
	listener->onKeyReleased = [=](EventKeyboard::KeyCode keycode, Event*event) {
		if (keycode == EventKeyboard::KeyCode::KEY_J)
			this->unschedule(schedule_selector(Knife::Attack));
	};
	EventDispatcher*eve = Director::getInstance()->getEventDispatcher();
	eve->addEventListenerWithSceneGraphPriority(listener, weapon);
	return true;
}

cocos2d::Sprite* Knife::getWeapon() {
	return weapon;
}

float Knife::getAttackInterval() {
	return attack_interval;
}

int Knife::getHurt() {
	return hurt;
}

int Knife::getBlueConsume() {
	return blue_consume;
}

void Knife::setWeapon(const std::string& filename) {
	weapon = cocos2d::Sprite::create(filename);
}

void Knife::setAttackIterval(float a) {
	attack_interval = a;
}

void Knife::setHurt(int h) {
	hurt = h;
}

void Knife::setBlueConsume(int b) {
	blue_consume = b;
}

void Knife::Attack(float dt) {
	weapon->runAction(RotateBy::create(0.3, 360));
}

void Knife::FollowMyHero(float dt) {
	weapon->setPosition(hero->getPositionX(), hero->getPositionY() - 5);
}