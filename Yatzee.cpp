#include "Yatzee.h"

void Yatzee::initialize(int index)
{
	for (int i = index; i < this->playerCapacity; i++)
	{
		this->protocols[i] = nullptr;
	}
}

void Yatzee::expand()
{
	this->playerCapacity += 2;
	ProtocolColumn* *temporaryProtocol = new ProtocolColumn*[this->playerCapacity];

	for (int i = 0; i < this->nrOfPlayers; i++)
	{
		temporaryProtocol[i] = this->protocols[i];
	}

	delete[] this->protocols;
	this->protocols = temporaryProtocol;
	this->initialize(this->nrOfPlayers);
}

Yatzee::Yatzee(int playerCapacity)
{
	this->playerCapacity = playerCapacity;
	this->protocols = new ProtocolColumn*[this->playerCapacity];
	this->nrOfPlayers = 0;
	this->initialize();
}

Yatzee::~Yatzee()
{
	for (int i = 0; i < this->nrOfPlayers; i++)
	{
		delete this->protocols[i];
	}

	delete[] this->protocols;
}

Yatzee::Yatzee(const Yatzee & originalObject)
{
	this->playerCapacity = originalObject.playerCapacity;
	this->currentPlayer = originalObject.currentPlayer;
	this->nrOfPlayers = originalObject.nrOfPlayers;
	this->protocols = new ProtocolColumn*[originalObject.playerCapacity];

	for (int i = 0; i < originalObject.nrOfPlayers; i++)
	{
		this->protocols[i] = new ProtocolColumn(*originalObject.protocols[i]);
	}

	this->initialize(originalObject.nrOfPlayers);
}

Yatzee & Yatzee::operator=(const Yatzee & originalObject)
{
	if (this != &originalObject) // Check for preventing self-assignment
	{
		for (int i = 0; i < this->playerCapacity && this->nrOfPlayers > 0; i++)
		{
			delete this->protocols[i];
		}

		delete[] this->protocols;

		this->playerCapacity = originalObject.playerCapacity;
		this->currentPlayer = originalObject.currentPlayer;
		this->nrOfPlayers = originalObject.nrOfPlayers;

		this->protocols = new ProtocolColumn*[originalObject.playerCapacity];

		for (int i = 0; i < originalObject.nrOfPlayers; i++)
		{
			this->protocols[i] = new ProtocolColumn(*originalObject.protocols[i]);
		}

		this->initialize(originalObject.nrOfPlayers);
	}

	return *this;
}

void Yatzee::addPlayer(string playerName)
{
	if (this->nrOfPlayers == this->playerCapacity)
	{
		this->expand();
	}

	this->protocols[this->nrOfPlayers++] = new ProtocolColumn(playerName);
}

string Yatzee::protocolInfoOfCurrentPlayer() const
{
	return this->protocols[this->currentPlayer]->toString();
}

int Yatzee::getNrOfPlayers() const
{
	return this->nrOfPlayers;
}

void Yatzee::toss(int diceValue)
{
	for (int i = 0; i < DICEAMOUNT; i++)
	{
		if (this->dices[i].getCurrentValue() != diceValue)
		{
			this->dices[i].toss();
		}
	}
}

void Yatzee::toss()
{
	for (int i = 0; i < DICEAMOUNT; i++)
	{
		this->dices[i].toss();
	}
}

string Yatzee::infoOfLatestToss() const
{
	string tossResult = "";

	for (int i = 0; i < DICEAMOUNT; i++) // To enable user to alter amount of dice used
	{
		tossResult += to_string(this->dices[i].getCurrentValue()) + " ";
	}

	return tossResult;
}

bool Yatzee::addResult(int diceValue) const
{
	int result = 0;
	bool added = false;

	for (int i = 0; i < DICEAMOUNT; i++)
	{
		if (this->dices[i].getCurrentValue() == diceValue)
		{
			result += diceValue;
		}
	}

	if (this->protocols[this->currentPlayer]->addResult(diceValue, result))
	{
		added = true;
	}

	return added;
}

string Yatzee::nameOfCurrentPlayer() const
{
	return this->protocols[this->currentPlayer]->getPlayerName();
}

void Yatzee::nextPlayersTurn()
{
	do
	{
		if (this->currentPlayer < this->nrOfPlayers - 1)
		{
			this->currentPlayer++;
		}
		else if (this->currentPlayer == this->nrOfPlayers - 1)
		{
			this->currentPlayer = 0;
		}
	} while (this->protocols[currentPlayer]->isFilled() && !(this->areAllPlayersDone())); // In case a player was added mid-game (unlikely)
}

bool Yatzee::areAllPlayersDone() const
{
	int playersDone = 0;

	for (int i = 0; i < this->nrOfPlayers; i++)
	{
		if (this->protocols[i]->isFilled())
		{
			playersDone++;
		}
	}
	
	return playersDone == this->nrOfPlayers;
}
