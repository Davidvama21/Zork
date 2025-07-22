#pragma once

#include "entity.h"


class Room : public Entity
{
public:
	Room(string name, string description);


	void look();
};

