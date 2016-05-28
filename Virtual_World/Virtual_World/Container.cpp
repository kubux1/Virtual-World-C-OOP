#include "Container.h"
#include "Organism.h"
#include "World.h"

List_element::List_element() {
	previous = nullptr;
	next = nullptr;
}
Container::Container() {
	head=nullptr;
	tail=nullptr;
}
// Wpisywanie nowego elementu do listy
void Container::insert_element(Organism *new_organism) {
	List_element *tmp = new List_element;
	if (head == nullptr) {
		head = tmp;
		tail = tmp;
		tmp->organism = new_organism;
	}
	else {	
		insert_secret(new_organism);
	}	
}

int Container::insert_secret(Organism *new_organism) {
	List_element *tmp = new List_element;
	List_element *q = new List_element;
	tmp = head;
	while (tmp->organism->getInitiative() > new_organism->getInitiative()) {
		if (tmp->next == nullptr)
			break;
		else
		tmp = tmp->next;
	}
	while (tmp->organism->getInitiative() == new_organism->getInitiative()) {
		if (tmp->next == nullptr)
			break;
		else
		tmp = tmp->next;
			}
	if (new_organism->getInitiative()<= tmp->organism->getInitiative()) {
		// Wstawianie przed elementem 
		if (tmp->next != nullptr) {
			q->next = tmp;
			q->previous = tmp->previous;
			tmp->previous->next = q;
			tmp->previous = q;
			q->organism = new_organism;
			return 0;
		}
		// Wstawianie za elementem
		if (tmp->next == nullptr) {
			q->next = nullptr;
			tail->next = q;
			q->previous = tail;
			tail = q;
			q->organism = new_organism;
			return 0;
		}
	}

	if (new_organism->getInitiative() > tmp->organism->getInitiative()) {
		if (tmp->previous == nullptr) {
			q->next = tmp;
			q->previous = tmp->previous;
			tmp->previous = q;
			head = q;
			q->organism = new_organism;
			return 0;
		}
		if (tmp->previous != nullptr) {
			q->next = tmp;
			q->previous = tmp->previous;
			tmp->previous->next = q;
			tmp->previous = q;
			q->organism = new_organism;
			return 0;
		}
	}
}
// Wyszukiwanie elementu do usuniêcia
List_element* Container::search_element(Organism *kill_organism) {
	List_element *tmp = new List_element;
	if (head == nullptr)
		return nullptr;
	if (head != nullptr) {
		tmp = head;
		while (tmp != nullptr) {
			if (tmp->organism == kill_organism)
				return tmp;
			tmp = tmp->next;
		}
	}
 	return nullptr; // jesli nie znaleziono 
}
// Usuwanie elementu z listy
int *Container::delete_element(Organism *kill_organism) {
	List_element *tmp = new List_element;
	List_element *q = new List_element;
	tmp = search_element(kill_organism);
	// usuwanie elementu z poczatku list, ktory nie jest te? ostatnim
	if (tmp == head && tmp != tail) {
		head = tmp->next;
		tmp->next->previous = nullptr;
		delete(tmp);
		return 0;
	}
	// usuwanie jedynego elemntu w liscie
	if (tmp == head && tmp == tail) {
		head = nullptr;
		tail = nullptr;
		delete(tmp);
		return 0;
	}
	// usuwanie elementu w srodku
	if (tmp != head && tmp != tail) {
		tmp->previous->next = tmp->next;
		tmp->next->previous = tmp->previous;
		tmp = nullptr;
		//delete(temp)
		return 0;
	}
	//ususwanie ostatniego elementu ktory nie jest pierwszym
	if (tmp != head && tmp == tail) {
		tail = tmp->previous;
		tmp->previous->next = nullptr;
		delete(tmp);
		return 0;
	}

}
