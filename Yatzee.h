#ifndef YATZEE_H
#define YATZEE_H
#include <string>
#include "ProtocolColumn.h"
#include "Dice.h"

using namespace std;

const int DICEAMOUNT = 5;

class Yatzee
{
private:
	int playerCapacity;
	int nrOfPlayers;
	int currentPlayer;
	void initialize(int index = 0);
	void expand();
	ProtocolColumn* *protocols;
	Dice dices[DICEAMOUNT];

public:
	Yatzee(int playerCapacity = 2); // Constructor
	~Yatzee(); // Destructor
	Yatzee(const Yatzee& originalObject); // Copy-constructor
	Yatzee& operator = (const Yatzee& originalObject); // Assignment operator

	void addPlayer(string playerName);
	string protocolInfoOfCurrentPlayer() const;
	int getNrOfPlayers() const;
	void toss(int diceValue);
	void toss();
	string infoOfLatestToss() const;
	bool addResult(int diceValue) const;
	string nameOfCurrentPlayer() const;
	void nextPlayersTurn();
	bool areAllPlayersDone() const;
};

#endif