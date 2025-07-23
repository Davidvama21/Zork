#pragma once

#include "entity.h"


class Room : public Entity
{
public:
	Room(string name, string description);

	void look();

	// Devuelve el puntero al room siguiente si sigues la dirección direction (de brújula);
	// en caso de no existir devuelve null
	Room* getNextRoom (string direction);
};

