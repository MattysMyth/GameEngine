#include "Triangle1.h"

Triangle1::Triangle1()
{
    Engine::Vertex vert1, vert2, vert3;

    vert1.position.x = -0.5f;
    vert1.position.y = -0.5f;
    vert1.color.red = 1.0f;
    vert1.color.green = 0.0f;
    vert1.color.blue = 0.0f;
    vert1.color.alpha = 1.0f;

    vert2.position.x = -0.5f;
    vert2.position.y = 0.5f;
    vert2.color.red = 1.0f;
    vert2.color.green = 0.0f;
    vert2.color.blue = 0.0f;
    vert2.color.alpha = 1.0f;

    vert3.position.x = 0.5f;
    vert3.position.y = 0.5f;
    vert3.color.red = 1.0f;
    vert3.color.green = 0.0f;
    vert3.color.blue = 0.0f;
    vert3.color.alpha = 1.0f;

    verticies.push_back(vert1);
    verticies.push_back(vert2);
    verticies.push_back(vert3);

    indices.push_back(0);
    indices.push_back(1);
    indices.push_back(2);

}

Triangle1::~Triangle1()
{

}

void Triangle1::update()
{

}