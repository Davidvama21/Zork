#pragma once

#include <string>
#include <list>

using namespace std;

enum EntityType
{
	ENTITY,
	ROOM,
	EXIT,
	ITEM,
	CREATURE,
	PLAYER
};

class Entity
{
public:
	Entity(string name, string description);
	string getName();
	string getDescription();
	EntityType getType();

	void addElement(Entity* entity);

protected:

	EntityType type;

	string name;
	string description;

	list <Entity*> contents; // Lista para que se respete el orden de elementos al explorarla
};

