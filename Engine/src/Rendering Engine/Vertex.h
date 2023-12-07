#ifndef Vertex_H
#define Vertex_H

namespace Engine
{
	struct Position
	{
		float x, y, z;
	};

	struct Color
	{
		float red, green, blue, alpha;
	};

	struct Vertex
	{

		Position position;
		Color color;

		Vertex();
		Vertex(Position position, Color color);

	};
}

#endif // !Vertex_H
