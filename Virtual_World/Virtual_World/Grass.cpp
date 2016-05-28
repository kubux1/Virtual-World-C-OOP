#include "Grass.h"
using namespace std;

plants::Grass::Grass(World &organism_world,Container *world_organisms, Organism* **organisms_array, bool born, int parent_pos_x, int parent_pos_y) {
	Random randomNumber;
	int posX, posY;
	this->setWorld(organism_world);
	// Losowanie pozycji i sprawdzanie czy nie jest juz zajeta dla nie urodzonego organizmu
	if (born == false) {
		while (true) {
			posX = randomNumber.Rand_pos_x(this->getWeight());
			posY = randomNumber.Rand_pos_y(this->getHeight());
			if (organisms_array[posX][posY] == nullptr) {
				Organism::setOrganism(0, 0, 1, "Grass", posX, posY, organism_world);
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
		if ((posX != parent_pos_x || posY != parent_pos_y) && posX >= 0 && posX < this->getWeight() && posY >= 0 && posY < this->getHeight()) {
			if (organisms_array[posX][posY] == nullptr) {
				organisms_array[posX][posY] = this;
				Organism::setOrganism(0, 0, 1, "Grass", posX, posY, organism_world);
				world_organisms->insert_element(this);
				this->plantGrowMessage();
			}
		}
	}
}

plants::Grass::Grass(World &organism_world, Container *world_organisms, Organism* **organisms_array, int strength, int initiative, int age, string name, int posX, int posY) {
	Organism::setOrganism(strength, initiative, age, name, posX, posY, organism_world);
	world_organisms->insert_element(this);
	organisms_array[posX][posY] = this;
}
	void plants::Grass::action(Container *world_organisms, Organism* **organisms_array) {
		Random random_number;
		if (random_number.Rand_reproduce() == true) { // Jesli szansa na rozmanzanie sie powiodla to sie rozmnaza
			new Grass(*this->getOrganismWorld(),world_organisms,organisms_array, true, this->getPosX(), this->getPosY());
			
		}
	}
	void plants::Grass::collision(Container *world_organisms, Organism* **organisms_array, int move_x, int move_y) {}