#include <Mango/Layers/CanvasLayer.h>

namespace Mango
{
    void CanvasLayer::OnImGuiRender()
    {
        ImGui::Begin("Canvas");
        ImGui::Text("proute");
        ImGui::End();
    }
}
