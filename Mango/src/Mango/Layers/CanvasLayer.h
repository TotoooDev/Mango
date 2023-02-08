#pragma once
#include <Mango/Layer.h>
#include <imgui/imgui.h>

namespace Mango
{
    class CanvasLayer : public Layer
    {
    public:
        void OnStart() override {}
        void OnUpdate(float timestep) override {}
        void OnImGuiRender() override
        {
            ImGui::Begin("Canvas");
            ImGui::Text("Proute");
            ImGui::End();
        }
        void OnEnd() override {}
    };
}
