#ifndef __MENU_DIALOG_LAYER_H__
#define __MENU_DIALOG_LAYER_H__

#include "cocos2d.h"

USING_NS_CC;

class MenuDialog : public cocos2d::Layer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    CREATE_FUNC(MenuDialog);
private:
    
};

#endif // __MENU_DIALOG_LAYER_H__
