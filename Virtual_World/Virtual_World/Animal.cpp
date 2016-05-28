#include "Animal.h"

void animals::Animal::action(Container *world_organisms, Organism* **organisms_array) {
	Random randomNumber;
	int moveX = 0, moveY = 0;
	int posX = this->getPosX();
	int posY = this->getPosY();

	this->increaseAge();
	while (true) {
		moveX = randomNumber.Rand_move_x();
		moveY = randomNumber.Rand_move_y();
		if (moveX != 0 || moveY != 0) {
			if ((posX + moveX) >= 0 && (posX + moveX) < this->getWeight() && (posY + moveY) >= 0 && (posY + moveY) < this->getHeight()) // Sprawdzanie czy nie wyjdzie poza mape
				break;
		}
	}
	if (organisms_array[posX + moveX][posY + moveY] == nullptr) {
		organisms_array[posX + moveX][posY + moveY] = this;
		organisms_array[posX][posY] = nullptr;
		this->changePosition(posX + moveX, posY + moveY);
	}
	else
		collision(world_organisms, organisms_array, moveX, moveY);
}

void animals::Animal::collision(Container *world_organisms, Organism* **organisms_array, int moveX, int moveY) {
	int posX = this->getPosX();
	int posY = this->getPosY();
	
	if (organisms_array[posX + moveX][posY + moveY]->getName() == this->getName()) { // Jesli te same organizmy to rodzi sie nowy organizm
		reproduce(world_organisms, organisms_array, posX, posY);
	}
	
	else { // Jesli inne to nastepuje walka
		fight(world_organisms, organisms_array, moveX, moveY);
	}
}

int animals::Animal::fight(Container *world_organisms, Organism* **organisms_array, int moveX, int moveY) {
		int posX = this->getPosX();
		int posY = this->getPosY();
		organisms_array[posX + moveX][posY + moveY]->defence(world_organisms, organisms_array, moveX, moveY);
		return 0;
	}

