#pragma once
#include <string>
using namespace std;

class StackElement {
	friend class Stack;
public:
	StackElement();
private:
	StackElement *previous;
	string text;
};

class Stack {
public:
	Stack();
	void push(string text); // Dodawanie elementu do kolejki
	void popBack(); // Usuwanie elementu z kolejki
	string show(int messageNumber); // Wyswietlanie komunikatu
private:
	StackElement *top = new StackElement;
};




