#include <iostream>

#include "room.h"
#include "exit.h"

using namespace std;

Room::Room(string name, string description) : Entity(name, description) { // Aquí reaprovechamos la definición de Entity

	type = ROOM;
}

void Room::look() { // PODRÍA ESTAR (LO 1ERO) EN ENTITY?

	cout << endl << getName() << endl;
	cout << getDescription() << endl;

	// Aquí habrá que mostrar items, salidas... cuando estén

	// Salidas de la sala //

	for (list<Entity*>::iterator it = contents.begin(); it != contents.end(); ++it) {
		Entity* currentEntity = *it;
		if (currentEntity->getType() == EXIT) {

			pair <string, Room*> oppositeRoomData = ( (Exit*)currentEntity )->getOppositeRoomData (this);

			cout << "On the " << oppositeRoomData.first << " there is a " << currentEntity->getDescription() << " leading to the " << oppositeRoomData.second->getName() << endl;
		}
	}

	// Ítems de la sala //

	for (list<Entity*>::iterator it = contents.begin(); it != contents.end(); ++it) {
		Entity* currentEntity = *it;
		if (currentEntity->getType() == ITEM)
			cout << "There is an item here: " << currentEntity->getName() << endl;
	}
}
