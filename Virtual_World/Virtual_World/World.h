#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include "Organism.h"
#include "Container.h"
#include "Random.h"
#include "Human_Control.h"
#include "Messages.h"
#include "Human.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Grass.h"
#include "Dandelion.h"
#include "Guarana.h"
#include "Berries.h"

using namespace std;
using namespace plants;
using namespace animals;
class World
{
	friend class Organism;
public:
	World(int height, int weight);
	void fillArray(); // Ustawienie tablicy organizmow na nullptr przy starcie gry
	void makeTour(); // Wykonywanie tury
	void scribeWorld(); // Rysowanie swiata
	bool getGameStatus(); // Sprawdzanie czy nastapil koniec gry
	void putMessage(string statement); // Wstawia komunikat do stosu
	void saveToFile(); // Zapisywanie do pliku
	void readFromFile(); // Odczytywanie z pliku
	int getHeight();
	int getWeight();
	Container* getContainer();
	List_element* getTmp();
	Human_Control *getHumanControl(); 
private:
	Container *worldOrganisms = new Container; 
	List_element* tmp = new List_element;
	Organism* **organismsArray;
	Organism* org;
	Human_Control *humanControl = new Human_Control;
	Stack *messages = new Stack;
	bool gameStatus_;
	int howMany_;
	int height_;
	int weight_;
};

//mt19937
//rand_device