#include "Weapon_machinegun.h"
#include "SimpleAudioEngine.h"
#include "Bullet.h"

USING_NS_CC;

Weapon_machinegun* Weapon_machinegun::create(float a, int h, int b, const std::string& filename, cocos2d::Sprite* he) {
	Weapon_machinegun* p = new(std::nothrow)Weapon_machinegun;
	p->init(a, h, b, filename, he);
	return p;
}

void Weapon_machinegun::Attack(float dt) {
	auto bullet = Bullet::create(7, 0, 5, "bulletpoorgun.png");
	auto body = PhysicsBody::createEdgeBox(bullet->getBullet()->getContentSize());
	bullet->getBullet()->setPhysicsBody(body);
	bullet->getBullet()->setPosition(Vec2(weapon->getPosition()));
	this->addChild(bullet->getBullet());
	this->addChild(bullet);
}