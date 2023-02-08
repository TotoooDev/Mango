#include <Mango/App.h>
#include <Mango/Layers/CanvasLayer.h>
#include <Mango/Layers/MainWindowLayer.h>

int main(int argc, char* argv[])
{
    Mango::WindowSpecification spec("Mango", 800, 600, false);
    Mango::App app(spec);
    app.AddLayer(new Mango::MainWindowLayer);
    app.AddLayer(new Mango::CanvasLayer);
    app.Run();

    return 0;
}
