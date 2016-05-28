#include "Turtle.h"
using namespace std;

animals::Turtle::Turtle(World &organism_world, Container *world_organisms, Organism* **organisms_array, bool born, int parent_pos_x, int parent_pos_y) {
	Random randomNumber;
	myException notBorn;
	int posX, posY;
	this->setWorld(organism_world);
	// Losowanie pozycji i sprawdzanie czy nie jest juz zajeta dla nie urodzonego organizmu
	if (born == false) {
		while (true) {
			posX = randomNumber.Rand_pos_x(this->getWeight());
			posY = randomNumber.Rand_pos_y(this->getHeight());
			if (organisms_array[posX][posY] == nullptr) {
				Organism::setOrganism(2, 1, 1, "Turtle", posX, posY, organism_world);
				world_organisms->insert_element(this);
				organisms_array[posX][posY] = this;
				break;
			}
		}
	}
	// Dla urodzonego organizmu
	else {
		posX = parent_pos_x + randomNumber.Rand_move_x();
		posY = parent_pos_y + randomNumber.Rand_move_y();
		Organism::setOrganism(2, 1, 1, "Turtle", posX, posY, organism_world);
		if ((posX != parent_pos_x || posY != parent_pos_y) && posX >= 0 && posX < this->getWeight() && posY >= 0 && posY < this->getHeight()) {
			try {
				if (organisms_array[posX][posY] == nullptr) {
					organisms_array[posX][posY] = this;
					world_organisms->insert_element(this);
					this->animalBirthMessage();
				}
				else throw notBorn;
			}
			catch (myException notBornAnimal) {
				notBornAnimal.animalNotBorn(this->getOrganismWorld(), this->getName());
			}
		}
	}
}

animals::Turtle::Turtle(World &organism_world, Container *world_organisms, Organism* **organisms_array, int strength, int initiative, int age, string name, int posX, int posY) {
	Organism::setOrganism(strength, initiative, age, name, posX, posY, organism_world);
	world_organisms->insert_element(this);
	organisms_array[posX][posY] = this;
}


void animals::Turtle::action(Container *world_organisms, Organism* **organisms_array) {
	Random randomNumber;
	int moveX = 0, moveY = 0;
	int posX = this->getPosX();
	int posY = this->getPosY();

	this->increaseAge();
	if (randomNumber.turtleMove() == true) {
		while (true) {
			moveX = randomNumber.Rand_move_x();
			moveY = randomNumber.Rand_move_y();
			if (moveX != 0 || moveY != 0) {
				if ((posX + moveX) >= 0 && (posX + moveX) < this->getWeight() && (posY + moveY) >= 0 && (posY + moveY) <this->getHeight()) // Sprawdzanie czy nie wyjdzie poza mape
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
}


int animals::Turtle::reproduce(Container *world_organisms, Organism* **organisms_array, int parentPosX, int parentPosY) {
	new Turtle(*(this->getOrganismWorld()), world_organisms, organisms_array, true, parentPosX, parentPosY);
	return 0;
}

int animals::Turtle::defence(Container *world_organisms, Organism* **organisms_array, int moveX, int moveY) {
	int posX = this->getPosX();
	int posY = this->getPosY();
	if (organisms_array[posX - moveX][posY - moveY]->getStrength() < 5) {
		return 0;
	}
	else this->Organism::defence(world_organisms,organisms_array, moveX, moveY);
	return 0;
}

