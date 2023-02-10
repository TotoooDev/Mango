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
        struct Node
        {
            std::vector<Node*> LinkedNodes;
            bool IsFirst = false;
            bool IsFinal = false;
        };

        ImVec2 m_Scrolling = ImVec2(0.0f, 0.0f);
        std::vector<Node> m_Points;
    };
}
