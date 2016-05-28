#include "Wolf.h"
using namespace std;

animals::Wolf::Wolf(World &organism_world,Container *world_organisms, Organism* **organisms_array, bool born, int parent_pos_x, int parent_pos_y) {
	Random randomNumber;
	myException notBorn;
	int posX, posY;
	this->setWorld(organism_world);
	if (born == false) {  	// Losowanie pozycji i sprawdzanie czy nie jest juz zajeta dla nie urodzonego organizmu
		while (true) {
			posX = randomNumber.Rand_pos_x(this->getWeight());
			posY = randomNumber.Rand_pos_y(this->getHeight());
			if (organisms_array[posX][posY] == nullptr) {
				Organism::setOrganism(9, 5, 1, "Wolf", posX, posY, organism_world);
				world_organisms->insert_element(this);
				organisms_array[posX][posY] = this;
				break;
			}
		}
	}

	
	else { // -||- dla urodzonego organizmu
			posX = parent_pos_x + randomNumber.Rand_move_x();
			posY = parent_pos_y + randomNumber.Rand_move_y();
			Organism::setOrganism(9, 5, 1, "Wolf", posX, posY, organism_world);
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

animals::Wolf::Wolf(World &organism_world, Container *world_organisms, Organism* **organisms_array, int strength, int initiative, int age, string name, int posX, int posY) {
	Organism::setOrganism(strength, initiative,age, name, posX, posY, organism_world);
	world_organisms->insert_element(this);
	organisms_array[posX][posY] = this;
}


int animals::Wolf::reproduce(Container *world_organisms, Organism* **organisms_array, int parentPosX, int parentPosY) {
	new Wolf(*(this->getOrganismWorld()), world_organisms, organisms_array, true, parentPosX, parentPosY);

	return 0;
}


