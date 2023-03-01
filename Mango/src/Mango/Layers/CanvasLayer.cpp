#include <Mango/Layers/CanvasLayer.h>
#include <cmath>

namespace Mango
{
    void CanvasLayer::OnImGuiRender()
    {
        ImGui::Begin("Canvas");
        ImGui::Text("proute");

        ImGuiIO& io = ImGui::GetIO();

        ImVec2 canvas_p0 = ImGui::GetCursorScreenPos();      // ImDrawList API uses screen coordinates!
        ImVec2 canvas_sz = ImGui::GetContentRegionAvail();   // Resize canvas to what's available
        if (canvas_sz.x < 50.0f) canvas_sz.x = 50.0f;
        if (canvas_sz.y < 50.0f) canvas_sz.y = 50.0f;
        ImVec2 canvas_p1 = ImVec2(canvas_p0.x + canvas_sz.x, canvas_p0.y + canvas_sz.y);

        ImDrawList* drawList = ImGui::GetWindowDrawList();
        drawList->AddRectFilled(canvas_p0, canvas_p1, IM_COL32(50, 50, 50, 255));

        // This will catch our interactions
        ImGui::InvisibleButton("canvas", canvas_sz, ImGuiButtonFlags_MouseButtonLeft | ImGuiButtonFlags_MouseButtonRight);
        const bool is_hovered = ImGui::IsItemHovered(); // Hovered
        const bool is_active = ImGui::IsItemActive();   // Held
        const ImVec2 origin(canvas_p0.x + m_Scrolling.x, canvas_p0.y + m_Scrolling.y); // Lock scrolled origin
        const ImVec2 mousePosInCanvas(io.MousePos.x - canvas_p0.x, io.MousePos.y - canvas_p0.y);

        if (is_hovered && ImGui::IsItemClicked())
        {
            bool collidesNode = false;
            for (auto& node : m_Nodes)
            {
                float distance = std::sqrt((node.Pos.x - mousePosInCanvas.x) * (node.Pos.x - mousePosInCanvas.x) + (node.Pos.y - mousePosInCanvas.y) * (node.Pos.y - mousePosInCanvas.y));
                if (distance <= m_NodeRadius * 2.0f)
                {
                    m_SelectedNode = &node;
                    collidesNode = true;
                }
            }
            if (!collidesNode)
                m_Nodes.push_back(mousePosInCanvas);
        }

        for (auto& node : m_Nodes)
        {
            drawList->AddCircle(ImVec2(canvas_p0.x + node.Pos.x, canvas_p0.y + node.Pos.y), m_NodeRadius, IM_COL32(240, 240, 240, 255));
            for (auto& linkedNode : node.LinkedNodes)
            {
                ImVec2 pos1(canvas_p0.x + node.Pos.x, canvas_p0.y + node.Pos.y);
                ImVec2 pos2(canvas_p0.x + linkedNode->Pos.x, canvas_p0.y + linkedNode->Pos.y);
                drawList->AddLine(pos1, pos2, IM_COL32(240, 240, 240, 255));
            }
        }

        ImGui::End();
    }
}
