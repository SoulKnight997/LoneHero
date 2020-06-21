#ifndef __FOURTH_SCENE_H__
#define __FOURTH_SCENE_H__

#include "cocos2d.h"
#include "Hero.h"

class Fourth : public cocos2d::Layer
{
private:

public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);



	// implement the "static create()" method manually
	CREATE_FUNC(Fourth);
};

#endif // __HELLOWORLD_SCENE_H__
