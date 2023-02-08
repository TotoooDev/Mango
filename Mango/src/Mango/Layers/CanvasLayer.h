#pragma once
#include <Mango/Layer.h>
#include <imgui/imgui.h>
#include <vector>

namespace Mango
{
    class CanvasLayer : public Layer
    {
    public:
        void OnStart() override {}
        void OnUpdate(float timestep) override {}
        void OnImGuiRender() override;
        void OnEnd() override {}

    private:
        ImVec2 m_Scrolling = ImVec2(0.0f, 0.0f);
        std::vector<ImVec2> m_Points;
    };
}
