#include "pch.h"
#include "VAO.h"

Engine::VAO::VAO()
{
	glGenVertexArrays(1, &id);
	glBindVertexArray(id);
}

Engine::VAO::~VAO()
{
	glDeleteBuffers(1, &id);
}

void Engine::VAO::bind()
{
	glBindVertexArray(id);
}

void Engine::VAO::unbind()
{
	glBindVertexArray(0);
}

unsigned int Engine::VAO::getID()
{
	return id;
}