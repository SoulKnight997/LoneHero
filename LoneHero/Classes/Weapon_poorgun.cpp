#include "Weapon_poorgun.h"
#include "SimpleAudioEngine.h"
#include "heroBullet.h"

USING_NS_CC;

Weapon_poorgun* Weapon_poorgun::create(float a, int h, int b, const std::string& filename,cocos2d::Sprite* he,vector<HeroBullet*>bullet) {
	Weapon_poorgun* p = new(std::nothrow)Weapon_poorgun;
	p->init(a, h, b, filename, he,bullet);
	return p;
}

void Weapon_poorgun::Attack(float dt) {
	auto bullet = HeroBullet::create(7, angle, 2, "bulletpoorgun.png");
	auto body = PhysicsBody::createEdgeBox(bullet->getBullet()->getContentSize());
	_bullet.push_back(bullet);
	bullet->getBullet()->setPhysicsBody(body);
	bullet->getBullet()->setPosition(Vec2(weapon->getPosition()));
	this->addChild(bullet->getBullet());
	this->addChild(bullet);
}