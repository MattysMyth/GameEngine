#include "pch.h"
#include "Shader.h"

Engine::Shader::Shader(const std::string& filePath, Engine::ShaderType shaderType)
{
    m_Type = shaderType;
    m_SourceString = parseShader(filePath);
    m_SourceCode = m_SourceString.c_str();

    switch (m_Type)
    {
    case Engine::ShaderType::VERTEX:
        m_ShaderID = glCreateShader(GL_VERTEX_SHADER);
        break;
    case Engine::ShaderType::FRAGMENT:
        m_ShaderID = glCreateShader(GL_FRAGMENT_SHADER);
        break;
    default:
        break;
    }
    
    glShaderSource(m_ShaderID, 1, &m_SourceCode, nullptr);
    glCompileShader(m_ShaderID);

    // check for shader compile errors
    int success;
    glGetShaderiv(m_ShaderID, GL_COMPILE_STATUS, &success);
    if (success == GL_FALSE)
    {
        int length;
        glGetShaderiv(m_ShaderID, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(m_ShaderID, length, &length, message);
        std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << message << std::endl;
    }

}

Engine::Shader::~Shader()
{

}

std::string Engine::Shader::parseShader(const std::string& filePath)
{
    std::ifstream stream(filePath);

    std::stringstream ss;
    std::string line;
    while (std::getline(stream, line))
    {
        ss << line << '\n';
    }

    return ss.str();
}

unsigned int Engine::Shader::getID()
{
    return m_ShaderID;
}

void Engine::Shader::bind()
{
    glUseProgram(m_ShaderID);
}

void Engine::Shader::unbind()
{
    glUseProgram(0);
}

void Engine::Shader::uploadUniformInt(const std::string& name, int value)
{

}

void Engine::Shader::uploadUniformFloat(const std::string& name, float value)
{

}

void Engine::Shader::uploadUniformFloat2(const std::string& name, const glm::vec2& value)
{

}

void Engine::Shader::uploadUniformFloat3(const std::string& name, const glm::vec3& value)
{

}

void Engine::Shader::uploadUniformFloat4(const std::string& name, const glm::vec4& value)
{

}

void Engine::Shader::uploadUniformMat3(const std::string& name, const glm::mat3& matrix)
{

}

void Engine::Shader::uploadUniformMat4(const std::string& name, const glm::mat4& matrix)
{

}