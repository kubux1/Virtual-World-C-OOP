#include "World.h"
#include "curses.h"

World::World(int height, int weight) {
	Random randomOrganism;
	
	this->gameStatus_ = true;
	this->height_ = height;
	this->weight_ = weight;

    organismsArray = new Organism**[weight];
	for (int i = 0; i < weight; i++) {
		organismsArray[i] = new Organism*[height];
	}
        this->fillArray();

	new Human(*this, worldOrganisms, organismsArray);

	for (int i = 0; i < 15; i++) {
		int organismNumber = randomOrganism.randOrganism();
		switch (organismNumber) {
		case 0:
		{
			new Wolf(*this, worldOrganisms, organismsArray);
			break;
		}
		case 1:
		{
			new Sheep(*this, worldOrganisms, organismsArray);
			break;
		}
		case 2: {
			new Fox(*this, worldOrganisms, organismsArray); 
			break;
		}
		case 3:
		{
			new Turtle(*this, worldOrganisms, organismsArray); 
			break;
		}
		case 4:
		{
			new Antelope(*this, worldOrganisms, organismsArray); 
			break;
		}
		case 5:
		{
			new Grass(*this, worldOrganisms, organismsArray);
			break;
		}
		case 6:
		{
			new Dandelion(*this, worldOrganisms, organismsArray);
			break;
		}
		case 7:
		{
			new Guarana(*this, worldOrganisms, organismsArray);
			break;
		}
		case 8:
		{
		    new Berries(*this, worldOrganisms, organismsArray);
			break;
		}
		default:
			break;
		}
	}
	this->scribeWorld();
}
void World::saveToFile() { 
        ofstream myfile;
	    this->tmp = worldOrganisms->head;
		
		myfile.open("VirtualWorld-Save.txt");
		myfile << this->height_ << endl;
		myfile << this->weight_ << endl;
	while (this->tmp != nullptr) {
		howMany_++;
		myfile << this->tmp->organism->getStrength() << endl;
		myfile << this->tmp->organism->getInitiative() << endl;
		myfile << this->tmp->organism->getAge() << endl;
		myfile << this->tmp->organism->getName() << endl;
		myfile << this->tmp->organism->getPosX() << endl;
		myfile << this->tmp->organism->getPosY() << endl;
		if (this->tmp->organism->getName() == "Human") {
			myfile << this->humanControl->getDuration() << endl;
			myfile << this->humanControl->getCooldwon() << endl;
			myfile << this->humanControl->getUsed() << endl;
		}
		tmp = tmp->next;
	}
	myfile << howMany_<< endl;
	myfile.close();
}

void World::readFromFile() {
	int strength;
	int initiative;
	int age;
	string name;
	int posX;
	int posY;
	int sizeX;
	int sizeY;
	int duration;
	int cooldown;
	bool used;

	 Container * con = new Container;
	 worldOrganisms = con;
	ifstream myfile;
	myfile.open("VirtualWorld-Save.txt");
	string line, lastLine;
	while (getline(myfile, line))
	{
		cout << line << endl;
		lastLine = line;
	}
	myfile.seekg(0, myfile.beg);
	ifstream myfile1;
	myfile1.open("VirtualWorld-Save.txt");
	myfile1 >> sizeX;
	myfile1 >> sizeY;

	this->weight_ = sizeX;	
	this->height_ = sizeY;
    
	organismsArray = new Organism**[weight_];
	for (int i = 0; i < weight_; i++) {
		organismsArray[i] = new Organism*[height_];
	}
	this->fillArray();

	for (int i = 0; i <stoi(lastLine); i++) {
		myfile1 >> strength;
		myfile1 >> initiative;
		myfile1 >> age;
		myfile1 >> name;
		myfile1 >> posX;
		myfile1 >> posY;
		if (name == "Human") {
			myfile1 >> duration;
			myfile1 >> cooldown;
			myfile1 >> used;
		}
		if(name == "Wolf")
			new Wolf(*this,worldOrganisms, organismsArray, strength, initiative, age,  name,  posX, posY);
		if (name == "Sheep")
			new Sheep(*this, worldOrganisms, organismsArray, strength, initiative, age, name, posX, posY);
		if (name == "Fox")
			new Fox(*this, worldOrganisms, organismsArray, strength, initiative, age, name, posX, posY);
		if (name == "Turtle")
			new Turtle(*this, worldOrganisms, organismsArray, strength, initiative, age, name, posX, posY);
		if (name == "Antelope")
			new Antelope(*this, worldOrganisms, organismsArray, strength, initiative, age, name, posX, posY);
		if (name == "Grass")
			new Grass(*this, worldOrganisms, organismsArray, strength, initiative, age, name, posX, posY);
		if (name == "Dandelion")
			new Dandelion(*this, worldOrganisms, organismsArray, strength, initiative, age, name, posX, posY);
		if (name == "Guarana")
			new Guarana(*this, worldOrganisms, organismsArray, strength, initiative, age, name, posX, posY);
		if (name == "Berries")
			new Berries(*this, worldOrganisms, organismsArray, strength, initiative, age, name, posX, posY);
		if (name == "Human") {
			new Human(*this, worldOrganisms, organismsArray, strength, initiative, age, name, posX, posY);
			this->humanControl->setControls(duration, cooldown, used);
		}
	}
	myfile.close();
}
int World::getHeight() {
	return this->height_;
}
int World::getWeight() {
	return this->weight_;
}
void World::makeTour() {
	List_element *tmp_dead = new List_element;

    this->tmp = worldOrganisms->head;
	while (this->tmp != nullptr) { 
		tmp_dead = this->tmp->next;
		this->tmp->organism->action(worldOrganisms, organismsArray);
		if (this->tmp == nullptr)
			this->tmp = tmp_dead;
		else
		this->tmp = this->tmp->next;
	}
	this->scribeWorld();
}

