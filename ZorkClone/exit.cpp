#include "exit.h"

// key = null => camino abierto
// Reaprovechamos name y description de la superclase para contener firstdir_name y exitType, respectivamente (exitType será el objeto de salida: ej. Puerta)
Exit::Exit(string firstdir_name, string seconddir_name, Room * firstdir_room, Room * seconddir_room, string exitType, Item * key) : Entity (firstdir_name, exitType)
{
	type = EXIT;

	otherdir_name = seconddir_name;
	this->firstdir_room = firstdir_room;
	this->seconddir_room = seconddir_room;
	this->key = key;
}

// Sin key (= null)
Exit::Exit(string firstdir_name, string seconddir_name, Room * firstdir_room, Room * seconddir_room, string exitType) : Entity(firstdir_name, exitType)
{
	type = EXIT;

	otherdir_name = seconddir_name;
	this->firstdir_room = firstdir_room;
	this->seconddir_room = seconddir_room;
	key = NULL;
}

// Devuelve la dirección y sala opuestas al room pasado (se presupone que el room ESTÁ en algún lado del exit)
pair<string, Room*> Exit::getOppositeRoomData(Room * room)
{
	if (room == firstdir_room)
		return pair<string, Room*>(otherdir_name, seconddir_room);

	else
		return pair<string, Room*>(name, firstdir_room);
}
