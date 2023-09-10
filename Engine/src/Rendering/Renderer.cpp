#include "pch.h"
#include "Renderer.h"
#include <filesystem>

Engine::Renderer::Renderer()
{
    // Create a Shader Program
    createShader();
    // Initialize a Vertex Array Object
    vao = new VAO();
    // Initialize a Vertex Buffer Object
    vbo = new VBO();
    // Initialize a Index Buffer Object
    ibo = new IBO();
}

Engine::Renderer::~Renderer()
{
    delete vao;
    delete vbo;
    delete ibo;

    vao = nullptr;
    vbo = nullptr;
    ibo = nullptr;
}

bool Engine::Renderer::createShader()
{
    Shader vertexShader("../Engine/src/Shaders/Vertex.shader", ShaderType::VERTEX);

    Shader fragmentShader("../Engine/src/Shaders/Fragment.shader", ShaderType::FRAGMENT);

    // link shaders to a program
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader.getID());
    glAttachShader(shaderProgram, fragmentShader.getID());
    glLinkProgram(shaderProgram);
    glValidateProgram(shaderProgram);

    // check for linking errors
    int success;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (success == GL_FALSE)
    {
        int length;
        glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)alloca(length * sizeof(char));
        glGetProgramInfoLog(shaderProgram, length, &length, message);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << message << std::endl;
    }

    // Delete Shader objects as we've compiled and linked the program
    glDeleteShader(vertexShader.getID());
    glDeleteShader(fragmentShader.getID());

    glUseProgram(shaderProgram);

    matrixID = glGetUniformLocation(shaderProgram, "mvp");

    return true;
}

void Engine::Renderer::updateRenderer(std::set<Entity*>* entities)
{
    std::vector<Vertex> verticies;
    std::vector<unsigned int> indices;
    unsigned int indexOffset = 0;
    for (Entity* entity : *entities)
    {
        for (const Vertex &vertex : entity->verticies)
        {
            verticies.push_back(vertex);
        }
        for (const unsigned int &index : entity->indices)
        {
            indices.push_back(index + indexOffset);
        }
        indexOffset += entity->verticies.size();
    }
    vbo->update(verticies);
    ibo->update(indices);
}

void Engine::Renderer::render(std::set<Entity*>* entities)
{
    // Clear current buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Orthographic view from the camera (Projection)
    glm::mat4 projectionMatrix = glm::ortho(-5.0f, 5.0f, -5.0f, 5.0f, 0.0f, 1.0f);

    // Camera Matrix (View)
    glm::mat4 viewMatrix(1.0f);

    // Per Entity rendering
    unsigned int indiceOffeset = 0;
    for (Entity* entity : *entities)
    {
        // Model Matrix (Model)
        glm::mat4 modelMatrix = glm::mat4(1.0f);

        glm::vec3 transformVector = glm::vec3(entity->transform.position.x, entity->transform.position.y, entity->transform.position.z);
        glm::vec3 rotateVector = glm::vec3(entity->transform.rotation.x, entity->transform.rotation.y, entity->transform.rotation.z);
        glm::vec3 scaleVector = glm::vec3(entity->transform.scale.x, entity->transform.scale.y, entity->transform.scale.z);

        modelMatrix = glm::translate(modelMatrix, transformVector);
        modelMatrix = glm::rotate(modelMatrix, 0.0f, rotateVector); // Rotation needs to be updated to take in angle data
        modelMatrix = glm::scale(modelMatrix, scaleVector);

        // Set Model View Projection matrix on the CPU
        mvp = projectionMatrix * viewMatrix * modelMatrix;

        // Send current mvp matrix to the Shader on the GPU
        glUniformMatrix4fv(matrixID, 1, GL_FALSE, &mvp[0][0]);

        // Draw call
        glDrawElements(GL_TRIANGLES, entity->indices.size(), GL_UNSIGNED_INT, (void*)(indiceOffeset * sizeof(GLfloat)));

        indiceOffeset += entity->indices.size();
    }

}