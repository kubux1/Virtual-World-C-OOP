#pragma once
#include "Animal.h"
#include "Random.h"
#include "Container.h"
#include "myException.h"

namespace animals{
class Wolf
	: public Animal
{
public:
	void cos()override {};
	Wolf(World &organism_world,Container *world_organisms,Organism* **organisms_array,bool born=0, int parent_pos_x=0,int parent_pos_y=0);
	Wolf(World &organism_world, Container *world_organisms, Organism* **organisms_array, int strength, int initiative, int age, string name, int posX, int posY);
	int reproduce(Container *world_organisms, Organism* **organisms_array, int pos_x, int pos_y);
};
}