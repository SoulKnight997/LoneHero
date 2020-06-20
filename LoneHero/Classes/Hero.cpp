#include "Hero.h"
#include "SimpleAudioEngine.h"
#include "Bullet.h"

USING_NS_CC;

Hero* Hero::create(int blo, int shi, int blu, const std::string& filename) {
	Hero*p = new(std::nothrow)Hero;
	p->init(blo, shi, blu, filename);
	return p;
}

//int right = 0, left = 0, up = 0, down = 0;
bool Hero::init(int blo, int shi, int blu, const std::string& filename) {
	blood = blo, shield = shi, blue = blu;
	buff = 0;
	frequency = 0;
	time = clock();
	hero = cocos2d::Sprite::create(filename);
	/*auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(Hero::Press, this);
	listener->onKeyReleased = CC_CALLBACK_2(Hero::Released, this);
	EventDispatcher*eve = Director::getInstance()->getEventDispatcher();
	eve->addEventListenerWithSceneGraphPriority(listener, hero);
	this->scheduleUpdate();*/
	return true;
}
/*void Hero::update(float dt) {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 pos = hero->getPosition();
	float pos_x = hero->getPositionX();
	float pos_y = hero->getPositionY();
	
}

void Hero::Press(EventKeyboard::KeyCode code, Event*event) {
	auto target = event->getCurrentTarget();
	switch (code) {
	case EventKeyboard::KeyCode::KEY_A:left = 1;break;
	case EventKeyboard::KeyCode::KEY_S:down = 1;break;
	case EventKeyboard::KeyCode::KEY_D:right = 1;break;
	case EventKeyboard::KeyCode::KEY_W:up = 1;break;
	case EventKeyboard::KeyCode::KEY_K: {
		/*if ((frequency == 0) || (clock() - time >= 20)) {
			time = clock();
			frequency += 1;
			buff = 1;
		}
		log("%f", hero->getPositionX());
	}
	}
}

void Hero::Released(EventKeyboard::KeyCode code, Event*event) {
	switch (code) {
	case EventKeyboard::KeyCode::KEY_A:left = 0;break;
	case EventKeyboard::KeyCode::KEY_S:down = 0;break;
	case EventKeyboard::KeyCode::KEY_D:right = 0;break;
	case EventKeyboard::KeyCode::KEY_W:up = 0;break;
	}
}*/


int Hero::getBlood() {
	return blood;
}

int Hero::getShield() {
	return shield;
}

int Hero::getBlue() {
	return blue;
}

int Hero::getBuff() {
	return buff;
}

cocos2d::Sprite* Hero::getHero() {
	return hero;
}

void Hero::setBlood(int blo) {
	blood = blo;
}

void Hero::setShield(int shi) {
	shield = shi;
}

void Hero::setBlue(int blu) {
	blue = blu;
}

void Hero::setHero(const std::string& filename) {
	hero = cocos2d::Sprite::create(filename);
}

void Hero::setBuff(int b) {
	buff = b;
}