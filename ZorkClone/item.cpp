#include "item.h"

// Declaraci�n de Item. message = "" indica que no hay texto que leer
Item::Item(string name, string description, bool pickable, string message) : Entity (name, description)
{
	type = ITEM;

	this->pickable = pickable;
	this->message = message;
}

// Versi�n reducida que directamente pone el mensaje vac�o
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
