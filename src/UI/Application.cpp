#include "Application.h"

Application::Application()
    : m_glslVersion("#version 130"), m_mainScale(0.0), m_window(nullptr), m_width(WINDOW_WIDTH), m_height(WINDOW_HEIGHT), m_title("Hello world"), m_io(nullptr), m_style(), m_windowColor(), m_simpleWindow(nullptr), m_plot3d(nullptr)
{
}


bool Application::Init()
{
    glfwSetErrorCallback(glfwErrorCallback);

    InitComponents();


    if (!glfwInit())
        return 1;

#if defined(IMGUI_IMPL_OPENGL_ES2)
    m_glslVersion = "#version 100";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);

#elif defined(IMGUI_IMPL_OPENGL_ES3)
    m_glslVersion = "#version 300 es";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
#else
    m_glslVersion = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
#endif

    m_mainScale = ImGui_ImplGlfw_GetContentScaleForMonitor(glfwGetPrimaryMonitor());
    m_window = glfwCreateWindow(static_cast<int>(m_width * m_mainScale),
                                static_cast<int>(m_height * m_mainScale),
                                m_title.c_str(),
                                nullptr,
                                nullptr);
    if (m_window == nullptr)
        return false;

    glfwMakeContextCurrent(m_window);
    glfwSwapInterval(0);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    m_plot3d->Plot3dInit();

    m_io = &ImGui::GetIO();
    (void) m_io;

    m_io->ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    m_style = ImGui::GetStyle();
    m_style.ScaleAllSizes(m_mainScale);
    m_style.FontScaleDpi = m_mainScale;

    ImGui_ImplGlfw_InitForOpenGL(m_window, true);

#ifdef __EMSCRIPTEN__
    EM_ASM({ Module['canvas'] = document.getElementById('canvas'); });
    ImGui_ImplGlfw_InstallEmscriptenCallbacks(m_window, "#canvas");
#endif



    ImGui_ImplOpenGL3_Init(m_glslVersion.c_str());

    m_windowColor = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);


    return true;
}


void Application::InitComponents()
{
    m_simpleWindow = new SimpleWindow(m_io);
    m_plot3d = new Plot3d();
}

void Application::StartImGui()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void Application::CleanUp()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    m_plot3d->CleanUp();
    ImGui::DestroyContext();

    glfwDestroyWindow(m_window);
    glfwTerminate();
}


void Application::Run()
{
#ifdef __EMSCRIPTEN__
    m_io->IniFilename = nullptr;
    EMSCRIPTEN_MAINLOOP_BEGIN
#else
    while (!glfwWindowShouldClose(m_window))
#endif
    {
        glfwPollEvents();

        if (glfwGetWindowAttrib(m_window, GLFW_ICONIFIED) != 0) {
            ImGui_ImplGlfw_Sleep(10);
            continue;
        }
        StartImGui();

        /*
         * 
         * Component Rendering section
         * 
         * 
         */

        m_simpleWindow->Render();
        m_plot3d->Render();

        /*
         * 
         * Component Rendering section ends here
         * 
         */
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(m_window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(m_windowColor.x * m_windowColor.w,
                     m_windowColor.y * m_windowColor.w,
                     m_windowColor.z * m_windowColor.w,
                     m_windowColor.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(m_window);
    }
#ifdef __EMSCRIPTEN__
    EMSCRIPTEN_MAINLOOP_END;
#endif

    CleanUp();
}