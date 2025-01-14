//
//  EnemySprite.hpp
//  gameTest-mobile
//
//  敵キャラクターのクラス
//
//  Created by 丹野健介 on 2019/11/08.
//

#ifndef EnemySprite_hpp
#define EnemySprite_hpp

#include "CharacterSprite.hpp"
#include <vector>

/// 回転方向
typedef enum {
    turn_right,
    turn_left,
    turn_none
} rotateDirectcion;

/// 警備の種類
typedef enum {
    patorol_roundtrip, // 往復
    patorol_rotateifpossible, // 巡回(曲がれるなら曲がる)
    patorol_rotatehitwall, // 巡回(壁にぶつかったら曲がる)
    patorol_random, // 巡回(ランダム移動)
    patorol_chase, // 追跡中
    patorol_chaseForever, // 追跡中(繰り返し)
    patorol_according, // 経路に沿って移動中
    patorol_nomove, // 移動なし
    patorol_none // 警備なし
} patorolType;

/// 吹き出しの種類
typedef enum {
    exclamation,
    question
} speechBubbleType;


class EnemySprite : public CharacterSprite
{
protected:
    /// 初期警備タイプ
    ::patorolType m_initPatorolType;
    /// 警備タイプ
    ::patorolType m_patorolType;
    /// 巡回時の回転方向
    ::rotateDirectcion m_rotateDirection;
    /// 経路
    std::vector<Vec2> m_routeStack;
    /// 経路の進捗を管理するインデックス
    int m_routeStackIndex;
    /// プレイヤーを最後に発見した座標
    Vec2 m_playerLostPoint;
    /// プレイヤーを見失った際に見た次の座標
    Vec2 m_playerLostNextPoint;
    /// 聞こえた位置に移動中かどうか
    bool m_movingHeardSoundPoint;
    /// プレイヤー発見中かどうか
    bool m_isFoundPlayer;
    /// 壁叩きの音が聞こえる範囲
    int m_hearableRange;
    
    void setupAnimationCache();
    void setDirectcion(::directcion direction);
    void hitToBullet(int damage, ::directcion bulletDirection);
    bool canMovePos(Vec2 const& pos);
    bool canMoveNextPos();
    void rotate();
    void dead();
    virtual void update(float delta);
    virtual void foundPlayer();
    virtual void losePlayer();
    bool checkFindPlayer();
    virtual void patrolRoundTrip();
    virtual void patrolRotateIfPossible();
    virtual void patrolRotateHitWall();
    virtual void patrolRandom();
    virtual void patrolChase();
    virtual void patrolChaseForever();
    virtual void patrolAccording();
    
public:
    static EnemySprite* create(const std::string& filename, const Vec2 &pos, ::directcion direction, float updatePosFrame, ::patorolType patorolType);
    virtual bool initWithFileName(const std::string& filename, const Vec2 &pos, ::directcion direction, float updatePosFrame, ::patorolType patorolType);
    void setPatorolType(::patorolType patorolType);
    void setRotateDirectcion(::rotateDirectcion rotateDirection);
    void showSpeechBubble(::speechBubbleType speechBubbleType);
    int hearableRange();
    void moveToPos(Vec2 const& pos);
    void startPatrol();
    void stopPatrol();
   
};

#endif /* EnemySprite_hpp */
