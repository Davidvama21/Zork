#include <iostream>

#include "room.h"
#include "exit.h"

using namespace std;

Room::Room(string name, string description) : Entity(name, description) { // Aqu� reaprovechamos la definici�n de Entity

	type = ROOM;
}

void Room::look() { // PODR�A ESTAR (LO 1ERO) EN ENTITY?

	cout << endl << getName() << endl;
	cout << getDescription() << endl;

	// Aqu� habr� que mostrar items, salidas... cuando est�n

	// Salidas de la sala //

	for (list<Entity*>::iterator it = contents.begin(); it != contents.end(); ++it) {
		Entity* currentEntity = *it;
		if (currentEntity->getType() == EXIT) {

			pair <string, Room*> oppositeRoomData = ( (Exit*)currentEntity )->getOppositeRoomData (this);

			cout << "On the " << oppositeRoomData.first << " there is a " << currentEntity->getDescription() << " leading to the " << oppositeRoomData.second->getName() << endl;
		}
	}

	// �tems de la sala //

	for (list<Entity*>::iterator it = contents.begin(); it != contents.end(); ++it) {
		Entity* currentEntity = *it;
		if (currentEntity->getType() == ITEM)
			cout << "There is an item here: " << currentEntity->getName() << endl;
	}
}
