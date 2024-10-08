#pragma once

#include <memory>
#include "renderer.h"
#include <imgui.h>

class Application {
public:
    Application();
    ~Application();

    void run();

private:
    void update();
    void render();

    std::unique_ptr<Renderer> m_renderer;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
};