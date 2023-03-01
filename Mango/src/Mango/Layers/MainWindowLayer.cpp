#include <Mango/Layers/MainWindowLayer.h>
#include <Mango/App.h>
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
                if (ImGui::MenuItem("Quit", "Alt+F4"))
                    App::Get().Quit();
				ImGui::EndMenu();
			}
			ImGui::EndMainMenuBar();
		}
	}
}
