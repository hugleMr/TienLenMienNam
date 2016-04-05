#ifndef __TRANSFER_SCENE_H__
#define __TRANSFER_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "MSprite.hpp"

USING_NS_CC;

using namespace cocos2d::ui;

class TransferScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    void menuCallBack(Ref* sender,Widget::TouchEventType type);
    void tabViewCallBack(Ref* sender,Widget::TouchEventType type);
    
    // implement the "static create()" method manually
	CREATE_FUNC(TransferScene);
    
public:
    MSprite* selected;
    void initMenu(Size size,Vec2 origin,float btn_size);
    
private:
	void gotoStartScene(float dt);
};

#endif // __TRANSFER_SCENE_H__
