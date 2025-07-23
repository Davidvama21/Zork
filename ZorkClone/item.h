#pragma once

#include "entity.h"

class Item : public Entity
{
public:

	Item(string name, string description, bool pickable, string message);
	Item(string name, string description, bool pickable);

	bool isPickable();

private:

	string message; // vacío ("") si no contiene texto que se pueda leer
	bool pickable; // indica si se puede coger
};

