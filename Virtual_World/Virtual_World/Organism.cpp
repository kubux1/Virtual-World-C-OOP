#include "Organism.h"
#include <iostream>
#include "World.h"

void Organism::setOrganism(int strength, int initiative, int age, string name,int posX, int posY,World &organismWorld) {
	this->strength_ = strength;
	this->initiative_ = initiative;
	this->age_ = age;
	this->name_ = name;
	this->posX_ = posX;
	this->posY_ = posY;
	this->organismWorld_ = &organismWorld;
}

int Organism::getStrength() {
	return this->strength_;
}

int Organism::getInitiative() {
	return this->initiative_;
}

int Organism::getAge() {
	return this->age_;
}

string Organism::getName() {
	return this->name_;
}

int Organism::getPosX() {
	return this->posX_;
}

int Organism::getPosY() {
	return this->posY_;
}

World* Organism::getOrganismWorld() {
	return this->organismWorld_;
}

void Organism::increaseStrength() {
	this->strength_ += 3;
	this->organismWorld_->messages->push(this->name_ + " ate a Guarana!");
}

void Organism::increaseAge() {
	this->age_+=1;
}

void Organism::changePosition(int posX, int posY) {
	this->posX_ = posX;
	this->posY_ = posY;
}

void Organism::killOrganism(Organism* deadOrganism) {
	this->organismWorld_->messages->push(deadOrganism->name_ + " is killed by " + this->name_);
	deadOrganism->organismWorld_->tmp = nullptr;
}

int Organism::getHumanMoveX() {
	return this->organismWorld_->humanControl->getMoveX();
}

int Organism::getHumanMoveY() {
	return this->organismWorld_->humanControl->getMoveY();
}
void Organism::setHumanSuperPower() {
	this->organismWorld_->humanControl->setHumanSuperPower();
}
void Organism::decreaseSuperPowerDuration() {
	this->organismWorld_->humanControl->decreaseSuperPowerDuration();
}
void Organism::decreaseSuperPowerCooldown() {
	this->organismWorld_->humanControl->decreaseSuperPowerCooldown();
}
bool Organism::durationPowerStatus() {
	return this->organismWorld_->humanControl->durationPowerStatus();
}
bool Organism::cooldownPowerStatus() {
	return this->organismWorld_->humanControl->cooldownPowerStatus();
}
void Organism::animalBirthMessage() {
	this->organismWorld_->messages->push("A new " + this->name_ + " is born!");
}
void Organism::plantGrowMessage() {
	this->organismWorld_->messages->push("A new " + this->name_ + " has grown!");
}
void Organism::humanPowerkills(string name) {
	this->organismWorld_->messages->push(name + " is killed by human power");
}
int Organism::defence(Container *world_organisms, Organism* **organisms_array, int move_x, int move_y) { // Walka organizmow

   	if (organisms_array[this->posX_ - move_x][this->posY_ - move_y]->strength_ >= this->strength_) { // Ginie organizm broniacy sie
		this->organismWorld_->messages->push(this->name_ + " is killed by "+ organisms_array[this->posX_ - move_x][this->posY_ - move_y]->name_);
		organisms_array[this->posX_ - move_x][this->posY_ - move_y]->posX_ = this->posX_;
		organisms_array[this->posX_ - move_x][this->posY_ - move_y]->posY_ = this->posY_;
		organisms_array[this->posX_][this->posY_] = organisms_array[this->posX_ - move_x][this->posY_ - move_y];
		organisms_array[this->posX_ - move_x][this->posY_ - move_y] = nullptr;
		organismWorld_->worldOrganisms->delete_element(this);
		delete this;
		return 0;
	}
	
	if (organisms_array[this->posX_ - move_x][this->posY_ - move_y]->strength_ < this->strength_) {		// Ginie organizm atakujacy
		this->organismWorld_->messages->push(organisms_array[this->posX_ - move_x][this->posY_ - move_y]->name_ + " is killed by " + this->name_);
		organismWorld_->worldOrganisms->delete_element(organisms_array[this->posX_ - move_x][this->posY_ - move_y]);
		organisms_array[this->posX_ - move_x][this->posY_ - move_y] = nullptr;
		organismWorld_->tmp = nullptr;
		return 0;
	}
}
void Organism::setWorld(World &organismWorld) {
	this->organismWorld_ = &organismWorld;
}
int Organism::getHeight() {
	return this->organismWorld_->getHeight();
}
int Organism::getWeight() {
	return this->organismWorld_->getWeight();
}

Organism::~Organism() {
	this->strength_ = NULL;
	this->initiative_ = NULL;
	this->age_ = NULL;
	this->name_ = "";
	this->posX_ = -1;
	this->posY_ = -1;
	this->organismWorld_ = nullptr;
}

void Organism::operator =(const Organism* org) {
	this->strength_ = org->strength_;
	this->initiative_ = org->initiative_;
	this->age_ = org->age_;
	this->name_ = org->name_;
	this->posX_ = org->posX_;
	this->posY_ = org->posY_;
	this->organismWorld_ = org->organismWorld_;
}

