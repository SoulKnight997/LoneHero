#include "Weapon.h"
#include "SimpleAudioEngine.h"
#include "Bullet.h"

USING_NS_CC;

bool Weapon::init(float a, int h, int b, const std::string& filename,cocos2d::Sprite* he) {
	attack_interval = a, hurt = h, blue_consume = b;
	hero = he;
	weapon = cocos2d::Sprite::create(filename);
	this->schedule(schedule_selector(Weapon::FollowMyHero), 0.01f);
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = [=] (EventKeyboard::KeyCode keycode,Event*event){
		if (keycode == EventKeyboard::KeyCode::KEY_J) {
			auto bullet = Bullet::create(7, 0, 5, "bulletpoorgun.png");
			auto body = PhysicsBody::createEdgeBox(bullet->getBullet()->getContentSize());
			bullet->getBullet()->setPhysicsBody(body);
			bullet->getBullet()->setPosition(Vec2(weapon->getPosition()));
			this->addChild(bullet->getBullet());
			this->addChild(bullet);
			this->schedule(schedule_selector(Weapon::Attack), attack_interval);
		}
	};
	listener->onKeyReleased = [=](EventKeyboard::KeyCode keycode, Event*event) {
		if (keycode == EventKeyboard::KeyCode::KEY_J)
			this->unschedule(schedule_selector(Weapon::Attack));
	};
	EventDispatcher*eve = Director::getInstance()->getEventDispatcher();
	eve->addEventListenerWithSceneGraphPriority(listener, weapon);
	return true;
}

cocos2d::Sprite* Weapon::getWeapon() {
	return weapon;
}

float Weapon::getAttackInterval() {
	return attack_interval;
}

int Weapon::getHurt() {
	return hurt;
}

int Weapon::getBlueConsume() {
	return blue_consume;
}

void Weapon::setWeapon(const std::string& filename) {
	weapon = cocos2d::Sprite::create(filename);
}

void Weapon::setAttackIterval(float a) {
	attack_interval = a;
}

void Weapon::setHurt(int h) {
	hurt = h;
}

void Weapon::setBlueConsume(int b) {
	blue_consume = b;
}

void Weapon::Attack(float dt) {

}

void Weapon::FollowMyHero(float dt) {
	weapon->setPosition(hero->getPositionX(), hero->getPositionY() - 5);
}