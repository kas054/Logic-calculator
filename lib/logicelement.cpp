#include <iostream>
#include "logicelement.h"


LogicElement::LogicElement(int in, int out) : RealSZ(in+out), ar(new Terminal[in + out])
{
	for (int i = 0; i < in; i++)
	{
		ar[i].setconnects(0);
		ar[i].setposition(2);
		ar[i].settype(Input);
	}
	for (int i = in; i < in + out; i++)
	{
		ar[i].setconnects(0);
		ar[i].setposition(2);
		ar[i].settype(Output);
	}
}

// Destructor

LogicElement::~LogicElement()
{
	delete[] ar;
}

// Copy constructor

LogicElement::LogicElement(const LogicElement& le) : RealSZ(le.RealSZ)
{
	ar = new Terminal[RealSZ];
	for (int i = 0; i < RealSZ; i++)
		ar[i] = le.ar[i];
}

// Move constructor

LogicElement::LogicElement(LogicElement&& le) :RealSZ(le.RealSZ), ar(le.ar) 
{ 
	le.ar = nullptr; 
}

// Overload operator = (copy)

LogicElement& LogicElement::operator =(const LogicElement& le)
{
	if (this != &le) {
		RealSZ = le.RealSZ;
		delete[] ar;
		ar = new Terminal[RealSZ];
		for (int i = 0; i < RealSZ; i++)
			ar[i] = le.ar[i];
	}
	return *this;
}

// Move = operator

LogicElement& LogicElement::operator =(LogicElement&& le)
{
	int tmp = RealSZ;
	RealSZ = le.RealSZ;
	le.RealSZ = tmp;
	Terminal* ptr = ar;
	ar = le.ar;
	le.ar = ptr;
	return *this;
}

// Metods
void LogicElement::newpositionforall(int *mass) {
	for (int i = 0; i < getRealSZ(); i++) 
	{
		newposition(i, mass[i]);
	}
	return;
}
void LogicElement::PrintAllInfo() const {
	for (int i = 0; i < RealSZ; i++) {
		std::cout << "Terminal number " << i + 1 << " info: " << std::endl;
		if (ar[i].getType()) {
			std::cout << "Type = Input,  ";
		}
		else {
			std::cout << "Type = Output,  ";
		}
		std::cout << "Connects = " << ar[i].getConnects() << ",  ";
		if (ar[i].getposition() != 2) {
			std::cout << "Position = " << ar[i].getposition() << std::endl;
		}
		else {
			std::cout << "Position not stated" << std::endl;
		}
	}
	return ;
}
void LogicElement::newposition(int num, int pos) {
	if (num < RealSZ)
	{
		if (pos >= 0 && pos <= 2)
			ar[num].setposition(pos);
		else 
			throw std::overflow_error("No such position");
		return;
	}
	else
		throw std::overflow_error("No Terminal with such number");
}
int LogicElement::positioncheck(int num) const {
	if (num < RealSZ)
	{
		return ar[num].getposition();
	}
	else throw std::overflow_error("No Terminal with such number");
}
void LogicElement::increaseNconnections(int num) {
	if (num < RealSZ ) {
		if (ar[num].getType() == Input) {
			if (ar[num].getConnects() < 3)
			{
				ar[num].setconnects(ar[num].getConnects() + 1);
				return;
			}
			else throw std::overflow_error("Max Number of connections");
		}
		else {
			if (ar[num].getConnects() < 1)
			{
				ar[num].setconnects(ar[num].getConnects() + 1);
				return;
			}
			else throw std::overflow_error("Max Number of connections");
		}
	}
	else throw std::overflow_error("No Terminal with such number");
}
void LogicElement::decreaseNconnections(int num) {
	if (num <= getRealSZ()) {
		if (ar[num].getType() == Input) {
			if (ar[num].getConnects() > 0)
			{
				ar[num].setconnects(ar[num].getConnects() - 1);
				return;
			}
			else throw std::overflow_error("Min number of connections");
			
		}
		else {
			if (ar[num].getConnects() > 0)
			{
				ar[num].setconnects(ar[num].getConnects() - 1);
				return;
			}
			else throw std::overflow_error("Min number of connections");
		}
	}
	else throw std::overflow_error("No Terminal with such number");
}
void LogicElement::addTerminal(Types Type, int con, int pos) {

	Terminal *oldar = this->ar;
	ar = new Terminal[RealSZ + 1];
	for (int i = 0; i < RealSZ; i++) {
		ar[i] = oldar[i];
	}
	delete[] oldar;
	ar[RealSZ].setconnects(con);
	ar[RealSZ].setposition(pos);
	if (Type == 1) { // add output terminal
		ar[RealSZ].settype(Output);
		this->RealSZ += 1;
		return;
	}
	else // add input tepminal
	{
		ar[RealSZ].settype(Input);
		this->RealSZ += 1;
		return;
	}
}
int LogicElement::getRealSZ() const { return RealSZ; }
Terminal LogicElement::getar(int i) const { 
	if (i < RealSZ) 
		return ar[i]; }
