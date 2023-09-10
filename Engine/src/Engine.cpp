#include "pch.h"
#include "Engine.h"

Engine::Engine::Engine()
{
	window = new Window();
    
    // Initialise GLAD, throw an error if GLAD failed to initialise
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }

    renderer = new Renderer();
}

Engine::Engine::~Engine()
{
	delete window;
    delete renderer;

	window = nullptr;
    renderer = nullptr;
}

void Engine::Engine::draw()
{
    renderer->render(&entities);

    // Swap the buffers
    glfwSwapBuffers(window->GLFWinstance);

    // Poll and process events
    glfwPollEvents();
}

void Engine::Engine::instantiateEntity(Entity* entity)
{
    entities.insert(entity);
    renderer->updateRenderer(&entities);
}

void Engine::Engine::deleteEntity(Entity* entity)
{
    entities.erase(entity);
    renderer->updateRenderer(&entities);
}

bool Engine::Engine::isKeyPressed(int key)
{
    return window->input->isPressed(key);
}