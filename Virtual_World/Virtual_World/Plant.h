#pragma once
#include "Organism.h"
namespace plants {
	class Plant
		:public Organism
	{
	public:
		void action(Container *world_organisms, Organism* **organisms_array) = 0; // Proba rozmnozenia 
		void collision(Container *world_organisms, Organism* **organisms_array, int move_x, int move_y) = 0;
	};
}