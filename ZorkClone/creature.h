#pragma once

#include "entity.h"
#include "room.h"

class Creature : public Entity
{
public:

	Creature (string name, string description, Room* location);

	Room* getRoom();

protected:

	Room* location;

};

