// Virtual_World.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <fstream>
#include "World.h"

using namespace std;

int main()
{ 
	int height = 0, weight = 0;

	while (true) {
		cout << "Map height: ";
		cin >> height;
		cout << "Map weight: ";
		cin >> weight;
		if (weight + height > 15)
			break;
	}

	World *letsPlay = new World(height,weight);

	while (letsPlay->getGameStatus() == true) {
		letsPlay->makeTour();
	}
	
  return 0;
}

