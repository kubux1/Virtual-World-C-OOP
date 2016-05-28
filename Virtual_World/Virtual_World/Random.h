#pragma once
#include <random>
class Random
{
public:
	int randOrganism();
	int Rand_pos_x(int weight);
	int Rand_pos_y(int height);
	int Rand_move_x();
	int Rand_move_y();
	bool Rand_reproduce();
	bool turtleMove();
	bool antelopeEscape();
};