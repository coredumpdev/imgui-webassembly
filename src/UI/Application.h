#include <GLFW/glfw3.h>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#ifdef __EMSCRIPTEN__
#include <emscripten_mainloop_stub.h>
#include <emscripten.h>
#endif

#include "Components/SimpleWindow.h"
#include "Components/Plot3d.h"

#include <iostream>

#define GL_SILENCE_DEPRECATION

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

class Application
{
public:
    explicit Application();
    bool Init();
    void InitComponents();
    void StartImGui();
    void RenderImGui();
    void CleanUp();
    void Run();

private:
    std::string m_glslVersion;
    float m_mainScale;
    GLFWwindow *m_window;
    int m_width;
    int m_height;
    std::string m_title;
    ImGuiIO *m_io;
    ImGuiStyle m_style;
    ImVec4 m_windowColor;

    // Components
    SimpleWindow *m_simpleWindow;
    Plot3d *m_plot3d;

private:
    static void glfwErrorCallback(int error, const char *description)
    {
        std::cerr << "[Error Code: " << error << "]: " << description << std::endl;
    }
};