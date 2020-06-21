#include "Weapon_shotgun.h"
#include "SimpleAudioEngine.h"
#include "Bullet.h"

USING_NS_CC;

Weapon_shotgun* Weapon_shotgun::create(float a, int h, int b, const std::string& filename, cocos2d::Sprite* he) {
	Weapon_shotgun* p = new(std::nothrow)Weapon_shotgun;
	p->init(a, h, b, filename, he);
	return p;
}

void Weapon_shotgun::Attack(float dt) {
	auto bullet1 = Bullet::create(7, angle, 5, "bulletshotgun.png");
	auto body1 = PhysicsBody::createEdgeBox(bullet1->getBullet()->getContentSize());

	//_bullet.push_back(bullet1);

	bullet1->getBullet()->setPhysicsBody(body1);
	bullet1->getBullet()->setPosition(Vec2(weapon->getPosition()));
	this->addChild(bullet1->getBullet());
	this->addChild(bullet1);
	auto bullet2 = Bullet::create(7, angle + 0.3, 5, "bulletshotgun.png");
	auto body2 = PhysicsBody::createEdgeBox(bullet2->getBullet()->getContentSize());

	//_bullet.push_back(bullet2);

	bullet2->getBullet()->setPhysicsBody(body2);
	bullet2->getBullet()->setPosition(Vec2(weapon->getPosition()));
	this->addChild(bullet2->getBullet());
	this->addChild(bullet2);
	auto bullet3 = Bullet::create(7, angle + 0.6, 5, "bulletshotgun.png");
	auto body3 = PhysicsBody::createEdgeBox(bullet3->getBullet()->getContentSize());

	//_bullet.push_back(bullet3);

	bullet3->getBullet()->setPhysicsBody(body3);
	bullet3->getBullet()->setPosition(Vec2(weapon->getPosition()));
	this->addChild(bullet3->getBullet());
	this->addChild(bullet3);
	auto bullet4 = Bullet::create(7, angle - 0.3, 5, "bulletshotgun.png");
	auto body4 = PhysicsBody::createEdgeBox(bullet4->getBullet()->getContentSize());

	//_bullet.push_back(bullet4);

	bullet4->getBullet()->setPhysicsBody(body4);
	bullet4->getBullet()->setPosition(Vec2(weapon->getPosition()));
	this->addChild(bullet4->getBullet());
	this->addChild(bullet4);
	auto bullet5 = Bullet::create(7, angle - 0.6, 5, "bulletshotgun.png");
	auto body5 = PhysicsBody::createEdgeBox(bullet5->getBullet()->getContentSize());

	//_bullet.push_back(bullet5);

	bullet5->getBullet()->setPhysicsBody(body5);
	bullet5->getBullet()->setPosition(Vec2(weapon->getPosition()));
	this->addChild(bullet5->getBullet());
	this->addChild(bullet5);
	time = clock();
}