#include "application.h"
#include <stdexcept>

Application::Application() : m_running(false) {
  init();
}

Application::~Application() {
  cleanup();
}

void Application::init() {
  m_renderer = std::make_unique<Renderer>();
  m_running = true;
}

void Application::run() {
  while (m_running) {
    update();
    render();
  }
}

void Application::update() {
  // TODO: Implement update logic
}

void Application::render() {
  m_renderer->beginFrame();
  // TODO: Implement rendering logic
  m_renderer->endFrame();
}

void Application::cleanup() {
  m_renderer.reset();
}