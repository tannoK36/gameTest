//
//  Stage15Scene.hpp
//  gameTest-mobile
//
//  Created by 丹野健介 on 2020/04/19.
//

#ifndef Stage15Scene_hpp
#define Stage15Scene_hpp

#include "StageSceneBase.hpp"

class Stage15Scene : public StageSceneBase
{
private:
    void initCharactors();
    void initScoreStandard();
    void gameStart();
    void doContinue();
    void checkState();
    
public:
    static Stage15Scene *createScene();
    
};

#endif /* Stage15Scene_hpp */
