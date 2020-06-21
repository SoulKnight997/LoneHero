#include "Weapon_shotgun.h"
#include "SimpleAudioEngine.h"
#include "heroBullet.h"

USING_NS_CC;

Weapon_shotgun* Weapon_shotgun::create(float a, int h, int b, const std::string& filename, cocos2d::Sprite* he,vector<HeroBullet*>bullet) {
	Weapon_shotgun* p = new(std::nothrow)Weapon_shotgun;
	p->init(a, h, b, filename, he,bullet);
	return p;
}

void Weapon_shotgun::Attack(float dt) {
	auto bullet1 = HeroBullet::create(7, angle, 5, "bulletshotgun.png");
	auto body1 = PhysicsBody::createEdgeBox(bullet1->getBullet()->getContentSize());
	bullet1->getBullet()->setPhysicsBody(body1);
	bullet1->getBullet()->setPosition(Vec2(weapon->getPosition()));
	this->addChild(bullet1->getBullet());
	this->addChild(bullet1);
	auto bullet2 = HeroBullet::create(7, angle + 0.3, 5, "bulletshotgun.png");
	auto body2 = PhysicsBody::createEdgeBox(bullet2->getBullet()->getContentSize());
	bullet2->getBullet()->setPhysicsBody(body2);
	bullet2->getBullet()->setPosition(Vec2(weapon->getPosition()));
	this->addChild(bullet2->getBullet());
	this->addChild(bullet2);
	auto bullet3 = HeroBullet::create(7, angle + 0.6, 5, "bulletshotgun.png");
	auto body3 = PhysicsBody::createEdgeBox(bullet3->getBullet()->getContentSize());
	bullet3->getBullet()->setPhysicsBody(body3);
	bullet3->getBullet()->setPosition(Vec2(weapon->getPosition()));
	this->addChild(bullet3->getBullet());
	this->addChild(bullet3);
	auto bullet4 = HeroBullet::create(7, angle - 0.3, 5, "bulletshotgun.png");
	auto body4 = PhysicsBody::createEdgeBox(bullet4->getBullet()->getContentSize());
	bullet4->getBullet()->setPhysicsBody(body4);
	bullet4->getBullet()->setPosition(Vec2(weapon->getPosition()));
	this->addChild(bullet4->getBullet());
	this->addChild(bullet4);
	auto bullet5 = HeroBullet::create(7, angle - 0.6, 5, "bulletshotgun.png");
	auto body5 = PhysicsBody::createEdgeBox(bullet5->getBullet()->getContentSize());
	bullet5->getBullet()->setPhysicsBody(body5);
	bullet5->getBullet()->setPosition(Vec2(weapon->getPosition()));
	this->addChild(bullet5->getBullet());
	this->addChild(bullet5);
	time = clock();
}