#include "Enemy.h"
#include "SimpleAudioEngine.h"
#include "math.h"

USING_NS_CC;

bool Enemy::init(int b,int s, const std::string& filename) {
	blood = b;
	speed = s;
	direction = 0;
	enemy = cocos2d::Sprite::create(filename);
	this->schedule(schedule_selector(Enemy::Move), 0.05f);
	this->schedule(schedule_selector(Enemy::directionChange), 3.0f);
	this->schedule(schedule_selector(Enemy::Attack), 2.0f);
	return true;
}

cocos2d::Sprite* Enemy::getEnemy() {
	return enemy;
}

int Enemy::getBlood() {
	return blood;
}

float Enemy::getDirection() {
	return direction;
}

int Enemy::getSpeed() {
	return speed;
}

void Enemy::setEnemy(const std::string& filename) {
	enemy = cocos2d::Sprite::create(filename);
}

void Enemy::setBlood(int b) {
	blood = b;
}

void Enemy::setSpeed(int s) {
	speed = s;
}

void Enemy::setDirection(float d) {
	direction = d;
}

void Enemy::Move(float dt) {

}

void Enemy::Attack(float dt) {

}

void Enemy::directionChange(float dt) {

}