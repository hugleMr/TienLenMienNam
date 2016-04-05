#include "LoginScene.h"
#include "TableSelect.h"
#include "ShowGame.h"
#include "TLMienNam.h"
#include "MButton.hpp"
#include "MText.hpp"
#include "MSprite.hpp"
#include "MEditBox.hpp"
#include "MLabel.hpp"
#include "GameConfig.h"
#include "protobufObject/login.pb.h"

#define BTN_FACEBOOK 1
#define BTN_LOGIN 2
#define BTN_REGISTER 3
#define BTN_PLAYNOW 4
#define BTN_FOGOTPASSWORD 5
#define EDITBOX_MATKHAU 6
#define EDITBOX_TAIKHOAN 7

using namespace cocos2d::ui;

Scene* LoginScene::createScene()
{
    
    auto scene = Scene::create();
   
    auto layer = LoginScene::create();

    scene->addChild(layer);

    return scene;
}

bool LoginScene::init()
{
    
    if ( !Layer::init() )
    {
        return false;
    }
    
    BINLoginRequest *loginRequest = new BINLoginRequest();
    
    
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    float w = visibleSize.width;
    float h = visibleSize.height;
    
    
    auto bkg = MSprite::create(bkg_login_,visibleSize);
    bkg->setPosition(origin.x, origin.y);
    
    
    //hotline
    auto hotline_txt = MLabel::create("Hotline : 19001755",25);
    hotline_txt->setPosition(Vec2(origin.x+15,origin.y+h-15-hotline_txt->getHeight()));
    
    
    //version
    auto version_txt = MLabel::create("Ver 1.0",25);
    version_txt->setPosition(Vec2(origin.x+w-version_txt->getWidth()-15,
                                  origin.y+h-15-version_txt->getHeight()));
    
    
    //girl
    auto girl = MSprite::create(sprite_girl_login_);
    girl->setPosition(origin.x + visibleSize.width / 8, origin.y);
    
    
    //========================= buttons
    
    
    //loginfacebook Button
    auto btn_login_facebook = MButton::create(btn_login_facebook_,"Đăng nhập facebook",30,BTN_FACEBOOK);
    btn_login_facebook->setPosition(Vec2(w*0.95f-btn_login_facebook->getWidth(),h/3.0f));
    btn_login_facebook->setZoomScale(0.01f);
    btn_login_facebook->addTouchEventListener( CC_CALLBACK_2(LoginScene::menuCallBack,this));
    
    
    //đăng nhập
    auto btn_login = MButton::create(btn_login_,"Đăng nhập",30,BTN_LOGIN);
    btn_login->setPosition(Vec2(btn_login_facebook->getPosition().x,
                                btn_login_facebook->getPosition().y+btn_login_facebook->getHeight()-5));
    btn_login->addTouchEventListener( CC_CALLBACK_2(LoginScene::menuCallBack,this));
    
    
    //đăng ký
    auto btn_register = MButton::create(btn_login_,"Đăng ký",30,BTN_REGISTER);
    btn_register->setPosition(Vec2(btn_login_facebook->getPosition().x+btn_login_facebook->getWidth()/2
                                   -btn_register->getWidth()/2,
                                   btn_login->getPosition().y));
    btn_register->addTouchEventListener( CC_CALLBACK_2(LoginScene::menuCallBack,this));
    
    
    //choi ngay
    auto btn_playnow = MButton::create(btn_login_,"Chơi ngay",30,BTN_PLAYNOW);
    btn_playnow->setPosition(Vec2(btn_login_facebook->getPosition().x+btn_login_facebook->getWidth()
                                  -btn_playnow->getWidth(),
                                  btn_login->getPosition().y));
    btn_playnow->addTouchEventListener( CC_CALLBACK_2(LoginScene::menuCallBack,this));
    
    
    //quen mk
    auto fogotPassword = MButton::create("Quên mật khẩu?",25,BTN_FOGOTPASSWORD);
    fogotPassword->setPosition(Vec2(btn_login_facebook->getPosition().x+btn_login_facebook->getWidth()
                                    -fogotPassword->getWidth()-5,
                                btn_playnow->getPosition().y+btn_playnow->getHeight()+10));
    fogotPassword->addTouchEventListener( CC_CALLBACK_2(LoginScene::menuCallBack,this));
    
    
    //underline
    auto under_line = MText::create("______________",25);
    under_line->setPosition(Vec2(fogotPassword->getPosition().x,fogotPassword->getPosition().y));
    
    
    //========================= Text Field
    
    // Textfield mat khau
    auto background_matkhau = MSprite::create(bkg_input_login_);
    
    auto edit_matkhau = MEditBox::create(background_matkhau->getContentSize(),bkg_input_login_);
    edit_matkhau->setPosition(Vec2(btn_login_facebook->getPosition().x+10,
                                   fogotPassword->getPosition().y+fogotPassword->getHeight()+10));
    edit_matkhau->setPlaceHolder("  Nhập mật khẩu");
    edit_matkhau->setMaxLength(12);
    edit_matkhau->setTag(EDITBOX_MATKHAU);
    edit_matkhau->setInputFlag(EditBox::InputFlag::PASSWORD);
    edit_matkhau->setDelegate(this);
    
    
    // Textfield tai khoan
    
    auto edit_user = MEditBox::create(background_matkhau->getContentSize(),bkg_input_login_);
    edit_user->setPosition(Vec2(edit_matkhau->getPosition().x,
                                edit_matkhau->getPosition().y+background_matkhau->getHeight()+10));
    edit_user->setPlaceHolder("  Nhập tên");
    edit_user->setTag(EDITBOX_TAIKHOAN);
    edit_user->setMaxLength(12);
    edit_user->setDelegate(this);
    
    
    this->addChild(bkg);
    this->addChild(hotline_txt);
    this->addChild(version_txt);
    this->addChild(girl);
    
    
    this->addChild(btn_login_facebook);
    this->addChild(btn_login);
    this->addChild(btn_register);
    this->addChild(btn_playnow);
    this->addChild(fogotPassword);
    this->addChild(under_line);
    
    this->addChild(edit_matkhau);
    this->addChild(edit_user);
    
    //edit_matkhau->touchDownAction(NULL, cocos2d::ui::Widget::TouchEventType::ENDED);
    
    
    sprite = Sprite::create("bgr_textview.png");
    sprite->setPosition(this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY());
    this->addChild(sprite, 0);
    
    this->scheduleUpdate();
    
    
    return true;
}


