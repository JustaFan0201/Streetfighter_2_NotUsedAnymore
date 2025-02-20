//
// Created by FanFan on 2025/2/2.
//

#ifndef SLECTSCENE_HPP
#define SLECTSCENE_HPP
#include "Scene.hpp"
namespace Util {
    struct image_space {
        std::shared_ptr<Image> image;
        Transform transform;
    };

    class SlectScene : public Scene {
    private:
        bool m_WaitingForEnter=true;
        unsigned long start = Time::GetElapsedTimeMs();
        std::shared_ptr<SFX> soundEffect_enter = std::make_shared<SFX>("../voice/01 Select Screen & World Map/SFII_02 - Move Cursor.wav");
        std::shared_ptr<SFX> soundEffect_slect = std::make_shared<SFX>("../voice/01 Select Screen & World Map/SFII_03 - Selection.wav");
        image_space character;
        image_space first_player;
        image_space first_player_screen;
    public:
        SlectScene();
        void Init() override;   // 初始化
        void Update() override; // 更新場景
        void Render() override; // 渲染圖片
    };

}
#endif //SLECTSCENE_HPP
