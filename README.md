# C++ ImGui WebAssembly Project

This project is a boilerplate and an example of how to run **ImGui** and **ImPlot** libraries on the web using **WebAssembly** compiled with **C++** and **Emscripten**. This repository demonstrates how powerful C++ UI libraries, originally developed for desktop applications, can be ported to the web environment. 💻✨

![Project Preview](img/img.gif)

---

## About the Project

This project uses a combination of C++ libraries to create a web-based user interface. The core components include:

-   **ImGui:** A bloat-free graphical user interface library for C++.
-   **ImPlot:** An immediate mode plotting library for ImGui, used for creating 2D and 3D plots.
-   **Emscripten:** A compiler toolchain for compiling C/C++ code into WebAssembly.
-   **GLFW** and **OpenGL3:** Used for the rendering backend, which are then emulated by Emscripten to run in the browser.

The project structure is organized to keep the source code, libraries, and build tools separate, allowing for clean and maintainable code.

---

## Setup and Building

To build this project, you will need the **Emscripten SDK**. If you don't have it installed, you can follow the official Emscripten installation guide.

1.  **Install the Emscripten SDK:**
    ```bash
    git clone https://github.com/emscripten-core/emsdk.git
    cd emsdk
    ./emsdk install latest
    ./emsdk activate latest
    source ./emsdk_env.sh
    ```

2.  **Clone the repository:**
    ```bash
    git clone https://github.com/coredumpdev/imgui-webassembly.git
    cd imgui-webassembly
    ```

3.  **Build the project:**
    Thanks to the Makefile, you can easily compile the project with a single command.
    ```bash
    make
    ```

---

## Usage

After the compilation is complete, an **`.html`**, **`.js`**, and **`.wasm`** file will be created in the current folder. You need to run these files through a web server. You can use Python's built-in server for this purpose:

1.  **Start the Python server:**
    ```bash
    python3 -m http.server
    ```

2.  Open your browser and go to **`http://localhost:8000`**. You can now see the ImGui and ImPlot interface running in your browser.

---

## Contributing

If you'd like to contribute to the project, please open a pull request or an issue for any bugs or suggestions. All contributions are welcome!

---

## License

This project is licensed under the **MIT License**. See the `LICENSE` file for more details.