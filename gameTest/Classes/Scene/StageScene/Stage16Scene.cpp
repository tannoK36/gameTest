//
//  Stage16Scene.cpp
//  gameTest-mobile
//
//  Created by 丹野健介 on 2020/03/22.
//

#include "Stage16Scene.hpp"

#pragma mark -
#pragma mark Init
/**
    シーンの作成
 */
Stage16Scene* Stage16Scene::createScene()
{
    Stage16Scene *scene = new (std::nothrow) Stage16Scene();
    if (scene && scene->init(16))
    {
        scene->autorelease();
        return scene;
    }
    CC_SAFE_DELETE(scene);
    return nullptr;
}


/**
    キャラクターの初期化処理
 */
void Stage16Scene::initCharactors()
{
    // プレイヤー
    this->m_player = PlayerSprite::create("player_back1.png", Vec2(5.0f, 29.0f), ::back, 30.0f);
    this->m_player->setAnchorPoint(Vec2(0.0f, 0.0f));
    this->addChild(this->m_player);
    
    // 敵キャラクター
    EnemySprite* enemy1 = EnemySprite::create("enemy1.png", Vec2(11.0f, 25.0f), ::left, 30.0f, patorol_rotateifpossible);
    enemy1->setAnchorPoint(Vec2(0.0f, 0.0f));
    this->addChild(enemy1);
    enemy1->setRotateDirectcion(turn_left);
    
    EnemySprite* enemy2 = EnemySprite::create("enemy1.png", Vec2(7.0f, 22.0f), ::right, 30.0f, patorol_rotateifpossible);
    enemy2->setAnchorPoint(Vec2(0.0f, 0.0f));
    this->addChild(enemy2);
    enemy2->setRotateDirectcion(turn_right);
    
    EnemySprite* enemy3 = EnemySprite::create("enemy1.png", Vec2(11.0f, 19.0f), ::left, 30.0f, patorol_rotateifpossible);
    enemy3->setAnchorPoint(Vec2(0.0f, 0.0f));
    this->addChild(enemy3);
    enemy3->setRotateDirectcion(turn_left);
    
    EnemySprite* enemy4 = EnemySprite::create("enemy1.png", Vec2(7.0f, 16.0f), ::right, 30.0f, patorol_rotateifpossible);
    enemy4->setAnchorPoint(Vec2(0.0f, 0.0f));
    this->addChild(enemy4);
    enemy4->setRotateDirectcion(turn_right);
    
    EnemySprite* enemy5 = EnemySprite::create("enemy1.png", Vec2(11.0f, 13.0f), ::left, 30.0f, patorol_rotateifpossible);
    enemy5->setAnchorPoint(Vec2(0.0f, 0.0f));
    this->addChild(enemy5);
    enemy5->setRotateDirectcion(turn_left);
}


/**
   スコア基準値の初期化処理
*/
void Stage16Scene::initScoreStandard()
{
    this->m_scoreStandard.timeScoreStandardA = 15;
    this->m_scoreStandard.timeScoreStandardB = 45;
    this->m_scoreStandard.foundScoreStandardA = 0;
    this->m_scoreStandard.foundScoreStandardB = 3;
}


#pragma mark -
#pragma mark GameEvent
/**
    ゲーム開始時の処理
 */
void Stage16Scene::gameStart()
{
    // ミッション開始のメッセージ表示後、ゲームスタート
    this->m_mdController->createStartReachMissonMessage([this]() {
        StageSceneBase::gameStart();
        this->m_mdController->m_dialog->setCompleteAction(nullptr);
    });
}


/**
    コンティニューを実行
 */
void Stage16Scene::doContinue()
{
    StageSceneBase::doContinue();
    
    // コンティニュー
    Scene* StageSceneBase = this->createScene();
    TransitionFade* fade = TransitionFade::create(1.0f, StageSceneBase);
    Director::getInstance()->replaceScene(fade);
}


/**
    状況の判定
 */
void Stage16Scene::checkState()
{
    // クリア座標判定
    if (this->m_player->worldPosition() == Vec2(12.0f, 12.0f)) {
        this->stageClear();
    }
    
    return;
}
