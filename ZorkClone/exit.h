#pragma once

#include <string>
#include <utility> // Para los pairs

#include "entity.h"
#include "room.h"
#include "item.h"

class Exit : public Entity{

public:
	Exit(string firstdir_name, string seconddir_name, Room* firstdir_room, Room* seconddir_room, string exitType, Item* key);
	Exit(string firstdir_name, string seconddir_name, Room* firstdir_room, Room* seconddir_room, string exitType); // sin llave (=> camino abierto)

	// Devuelve la direcci�n y sala opuestas al room pasado (se presupone que el room EST� en alg�n lado del exit)
	pair <string, Room*> getOppositeRoomData(Room* room);

private:

	string otherdir_name;
	Room* firstdir_room;
	Room* seconddir_room;

	Item* key; // si = null, significa que el camino est� abierto
};

