#ifndef Renderer_h
#define Renderer_h

#include "pch.h"
#include "Shaders/Shader.h"
#include "VAO.h"
#include "VBO.h"
#include "IBO.h"
#include "Entity.h"

namespace Engine
{
	struct Renderer
	{
		Renderer();
		~Renderer();

		bool createShader();

		void updateRenderer(std::set<Entity*>* entities);

		void render(std::set<Entity*>* entities);

	private:

		VAO* vao;

		VBO* vbo;

		IBO* ibo;

		glm::mat4 mvp;

		unsigned int matrixID;

	};
}

#endif // !Renderer_h
