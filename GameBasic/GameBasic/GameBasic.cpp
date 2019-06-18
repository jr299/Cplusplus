// GameBasic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include"cstring"
#include"iomanip"
#include<string>

using namespace std;
#define SMAP 10
#define SNAME 20
//SMAP: Kich thuoc cua map
//SNAME: Kich thuoc cua ten nguoi choi

int choose;

char player1[SNAME];
char player2[SNAME];

void displayMenu()
{
	cout << "==========================TIC TAC TOE==========================" << endl;
	cout << "+ Wellcome to Tic-tac-toe game! Play with your way!           +" << endl;
	cout << "===============================================================" << endl;
	cout << "SELECT YOUR MODE (1 - PLAY GAME, OTHER - EXIT GAME): ";
}

void inputName()
{
	cin.ignore();
	cout << "Enter Player 1 Name: ";
	cin.getline(player1, 20);
	cout << "Enter Player 2 Name: ";
	fflush(stdin);
	cin.getline(player2, 20);
}

void printMap(char map[SMAP][SMAP])
{
	for (int i = 0; i < SMAP; i++)
	{
		for (int j = 0; j < SMAP; j++)
		{
			cout << map[i][j] << "\t";
		}
		cout << endl;
	}
}

char checkPlayerWin(char map[SMAP][SMAP])
{
	//hang ngang
	for (int i = 0; i < SMAP; i++)
	{
		if (map[i][0] == '.')
		{
			continue;
		}
		for (int j = 1; j < SMAP; j++)
		{
			if (map[i][j] != map[i][0])
			{
				break;
			}
			if (j == SMAP - 1)
			{
				return map[i][0];
			}
		}
	}

	//hang doc
	for (int j = 0; j < SMAP; j++)
	{
		if (map[0][j] == '.')
		{
			continue;
		}
		for (int i = 1; i < SMAP; i++)
		{
			if (map[i][j] != map[0][j])
			{
				break;
			}
			if (i == SMAP - 1)
			{
				return map[0][j];
			}
		}
	}

	//cheo thuan
	if (map[0][0] != '.')
	{
		for (int i = 1; i < SMAP; i++)
		{
			if (map[i][i] != map[0][0])
			{
				break;
			}
			if (i == SMAP - 1)
			{
				return map[0][0];
			}
		}
	}

	//cheo ngich
	if (map[0][SMAP - 1] != '.')
	{
		for (int j = 1; j < SMAP; j++)
		{
			if (map[j][SMAP - j - 1] != map[0][SMAP - 1])
			{
				break;
			}
			if (j == SMAP - 1)
			{
				return map[0][SMAP - 1];
			}
		}
	}

	return 'H';
}

void startGame()
{
	char m[SMAP][SMAP];
	for(int i = 0 ; i < SMAP; i++)
		for (int j = 0; j < SMAP; j++)
		{
			m[i][j] = '.';
		}
	
	int r, c;
	int count = SMAP * SMAP;
	int turn = 0;

	//print map
	printMap(m);

	do
	{
		turn++;

		//player1
		do
		{
			cout << "--> Player 1 (" << player1 << ") - turn " << turn << endl;
			cout << "Nhap vi tri (r,c): ";
			cin >> r >> c;
			if (r < 0 || r > SMAP - 1 || c < 0 || c > SMAP - 1)
			{
				cout << "Ban nhap sai, moi nhap lai !" << endl;
			}
			else if (m[r][c] == 'O' || m[r][c] == 'X')
			{
				cout << "Vi tri da duoc chon, moi nhap lai !" << endl;
			}
		} while (r < 0 || r > SMAP - 1 || c < 0 || c > SMAP - 1 || m[r][c] == 'O' || m[r][c] == 'X');
		m[r][c] = 'O';

		//print map
		printMap(m);

		//check win
		if (checkPlayerWin(m) == 'O')
		{
			cout << "==========FINISH===========" << endl;
			cout << "==> Player 1 (" << player1 << ") Win! <==" << endl;
			break;
		}
		count--;

		//check draw
		if (checkPlayerWin(m) == 'H')
		{
			if (count == 0)
			{
				cout << "==========FINISH===========" << endl;
				cout << "==>        Draw!        <==" << endl;
				break;
			}
		}
		
		//player2
		do
		{
			cout << "--> Player 2 (" << player2 << ") - turn " << turn << endl;
			cout << "Nhap vi tri (r,c): ";
			cin >> r >> c;
			if (r < 0 || r > SMAP - 1 || c < 0 || c > SMAP - 1)
			{
				cout << "Ban nhap sai, moi nhap lai !" << endl;
			}
			else if (m[r][c] == 'O' || m[r][c] == 'X')
			{
				cout << "Vi tri da duoc chon, moi nhap lai !" << endl;
			}
		} while (r < 0 || r > SMAP - 1 || c < 0 || c > SMAP - 1 || m[r][c] == 'O' || m[r][c] == 'X');
		m[r][c] = 'X';

		//print map
		printMap(m);

		//check win
		if (checkPlayerWin(m) == 'X')
		{
			cout << "==========FINISH===========" << endl;
			cout << "==> Player 2 (" << player2 << ") Win! <==" << endl;
			break;
		}
		count --;

		//check draw
		if (checkPlayerWin(m) == 'H')
		{
			if (count == 0)
			{
				cout << "==========FINISH===========" << endl;
				cout << "==>        Draw!        <==" << endl;
				break;
			}
		}
	} while (true);

}

void playGame()
{
	//nhap ten nguoi choi
	inputName();

	//bat dau choi game
	startGame();
}

void processMode(int)
{
	switch (choose)
	{
	case 1:
		playGame();
		break;
	default:
		break;
	}
}

int main()
{
	//hien thi menu
	displayMenu();

	//nhap lua chon
	cin >> choose;

	//xu ly chuc nang
	processMode(choose);
	system("pause");
    return 0;
}

