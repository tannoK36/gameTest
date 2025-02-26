//
//  StageUILayer.hpp
//  gameTest-mobile
//
//  ステージシーンのUIレイヤー
//
//  Created by 丹野健介 on 2020/02/26.
//

#ifndef StageUILayer_hpp
#define StageUILayer_hpp

USING_NS_CC;

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "StageLeftUILayer.hpp"
#include "StageRightUILayer.hpp"

class StageUILayer : public Layer
{
private:
    /// 左サイドバー
    StageLeftUILayer *m_leftLayer;
    /// 右サイドバー
    StageRightUILayer *m_rightLayer;
    
public:
    CREATE_FUNC(StageUILayer);
    virtual bool init();
    ::padState padState();
    void touchAEvent(Ref *pSender, ui::Widget::TouchEventType type);
    void touchBEvent(Ref *pSender, ui::Widget::TouchEventType type);
    void touchPauseEvent(Ref *pSender, ui::Widget::TouchEventType type);
    void heartOff(int i);
    void updateTime(float time);
    
};

#endif /* StageUILayer_hpp */
