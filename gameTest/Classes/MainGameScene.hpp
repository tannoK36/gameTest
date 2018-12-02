//
//  MainGameScene.hpp
//  tannoGame
//
//  Created by 健介 丹野 on 2018/08/18.
//
//

#ifndef MainGameScene_hpp
#define MainGameScene_hpp

USING_NS_CC;

#include <vector>
#include "cocos2d.h"
#include "ui/CocosGUI.h"

#include "CharacterSprite.hpp"

class MainGameScene : public Layer
{
public:
    
    TMXTiledMap* pMap;
    Camera* pCamera;
    CharacterSprite* pPlayer;
    CharacterSprite* mob1;
    
    std::vector<CharacterSprite*> charactersVector;
    
    Label* playerMapPointLabel { nullptr };
    
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(MainGameScene);
    // ボタンのタッチイベント
    void touchCrossKeyEvent(Ref *pSender, ui::Widget::TouchEventType type);
    void updatePosition(float frame);
    void updateMobPosition(float frame);
    int checkNextTileGID();
};

#endif /* MainGameScene_hpp */
