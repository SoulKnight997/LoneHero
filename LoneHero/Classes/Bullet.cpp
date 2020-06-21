#include "Bullet.h"
#include "SimpleAudioEngine.h"
#include "math.h"

USING_NS_CC;

Bullet* Bullet::create(int s, double a, int h, const std::string& filename) {
	Bullet*p = new(std::nothrow)Bullet;
	p->init(s, a, h, filename);

	return p;
}

bool Bullet::init(int s, double a, int h, const std::string& filename) {
	speed = s, angle = a, hurt = h;
	bullet = cocos2d::Sprite::create(filename);
	auto listener = EventListenerKeyboard::create();
	this->scheduleUpdate();
	return true;
}

cocos2d::Sprite* Bullet::getBullet() {
	return bullet;
}

void Bullet::update(float dt) {
	++num;
	bullet->setPosition(bullet->getPositionX() + speed * cos(angle), bullet->getPositionY() + speed * sin(angle));
	if (num >= 60) {
		bullet->setVisible(false);
	}
}

int Bullet::getSpeed() {
	return speed;
}

float Bullet::getAngle() {
	return angle;
}

int Bullet::getHurt() {
	return hurt;
}

void Bullet::setBullet(const std::string& filename) {
	bullet = cocos2d::Sprite::create(filename);
}

void Bullet::setSpeed(int s) {
	speed = s;
}

void Bullet::setAngle(float a) {
	angle = a;
}

void Bullet::setHurt(int h) {
	hurt = h;
}

//Vec2 Bullet::tileCoordFromPosition(Vec2 pos)
//{
//	log("%f,%f", pos.x, pos.y);
//	int x = (pos.x *4.3) / _tileMap->getTileSize().width;
//	int y = ((_tileMap->getMapSize().height*_tileMap->getTileSize().height / 4.2) - pos.y) /
//		(_tileMap->getTileSize().height / 4.2);
//	return Vec2(x, y);
//}

//bool Bullet::isContact(cocos2d::Vec2 position) {
//
//	//int tiledGid = meta->getTileGIDAt(tiledPos);//获取这个格子的唯一标识
//	Vec2 tileCoord = this->tileCoordFromPosition(position);
//	int tileGid = _collidable->getTileGIDAt(tileCoord);
//	if (tileGid != 0) {
//
//		Value prop = _tileMap->getPropertiesForGID(tileGid);
//		ValueMap propValueMap = prop.asValueMap();
//		std::string collision = propValueMap["Collidable"].asString();
//
//		if (collision == "true")//碰撞检测成功
//		{
//			log("collision is true");
//			return 0;
//		}
//	}
//	return false;
//}
//
//void Bullet::stopBullet() {
//	log("fuck!!!!!");
//}
