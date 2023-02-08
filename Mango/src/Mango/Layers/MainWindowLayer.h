#pragma once
#include <Mango/Layer.h>

namespace Mango
{
	class MainWindowLayer : public Layer
	{
	public:
		void OnStart() override {}
		void OnUpdate(float timestep) override {}
		void OnImGuiRender() override;
		void OnEnd() override {}
	};
}