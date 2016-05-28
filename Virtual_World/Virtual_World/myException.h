#pragma once
#include <string>
#include "World.h"
using namespace std;
class myException {
public:
	void animalNotBorn(World *organismWorld,string name);
};