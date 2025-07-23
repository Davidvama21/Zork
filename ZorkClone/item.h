#pragma once

#include "entity.h"

class Item : public Entity
{
public:

	Item(string name, string description, string message);
	Item(string name, string description);

private:

	string message; // vacío ("") si no contiene texto que se pueda leer

};

