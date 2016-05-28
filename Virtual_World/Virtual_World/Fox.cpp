#include "Fox.h"
using namespace std;

animals::Fox::Fox(World &organism_world, Container *world_organisms, Organism* **organisms_array, bool born, int parent_pos_x, int parent_pos_y) {
	Random randomNumber;
	myException notBorn;
	int posX, posY;
	this->setWorld(organism_world);
	if (born == false) { // Losowanie pozycji i sprawdzanie czy nie jest juz zajeta dla nie urodzonego organizmu
		while (true) {
			posX = randomNumber.Rand_pos_x(this->getWeight());
			posY = randomNumber.Rand_pos_y(this->getHeight());
			if (organisms_array[posX][posY] == nullptr) {
				Organism::setOrganism(3, 7, 1, "Fox", posX, posY, organism_world);
				world_organisms->insert_element(this);
				organisms_array[posX][posY] = this;
				break;
			}
		}
	}
	
	else { // -||- dla urodzonego organizmu
		posX = parent_pos_x + randomNumber.Rand_move_x();
		posY = parent_pos_y + randomNumber.Rand_move_y();
		Organism::setOrganism(3, 7, 1, "Fox", posX, posY, organism_world);
		if ((posX != parent_pos_x || posY != parent_pos_y) && posX >= 0 && posX <this->getWeight() && posY >= 0 && posY < this->getHeight()) {
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

animals::Fox::Fox(World &organism_world, Container *world_organisms, Organism* **organisms_array, int strength, int initiative, int age, string name, int posX, int posY) {
	Organism::setOrganism(strength, initiative, age, name, posX, posY, organism_world);
	world_organisms->insert_element(this);
	organisms_array[posX][posY] = this;
}

int animals::Fox::reproduce(Container *world_organisms, Organism* **organisms_array, int parentPosX, int parentPosY) {
	new Fox(*(this->getOrganismWorld()), world_organisms, organisms_array, true, parentPosX, parentPosY);
	return 0;
}

int animals::Fox::fight(Container *world_organisms, Organism* **organisms_array, int moveX, int moveY) {
	int posX = this->getPosX();
	int posY = this->getPosY();
	if (organisms_array[posX + moveX][posY + moveY]->getStrength() > this->getStrength()) {
		return 0;
	}
	else
	organisms_array[posX + moveX][posY + moveY]->defence(world_organisms, organisms_array, moveX, moveY);
	return 0;
}

