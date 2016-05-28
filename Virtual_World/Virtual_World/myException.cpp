#include "myException.h"

void myException::animalNotBorn(World *organismWorld,string name) {
	organismWorld->putMessage(name + " couldn't be born");
}