#ifndef DICE_H
#define DICE_H

using namespace std;

class Dice
{
private:
	int randomNumber;
	int numbOfFaces;

public:
	Dice(int nrOfFaces = 6);
	~Dice();
	void toss();
	int getCurrentValue() const;
};

#endif
