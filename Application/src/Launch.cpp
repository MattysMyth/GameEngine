#include <Engine.h>
#include "Triangle1.h"
#include "Triangle2.h"

int main()
{
	Engine::Engine engine;

	Triangle1* triangle1 = new Triangle1();
	Triangle2* triangle2 = new Triangle2();

	engine.instantiateEntity(triangle1);
	engine.instantiateEntity(triangle2);

	double currentTime = 0.0;
	double lastTime = glfwGetTime();
	double deltaTime = 0.0;

	while (true)
	{
		currentTime = glfwGetTime();
		deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		engine.draw();
		if (engine.isKeyPressed(KEY_ESCAPE))
		{
			break;
		}
		if (engine.isKeyPressed(KEY_RIGHT))
		{
			triangle1->transform.position.x += (5.0f * deltaTime);
		}

	}

	return 0;
}