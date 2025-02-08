//
// Created by FanFan on 2025/1/27.
//

#ifndef SCENE_HPP
#define SCENE_HPP
#include <memory>
#include "Util/Animation.hpp"
#include "Util/BGM.hpp"
#include "Core/Context.hpp"
#include "Util/Input.hpp"
#include "Util/Logger.hpp"
#include "Util/Transform.hpp"
#include "Util/Time.hpp"
#include "Util/SFX.hpp"
#include "Util/Text.hpp"
namespace Util {
    class Scene {
    public:
        virtual ~Scene() = default;
        // 初始化場景
        virtual void Init() = 0;
        // 更新場景
        virtual void Update() = 0;
        // 渲染場景
        virtual void Render() = 0;
        bool getSenseEnd() const;//判斷場景是否能結束
        int getmode() const;//取得選擇的模式
    protected:
        std::shared_ptr<Util::Animation> m_Animation;
        std::shared_ptr<Util::BGM> m_BGM;
        bool SenseEnd=false;
        int mode=0;//0=story 1=battle
    };
} // namespace Util

#endif // SCENE_HPP
