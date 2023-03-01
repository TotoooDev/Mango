#pragma once
#include <Mango/Window.h>
#include <Mango/Layer.h>
#include <vector>

namespace Mango
{
    class App
    {
    public:
        App(const WindowSpecification& spec);

        static App& Get() { return *m_Instance; }

        void Run();
        void Quit();

        void AddLayer(Layer* layer);
        void RemoveLayer(Layer* layer);

        Window GetWindow() const { return m_Window; }
        WindowSpecification GetWindowSpec() const { return m_Window.GetSpec(); }

    private:
        void UpdateTimestep();

        static App* m_Instance;

        Window m_Window;
        std::vector<Layer*> m_Layers;

        bool m_IsRunning = true;
        float m_LastFrame = 0.0f;
        float m_Timestep = 0.0f;
    };
}
