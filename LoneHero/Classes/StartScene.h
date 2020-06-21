#ifndef __START_SCENE_H__
#define __START_SCENE_H__

#include "cocos2d.h"
#include "Hero.h"

class Start : public cocos2d::Layer
{
private:
	
public:
	cocos2d::TMXLayer* _safeCollidable;
	cocos2d::TMXTiledMap* _safeMap;
	static cocos2d::Scene* createScene();

	void MenuItemWeapon1Callback(cocos2d::Ref *pSender);
	void MenuItemWeapon2Callback(cocos2d::Ref *pSender);
	void MenuItemWeapon3Callback(cocos2d::Ref *pSender);
	void MenuItemWeapon4Callback(cocos2d::Ref *pSender);

	void MenuItemBackCallback(cocos2d::Ref *pSender);

	virtual bool init();

	virtual bool gameTouchBegan(cocos2d::Touch*, cocos2d::Event*);

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);



	// implement the "static create()" method manually
	CREATE_FUNC(Start);
};

#endif // __HELLOWORLD_SCENE_H__
