#include <implot.h>
#include <implot3d.h>
#include <imgui.h>


class Plot3d
{
public:
    explicit Plot3d();
    void Plot3dInit();
    void Render();
    void CleanUp();
};