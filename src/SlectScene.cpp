//
// Created by FanFan on 2025/2/2.
//

#include "SlectScene.hpp"
namespace Util {
    SlectScene::SlectScene(){}
    void SlectScene::Init() {
        m_Animation.animation = std::make_shared<Animation>(
            std::vector<std::string> {//每一張動畫圖片
                "../sencepicture/slect/map.png"
            },
            true,
            2000,
            false,
            100
        );
        m_Animation.transform.SetPosition(0.0f, 0.0f);
        Core::Context::GetInstance()->ScaleAnimationToWindow(m_Animation.animation);//調整動畫大小符合視窗
        m_BGM = std::make_shared<BGM>("../music/03 Player Select.mp3");
        m_BGM->SetVolume(20);  // 設定音量
        m_BGM->Play(-1); // 播放

        character_match_country.image=countries[0];

        character.image = std::make_shared<Image>("../sencepicture/slect/ryu_face.png");//角色
        character.transform.SetPosition(-420, -180);

        first_player.image = std::make_shared<Image>("../sencepicture/slect/1p.png");//1p
        first_player.transform.SetPosition(-420, 20);
        first_player.image->SetSize(glm::vec2(162, 84));

        first_player_screen.image = std::make_shared<Image>("../sencepicture/slect/1p_screen.png");//1p框框
        first_player_screen.transform.SetPosition(-160, -150);
        first_player_screen.image->SetSize(glm::vec2(120, 144));

        for(auto i:countries_dark) {//所有國家灰色的
            i.image->SetSize(glm::vec2(72, 58));
        }
    }

    void SlectScene::Update() {
        if (Input::IsKeyPressed(Keycode::MOUSE_LB)) {
            glm::vec2 mousePos = Input::GetCursorPosition(); // 取得滑鼠座標
            std::cout << "Mouse Clicked at: (" << mousePos.x << ", " << mousePos.y << ")" << std::endl;
        }
        glm::vec2 position = first_player_screen.transform.GetPosition();
        int row = chooseIndex / 4;
        int col = chooseIndex % 4;

        if (Input::IsKeyDown(Keycode::W) && row > 0) {
            chooseIndex -= 4;
            position.y += 103;
            soundEffect_slect->Play(0);
        }
        if (Input::IsKeyDown(Keycode::S) && row < 1) {
            chooseIndex += 4;
            position.y -= 103;
            soundEffect_slect->Play(0);
        }
        if (Input::IsKeyDown(Keycode::A) && col > 0) {
            chooseIndex--;
            position.x -= 107;
            soundEffect_slect->Play(0);
        }
        if (Input::IsKeyDown(Keycode::D) && col < 3) {
            chooseIndex++;
            position.x += 107;
            soundEffect_slect->Play(0);
        }
        if (Input::IsKeyDown(Keycode::RETURN)) {
            soundEffect_enter->Play(0);
        }
        character_match_country.image=countries[chooseIndex];//角色的國家
        character_match_country.image->SetSize(glm::vec2(72, 58));
        character_match_country.transform.SetPosition(countries_dark[chooseIndex].transform.GetPosition());

        character.image = characters[chooseIndex]; //角色
        character.image->SetSize(glm::vec2(288, 345));
        first_player_screen.transform.SetPosition(position.x, position.y);//1p框框
    }

    void SlectScene::Render() {
        // 在這裡渲染動畫的當前幀
        m_Animation.animation->Draw(m_Animation.transform, 0.0f);
        character.image->Draw(character.transform, 1.0f);
        first_player.image->Draw(first_player.transform, 1.0f);
        first_player_screen.image->Draw(first_player_screen.transform, 1.0f);
        for(auto i:countries_dark) {
            i.image->Draw(i.transform, 1.0f);
        }
        character_match_country.image->Draw(character_match_country.transform, 2.0f);
    }

}