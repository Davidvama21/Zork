#include <iostream>

#include "room.h"

using namespace std;

Room::Room(string name, string description) : Entity(name, description) { // Aquí reaprovechamos la definición de Entity

	type = ROOM;
}

void Room::look() { // PODRÍA ESTAR (LO 1ERO) EN ENTITY?

	cout << endl << getname() << endl;
	cout << getdescription() << endl;

	// Aquí habrá que mostrar items, salidas... cuando estén
}