Types Terminal::getType() const { return Type; }
int Terminal::getConnects() const { return Connects; }
int Terminal::getposition() const { return position; }
void Terminal::setposition(int pos) { position = pos; }
void Terminal::setconnects(int con) { Connects = con; }
void Terminal::settype(Types typ) { Type = typ; }

std::ostream& operator <<(std::ostream& s, const LogicElement& le)
{
	if (le.getRealSZ() == 0)
		s << "LogicElement is empty";
	else
		for (int i = 0; i < le.getRealSZ(); i++)
		{
			s << "Terminal number " << i + 1 << " info: " << std::endl;
			if (le.getar(i).getType() == Input) {
				s << "Type = Input,  ";
			}
			else {
				s << "Type = Output,  ";
			}
			s << "Connects:" << le.getar(i).getConnects() << ",  ";
			if (le.getar(i).getposition() != 2)
			{
				s << "Position = " << le.getar(i).getposition() << std::endl;
			}
			else
			{
				s << "Position not stated" << std::endl;
			}
		}
	s << std::endl;
	return s;
}
LogicElement& LogicElement::operator +=(const Terminal& terminal)
{
	Terminal* oldar = this->ar;
	ar = new Terminal[RealSZ + 1];
	for (int i = 0; i < RealSZ; i++) {
		ar[i] = oldar[i];
	}
	delete[] oldar;
		this->ar[RealSZ].settype(terminal.getType());
		this->ar[RealSZ].setconnects(terminal.getConnects());
		this->ar[RealSZ].setposition(terminal.getposition());
		RealSZ += 1;
		return *this;
}
LogicElement& LogicElement::operator +(int terminalnumber)
{
	if (terminalnumber <= RealSZ)
	{
		if (this->getar(terminalnumber).getType() == Input)
		{
			if ((this->getar(terminalnumber).getConnects() + 1 <= 1) && (this->getar(terminalnumber).getConnects() + 1 >= 0))
			{
				int num = this->getar(terminalnumber).getConnects();
				this->ar[terminalnumber].setconnects(num + 1);
				return *this;
			}
			else throw std::overflow_error("Max number of connections");
		}
		else
		{
			if ((this->getar(terminalnumber).getConnects() + 1 <= 3) && (this->getar(terminalnumber).getConnects() + 1 >= 0))
			{
				int num = this->getar(terminalnumber).getConnects();
				this->ar[terminalnumber].setconnects(num + 1);
				return *this;
			}
			else
				throw std::overflow_error("Max number of connections");
		}

	}
	else throw std::overflow_error("No Terminal with such number");
}
LogicElement& LogicElement::operator -(int terminalnumber)
{
	if (terminalnumber <= RealSZ)
	{
		if (this->getar(terminalnumber).getType() == Input)
		{
			if ((this->getar(terminalnumber).getConnects() - 1 <= 1) && (this->getar(terminalnumber).getConnects() - 1 >= 0))
			{
				int num = this->getar(terminalnumber).getConnects();
				this->ar[terminalnumber].setconnects(num - 1);
				return *this;
			}
			else
				throw std::overflow_error("Min number of connections");
		}
		else
		{
			if ((this->getar(terminalnumber).getConnects() - 1 <= 3) && (this->getar(terminalnumber).getConnects() - 1 >= 0))
			{
				int num = this->getar(terminalnumber).getConnects();
				this->ar[terminalnumber].setconnects(num - 1);
				return *this;
			}
			else
				throw std::overflow_error("Min number of connections");
		}
	}
	else throw std::overflow_error("No Terminal with such number");
}
Terminal& LogicElement::operator [](int terminalnumber) 
{
	if (terminalnumber < RealSZ)
		return ar[terminalnumber];
}
