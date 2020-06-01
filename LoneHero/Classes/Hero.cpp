#include "Hero.h"
#include "SimpleAudioEngine.h"
#include "Bullet.h"

USING_NS_CC;

Hero* Hero::create(int blo, int shi, int blu, const std::string& filename) {
	Hero*p = new(std::nothrow)Hero;
	p->init(blo, shi, blu, filename);
	return p;
}

int right = 0, left = 0, up = 0, down = 0;
bool Hero::init(int blo, int shi, int blu, const std::string& filename) {
	blood = blo, shield = shi, blue = blu;
	hero = cocos2d::Sprite::create(filename);
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(Hero::Press, this);
	listener->onKeyReleased = CC_CALLBACK_2(Hero::Released, this);
	EventDispatcher*eve = Director::getInstance()->getEventDispatcher();
	eve->addEventListenerWithSceneGraphPriority(listener, hero);
	this->scheduleUpdate();
	return true;
}

void Hero::update(float dt) {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	if ((right == 1) && (hero->getPositionX() < visibleSize.width))
		hero->setPosition(hero->getPositionX() + 3, hero->getPositionY());
	if ((left == 1) && (hero->getPositionX() > 0))
		hero->setPosition(hero->getPositionX() - 3, hero->getPositionY());
	if ((up == 1) && (hero->getPositionY() < visibleSize.height))
		hero->setPosition(hero->getPositionX(), hero->getPositionY() + 3);
	if ((down == 1) && (hero->getPositionY() > 0))
		hero->setPosition(hero->getPositionX(), hero->getPositionY() - 3);
}

void Hero::Press(EventKeyboard::KeyCode code, Event*event) {
	auto target = event->getCurrentTarget();
	switch (code) {
	case EventKeyboard::KeyCode::KEY_A:left = 1;break;
	case EventKeyboard::KeyCode::KEY_S:down = 1;break;
	case EventKeyboard::KeyCode::KEY_D:right = 1;break;
	case EventKeyboard::KeyCode::KEY_W:up = 1;break;
	case EventKeyboard::KeyCode::KEY_J: {
		auto bullet = Bullet::create(7, 0, 5, "square.png");
		auto body = PhysicsBody::createEdgeBox(bullet->getBullet()->getContentSize());
		bullet->getBullet()->setPhysicsBody(body);
		bullet->getBullet()->setPosition(Vec2(target->getPosition()));
		this->addChild(bullet->getBullet());
		this->addChild(bullet);
		break;
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
}

int Hero::getBlood() {
	return blood;
}

int Hero::getShield() {
	return shield;
}

int Hero::getBlue() {
	return blue;
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