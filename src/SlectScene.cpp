//
// Created by FanFan on 2025/2/2.
//

#include "SlectScene.hpp"
namespace Util {
    SlectScene::SlectScene(){}
    void SlectScene::Init() {
        m_Animation = std::make_shared<Animation>(
            std::vector<std::string> {//每一張動畫圖片
                "../sencepicture/slect/map.png"
            },
            true,
            2000,
            false,
            100
        );
        Core::Context::GetInstance()->ScaleAnimationToWindow(m_Animation);//調整動畫大小符合視窗
        m_BGM = std::make_shared<BGM>("../music/03 Player Select.mp3");
        m_BGM->SetVolume(20);  // 設定音量
        m_BGM->Play(-1); // 播放
        character.image = std::make_shared<Image>("../sencepicture/slect/ken_face.png");
        first_player.image = std::make_shared<Image>("../sencepicture/slect/1p.png");
        first_player_screen.image = std::make_shared<Image>("../sencepicture/slect/1p_screen.png");
        character.transform.SetPosition(-420, -180);
        character.image->SetSize(glm::vec2(288, 345));
        first_player.transform.SetPosition(-420, 40);
        first_player.image->SetSize(glm::vec2(81, 42));
        first_player_screen.transform.SetPosition(-160, -150);
        first_player_screen.image->SetSize(glm::vec2(96, 108));

    }

    void SlectScene::Update() {
        if (Util::Input::IsKeyPressed(Keycode::MOUSE_LB)) {
            glm::vec2 mousePos = Util::Input::GetCursorPosition(); // 取得滑鼠座標
            std::cout << "Mouse Clicked at: (" << mousePos.x << ", " << mousePos.y << ")" << std::endl;
        }
    }

    void SlectScene::Render() {
        // 在這裡渲染動畫的當前幀
        Transform transform;//背景
        transform.SetPosition(0.0f, 0.0f);
        m_Animation->Draw(transform, 0.0f);
        character.image->Draw(character.transform, 1.0f);
        first_player.image->Draw(first_player.transform, 1.0f);
        first_player_screen.image->Draw(first_player_screen.transform, 1.0f);
    }

}