/*
* Programmer: Christoffer Willander		Date completed: February 4th, 2018
* Instructor: Mats-Ola Landbris			Class: DV1497
*
* Simple Yatzee Game
*/

#include "Yatzee.h"
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand(static_cast<unsigned int>(time(0)));

	int playerCapacity = 0;
	int saveDice = 0;
	int saveResult = 0;

	string nameSelection = "?";

	cout << "How many are playing? ";
	cin >> playerCapacity; 
	cin.ignore();
	system("@cls||clear");

	Yatzee game(playerCapacity);
	
	while (game.getNrOfPlayers() < playerCapacity) // While not all players have entered a name
	{
		cout << "Player " + to_string(game.getNrOfPlayers() + 1) + ", enter your name: ";
		getline(cin, nameSelection);
		game.addPlayer(nameSelection);
		system("@cls||clear");
	}

	while (!(game.areAllPlayersDone())) // While not all players are finished playing
	{
		for (int i = 0; i < 3; i++)
		{
			system("@cls||clear");
			cout << game.protocolInfoOfCurrentPlayer() << endl << endl;

			if (i == 0)
			{
				game.toss();
				cout << "First roll: " << game.infoOfLatestToss() << endl;
			}
			else if (i == 1)
			{
				game.toss(saveDice);
				cout << "Second roll: " << game.infoOfLatestToss() << endl;
			}
			else if (i == 2)
			{
				game.toss(saveDice);
			}
			
			if (i < 2)
			{
				cout << endl << "Save dice with value: ";
				cin >> saveDice;
				cin.ignore();
			}
		}

		do
		{
			system("@cls||clear");
			cout << game.protocolInfoOfCurrentPlayer() << endl << endl;
			cout << "Third roll: " << game.infoOfLatestToss() << endl;
			cout << endl << "Save result as: ";
			cin >> saveResult;
			cin.ignore();
			system("@cls||clear");
		} while (!(game.addResult(saveResult)));
		
		cout << game.protocolInfoOfCurrentPlayer() << endl << endl;
		game.nextPlayersTurn();
		
		if (!(game.areAllPlayersDone()))
		{
			cout << game.nameOfCurrentPlayer() + ", press return to make your next move..." << endl;;
		}
		else
		{
			cout << "Press return to show results..." << endl;
		}

		getchar();
		system("@cls||clear");
	}

	system("@cls||clear");
	cout << "Game finished. See results below." << endl << endl;

	for (int i = 0; i < game.getNrOfPlayers(); i++)
	{
		cout << game.protocolInfoOfCurrentPlayer() << endl << endl;
		game.nextPlayersTurn();
	}

	system("pause");
	return 0;
}