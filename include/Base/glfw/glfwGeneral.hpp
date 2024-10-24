#pragma once

#ifndef _GLFW_GENERAL_H
#define _GLFW_GENERAL_H

#include "Base/vk/vkBase.hpp"
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
GLFWwindow *pWindow;
GLFWmonitor *pMonitor;

const char *windowTitle = "EasyVulkan";

bool InitializeWindow(VkExtent2D size, bool fullScreen = false, bool isResizable = true, bool limitFrameRate = false) {
    auto logger = Loggers::getLogger("glfwGeneral");

    if (!glfwInit()) {
        LOG_ERROR(logger, "Error : Failed to initialize GLFW");
        return false;
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    glfwWindowHint(GLFW_RESIZABLE, isResizable ? GLFW_TRUE : GLFW_FALSE);

    pMonitor = glfwGetPrimaryMonitor();
    const GLFWvidmode *pMode = glfwGetVideoMode(pMonitor);

    pWindow = fullScreen ? glfwCreateWindow(pMode->width, pMode->height, windowTitle, pMonitor, nullptr)
                         : glfwCreateWindow(size.width, size.height, windowTitle, nullptr, nullptr);

    if (!pWindow) {
        LOG_ERROR(logger, "Error : Failed to create GLFW window");
        glfwTerminate();
        return false;
    }

    return true;
}

void TerminateWindow() {
    glfwTerminate();
    return;
}

double time0 = glfwGetTime();
double time1 = 0.0f;
double dt = 0.0f;
int dframe = -1;

void TitleFps() {
    // static double time0 = glfwGetTime();
    // static double time1;
    // static double dt;
    // static int dframe = -1;
    static std::stringstream info;
    time1 = glfwGetTime();
    dframe++;
    if ((dt = time1 - time0) >= 1) {
        info.precision(1);
        info << windowTitle << "    " << std::fixed << dframe / dt << " FPS";
        glfwSetWindowTitle(pWindow, info.str().c_str());
        info.str(""); // 别忘了在设置完窗口标题后清空所用的stringstream
        time0 = time1;
        dframe = 0;
    }
}

#endif