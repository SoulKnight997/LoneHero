#ifndef __HELPSCENE_SCENE_H__
#define __HELPSCENE_SCENE_H__

#include "cocos2d.h"

class Help : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void MenuItemBackCallback(cocos2d::Ref *pSender);

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(Help);
};

#endif // __HELLOWORLD_SCENE_H__
