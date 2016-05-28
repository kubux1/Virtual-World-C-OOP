#pragma once
#include "Plant.h"
#include "Random.h"
namespace plants {
	class Dandelion
		: public Plant
	{

	public:
		Dandelion(World &organism_world, Container *world_organisms, Organism* **organisms_array, bool born = 0, int parent_pos_x = 0, int parent_pos_y = 0);
		Dandelion(World &organism_world, Container *world_organisms, Organism* **organisms_array, int strength, int initiative, int age, string name, int posX, int posY);
		void action(Container *world_organisms, Organism* **organisms_array);
		void collision(Container *world_organisms, Organism* **organisms_array, int move_x, int move_y);

	};
}

