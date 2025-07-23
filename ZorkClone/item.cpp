#include "item.h"

// Declaraci�n de Item. message = "" indica que no hay texto que leer
Item::Item(string name, string description, string message) : Entity (name, description)
{
	type = ITEM;
	this->message = message;
}

// Versi�n reducida que directamente pone el mensaje vac�o
Item::Item(string name, string description) : Entity (name, description)
{
	type = ITEM;
	message = "";
}
