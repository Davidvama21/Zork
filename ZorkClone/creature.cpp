#include "creature.h"

Creature::Creature(string name, string description, Room * location) : Entity(name, description)
{
	type = CREATURE;
	this->location = location;
}

// Devuelve un puntero a la sala en la que está actualmente la criatura
Room* Creature::getRoom(){

	return location;
}

void Creature::changeRoom(Room * new_room)
{
	location = new_room;
}
