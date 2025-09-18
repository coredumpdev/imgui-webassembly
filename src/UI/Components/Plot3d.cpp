#include "Plot3d.h"

Plot3d::Plot3d(){}

void Plot3d::Plot3dInit()
{
    ImPlot::CreateContext();
    ImPlot3D::CreateContext();
}

void Plot3d::Render()
{
    ImPlot::ShowDemoWindow();
    ImPlot3D::ShowDemoWindow();
}

void Plot3d::CleanUp()
{
    ImPlot3D::DestroyContext();
    ImPlot::DestroyContext();
}