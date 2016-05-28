#include "Human_Control.h"

Human_Control::Human_Control() {
	this->moveX_ = 0;
	this->moveY_ = 0;
	this->humanSuperPower_ = false;
	this->duration_ = 0;
	this->cooldown_ = 5;
	this->used_ = false;
}
int Human_Control::getMoveX() {
	return this->moveX_;
}
int Human_Control::getMoveY() {
	return this->moveY_;
}
void Human_Control::setMoveX(int moveX) {
	this->moveX_ = moveX;
}
void Human_Control::setMoveY(int moveY) {
   this->moveY_ = moveY;
}
void Human_Control::deleteCoordinates() {
	this->moveX_ = 0;
	this->moveY_ = 0;
}

bool Human_Control::setHumanSuperPower() {
	if (this->cooldown_ == 5 && this->duration_ == 0 && used_ == false) {
		this->duration_ = 5;
		return true;
	}
	else 
		return false;
}
bool Human_Control::durationPowerStatus() {
	if (this->cooldown_ == 5 && this->duration_ > 0)
		return true;
	else return false;
}
bool Human_Control::cooldownPowerStatus() {
	if (used_ == true)
		return true;
	else return false;
}
void Human_Control::decreaseSuperPowerDuration() {
	if (this->duration_ > 0)
		this->duration_ -= 1;
	if(this->duration_ == 0)
		used_ = true;
}
void Human_Control::decreaseSuperPowerCooldown() {
	if (this->duration_ == 0 && this->cooldown_ > 0)
		this->cooldown_ -= 1;
	else {
		cooldown_ = 5;
		used_ = false;
	}
}

int Human_Control::getDuration() {
	return this->duration_;
}
int Human_Control::getCooldwon() {
	return this->cooldown_;
}
bool Human_Control::getUsed() {
	return this->used_;
}
void Human_Control::setControls(int duration, int cooldown, int used) {
	this->duration_ = duration;
	this->cooldown_ = cooldown;
	this->used_ = used;
}
