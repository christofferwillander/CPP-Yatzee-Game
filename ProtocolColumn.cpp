#include "ProtocolColumn.h"

ProtocolColumn::ProtocolColumn(string name)
{
	this->playerName = name;
	
	for (int i = 0; i < 6; i++)
	{
		this->result[i] = 0;
		this->taken[i] = false;
	}
}

ProtocolColumn::~ProtocolColumn()
{

}

bool ProtocolColumn::addResult(int diceValue, int result)
{
	bool success = false;

	if (diceValue == 1 && !(this->taken[0]))
	{
		this->result[0] = result;
		this->taken[0] = true;
		success = true;
	}
	else if (diceValue == 2 && !(this->taken[1]))
	{
		this->result[1] = result;
		this->taken[1] = true;
		success = true;
	}
	else if (diceValue == 3 && !(this->taken[2]))
	{
		this->result[2] = result;
		this->taken[2] = true;
		success = true;
	}
	else if (diceValue == 4 && !(this->taken[3]))
	{
		this->result[3] = result;
		this->taken[3] = true;
		success = true;
	}
	else if (diceValue == 5 && !(this->taken[4]))
	{
		this->result[4] = result;
		this->taken[4] = true;
		success = true;
	}
	else if (diceValue == 6 && !(this->taken[5]))
	{
		this->result[5] = result;
		this->taken[5] = true;
		success = true;
	}
	
	return success;
}

string ProtocolColumn::getPlayerName() const
{
	return this->playerName;
}

int ProtocolColumn::getTotalSum() const
{
	return (this->result[0] + this->result[1] + this->result[2] + this->result[3] + this->result[4] + this->result[5]);
}

bool ProtocolColumn::isFilled() const
{
	return (this->taken[0] && this->taken[1] && this->taken[2] && this->taken[3] && this->taken[4] && this->taken[5]);
}

string ProtocolColumn::toString() const
{
	return "----------------------\n" + this->playerName + "\n1      :  " + to_string(this->result[0]) + "\n2      :  " + to_string(this->result[1]) + "\n3      :  " + to_string(this->result[2]) + "\n4      :  " + to_string(this->result[3]) + +"\n5      :  " + to_string(this->result[4]) + +"\n6      :  " + to_string(this->result[5]) + "\n----------------------\n" + "SUM    =  " + to_string(this->getTotalSum());
}
