#pragma once

namespace Mango
{
    class Layer
    {
    public:
        virtual void OnStart() = 0;
        virtual void OnUpdate(float timestep) = 0;
        virtual void OnEnd() = 0;
        virtual void OnImGuiRender() = 0;
    };
}
