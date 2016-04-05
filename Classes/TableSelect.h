
#ifndef __TABLESELECT_SCENE_H__
#define __TABLESELECT_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "MSprite.hpp"

using namespace cocos2d;

class TableSelect : public cocos2d::Layer
{
    
    Size window_size;
public :

    static cocos2d::Scene* createScene();
    
    void menuCallBack(Ref *sender,ui::Widget::TouchEventType type);
    void phongCallBack(Ref *sender,ui::Widget::TouchEventType type);
    void tableCallBack(Ref *sender,ui::Widget::TouchEventType type);
    
    virtual bool init();
    
    CREATE_FUNC(TableSelect);
    
    //void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
    
public:
    MSprite * btn_phong;
    void initMenu(Size size,Vec2 origin);
    void initTable(Size size,Vec2 origin);
    
};
#endif // __TABLESELECT_SCENE_H_