void LoginScene::update(float delta){
    auto position = sprite->getPosition();
    position.x -= 250 * delta;
    if (position.x  < 0 - (sprite->getBoundingBox().size.width / 2))
        position.x = this->getBoundingBox().getMaxX() + sprite->getBoundingBox().size.width/2;
    sprite->setPosition(position);
}


void LoginScene::menuCallBack(Ref *pSender, Widget::TouchEventType eventType){
    if(eventType == Widget::TouchEventType::ENDED){
        MButton *button = (MButton*) pSender;
        int tag = button->getTag();
        switch (tag) {
            case BTN_FACEBOOK:
                CCLOG("%s","Login with facebook!");
                break;
            case BTN_LOGIN:
                CCLOG("%s","Login with esxit!");
                break;
            case BTN_REGISTER:
                {
                    auto registerscene = RegisterScene::createScene();
                    Director::getInstance()->replaceScene(TransitionMoveInR::create(0.25f, registerscene));
                    
                }
                break;
            case BTN_PLAYNOW:
                {
                    auto select = ShowGame::createScene();
                    Director::getInstance()->replaceScene(TransitionCrossFade::create(0.15f, select));
                }
                break;
            case BTN_FOGOTPASSWORD:
                CCLOG("%s","Forgot_Password!");
                break;
            default:
                
                break;
        }
    }

}


#pragma mark - EditBoxDelegate

void LoginScene::editBoxEditingDidBegin(EditBox *editBox) {
    CCLOG("%s","edit begin!");
}

void LoginScene::editBoxEditingDidEnd(EditBox *editBox) {
    
    CCLOG("%s","edit end!");
}

void LoginScene::editBoxTextChanged(EditBox *editBox, const std::string& text) {
    CCLOG("%s","edit changed!");
}

void LoginScene::editBoxReturn(EditBox *editBox) {
    switch (editBox->getTag()) {
        case EDITBOX_MATKHAU:
            this->password_str = editBox->getText();
            CCLOG("%s",this->password_str.c_str());
            break;
        case EDITBOX_TAIKHOAN:
            this->user_id_str = editBox->getText();
            CCLOG("%s",this->user_id_str.c_str());
            break;
        default:
            break;
    }
}


