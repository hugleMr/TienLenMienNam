
#ifndef __SETTING_DIALOG_LAYER_H__
#define __SETTING_DIALOG_LAYER_H__

#include "cocos2d.h"
#include "ShowGame.h"

USING_NS_CC;

class SettingDialog : public cocos2d::Layer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
	void setScore(int score);
    
    // implement the "static create()" method manually
	CREATE_FUNC(SettingDialog);
private:
	void gotoMenuScene();
	void gotoPlayScene();
	int _score;
	Label* _scoreLabel;
	Label* _highScoreLabel;
    Sprite*  dark_background;
    void setAlphaToDarkBackground(float alpha);
};

#endif // __SETTING_DIALOG_LAYER_H__
