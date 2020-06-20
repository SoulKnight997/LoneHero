#ifndef __THIRD_SCENE_H__
#define __THIRD_SCENE_H__

#include "cocos2d.h"
#include "Hero.h"

class Third : public cocos2d::Layer
{
private:

public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);



	// implement the "static create()" method manually
	CREATE_FUNC(Third);
};

#endif // __HELLOWORLD_SCENE_H__
