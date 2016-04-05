#include "MenuDialog.h"

// on "init" you need to initialize your instance
bool MenuDialog::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    //Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
	//Background
    auto bkg = Sprite::create("bgr_popup.png");
    bkg->setAnchorPoint(Vec2(0,0));
    bkg->setPosition(Vec2(5,5));

    
    return true;
}

