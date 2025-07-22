// ZorkClone.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <sstream> // para el istringstream

#include "world.h"

using namespace std;

// Funciones auxiliares //


void print_words(const vector <string>& words) {

	if (not words.empty()) {

		cout << words[0];

		for (int i = 1; i < words.size(); ++i)
			cout << ' ' << words[i];

		cout << endl;
	}
}

//  Devuelve las palabras separadas del texto que haya por entrada
vector <string> getwords() {

	string input; getline (std::cin, input); // getline en vez de cin directo porque coge entradas vacías tras enter

	stringstream ss(input); // para extraer palabras

	vector <string> words;
	string current_word;

	while (ss >> current_word) {

		words.push_back (current_word);
	}

	return words;
}

int main()
{
    std::cout << "Hello! This is a test prompt for Zork Clone\n";

	World game;

	// Forzamos al principio a que se ejecute la acción "look" para que salga descripción de la 1a área
	vector <string> words(1); words[0] = "look";
	game.parseCommand(words);

	bool run;

	do {

		cout << '>';
		words = getwords(); // del input

		//print_words(words); //  TEST

		run = game.parseCommand(words); //(not words.empty() and words[0] != "quit");

	} while (run);

	std::cout << "Thanks for playing!\n";
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
