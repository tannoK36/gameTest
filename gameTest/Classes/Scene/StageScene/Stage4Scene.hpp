//
//  Stage4Scene.hpp
//  gameTest-mobile
//
//  Created by 丹野健介 on 2020/03/22.
//

#ifndef Stage4Scene_hpp
#define Stage4Scene_hpp

#include "StageSceneBase.hpp"

class Stage4Scene : public StageSceneBase
{
private:
    void initCharactors();
    void initScoreStandard();
    void gameStart();
    void doContinue();
    void checkState();
    
public:
    static Stage4Scene *createScene();
    
};

#endif /* Stage4Scene_hpp */
