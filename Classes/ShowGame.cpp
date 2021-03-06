
#include "ShowGame.h"
#include "SettingDialog.h"
#include "TLMienNam.h"
#include "TableSelect.h"
#include "LoginScene.h"
#include "MButton.hpp"
#include "MSprite.hpp"
#include "GameConfig.h"

#define BTN_BACK 1
#define BTN_MENU 2
#define BTN_NAPXU 3
#define BTN_TROGIUP 4
#define BTN_CAIDAT 5

#define GAME_XITO 6
#define GAME_PHOM 7
#define GAME_TLMB 8
#define GAME_TLMN 9
#define GAME_BACAY 10
#define GAME_POCKER 11
#define GAME_XOCDIA 12

using namespace cocos2d::ui;

Scene* ShowGame::createScene() {
    
    auto scene = Scene::create();
    
    auto layer = ShowGame::create();

    scene->addChild(layer);

    return scene;
}

bool ShowGame::init() {
    
    if ( !Layer::init() ) {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    float w = visibleSize.width;
    float h = visibleSize.height;
    
    
    auto bkg = Sprite::create("bgr_listgame.jpg");
    bkg->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
    bkg->setScale(w/bkg->getContentSize().width, h/bkg->getContentSize().height);
    bkg->setColor(Color3B(52, 30, 164));
    this->addChild(bkg);
    
    auto girl = Sprite::create("girl2.png");
    girl->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+girl->getContentSize().height/2));
    this->addChild(girl);
    
    //====================================  buttons
    
    {
        
        auto btn_back = MButton::create(btn_back_,BTN_BACK);
        btn_back->setPosition(Vec2(origin.x +10,
                                   origin.y + visibleSize.height-10- btn_back->getHeight()));
        btn_back->addTouchEventListener( CC_CALLBACK_2(ShowGame::menuCallBack, this) );
        this->addChild(btn_back);
        
        //btn Menu
        auto btn_mennu = MButton::create(btn_menu_,BTN_MENU);
        btn_mennu->setPosition(Vec2(origin.x +w-10-btn_mennu->getContentSize().width,
                                    origin.y + visibleSize.height-10- btn_mennu->getHeight()));
        btn_mennu->addTouchEventListener( CC_CALLBACK_2(ShowGame::menuCallBack, this) );
        this->addChild(btn_mennu);
    }
    
    //====================================  navigation bar
    
    {
        
        auto bkg_navigationbar = MSprite::create("ic_navigationbar.png");
        bkg_navigationbar->setScale(w/bkg_navigationbar->getContentSize().width,1);
        bkg_navigationbar->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+
                                            bkg_navigationbar->getHeight()/2));
        this->addChild(bkg_navigationbar);
        
        // nap xu
        auto btn_napxu = MButton::createExtends("ic_charge.png","Nạp xu",30,BTN_NAPXU);
        btn_napxu->setPosition(Vec2(origin.x + visibleSize.width*1.3f/5,
                                    origin.y + bkg_navigationbar->getHeight()/2 - btn_napxu->getHeight()/2));
        btn_napxu->addTouchEventListener( CC_CALLBACK_2(ShowGame::menuCallBack, this) );
        this->addChild(btn_napxu);
        
        // tro giup
        auto btn_trogiup = MButton::createExtends("ic_help.png","Trợ giúp",30,BTN_TROGIUP);
        btn_trogiup->setPosition(Vec2(origin.x + visibleSize.width*3.3f/5,btn_napxu->getPosition().y));
        btn_trogiup->addTouchEventListener( CC_CALLBACK_2(ShowGame::menuCallBack, this) );
        this->addChild(btn_trogiup);
        
        // cai dat
        auto btn_caidat = MButton::createExtends("ic_setting.png","Cài đặt",30,BTN_CAIDAT);
        btn_caidat->setPosition(Vec2(origin.x + visibleSize.width*4.3f/5,btn_napxu->getPosition().y));
        btn_caidat->addTouchEventListener( CC_CALLBACK_2(ShowGame::menuCallBack, this) );
        this->addChild(btn_caidat);
    }
    
    //==================================== scroll view - game button
    
    // add scroll view
    auto game_button = MSprite::create("game_xocdia.png");
    
    Size scollFrameSize = Size(visibleSize.width,game_button->getHeight()*1.2f);
    auto scrollView = ScrollView::create();
    scrollView->setContentSize(scollFrameSize);
   
    scrollView->setPosition(Vec2(origin.x,origin.y+visibleSize.height*1/6));
    scrollView->setDirection(ScrollView::Direction::HORIZONTAL);
    scrollView->setScrollBarEnabled(false);
    scrollView->setBounceEnabled(true);
    scrollView->setInertiaScrollEnabled(true);
    scrollView->setTouchEnabled(true);
    
    auto containerSize = Size(game_button->getWidth()*7*1.2f, scollFrameSize.height);
    scrollView->setInnerContainerSize(containerSize);
    this->addChild(scrollView);
    
    {   // Game buttons
        
        auto game_xocdia = MButton::createItem("game_xocdia.png",GAME_XOCDIA);
        game_xocdia->setPosition(Vec2(containerSize.width*1-game_xocdia->getWidth()*1.2f/2,
                                      containerSize.height/2));
        game_xocdia->addTouchEventListener( CC_CALLBACK_2(ShowGame::gameItemCallBack, this) );
        scrollView->addChild(game_xocdia);
        
        auto game_xito = MButton::createItem("game_xito.png",GAME_XITO);
        game_xito->setPosition(Vec2(containerSize.width*6/7-game_xocdia->getWidth()*1.2f/2,
                                    containerSize.height/2));
        game_xito->addTouchEventListener( CC_CALLBACK_2(ShowGame::gameItemCallBack, this) );
        scrollView->addChild(game_xito);
        
        auto game_tlmn = MButton::createItem("game_tlmn.png",GAME_TLMN);
        game_tlmn->setPosition(Vec2(containerSize.width*5/7-game_xocdia->getWidth()*1.2f/2,
                                    containerSize.height/2));
        game_tlmn->addTouchEventListener( CC_CALLBACK_2(ShowGame::gameItemCallBack, this) );
        scrollView->addChild(game_tlmn);
        
        auto game_tlmb = MButton::createItem("game_tlmb.png",GAME_TLMB);
        game_tlmb->setPosition(Vec2(containerSize.width*4/7-game_xocdia->getWidth()*1.2f/2,
                                    containerSize.height/2));
        game_tlmb->addTouchEventListener( CC_CALLBACK_2(ShowGame::gameItemCallBack, this) );
        scrollView->addChild(game_tlmb);
        
        auto game_poker = MButton::createItem("game_poker.png",GAME_POCKER);
        game_poker->setPosition(Vec2(containerSize.width*3/7-game_xocdia->getWidth()*1.2f/2,
                                     containerSize.height/2));
        game_poker->addTouchEventListener( CC_CALLBACK_2(ShowGame::gameItemCallBack, this) );
        scrollView->addChild(game_poker);
        
        auto game_phom = MButton::createItem("game_phom.png",GAME_PHOM);
        game_phom->setPosition(Vec2(containerSize.width*2/7-game_xocdia->getWidth()*1.2f/2,
                                    containerSize.height/2));
        game_phom->addTouchEventListener( CC_CALLBACK_2(ShowGame::gameItemCallBack, this) );
        scrollView->addChild(game_phom);
        
        auto game_bacay = MButton::createItem("game_bacay.png",GAME_BACAY);
        game_bacay->setPosition(Vec2(containerSize.width*1/7-game_xocdia->getWidth()*1.2f/2,
                                     containerSize.height/2));
        game_bacay->addTouchEventListener( CC_CALLBACK_2(ShowGame::gameItemCallBack, this) );
        scrollView->addChild(game_bacay);
    }
    
    CCLOG("ShowGame-created");

    return true;
}


