#pragma once
class Position 
{
  public:
	Position(int pos_x, int pos_y);
	void setPos(int posX, int posY);
	int getPosX();
	int getPosY();
  private:
	int posX_;
	int posY_;
};