#include "renderer.h"
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <stdexcept>

Renderer::Renderer(bool fullscreen, int width, int height, const std::string& title)
    : m_width(width), m_height(height), m_title(title), m_window(nullptr), m_fullscreen(fullscreen), 
      m_clearColor(0.45f, 0.55f, 0.60f, 1.00f)
{
    init();
}

void Renderer::init() {
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWmonitor* monitor = m_fullscreen ? glfwGetPrimaryMonitor() : nullptr;
    if (m_fullscreen) {
        const GLFWvidmode* mode = glfwGetVideoMode(monitor);
        m_width = mode->width;
        m_height = mode->height;
    }

    m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), monitor, nullptr);
    if (!m_window) {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }

    glfwMakeContextCurrent(m_window);
    glfwSwapInterval(1); // Enable vsync

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(m_window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    // Set up window resize callback
    glfwSetWindowUserPointer(m_window, this);
    glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height) {
        Renderer* renderer = static_cast<Renderer*>(glfwGetWindowUserPointer(window));
        renderer->m_width = width;
        renderer->m_height = height;
        glViewport(0, 0, width, height);
    });
}

void Renderer::beginFrame() {
    glfwPollEvents();

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    glViewport(0, 0, m_width, m_height);
    glClearColor(m_clearColor.x, m_clearColor.y, m_clearColor.z, m_clearColor.w);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::endFrame() {
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(m_window);
}

bool Renderer::shouldClose() const {
    return glfwWindowShouldClose(m_window);
}

void Renderer::setClearColor(const ImVec4& color) {
    m_clearColor = color;
}

void Renderer::cleanup() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(m_window);
    glfwTerminate();
}

Renderer::~Renderer() {
    cleanup();
}