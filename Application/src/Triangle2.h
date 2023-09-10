#ifndef Triangle2_H
#define Triangle2_H

#include "Entity.h"

class Triangle2 : public Engine::Entity
{
public:
	Triangle2();
	~Triangle2();

	void update() override;

};

#endif // !Triangle2_H