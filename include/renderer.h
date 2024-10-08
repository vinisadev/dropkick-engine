#pragma once

#include <GLFW/glfw3.h>
#include <imgui.h>
#include <string>

class Renderer {
public:
    Renderer(bool fullscreen = true, int width = 800, int height = 600, const std::string& title = "Game Engine");
    ~Renderer();

    void beginFrame();
    void endFrame();
    bool shouldClose() const;

    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }
    void setClearColor(const ImVec4& color);

private:
    void init();
    void cleanup();

    GLFWwindow* m_window;
    int m_width;
    int m_height;
    std::string m_title;
    bool m_fullscreen;
    ImVec4 m_clearColor;
};