#include "UI/Application.h"

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
Application *g_app = nullptr;

void main_loop()
{
    if (g_app)
        g_app->Run();
}

int main(int argc, char *argv[])
{
    g_app = new Application();
    g_app->Init();

    main_loop();
    // emscripten_set_main_loop(main_loop, 0, true);
}
#else

int main(int argc, char *argv[])
{
    
    Application app;

    Application app;
    if (!app.Init())
        return 1;
    app.Run();
    return 0;
}

#endif