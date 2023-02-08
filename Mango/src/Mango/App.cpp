#include <Mango/App.h>
#include <Mango/Log.h>
#include <imgui/imgui.h>
#include <algorithm>

namespace Mango
{
    App* App::m_Instance = nullptr;

    App::App(const WindowSpecification& spec)
        : m_Window(spec)
    {
        if (!m_Instance)
            m_Instance = this;
        else
            MANGO_STOP("An application already exists!");
    }

    void App::Run()
    {
        while (!m_Window.ShouldClose())
        {
            m_Window.Update();

            for (auto& layer : m_Layers)
            {
                layer->OnUpdate(m_Timestep);
            }

            for (auto& layer : m_Layers)
            {
                layer->OnImGuiRender();
            }

            m_Window.Display();

            UpdateTimestep();
        }
    }

    void App::AddLayer(Layer* layer)
    {
        m_Layers.push_back(layer);
        layer->OnStart();
    }

    void App::RemoveLayer(Layer* layer)
    {
        auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
        if (it != m_Layers.end())
        {
            layer->OnEnd();
            m_Layers.erase(it);
        }
    }

    void App::UpdateTimestep()
    {
        float currentFrame = (float)glfwGetTime();
        m_Timestep = currentFrame - m_LastFrame;
        m_LastFrame = currentFrame;
    }
}
