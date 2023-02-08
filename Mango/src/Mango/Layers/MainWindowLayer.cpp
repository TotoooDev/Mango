#include <Mango/Layers/MainWindowLayer.h>
#include <imgui/imgui.h>

namespace Mango
{
	void MainWindowLayer::OnImGuiRender() 
	{
		ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());

		if (ImGui::BeginMainMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				ImGui::EndMenu();
			}
			ImGui::EndMainMenuBar();
		}
	}
}