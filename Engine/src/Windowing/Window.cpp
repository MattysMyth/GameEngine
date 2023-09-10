#include "pch.h"
#include "Window.h"

Engine::KeyInput::KeyInput(Engine::Window* window)
{
    glfwSetKeyCallback(window->GLFWinstance, KeyInput::callback);

    keys.insert({ GLFW_KEY_UNKNOWN, false });
    for (int i = 32; i <= 348; i++)
    {
        keys.insert( {i, false} );
    }
}

Engine::KeyInput::~KeyInput()
{

}

bool Engine::KeyInput::isPressed(int key) 
{
    bool result = false;

    std::map<int, bool>::iterator iterator = keys.find(key);
    if (iterator != keys.end()) 
    {
        result = keys[key];
    }

    return result;
}

void Engine::KeyInput::setIsKeyDown(int key, bool isDown) 
{
    std::map<int, bool>::iterator iterator = keys.find(key);
    if (iterator != keys.end()) {
        keys[key] = isDown;
    }
}

void Engine::KeyInput::callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    Engine::Window* instance = static_cast<Engine::Window*>(glfwGetWindowUserPointer(window));
    instance->input->setIsKeyDown(key, action != GLFW_RELEASE);
}

Engine::Window::Window()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWmonitor* monitorWindow = NULL;
    if (!m_windowedMode)
    {
        monitorWindow = glfwGetPrimaryMonitor();
        const GLFWvidmode* monitorMode = glfwGetVideoMode(monitorWindow);
        m_SCREEN_WIDTH = monitorMode->width;
        m_SCREEN_HEIGHT = monitorMode->height;
    }

    // Initialise a window, throw an error if window failed to initialise
    GLFWinstance = glfwCreateWindow(m_SCREEN_WIDTH, m_SCREEN_HEIGHT, "Window Title", monitorWindow, NULL);
    if (GLFWinstance == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(GLFWinstance);

    glfwSetWindowUserPointer(GLFWinstance, this);

    glfwSetFramebufferSizeCallback(GLFWinstance, framebuffer_size_callback);

    input = new KeyInput(this);
}

Engine::Window::~Window()
{

}

void Engine::Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}