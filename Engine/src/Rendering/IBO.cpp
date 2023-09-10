#include "pch.h"
#include "IBO.h"

Engine::IBO::IBO()
{
	glGenBuffers(1, &id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
	glBufferData(
		GL_ELEMENT_ARRAY_BUFFER,
		0,
		NULL,
		GL_STATIC_DRAW
	);
}

Engine::IBO::IBO(std::vector<unsigned int> indices)
{
	glGenBuffers(1, &id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
	glBufferData(
		GL_ELEMENT_ARRAY_BUFFER,
		sizeof(unsigned int) * indices.size(),
		static_cast<void*>(indices.data()),
		GL_STATIC_DRAW
	);
}

Engine::IBO::~IBO()
{
	glDeleteBuffers(1, &id);
}

void Engine::IBO::update(std::vector<unsigned int> indices)
{
	glBufferData(
		GL_ELEMENT_ARRAY_BUFFER,
		sizeof(unsigned int) * indices.size(),
		static_cast<void*>(indices.data()),
		GL_STATIC_DRAW
	);
}

void Engine::IBO::bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

void Engine::IBO::unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

unsigned int Engine::IBO::getID()
{
	return id;
}