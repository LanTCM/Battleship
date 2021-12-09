#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int maxShips = 5;

int board[10][10];

void clear()
{
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			board[i][j] = 0;
		}
	}
}

void showBoard()
{
	cout << "    0 1 2 3 4 5 6 7 8 9" << endl;
	cout << "    -------------------" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << i << " | ";
		for (int j = 0; j < 10; j++)
		{
			cout << board[j][i] << " ";
		}
		cout << endl;
	}
}

void setShips()
{
	int s = 0;
	while (s < maxShips)
	{
		int x = rand() % 10;
		int y = rand() % 10;
		if (board[x][y] != 1)
		{
			s++;
			board[x][y] = 1;
		}
	}
}

int numShips()
{
	int c = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (board[i][j] == 1)
				c++;
		}
	}
	return c;
}

bool attack(int x, int y)
{
	if (board[x][y] == 1)
	{
		board[x][y] = 2;
		return true;
	}
	else
	{
		board[x][y] = 3;
	}
	return false;
}

int main()
{
	srand(time(NULL));
	clear();
	setShips();
	int pos1, pos2;
	char france;
	cout << "1=Ship, 2=Hit, 3=Miss\nType Coordinates as 'X Y'"<< endl;
	while (1)
	{
		showBoard();
		cout << "Ships Left: " << numShips() << endl;
		cout << "Please Input Coordiantes to attack: "; 
		cin >> pos1 >> pos2;
		if (attack(pos1, pos2))
			cout << "Ship Hit!: " << endl;
		else
			cout << "Miss!" << endl;
		if (numShips() == 0)
		{
			cout << "You Won! All Enemy Ships Are Destroyed!" << endl;
			break;
		}
		cout << "Surrender?(y/n): ";  
		cin >> france;
		if (france == 'y')
		{
			cout << "Game Over" << endl;
			break;
		}
			
	}
	
	
	system("pause");
	return 0;
}