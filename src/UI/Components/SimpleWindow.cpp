#include "SimpleWindow.h"

SimpleWindow::SimpleWindow(ImGuiIO *io) : m_showAnotherWindow(false), m_io(io) {}

void SimpleWindow::Render()
{
    static float f = 0.0;
    static int counter = 0;

    ImGui::Begin("Hello world");

    ImGui::Text("This is some useful text");
    ImGui::Checkbox("Another Window", &m_showAnotherWindow);
    if (ImGui::Button("Button"))
    {
        counter++;
    }

    ImGui::SameLine();
    ImGui::Text("Counter = %d", counter);
    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
                1000.0f / m_io->Framerate,
                m_io->Framerate);
    ImGui::End();

    if (m_showAnotherWindow)
    {
        ImGui::Begin("Another Window", &m_showAnotherWindow);
        ImGui::Text("Hello from another window!");
        if (ImGui::Button("Close Me"))
            m_showAnotherWindow = false;
        ImGui::End();
    }
}