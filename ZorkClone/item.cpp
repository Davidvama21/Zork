#include "item.h"

// Declaración de Item. message = "" indica que no hay texto que leer
Item::Item(string name, string description, bool pickable, string message) : Entity (name, description)
{
	type = ITEM;

	this->pickable = pickable;
	this->message = message;
}

// Versión reducida que directamente pone el mensaje vacío
Item::Item(string name, string description, bool pickable) : Entity (name, description)
{
	type = ITEM;

	this->pickable = pickable;
	message = "";
}

bool Item::isPickable()
{
	return pickable;
}
