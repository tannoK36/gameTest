//
//  MessageDialog.hpp
//  gameTest-mobile
//
//  Created by agenda_tanno on 2018/12/07.
//

#ifndef MessageDialog_hpp
#define MessageDialog_hpp

USING_NS_CC;

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "ui/UIScale9Sprite.h"

class MessageDialog : public Node
{
private:
    ui::Scale9Sprite* frame = nullptr; // メッセージフレーム
    Label* label = nullptr; // 表示中のメッセージラベル
    Sprite* finishArrow; // 文字送り終了矢印
    std::vector<std::string> messageList; // 表示するメッセージのリスト
    const int LABEL_MARGIN = 30;
    bool isSending = false; 
    int charIndex = 0; // 現在の文字位置
    std::string message;    // 現在表示中のメッセージ
    size_t messageIndex = 0;    // 現在表示中のメッセージのインデックス
    int messageLength = 0; // 現在の文字列の長さ
    float interval = 0.1f; // 文字と文字を表示する間隔
    float distance = 0; // 前の文字を表示してからの経過時間
    std::function<void()> completedAction = nullptr; // 文字送り完了後のハンドラ
    
    void prepareLabel();
    void startArrowBlink();
    void stopAllowBlink();
    
public:
    MessageDialog() {};
    ~MessageDialog();
    virtual bool init(const int frameWidth, const int frameHeight);
    static MessageDialog* create(const int frameWidth, const int frameHeight);
    void start();
    void next();
    void update(float delta);
    void addMessage(const std::string &message);
    void setCompleteAction(std::function<void()> completedAction);
};

#endif /* MessageDialog_hpp */
