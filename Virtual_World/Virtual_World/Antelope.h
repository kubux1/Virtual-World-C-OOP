#pragma once
#include "Animal.h"
#include "Random.h"
#include "Container.h"
#include "myException.h"

namespace animals {
	class Antelope
		: public Animal
	{
	public:
		void cos()override {};
		Antelope(World &organism_world, Container *world_organisms, Organism* **organisms_array, bool born = 0, int parent_pos_x = 0, int parent_pos_y = 0);
		Antelope(World &organism_world, Container *world_organisms, Organism* **organisms_array, int strength, int initiative, int age, string name, int posX, int posY);
		void action(Container *world_organisms, Organism* **organisms_array)override;
		int reproduce(Container *world_organisms, Organism* **organisms_array, int pos_x, int pos_y);
		int defence(Container *world_organisms, Organism* **organisms_array, int move_x, int move_y)override;

	};
}