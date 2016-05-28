#pragma once
#include "Animal.h"
#include "Random.h"
#include "Container.h"

namespace animals {
	class Human
		: public Animal
	{
	public:
		void cos()override {};
		Human(World &organism_world, Container *world_organisms, Organism* **organisms_array);
		Human(World &organism_world, Container *world_organisms, Organism* **organisms_array, int strength, int initiative, int age, string name, int posX, int posY);
		void action(Container *world_organisms, Organism* **organisms_array)override;
		void collision(Container *world_organisms, Organism* **organisms_array, int move_x, int move_y)override;
		int reproduce(Container *world_organisms, Organism* **organisms_array, int pos_x, int pos_y) { return 0; };
		int defence(Container *world_organisms, Organism* **organisms_array, int move_x, int move_y)override;
	};
}
