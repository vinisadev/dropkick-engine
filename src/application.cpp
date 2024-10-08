#include "application.h"
#include <imgui.h>
#include <iostream>

Application::Application() : m_renderer(std::make_unique<Renderer>(true)), clear_color(0.45f, 0.55f, 0.60f, 1.00f) {}

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
    m_renderer->setClearColor(clear_color);
}

void Application::render() {
    const float padding = 10.0f;
    const float panelWidth = (m_renderer->getWidth() - padding * 3) / 2;
    const float panelHeight = (m_renderer->getHeight() - padding * 3) / 2;

    // Control Panel (top-left)
    ImGui::SetNextWindowPos(ImVec2(padding, padding));
    ImGui::SetNextWindowSize(ImVec2(panelWidth, panelHeight));
    ImGui::Begin("Control Panel", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize);
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

    // Scene Hierarchy panel (top-right)
    ImGui::SetNextWindowPos(ImVec2(padding * 2 + panelWidth, padding));
    ImGui::SetNextWindowSize(ImVec2(panelWidth, panelHeight));
    ImGui::Begin("Scene Hierarchy", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize);
    ImGui::Text("This panel could show your game objects.");
    // TODO: Implement a tree view of game objects
    ImGui::End();

    // Properties panel (bottom-left)
    ImGui::SetNextWindowPos(ImVec2(padding, padding * 2 + panelHeight));
    ImGui::SetNextWindowSize(ImVec2(panelWidth, panelHeight));
    ImGui::Begin("Properties", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize);
    ImGui::Text("This panel could show properties of selected objects.");
    // TODO: Implement property editing for selected objects
    ImGui::End();

    // Console panel (bottom-right)
    ImGui::SetNextWindowPos(ImVec2(padding * 2 + panelWidth, padding * 2 + panelHeight));
    ImGui::SetNextWindowSize(ImVec2(panelWidth, panelHeight));
    ImGui::Begin("Console", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize);
    ImGui::Text("This panel could show debug and log messages.");
    // TODO: Implement a scrollable console with log messages
    ImGui::End();
}