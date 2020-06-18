#ifndef __SETTINGS_SCENE_H__
#define __SETTINGS_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

class Settings : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void MenuItemOnCallback(cocos2d::Ref *pSender);
	void MenuItemOffCallback(cocos2d::Ref *pSender);
	void MenuItemOkCallback(cocos2d::Ref *pSender);

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(Settings);
};

#endif // __HELLOWORLD_SCENE_H__
