
#include "SettingDialog.h"


// on "init" you need to initialize your instance
bool SettingDialog::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    //dark background
    
    dark_background = Sprite::create("bg.png");
    dark_background->setPosition(Point(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2));
    dark_background->setScale(visibleSize.width/dark_background->getContentSize().width,
                              visibleSize.height/dark_background->getContentSize().height);
    dark_background->setColor(Color3B(1,1,1));
    setAlphaToDarkBackground(200);
    this->addChild(dark_background);
    
    
	//Background gameover
	auto overPanel = Sprite::create("bgr_setting.png");
	overPanel->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	
	this->addChild(overPanel);
    
    
    // button cancel
    auto btn_cancel = MenuItemImage::create("ic_button_close.png","ic_button_close.png",CC_CALLBACK_0(SettingDialog::gotoPlayScene,this));
    auto btn_cancel_menu = Menu::create(btn_cancel,nullptr);
    btn_cancel_menu->setPosition(overPanel->getPosition().x+overPanel->getContentSize().width/2
                                 -btn_cancel->getContentSize().width-15,
                                 overPanel->getPosition().y+overPanel->getContentSize().height/2
                                 -btn_cancel->getContentSize().height-15);
    this->addChild(btn_cancel_menu);
    
    
    auto btn_sound = MenuItemImage::create("toogle_off.png","toogle_off.png",CC_CALLBACK_0(SettingDialog::gotoMenuScene,this));
    
    auto btn_option = MenuItemImage::create("toogle_off.png","toogle_off.png",CC_CALLBACK_0(SettingDialog::gotoMenuScene,this));
    
    auto btn_recieve = MenuItemImage::create("toogle_off.png","toogle_off.png",CC_CALLBACK_0(SettingDialog::gotoMenuScene,this));
    
    auto menu = Menu::create(btn_sound,btn_option,btn_recieve,nullptr);
    menu->alignItemsVerticallyWithPadding(45);
    menu->setPosition(Point(overPanel->getPosition().x+overPanel->getContentSize().width/2
                                    -btn_sound->getContentSize().width,
                            origin.y+visibleSize.height*0.45f));
    this->addChild(menu);
    
    auto txt_setting = Text::create("Cài đặt","fonts/gamevina.otf",35);
    txt_setting->setPosition(Point(overPanel->getPosition().x,
                                  overPanel->getPosition().y+overPanel->getContentSize().height/2
                                   -txt_setting->getContentSize().height*2));
    this->addChild(txt_setting);
    
    auto txt_option = Text::create("Tùy chọn","fonts/gamevina.otf",30);
    txt_option->setPosition(Point(overPanel->getPosition().x-overPanel->getContentSize().width/2
                           +txt_option->getContentSize().width+20,
                           menu->getPosition().y));
    this->addChild(txt_option);
    
    auto txt_sound = Text::create("Âm thanh","fonts/gamevina.otf",30);
    txt_sound->setPosition(Point(overPanel->getPosition().x-overPanel->getContentSize().width/2
                                  +txt_sound->getContentSize().width+20,
                                  menu->getPosition().y+txt_option->getContentSize().width/2+ 45));
    this->addChild(txt_sound);
    
    auto txt_recieve = Text::create("Nhận lời mời","fonts/gamevina.otf",30);
    txt_recieve->setPosition(Point(overPanel->getPosition().x-overPanel->getContentSize().width/2
                                 +txt_sound->getContentSize().width+20,
                                 menu->getPosition().y-txt_option->getContentSize().width/2- 45));
    this->addChild(txt_recieve);
    
    return true;
}

void SettingDialog::gotoMenuScene()
{
	
}

void SettingDialog::setAlphaToDarkBackground(float alpha){
    dark_background->runAction(FadeTo::create(0,alpha));
}

void SettingDialog::gotoPlayScene()
{
    //setAlphaToDarkBackground(0);
    auto moveTo = MoveTo::create(0.25f, Vec2(0,this->getContentSize().height));
   // auto func = CallFunc::create(std:)
    auto sequencex = Sequence::create(moveTo,moveTo, NULL);
    this->runAction(sequencex);
	
}
void SettingDialog::setScore(int score)
{
	/*_score = score;

	auto userdefault = UserDefault::getInstance();
	auto highscore = userdefault->getIntegerForKey("HIGHSCORE", 0);

	if (_score > highscore)
	{
		highscore = _score;
		userdefault->setIntegerForKey("HIGHSCORE", highscore);
	}

	userdefault->flush();

	_scoreLabel->setString(StringUtils::format("%d", _score));
	_highScoreLabel->setString(StringUtils::format("HIGH SCORE: %d", highscore));*/
}