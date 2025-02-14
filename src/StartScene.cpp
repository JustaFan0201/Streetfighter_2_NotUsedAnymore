//
// Created by FanFan on 2025/1/27.
//

#include "StartScene.hpp"

namespace Util {
    StartScene::StartScene(){}
    void StartScene::Init() {
        m_Animation = std::make_shared<Animation>(
            std::vector<std::string> {//每一張動畫圖片
                "../sencepicture/start/start_1.png",
                "../sencepicture/start/start_2.png",
                "../sencepicture/start/start_3.png"
            },
            true,
            2000,
            false,
            100
        );
        Core::Context::GetInstance()->ScaleAnimationToWindow(m_Animation);//調整動畫大小符合視窗
        m_BGM = std::make_shared<BGM>("../music/title.mp3");
        m_BGM->SetVolume(15);  // 設定音量
        m_BGM->DelayedPlayAsync(2000, -1); // 延遲播放
        soundEffect->SetVolume(30);
    }

    void StartScene::Update() {
        // 確保動畫已經播放足夠時間
        if (Time::GetElapsedTimeMs() - start > 4000) {

            // 狀態1:等待玩家按下 ENTER 進入選擇模式
            if (m_WaitingForEnter) {
                if (Input::IsKeyDown(Keycode::RETURN)) {
                    m_WaitingForEnter = false; // 切換到選擇模式
                    Word_1.text = std::make_shared<Text>("../streetfighter.ttf", 32, "Story mode", Color(255, 127, 80));
                    Word_2.text = std::make_shared<Text>("../streetfighter.ttf", 32, "Battle mode", Color(255, 255, 255));
                    Word_1.transform.SetPosition(-180, -180);
                    Word_2.transform.SetPosition(180, -180);
                    soundEffect->Play(0);
                    m_Animation = std::make_shared<Animation>(
                        std::vector<std::string> {
                            "../sencepicture/start/start_4.png"
                        },
                        true,
                        2000,
                        false,
                        100
                    );
                }
            }

            // 狀態2:進入模式選擇
            else {
                Word_1.text->Draw(Word_1.transform, 1.0f);
                Word_2.text->Draw(Word_2.transform, 1.0f);

                if (Input::IsKeyPressed(Keycode::A) && mode == 1) {
                    Word_1.text->SetColor(Color(255, 127, 80));
                    Word_2.text->SetColor(Color(255, 255, 255));
                    soundEffect->Play(0);
                    mode = 0;
                }
                if (Input::IsKeyPressed(Keycode::D) && mode == 0) {
                    Word_2.text->SetColor(Color(255, 127, 80));
                    Word_1.text->SetColor(Color(255, 255, 255));
                    soundEffect->Play(0);
                    mode = 1;
                }
                //ENTER放開後進入SenseEnd
                if (Input::IsKeyDown(Keycode::RETURN)) {
                    soundEffect->Play(0);
                    SDL_Delay(600);
                    SenseEnd = true;
                }
            }
        }
    }
    void StartScene::Render() {
        // 在這裡渲染動畫的當前幀
        Transform transform_3;
        transform_3.SetPosition(0.0f, 0.0f);  // 設定圖片顯示位置
        m_Animation->Draw(transform_3, 0.0f);         // 畫出當前幀
    }

}
// namespace Util