#include "Weapon_machinegun.h"
#include "SimpleAudioEngine.h"
#include "heroBullet.h"

USING_NS_CC;

Weapon_machinegun* Weapon_machinegun::create(float a, int h, int b, const std::string& filename, cocos2d::Sprite* he, vector<HeroBullet*>bullet) {
	Weapon_machinegun* p = new(std::nothrow)Weapon_machinegun;
	p->init(a, h, b, filename, he,bullet);
	return p;
}

void Weapon_machinegun::Attack(float dt) {
	auto bullet = HeroBullet::create(7, angle, 2, "bulletpoorgun.png");
	auto body = PhysicsBody::createEdgeBox(bullet->getBullet()->getContentSize());
	bullet->getBullet()->setPhysicsBody(body);
	bullet->getBullet()->setPosition(Vec2(weapon->getPosition()));
	_bullet.push_back(bullet);
	this->addChild(bullet->getBullet());
	this->addChild(bullet);
}