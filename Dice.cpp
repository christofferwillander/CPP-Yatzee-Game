#include "Dice.h"
#include <cstdlib>

Dice::Dice(int numbOfFaces)
{
	this->numbOfFaces = numbOfFaces;
	this->randomNumber = (rand() % this->numbOfFaces) + 1;
}

Dice::~Dice()
{

}

void Dice::toss()
{
	this->randomNumber = (rand() % this->numbOfFaces) + 1;
}

int Dice::getCurrentValue() const
{
	return this->randomNumber;
}
