EMSDK = /home/tolga/.config/emsdk/upstream/emscripten

CXX = $(EMSDK)/emcc
CXXFLAGS = -O2 -std=c++17 \
  -Ilibs/include \
  -s USE_WEBGL2=1 \
  -s FULL_ES3=1 \
  -s WASM=1 \
  -s ALLOW_MEMORY_GROWTH=1 \
  -s DISABLE_EXCEPTION_CATCHING=0 \
  -s USE_PTHREADS=0


SRC = \
  src/main.cpp \
  src/UI/Application.cpp \
  src/UI/Components/SimpleWindow.cpp \
  src/UI/Components/Plot3d.cpp \
  src/ui-source/imgui.cpp \
  src/ui-source/imgui_draw.cpp \
  src/ui-source/imgui_widgets.cpp \
  src/ui-source/imgui_tables.cpp \
  src/ui-source/imgui_demo.cpp \
  src/ui-source/imgui_impl_opengl3.cpp \
  src/ui-source/implot.cpp \
  src/ui-source/implot_items.cpp \
  src/ui-source/implot_demo.cpp \
  src/ui-source/implot3d.cpp \
  src/ui-source/implot3d_items.cpp \
  src/ui-source/implot3d_demo.cpp \
  src/ui-source/implot3d_meshes.cpp \
  src/ui-source/imgui_impl_glfw.cpp \

OBJ = $(SRC:.cpp=.o)

TARGET = imgui-tutorial.html

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS) -s USE_GLFW=3

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	find src -name '*.o' -delete
	rm -f $(TARGET) *.wasm *.js