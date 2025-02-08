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
        std::shared_ptr<SFX> soundEffect_enter = std::make_shared<Util::SFX>("../voice/SFII_02 - Move Cursor.wav");
        std::shared_ptr<SFX> soundEffect_slect = std::make_shared<Util::SFX>("../voice/SFII_03 - Selection.wav");
    public:
        SlectScene();
        void Init() override;   // 初始化
        void Update() override; // 更新場景
        void Render() override; // 渲染圖片
    };

}
#endif //SLECTSCENE_HPP
