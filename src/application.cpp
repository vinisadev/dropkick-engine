#include "application.h"
#include <stdexcept>

Application::Application() : m_renderer(std::make_unique<Renderer>()) {}

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
  // TODO: Implement update logic
}

void Application::render() {
  ImGui::Begin("Dropkick Console!");
  ImGui::Text("Welcome to the Dropkick Engine!");
  if (ImGui::Button("Click me!")) {
    // TODO: Handle button click
  }
  ImGui::End();
}