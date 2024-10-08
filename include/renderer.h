#pragma once

class Renderer {
public:
  Renderer();
  ~Renderer();

  void beginFrame();
  void endFrame();

private:
  void init();
  void cleanup();
};