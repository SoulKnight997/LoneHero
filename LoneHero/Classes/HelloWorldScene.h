#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Hero.h"
#include "SimpleAudioEngine.h"

class HelloWorld : public cocos2d::Layer
{
private:
	cocos2d::TMXLayer* _collidable;
	cocos2d::TMXTiledMap* _tileMap;
	Hero* _role;
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
	virtual void cleanup();
	virtual void onEnterTransitionDidFinish();

	void MenuItemStartCallback(cocos2d::Ref *pSender);
	void MenuItemHelpCallback(cocos2d::Ref *pSender);
	void MenuItemSettingsCallback(cocos2d::Ref *pSender);
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
