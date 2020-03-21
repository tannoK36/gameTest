//
//  Stage4Scene.hpp
//  gameTest-mobile
//
//  Created by 丹野健介 on 2020/03/21.
//

#ifndef Stage4Scene_hpp
#define Stage4Scene_hpp

#include "StageSceneBase.hpp"

class Stage4Scene : public StageSceneBase
{
private:
    bool m_isTutorialMessage4; // チュートリアルメッセージ4表示済みかどうか
    
    void initMap();
    void initCharactors();
    void gameStart();
    void doContinue();
    void checkPosition();
    void stageClear();
    void createTutorialMessage2();
    
public:
    static Stage4Scene *createScene();
    
};

#endif /* Stage4Scene_hpp */
