#pragma once
#include "Organism.h"
#include "Random.h"

namespace animals{
	class Animal
		:public Organism
	{
	public:
		virtual void cos() = 0;
		virtual void action(Container *world_organisms, Organism* **organisms_array); // Przesuwa organizm na losowe pole
		virtual void collision(Container *world_organisms, Organism* **organisms_array, int move_x, int move_y); // Walka lub kolizja
		virtual int fight(Container *world_organisms, Organism * **organisms_array, int move_x, int move_y);
	private:
		virtual int reproduce(Container *world_organisms, Organism* **organisms_array, int pos_x, int pos_y) = 0;
	};
}