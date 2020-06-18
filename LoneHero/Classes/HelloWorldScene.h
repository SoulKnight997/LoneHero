#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Hero.h"

class HelloWorld : public cocos2d::Layer
{
private:
	cocos2d::TMXLayer* _collidable;
	cocos2d::TMXTiledMap* _tileMap;
	Hero* _role;
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

	void MenuItemStartCallback(cocos2d::Ref *pSender);
	void MenuItemHelpCallback(cocos2d::Ref *pSender);
	void MenuItemSettingsCallback(cocos2d::Ref *pSender);
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	void setRolePosition(cocos2d::Vec2 position);
	cocos2d::Vec2 tileCoordFromPosition(cocos2d::Vec2);
	void setViewpointCenter(cocos2d::Vec2 position);
	void update(float dt);
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
