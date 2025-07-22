#pragma once

#include <string>
#include <queue>

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
	string getname();
	string getdescription();

protected:

	EntityType type;

	string name;
	string description;

	queue <Entity*> contents;
};

