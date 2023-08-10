#include<iostream>
#include<conio.h>
using namespace std;

void display(char A[15][30]);
void mapcreation(char A[15][30]);
void down(char A[15][30]);
void up(char A[15][30]);
void left(char A[15][30]);
void right(char A[15][30]);

int x = 4, y = 2;
int k = 9, l = 6;
int n = 1, m = 1;
int flag = 0, score = 0;
int index = 6,index1=2;
int countingF = 0, countingF1 = 0;
int countingB = 0, countingB1 = 0;
int flag1 = 0, flag2 = 0;
int main()
{
	char A[15][30];
	int cntr = 0;
	char choice;
	int val = 0;

	while (1)
	{
		if (cntr == 0)
		{
			cout << "    MENUE:\n";
			cout << "        w.up\n";
			cout << "        s.down\n";
			cout << "        a.left\n";
			cout << "        d.right\n\n";
			cout << "                             GAME IS LOADING";
		}
		if (cntr == 1000000000)
		{
			break;
		}
		cntr++;
	}

	system("cls");
	mapcreation(A);
	display(A);
	cout << endl;

	while (1)
	{
		cout << "Enter your move:";
		choice = _getch();
		system("cls");
		if (choice == 's' || choice == 'S')
		{
			flag = 1;
			down(A);
		}
		if (choice == 'w' || choice == 'W')
		{
			flag = 2;
			up(A);
		}
		if (choice == 'a' || choice == 'A')
		{
			flag = 3;
			left(A);
		}
		if (choice == 'd' || choice == 'D')
		{
			flag = 4;
			right(A);
		}
		if (A[n][m] == '.')
		{
			score++;
		}

		if (A[n][m] == '0')
		{
			system("cls");
			cout << "\n\n\nGame is Finished" << "\t\t\tScore:" << score << "\n\n\n\n\n";
			break;
		}

		if (A[n][m] == '#' )
		{
			system("cls");
			cout << "\n\n\nGame Over" << "\t\t\tScore:" << score << "\n\n\n\n\n";
			break;
		}
		if (A[n][m] == '<')
		{
			system("cls");
			cout << "\n\n\nGame Over" << "\t\t\tScore:" << score << "\n\n\n\n\n";
			break;
		}
		
		display(A);
		cout << endl;
	}

	return 0;
}

void display(char A[15][30])
{
	cout << "\n\n******welcome to Pack-man game*******\n\n";
	cout << "\t\t\tScore:" << score << endl;
	A[n][m] = '@';
	A[k][l] = '<';
	A[x][y] = '>';

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			cout << A[i][j];
		}
		cout << endl;
	}
}

void mapcreation(char A[15][30])
{
	
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if (i == 0 || i == 14)
			{
				A[i][j] = '#';
			}
			else if (j == 0 || j == 29)
			{
				A[i][j] = '#';
			}
			else if (i == 5 && j > 8 && j < 20)
			{
				A[i][j] = '#';
			}
			else if (i == 8 && j > 8 && j < 20)
			{
				A[i][j] = '#';
			}
			else if (j == 8 && i > 4 && i < 9)
			{
				A[i][j] = '#';
			}
			else if (j == 5 && i > 6 && i < 14)
			{
				A[i][j] = '#';
			}
			else if (i == 3 && j > 8 && j < 29)
			{
				A[i][j] = '#';
			}
			else if (j == 20 && i > 7 && i < 14)
			{
				A[i][j] = '#';
			}
			else if (countingF==0 && l<20 && flag1==0)
			{
				A[k][l] = '<';
				l++;
				A[k][index] = '.';
				index++;
				countingF++;
				if (l == 19)
				{
					flag1 = 1;
				}
			}
			else if (countingB == 0 && l>4&& flag1==1)
			{
				A[k][l] = '<';
				l--;
				A[k][index] = '.';
				index--;
				countingB++;
				if (l == 5)
				{
					flag1 = 0;
				}
			}
			else if (countingF1 == 0 && y < 29 && flag2 == 0)
			{
				A[x][y] = '>';
				y++;
				A[x][index1] = '.';
				index1++;
				countingF1++;
				if (y == 28)
				{
					flag2 = 1;
				}
			}
			else if (countingB1 == 0 && y > 2 && flag2 == 1)
			{
				A[x][y] = '>';
				y--;
				A[x][index1] = '.';
				index1--;
				countingB1++;
				if (y == 3)
				{
					flag2 = 0;
				}
			}
			else if (n > 0 && flag == 1)
			{
				A[n - 1][m] = ' ';
			}
			else if (n > 0 && flag == 2)
			{
				A[n + 1][m] = ' ';
			}
			else if (m > 0 && flag == 3)
			{
				A[n][m + 1] = ' ';
			}
			else if (m > 0 && flag == 4)
			{
				A[n][m - 1] = ' ';
			}
			else
				A[i][j] = '.';


		}
		cout << endl;
	}
	

	A[11][13] = '0';
	countingF = 0;
	countingB = 0;
	countingF1 = 0;
	countingB1 = 0;
}

void down(char A[15][30])
{
	n++;
	mapcreation(A);
}

void up(char A[15][30])
{
	n--;
	mapcreation(A);
}

void left(char A[15][30])
{
	m--;
	mapcreation(A);
}

void right(char A[15][30])
{
	m++;
	mapcreation(A);
}

