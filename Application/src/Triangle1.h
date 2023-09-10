#ifndef Triangle1_H
#define Triangle1_H

#include "Entity.h"

class Triangle1 : public Engine::Entity
{
public:
	Triangle1();
	~Triangle1();

	void update() override;

};

#endif // !Triangle1_H