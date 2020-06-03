#ifndef __HERO_H__
#define __HERO_H__

#include"cocos2d.h"
#include"Weapon.h"

class Hero : public cocos2d::Node {
private:
	cocos2d::Sprite*hero;
	int blood, shield, blue;
public:
	static Hero*create(int, int, int, const std::string& filename);
	bool init(int, int, int, const std::string& filename);
	int getBlood();//����Ѫ��
	int getShield();//���ػ���ֵ
	int getBlue();//��������
	cocos2d::Sprite* getHero();//����ָ����hero��ָ��
	virtual void update(float dt);
	void setBlood(int);//����Ѫ��
	void setShield(int);//���û���ֵ
	void setBlue(int);//��������
	void setHero(const std::string& filename);//���þ���ͼƬ
	void Press(cocos2d::EventKeyboard::KeyCode code, cocos2d::Event*event);
	void Released(cocos2d::EventKeyboard::KeyCode code, cocos2d::Event*event);
};
#endif
