#include "item.h"

// Declaración de Item. message = "" indica que no hay texto que leer
Item::Item(string name, string description, string message) : Entity (name, description)
{
	type = ITEM;
	this->message = message;
}

// Versión reducida que directamente pone el mensaje vacío
Item::Item(string name, string description) : Entity (name, description)
{
	type = ITEM;
	message = "";
}