void ShowGame::menuCallBack(cocos2d::Ref *sender, Widget::TouchEventType type){
    if(type == Widget::TouchEventType::ENDED){
        MButton *button = (MButton*) sender;
        int tag = button->getTag();
        switch (tag) {
            case BTN_BACK:
                CCLOG("%s","btn_back");
                {
                    auto registerscene = LoginScene::createScene();
                    Director::getInstance()->replaceScene(TransitionCrossFade::create(0.25f, registerscene));
                }
                break;
            case BTN_CAIDAT:
                CCLOG("%s","btn_catdat");
                break;
            case BTN_MENU:
                CCLOG("%s","btn_menu");
                break;
            case BTN_NAPXU:
                CCLOG("%s","btn_napxu");
                break;
            case BTN_TROGIUP:
                CCLOG("%s","btn_trogiup");
                break;
            default:
                break;
        }
    }
    
}

void ShowGame::gameItemCallBack(cocos2d::Ref *sender, Widget::TouchEventType type){
    if(type == Widget::TouchEventType::ENDED){
        MButton *button = (MButton*) sender;
        int tag = button->getTag();
        switch (tag) {
            case GAME_XOCDIA:
                CCLOG("%s","game : xocdia");
                break;
            case GAME_XITO:
                CCLOG("%s","game : xito");
                break;
            case GAME_TLMN:
                CCLOG("%s","game : tlmn");
                {
                    auto registerscene = TableSelect::createScene();
                    Director::getInstance()->replaceScene(TransitionCrossFade::create(0.25f, registerscene));
                }
                break;
            case GAME_TLMB:
                CCLOG("%s","game : tlmb");
                break;
            case GAME_POCKER:
                CCLOG("%s","game : pocker");
                break;
            case GAME_PHOM:
                CCLOG("%s","game : phom");
                break;
            case GAME_BACAY:
                CCLOG("%s","game : bacay");
                break;
            default:
                break;
        }
    }
    
    
}



void ShowGame::gotoMenuDialog(){
    //Setting dialog
    
    auto settingdialog = SettingDialog::create();
    settingdialog->setPosition(Vec2(0,settingdialog->getContentSize().height));
    this->addChild(settingdialog);
    auto moveTo = MoveTo::create(0.25f, Vec2(0,0));
    settingdialog->runAction(moveTo);
   
}




