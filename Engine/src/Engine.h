#ifndef Engine_H
#define Engine_H

#include "Rendering/Renderer.h"
#include "Windowing/Window.h"
#include "Entity.h"

namespace Engine
{
	struct Engine
	{
		Engine();
		~Engine();

		void draw();

		void instantiateEntity(Entity* entity);

		void deleteEntity(Entity* entity);

		bool isKeyPressed(int key);

	private:

		Window* window;
		
		Renderer* renderer;

		std::set<Entity*> entities;

	};
}

#endif // !Engine_H
