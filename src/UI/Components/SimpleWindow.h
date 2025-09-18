#ifndef SIMPLEWINDOW_H
#define SIMPLEWINDOW_H

#include <imgui.h>

class SimpleWindow
{
public:
    explicit SimpleWindow(ImGuiIO *io = nullptr);
    void Render();

private:
    bool m_showAnotherWindow;
    ImGuiIO *m_io;
};

#endif