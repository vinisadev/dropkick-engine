#pragma once

#include <memory>
#include "renderer.h"

class Application {
public:
  Application();
  ~Application();

  void run();

private:
  void init();
  void update();
  void render();
  void cleanup();

  std::unique_ptr<Renderer> m_renderer;
  bool m_running;
};