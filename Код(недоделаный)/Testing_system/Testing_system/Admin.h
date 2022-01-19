#pragma once

#include <iostream>

#include "Guest.h"
#include "Uzer.h"
#include "Test.h"
#include "Statistic.h"
#include "Console.h"

using namespace std;

class AdminItem
{
public:
	AdminItem()
	{
	}
	~AdminItem()
	{
	}

private:

};


class Admin
{
public:
	Admin()
	{

	}
	~Admin()
	{

	}

	void Uzers(int height, int widht)
	{
		Con.SetColor(Con.EXE_COLOR);
		Con.Print_Message_By_Coord(2, height - 37, " Add ", widht);

		Con.SetColor(Con.MSG_COLOR);
		Con.Print_Message_By_Coord(2, height - 35, " Delete ", widht);


		char ch = 0;

		while (ch != esc)
		{
			switch (ch)
			{
			case up:
				if (currentidx != 0)
				{
					if (currentidx > 0)
						currentidx--;

					if (currentidx == 0)
					{
						Con.SetColor(Con.MSG_COLOR);
						Con.Print_Message_By_Coord(2, height - 35, " Delete ", widht);

						Con.SetColor(Con.EXE_COLOR);
						Con.Print_Message_By_Coord(2, height - 37, " Add ", widht);
					}
				}
				break;
			case down:
				if (currentidx < 1)
					currentidx++;

				if (currentidx == 1)
				{
					Con.SetColor(Con.MSG_COLOR);
					Con.Print_Message_By_Coord(2, height - 37, " Add ", widht);

					Con.SetColor(Con.EXE_COLOR);
					Con.Print_Message_By_Coord(2, height - 35, " Delete ", widht);
				}
				break;
			case enter:
				system("cls");

				if (currentidx == 0)
				{
//					Guest1.Add();
					UzerItem1.REGISTRACIA(height, widht);
					system("cls");
					Con.SetColor(Con.EXE_COLOR);
					Con.Print_Message_By_Coord(2, height - 37, " Add ", widht);

					Con.SetColor(Con.MSG_COLOR);
					Con.Print_Message_By_Coord(2, height - 35, " Delete ", widht);
				}
				if (currentidx == 1)
				{
					Con.Print_Message_By_Coord(2, height - 35, " cin Login deleted ", widht);
					string Log = {""};
					cin >> Log;
					Uzer1.Delete(Log);
				}
				break;
			default:

				break;
			}
			Con.SetColor(Con.MSG_COLOR);


			ch = _getch();
		}

	}

	void Start(int height, int widht)
	{
		system("cls");

		Con.SetColor(Con.MSG_COLOR);
		Con.Print_Message_By_Coord(2, height - 35, " Statistics ", widht);

		Con.SetColor(Con.MSG_COLOR);
		Con.Print_Message_By_Coord(2, height - 33, " Tests ", widht);

		Con.SetColor(Con.EXE_COLOR);
		Con.Print_Message_By_Coord(2, height - 37, " Uzers ", widht);


		char ch = 0;

		while (ch != esc)
		{
			switch (ch)
			{
			case up:
				if (currentidx != 0)
				{
					if (currentidx > 0)
						currentidx--;

					if (currentidx == 0)
					{
						Con.SetColor(Con.MSG_COLOR);
						Con.Print_Message_By_Coord(2, height - 35, " Statistics ", widht);

						Con.SetColor(Con.EXE_COLOR);
						Con.Print_Message_By_Coord(2, height - 37, " Uzers ", widht);
					}
					if (currentidx == 1)
					{
						Con.SetColor(Con.MSG_COLOR);
						Con.Print_Message_By_Coord(2, height - 33, " Tests ", widht);

						Con.SetColor(Con.EXE_COLOR);
						Con.Print_Message_By_Coord(2, height - 35, " Statistics ", widht);
					}
				}
				break;
			case down:
				if (currentidx < 2)
					currentidx++;

				if (currentidx == 1)
				{
					Con.SetColor(Con.MSG_COLOR);
					Con.Print_Message_By_Coord(2, height - 37, " Uzers ", widht);

					Con.SetColor(Con.EXE_COLOR);
					Con.Print_Message_By_Coord(2, height - 35, " Statistics ", widht);
				}
				if (currentidx == 2)
				{
					Con.SetColor(Con.MSG_COLOR);
					Con.Print_Message_By_Coord(2, height - 35, " Statistics ", widht);

					Con.SetColor(Con.EXE_COLOR);
					Con.Print_Message_By_Coord(2, height - 33, " Tests ", widht);
				}

				break;
			case enter:
				if (currentidx == 0)
				{
					system("cls");
					Uzers(height, widht);
				}
				else if (currentidx == 1)
				{

				}
				else if (currentidx == 2)
				{
					system("cls");
					string test_name;
					Con.SetColor(Con.MSG_COLOR);
					Con.Print_Message_By_Coord(2, height - 37, "Enter the name of the test ", widht);

//					getline(cin, test_name);
//					Test1.SetName(test_name);
					Ñategory1.Start(height, widht);
//					Test1.AddQuestions();
//					Test1.Print();
				}
				break;
			default:

				break;
			}
			Con.SetColor(Con.MSG_COLOR);


			ch = _getch();
		}
	}


private:
	int currentidx;
	Guest Guest1;
	UzerItem UzerItem1;
	Uzer Uzer1;
	Ñategory Ñategory1;
	Console Con;
	enum keys { esc = 27, up = 72, down = 80, enter = 13, tab = 9, del = 53, one = 49, two = 50, nine = 57, six = 54 };

};
