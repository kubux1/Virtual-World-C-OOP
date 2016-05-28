#pragma once
#include "Position.h"

Position::Position(int posX, int posY) {
	this->posX_ = posX;
	this->posY_ = posY;
}

void Position::setPos(int posX, int posY) {
	this->posX_ = posX;
	this->posY_ = posY;
}
int Position::getPosX() {
	return this->posX_;
}

int Position::getPosY() {
	return this->posY_;
}