#pragma once
#include <Mango/Layer.h>
#include <imgui/imgui.h>
#include <vector>

namespace Mango
{
    class CanvasLayer : public Layer
    {
    public:
        void OnStart() override
        {
            m_Nodes.push_back(ImVec2(100.0f, 100.0f));
            m_Nodes.push_back(ImVec2(200.0f, 250.0f));
            m_Nodes[0].LinkedNodes.push_back(&m_Nodes[1]);
        }
        void OnUpdate(float timestep) override {}
        void OnImGuiRender() override;
        void OnEnd() override {}

    private:
        struct Node
        {
            std::vector<Node*> LinkedNodes;
            bool IsFirst = false;
            bool IsFinal = false;
            ImVec2 Pos;

            Node(ImVec2 pos)
                : Pos(pos)
            {}
        };

        ImVec2 m_Scrolling = ImVec2(0.0f, 0.0f);
        std::vector<Node> m_Nodes;
        Node* m_SelectedNode = nullptr;
        float m_NodeRadius = 16.0f;
    };
}
