#ifndef __START_SCENE_H__
#define __START_SCENE_H__

#include "cocos2d.h"
#include "Hero.h"

class Start : public cocos2d::Layer
{
private:
	cocos2d::TMXLayer* _collidable;
	cocos2d::TMXTiledMap* _tileMap;
	Hero* _role;
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(Start);
};

#endif // __HELLOWORLD_SCENE_H__
