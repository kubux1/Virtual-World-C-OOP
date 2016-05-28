#include "Messages.h"

StackElement::StackElement() {
	this->previous = nullptr;
	this->text = "";
}
Stack::Stack() {
	this->top = nullptr;
}
void Stack::push(string text_oryg) {
		if (text_oryg != "") {
			StackElement *newEl = new StackElement;
			newEl->previous = nullptr;
			if (top != NULL)
				newEl->previous = top;
			newEl->text = text_oryg;
			top = newEl;
		}
	}

void Stack::popBack() {
		if (top != NULL) {
			StackElement *tmp =top;
			top = top->previous;
			delete(tmp);
		}
	}

string Stack::show(int messageNumber) {
	StackElement *tmp = top;
	if (top== NULL) {
		return "";
	}
	else {
			for (int i = 0; i < messageNumber; i++) {
				tmp = tmp->previous;
			}
			if (tmp != NULL) {
				return tmp->text;
			}
		else return "";
	}
}

