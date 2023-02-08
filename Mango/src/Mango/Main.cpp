#include <Mango/App.h>
#include <Mango/Layers/CanvasLayer.h>

int main(int argc, char* argv[])
{
    Mango::WindowSpecification spec("Mango", 800, 600, false);
    Mango::App app(spec);
    app.AddLayer(new Mango::CanvasLayer);

    app.Run();

    return 0;
}
