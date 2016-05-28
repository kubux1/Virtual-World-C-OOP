#pragma once
class Human_Control {
public:
	Human_Control();
	int getMoveX();
	int getMoveY();
	bool durationPowerStatus();
	bool cooldownPowerStatus();
	void setMoveX(int moveX);
	void setMoveY(int moveY);
	bool setHumanSuperPower();
	void deleteCoordinates();
	void decreaseSuperPowerDuration();
	void decreaseSuperPowerCooldown();
	int getDuration();
	int getCooldwon();
	bool getUsed();
	void setControls(int duration, int cooldown, int used);
private:
	int moveX_;
	int moveY_;
	bool humanSuperPower_;
	int duration_;
	int cooldown_;
	bool used_;
};