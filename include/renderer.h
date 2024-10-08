#pragma once

#include <GLFW/glfw3.h>
#include <imgui.h>
#include <string>

class Renderer {
public:
  Renderer(int width = 800, int height = 600, const std::string& title = "Dropkick Engine");
  ~Renderer();

  void beginFrame();
  void endFrame();
  bool shouldClose() const;

private:
  void init();
  void cleanup();

  GLFWwindow* m_window;
  int m_width;
  int m_height;
  std::string m_title;
};