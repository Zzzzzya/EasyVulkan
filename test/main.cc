#include "Base/glfw/glfwGeneral.hpp"

int main() {
    if (!InitializeWindow({1280, 1000})) {
        return -1;
    }

    while (!glfwWindowShouldClose(pWindow)) {
        glfwPollEvents();
        TitleFps();
    }

    TerminateWindow();

    return 0;
}