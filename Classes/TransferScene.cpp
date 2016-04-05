#include "TransferScene.h"
#include "M9Path.hpp"
#include "MLabel.hpp"
#include "MButton.hpp"
#include "GameConfig.h"


#define BTN_BACK 1
#define BTN_THECAO 2
#define BTN_VATPHAM 3
#define BTN_LICHSU 4

Scene* TransferScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = TransferScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool TransferScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    //SpriteFrameCache::getInstance()->addSpriteFramesWithFile("resources.plist");
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //=============
    
	auto introBG = MSprite::create("bgr_select_table.jpg",visibleSize);
	introBG->setPosition(Point(origin.x,origin.y));
	this->addChild(introBG);
    
    auto btn_back = MButton::create(btn_back_,BTN_BACK);
    btn_back->setPosition(Vec2(origin.x + 20,origin.y+visibleSize.height -20 - btn_back->getHeight()));
    this->addChild(btn_back);
    
    auto title = MLabel::create("Nạp/Chuyển xu ( Lưu ý: nạp qua thẻ cào sẽ được nhiều XU hơn)", 30);
    title->setPosition(btn_back->getPosition().x + btn_back->getWidth()+ 20,
                       btn_back->getPosition().y+btn_back->getHeight()/2-15);
    this->addChild(title);
    
    initMenu(visibleSize, origin, btn_back->getHeight());
    
    auto btn_thecao = MButton::create("null_bg.png","Thẻ cào",30, BTN_THECAO);
    btn_thecao->setContentSize(Size((visibleSize.width-40)/3,btn_back->getHeight()));
    btn_thecao->setScale9Enabled(true);
    btn_thecao->setPosition(Vec2(origin.x+20,btn_back->getPosition().y-10-btn_back->getHeight()));
    btn_thecao->addTouchEventListener(CC_CALLBACK_2(TransferScene::tabViewCallBack, this));
    
    auto btn_vatpham = MButton::create("null_bg.png","Vật phẩm",30, BTN_VATPHAM);
    btn_vatpham->setContentSize(Size((visibleSize.width-40)/3,btn_thecao->getHeight()));
    btn_vatpham->setScale9Enabled(true);
    btn_vatpham->setPosition(Vec2(btn_thecao->getPosition().x+btn_thecao->getWidth(),btn_thecao->getPosition().y));
    btn_vatpham->addTouchEventListener(CC_CALLBACK_2(TransferScene::tabViewCallBack, this));
    
    auto btn_lichsu = MButton::create("null_bg.png","Lịch sử giao dịch",30, BTN_LICHSU);
    btn_lichsu->setContentSize(Size((visibleSize.width-40)/3,btn_thecao->getHeight()));
    btn_lichsu->setScale9Enabled(true);
    btn_lichsu->setPosition(Vec2(btn_vatpham->getPosition().x+btn_vatpham->getWidth(),btn_thecao->getPosition().y));
    btn_lichsu->addTouchEventListener(CC_CALLBACK_2(TransferScene::tabViewCallBack, this));

    selected = MSprite::createExtendsDown("bgr_table_selected.png",Size((visibleSize.width-40)/3,btn_thecao->getHeight()));
    selected->setPosition(Vec2(btn_thecao->getPosition()));
    selected->setFlippedY(true);
    
    
    this->addChild(selected);
    this->addChild(btn_thecao);
    this->addChild(btn_vatpham);
    this->addChild(btn_lichsu);
    
    return true;
}

void TransferScene::initMenu(cocos2d::Size visibleSize, cocos2d::Vec2 origin , float btn_size){
    auto background_layout = M9Path::create("tab_one.9.png",Size(visibleSize.width-40,visibleSize.height-btn_size-40));
    background_layout->setPosition(origin.x+20,origin.y+20);
    this->addChild(background_layout);
    
    auto layout = Layout::create();
    layout->setContentSize(background_layout->getContentSize());
    layout->setPosition(background_layout->getPosition());
    this->addChild(layout);
    
    for (int i=0;i<3;i++){
        
    }
    
}


void TransferScene::menuCallBack(Ref* sender,Widget::TouchEventType type){
    if(type == Widget::TouchEventType::ENDED){
        MButton * button = (MButton*) sender;
        int tag = button->getTag();
    }
    
    
}

void TransferScene::tabViewCallBack(Ref* sender,Widget::TouchEventType type){
    if(type == Widget::TouchEventType::ENDED){
        MButton * button = (MButton*) sender;
        selected->runAction(MoveTo::create(0.1f,button->getPosition()));
        int tag = button->getTag();
        switch (tag) {
            case BTN_THECAO:
            {
                CCLOG("THẺ CÀO");
            }
                break;
            case BTN_VATPHAM:
            {
                CCLOG("VẬT PHẨM");
            }
                break;
            case BTN_LICHSU:
            {
                CCLOG("LỊCH SỬ");
            }
                break;
            default:
                break;
        }
    }
    
}

void TransferScene::gotoStartScene(float dt)
{
    
    
	//auto startscene = LoginScene::createScene();
	//Director::getInstance()->replaceScene(TransitionCrossFade::create(0.25f, startscene));
}
