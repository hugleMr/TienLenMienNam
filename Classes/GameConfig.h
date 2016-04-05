//  Created by Black3rry on 11/3/16.
//  Copyright (c) 2015 Black3rry. All rights reserved.

#ifndef Vina_GameConfig_h
#define Vina_GameConfig_h

#define XXX 400

enum {
    kCardLayer1 = 1,
    kCardLayer2 = 1,
    kCardLayer3 = 3,
    kCardLayer4 = 4,
    kCardLayer5 = 5,
    kCardlayer6 = 6
};

enum {
    kGameIntro,
    kGamePlay,
    kGameOver
};

enum CardState {
    Idle,
    OnHand,
    Putted,
    Fold,
    Destroy
};

enum PlayerState{
    Idle_Player,
    Play,
    Pass,
    Win,
    Lose,
    Pre
};

#define PROMOTE_GAME_URL "market://search?q=pub:XXX"

#define GAME_STATUS_PLAYING 1
#define GAME_STATUS_PAUSE   2
#define GAME_STATUS_OVER    3

//define game notifications
#define NOTIFICATION_GRAVITY_SWITCH "gravity switch"
#define NOTIFICATION_LEVEL_COMPLETED "level completed"

//==========================================================

//== Login screen
#define btn_login_facebook_ "btn_login_facebook.png"
#define btn_login_ "btn_login.png"
#define btn_register_ "btn_register.png"
#define btn_play_now_ "btn_play_now.png"
#define bkg_input_login_ "bkg_input_login.png"

#define sprite_girl_login_ "girl_login.png"
#define bkg_login_ "bkg_login.jpg"

//== Register screen
#define btn_register_register_ "btn_register_register.png"
#define bkg_input_sdt_ "bkg_input_sdt.png"
#define bkg_input_password_ "bkg_input_password.png"
#define bkg_input_repassword_ "bkg_input_repassword.png"
#define sprite_bigken_online_ "txt_bigken_online.png"
#define sprite_girl_register_ "girl_register.png"
#define bkg_register_ "bkg_register.png"

//== List Game Screen
#define btn_item_game_ "btn_item_game.png"
#define btn_back_ "btn_back.png"
#define btn_menu_ "btn_menu.png"
#define btn_setting_ "btn_setting"
#define btn_helper_ "btn_helper.png"
#define btn_load_cents_ "btn_load_cents.png"
#define btn_doi_thuong_ "btn_doi_thuong.png"
#define bkg_avatar_ "bkg_avatar.png"
#define sprite_coins_ "image_coins.png"
#define sprite_kens_ "image_kens.png"
#define sprite_girl_list_game_ "girl_list_game.png"
#define bkg_list_game_ "bkg_list_game.jpg"

// TLMN
#define btn_message_ "btn_messange.png"
#define btn_sound_on_ "btn_sound_on.png"
#define btn_sound_off_ "btn_sound_off.png"
#define btn_purchase_ "btn_purchase.png"
#define btn_button_ "ic_button_primary.png"

#define bkg_avatar_ "bkg_avatar.png"
#define bkg_chatbox_ "bkg_charbox.9.png"
#define bkg_table_ "bkg_table.jpg"

#endif
