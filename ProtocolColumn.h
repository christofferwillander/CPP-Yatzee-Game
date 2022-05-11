#ifndef PROTOCOLCOLUMN_H
#define PROTOCOLCOLUMN_H
#include <string>

using namespace std;

class ProtocolColumn
{
private:
	string playerName;
	int result[6];
	bool taken[6];

public:
	ProtocolColumn(string name = "?");
	~ProtocolColumn();
	bool addResult(int diceValue, int result);
	string getPlayerName() const;
	int getTotalSum() const;
	bool isFilled() const;
	string toString() const;
};

#endif
