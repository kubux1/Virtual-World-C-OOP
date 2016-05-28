#pragma once
class Organism;
class List_element
{
	friend class Container;
	friend class World;
public:
	List_element();
private:
	List_element *previous;
	List_element *next;
	Organism* organism;
};
class Container
{
	friend class World;
public:
	Container();
	void insert_element(Organism *new_organism); // Wstawianie bez mechanizmu, publiczne, przechodzi do insert_secret
	int *delete_element(Organism *kill_organism); // Wyszukuje z listy element do usuniecia
	List_element* search_element(Organism *kill_organism); // szukam elementu do usuniecia
private:
	List_element *head;
	List_element *tail;
	int insert_secret(Organism *new_organism); // Prywatne mechanika wstawiania elementu do listy
};