void World::fillArray() { 
	for (int i = 0; i < this->weight_; i++) {
		for (int j = 0; j <this->height_; j++) {
			this->organismsArray[i][j] = nullptr;
		}
	}
}

Container* World::getContainer() {
	return this->worldOrganisms;
}
List_element* World::getTmp() {
	return this->tmp;
}
Human_Control * World::getHumanControl() {
	return this->humanControl;
}

bool World::getGameStatus() {
	return gameStatus_;
}
void World::putMessage(string statement) {
	this->messages->push(statement);
}
void World::scribeWorld() { 
	int posX, posY;
	int rows = 0, columns = 0;
	int moveCoulmne = 1, messageNumber = 0;
	string name;

	this->tmp = worldOrganisms->head;
	initscr();
	getmaxyx(stdscr, rows, columns);
	start_color();

	while (tmp != nullptr) {
		name = tmp->organism->getName();
		posX = tmp->organism->getPosX();
		posY = tmp->organism->getPosY();
		if (name == "Wolf") {
			init_pair(1, COLOR_RED, COLOR_BLACK);
			attron(COLOR_PAIR(1));
			mvprintw(posY, posX, "W");
			attroff(COLOR_PAIR(1));
			tmp = tmp->next;
			continue;
		}
		if (name == "Sheep") {
			init_pair(2, COLOR_WHITE, COLOR_BLACK);
			attron(COLOR_PAIR(2));
			mvprintw(posY, posX, "S");
			attroff(COLOR_PAIR(2));
			tmp = tmp->next;
			continue;
		}
		if (name == "Fox") {
			init_pair(3, COLOR_RED, COLOR_BLACK);
			attron(COLOR_PAIR(3));
			mvprintw(posY, posX, "F");
			attroff(COLOR_PAIR(3));
			tmp = tmp->next;
			continue;
		}
		if (name == "Turtle") {
			init_pair(4, COLOR_CYAN, COLOR_BLACK);
			attron(COLOR_PAIR(4));
			mvprintw(posY, posX, "T");
			attroff(COLOR_PAIR(4));
			tmp = tmp->next;
			continue;
		}
		if (name == "Antelope") {
			init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
			attron(COLOR_PAIR(5));
			mvprintw(posY, posX, "A");
			attroff(COLOR_PAIR(5));
			tmp = tmp->next;
			continue;
		}
		if (name == "Grass") {
			init_pair(6, COLOR_GREEN, COLOR_BLACK);
			attron(COLOR_PAIR(6));
			mvprintw(posY, posX, "G");
			attroff(COLOR_PAIR(6));
			tmp = tmp->next;
			continue;
		}
		if (name == "Dandelion") {
			init_pair(7, COLOR_YELLOW, COLOR_BLACK);
			attron(COLOR_PAIR(7));
			mvprintw(posY, posX, "D");
			attroff(COLOR_PAIR(7));
			tmp = tmp->next;
			continue;
		}
		if (name == "Guarana") {
			init_pair(8, COLOR_GREEN, COLOR_BLACK);
			attron(COLOR_PAIR(8));
			mvprintw(posY, posX, "U");
			attroff(COLOR_PAIR(8));
			tmp = tmp->next;
			continue;
		}
		if (name == "Berries") {
			init_pair(9, COLOR_BLUE, COLOR_BLACK);
			attron(COLOR_PAIR(9));
			mvprintw(posY, posX, "B");
			attroff(COLOR_PAIR(9));
			tmp = tmp->next;
			continue;
		}
		if (name == "Human") {
			init_pair(10, COLOR_WHITE, COLOR_BLACK);
			attron(COLOR_PAIR(10));
			mvprintw(posY, posX, "H");
			attroff(COLOR_PAIR(10));
			tmp = tmp->next;
			continue;
		}
	}

	// Wyswietlanie komunikatow
		while (messages->show(messageNumber) != "") {
			char messageArray[100];
			strcpy(messageArray, messages->show(messageNumber).c_str());
			mvprintw(rows - moveCoulmne, (columns+weight_)/2 - (sizeof(messages->show(messageNumber)) / 2), messageArray);
			moveCoulmne++;
			messageNumber++;
		}

		// Interfejs 
		for (int i = 0; i < this->height_+1; i++)
			mvprintw(i,this->weight_, "#");
		for (int i = 0; i <this->weight_ + 1; i++)
			mvprintw(this->height_,i, "#");

		mvprintw(this->height_ + 2, 0, "Jakub Kotowski s161969");

	// Pobieranie kierunku ruchu dla czlowieka
	this->humanControl->deleteCoordinates();
	noecho();
 	char command = getch();
	if (command == 'w')
		this->humanControl->setMoveY(-1);
	if (command == 's')
		this->humanControl->setMoveY(1);
	if (command == 'a')
		this->humanControl->setMoveX(-1);
	if (command == 'd')
		this->humanControl->setMoveX(1);
	if (command == 'f') {
		this->saveToFile();
		this->messages->push("Game have been saved");
	}
	if (command == 'r')
		this->readFromFile();
	if (command == 'q')
		this->gameStatus_ = false;
	if (command == 'e') {
		if (this->humanControl->setHumanSuperPower() == true)
			this->messages->push("Super power used");
		else
			this->messages->push("Your super power is not ready yet");
		refresh();
		char command2 = getch();
		if (command2 == 'w')
			this->humanControl->setMoveY(-1);
		if (command2 == 's')
			this->humanControl->setMoveY(1);
		if (command2 == 'a')
			this->humanControl->setMoveX(-1);
		if (command2 == 'd')
			this->humanControl->setMoveX(1);
		refresh();
		endwin();
	}
	refresh();
	endwin();	
}