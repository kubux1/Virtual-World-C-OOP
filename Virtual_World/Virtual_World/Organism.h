#pragma once
#include <exception>
#include "Container.h"
#include "Position.h"
#include "Messages.h"

using namespace std;


class Organism
{
	//typeid
public:
	virtual void action(Container *world_organisms,Organism* **organisms_array) = 0; // Zachowanie organizmu w trakcie tury
	virtual void collision(Container *world_organisms,Organism* **organisms_array, int move_x, int move_y) = 0; // Zachowanie w trakcie kontaktu z innym organizmem
	void setOrganism(int strength, int initiative, int age, string name, int posX, int posY, World &organismWorld);
	int getStrength();
	int getInitiative();
	int getAge();
	string getName();
	int getPosX();
	int getPosY();
	int getHumanMoveX();
	int getHumanMoveY();
	void decreaseSuperPowerDuration();
	void decreaseSuperPowerCooldown();
	void setHumanSuperPower(); // Wlaczanie super umiejetnosci czlowieka
	bool durationPowerStatus(); // Sprawdzanie czy umiejetnosc nadal jest aktywna
	bool cooldownPowerStatus(); // Sprawdzanie czy czas oczekiwana do uruchomienia mocy czlowieka minal
	World * getOrganismWorld();	
	void increaseStrength();
	void increaseAge();
	void changePosition(int posX, int posY); // Ustawianie nowej pozycji
	void killOrganism(Organism* deadOrganism);
	int virtual defence(Container *world_organisms, Organism* **organisms_array, int move_x, int move_y); // Walka organizmow 
	void animalBirthMessage();
	void plantGrowMessage();
	void humanPowerkills(string name);
	int getHeight();
	int getWeight();
	void setWorld(World &organismWorld);
	~Organism();
	void operator =(const Organism* org);
private:	
	int strength_;
	int initiative_;
	int age_;
	string name_;
	int posX_;
	int posY_;
	World *organismWorld_;	 
};