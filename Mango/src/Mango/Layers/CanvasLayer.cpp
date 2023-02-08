#include <Mango/Layers/CanvasLayer.h>

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
        const ImVec2 mouse_pos_in_canvas(io.MousePos.x - canvas_p0.x, io.MousePos.y - canvas_p0.y);

        if (is_hovered && ImGui::IsItemClicked())
        {
            m_Points.push_back(mouse_pos_in_canvas);
        }

        for (auto& point : m_Points)
        {
            drawList->AddCircle(ImVec2(canvas_p0.x + point.x, canvas_p0.y + point.y), 16.0f, IM_COL32(240, 240, 240, 255));
        }

        ImGui::End();
    }
}
