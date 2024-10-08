#include "application.h"
#include <imgui.h>
#include <iostream>

Application::Application() : m_renderer(std::make_unique<Renderer>(true)) {}

Application::~Application() = default;

void Application::run() {
    while (!m_renderer->shouldClose()) {
        m_renderer->beginFrame();
        update();
        render();
        m_renderer->endFrame();
    }
}

void Application::update() {
    // TODO: Implement game logic updates
}

void Application::render() {
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar;
    
    // Create a full-screen window
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(static_cast<float>(m_renderer->getWidth()), static_cast<float>(m_renderer->getHeight())));
    
    ImGui::Begin("Main Window", nullptr, window_flags);

    if (ImGui::BeginMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            if (ImGui::MenuItem("Exit")) {
                // TODO: Implement exit functionality
            }
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }

    ImGui::Text("Welcome to the Dropkick Game Engine!");
    ImGui::Text("Window size: %dx%d", m_renderer->getWidth(), m_renderer->getHeight());

    static float f = 0.0f;
    static int counter = 0;

    ImGui::SliderFloat("Float", &f, 0.0f, 1.0f);
    ImGui::ColorEdit3("Clear Color", (float*)&clear_color);

    if (ImGui::Button("Button")) {
        counter++;
    }
    ImGui::SameLine();
    ImGui::Text("counter = %d", counter);

    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

    ImGui::End();
}