#include <iostream>

#include "room.h"

using namespace std;

Room::Room(string name, string description) : Entity(name, description) { // Aqu� reaprovechamos la definici�n de Entity

	type = ROOM;
}

void Room::look() { // PODR�A ESTAR (LO 1ERO) EN ENTITY?

	cout << endl << getname() << endl;
	cout << getdescription() << endl;

	// Aqu� habr� que mostrar items, salidas... cuando est�n
}
