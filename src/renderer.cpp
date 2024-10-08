#include "renderer.h"
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>

Renderer::Renderer() {
  init();
}

Renderer::~Renderer() {
  cleanup();
}

void Renderer::init() {
  // TODO: Initialize GLFW, OpenGL, and ImGui
}

void Renderer::beginFrame() {
  // TODO: Implement frame initialization
}

void Renderer::endFrame() {
  // TODO: Implement frame finalization and swapping
}

void Renderer::cleanup() {
  // TODO: Cleanup GLFW, OpenGL, and ImGui
}