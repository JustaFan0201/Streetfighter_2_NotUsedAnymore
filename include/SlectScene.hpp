//
// Created by FanFan on 2025/2/2.
//

#ifndef SLECTSCENE_HPP
#define SLECTSCENE_HPP
#include "Scene.hpp"
namespace Util {
    class SlectScene : public Scene {
    private:
        bool m_WaitingForEnter=true;
        unsigned long start = Time::GetElapsedTimeMs();
        std::shared_ptr<SFX> soundEffect_slect = std::make_shared<SFX>("../voice/01 Select Screen & World Map/SFII_02 - Move Cursor.wav");
        std::shared_ptr<SFX> soundEffect_enter = std::make_shared<SFX>("../voice/01 Select Screen & World Map/SFII_03 - Selection.wav");
        image_space character;
        image_space character_match_country;
        image_space first_player;
        image_space first_player_screen;
        std::vector<std::shared_ptr<Image>> characters = {
            std::make_shared<Image>("../sencepicture/slect/ryu_face.png"),
            std::make_shared<Image>("../sencepicture/slect/honda_face.png"),
            std::make_shared<Image>("../sencepicture/slect/blanka_face.png"),
            std::make_shared<Image>("../sencepicture/slect/guile_face.png"),
            std::make_shared<Image>("../sencepicture/slect/ken_face.png"),
            std::make_shared<Image>("../sencepicture/slect/chunli_face.png"),
            std::make_shared<Image>("../sencepicture/slect/zangief_face.png"),
            std::make_shared<Image>("../sencepicture/slect/dhalsim_face.png")
        };
        std::vector<std::shared_ptr<Image>> countries = {
            std::make_shared<Image>("../sencepicture/slect/japan.png"),
            std::make_shared<Image>("../sencepicture/slect/japan.png"),
            std::make_shared<Image>("../sencepicture/slect/brazil.png"),
            std::make_shared<Image>("../sencepicture/slect/usa.png"),
            std::make_shared<Image>("../sencepicture/slect/usa.png"),
            std::make_shared<Image>("../sencepicture/slect/china.png"),
            std::make_shared<Image>("../sencepicture/slect/ussr.png"),
            std::make_shared<Image>("../sencepicture/slect/india.png")
        };
        std::vector<image_space> countries_dark = {
            {std::make_shared<Image>("../sencepicture/slect/japan_dark.png"), glm::vec2(16, 94)},
            {std::make_shared<Image>("../sencepicture/slect/japan_dark.png"), glm::vec2(28, 168)},
            {std::make_shared<Image>("../sencepicture/slect/brazil_dark.png"), glm::vec2(323, 23)},
            {std::make_shared<Image>("../sencepicture/slect/usa_dark.png"), glm::vec2(350, 140)},
            {std::make_shared<Image>("../sencepicture/slect/usa_dark.png"), glm::vec2(338, 245)},
            {std::make_shared<Image>("../sencepicture/slect/china_dark.png"), glm::vec2(-113, 193)},
            {std::make_shared<Image>("../sencepicture/slect/ussr_dark.png"), glm::vec2(-251, 217)},
            {std::make_shared<Image>("../sencepicture/slect/india_dark.png"), glm::vec2(-228, 97)}
        };

        int chooseIndex = 0;
    public:
        SlectScene();
        void Init() override;   // 初始化
        void Update() override; // 更新場景
        void Render() override; // 渲染圖片
    };

}
#endif //SLECTSCENE_HPP
