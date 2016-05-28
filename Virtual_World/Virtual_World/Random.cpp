#include "Random.h"

using namespace std;

int Random::Rand_pos_x(int weight) {
	random_device rd;
	uniform_int_distribution<int> dist(0, weight-1);
	int pos_x = dist(rd);
	return pos_x;
}

int Random::Rand_pos_y(int height) {
	random_device rd;
	uniform_int_distribution<int> dist(0, height-1);
	int pos_y = dist(rd);
	return pos_y;
}

int Random::Rand_move_x() {
	random_device rd;
	uniform_int_distribution<int> dist(-1, 1);
	int move_x = dist(rd);
	return move_x;
}

int Random::Rand_move_y() {
	random_device rd;
	uniform_int_distribution<int> dist(-1, 1);
	int move_y = dist(rd);
	return move_y;
}

bool Random::Rand_reproduce() {
	random_device rd;
	uniform_int_distribution<int> dist(0, 100);
	int reproduce_chance = dist(rd);
	if (reproduce_chance <= 3)
		return true;
	else return false;
}

int Random::randOrganism() {
	random_device rd;
	uniform_int_distribution<int> dist(0, 9);
	int randOrg = dist(rd);
	return randOrg;
}

bool Random::turtleMove() {
	random_device rd;
	uniform_int_distribution<int> dist(0, 100);
	int reproduce_chance = dist(rd);
	if (reproduce_chance <= 75)
		return false;
	else return true;
}

bool Random::antelopeEscape() {
	random_device rd;
	uniform_int_distribution<int> dist(0, 50);
	int reproduce_chance = dist(rd);
	if (reproduce_chance <= 50)
		return true;
	else return false;
}