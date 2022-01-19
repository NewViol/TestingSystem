#pragma once

#include <iostream>
#include <Windows.h>
#include <fstream>
#include "conio.h"

#include "Console.h"
#include "MENU.h"
#include "Admin.h"
#include "Guest.h"
#include "Uzer.h"

using namespace std;

class Screen
{
public:
	Screen() : AdminTrue{ false }, currentidx{ 0 }
	{

	}
	~Screen()
	{

	}
	//void Print()
	//{

	//}

	bool Find(string Name_File, string LoginTrue, string PasswordTrue)
	{
		ifstream fin(Name_File);
		if (fin.is_open())
		{
			char* Login = new char[1024]{};
			char* Password = new char[1024]{};
			char* Identiti = new char[1024]{};

			char* Surname = new char[1024]{};
			char* Name = new char[1024]{};
			char* Patronymic = new char[1024]{};
			char* phone = new char[1024]{};
			
			while (!fin.eof())
			{
				fin.read(Login, 1024);
				string tmpLogin = Login;
				if (LoginTrue == tmpLogin)
				{
					fin.read(Password, 1024);
					string tmpPassword = Password;
					if (PasswordTrue == tmpPassword)
					{
						fin.read(Identiti, 1024);
						string tmpIdentiti = Identiti;
						if (tmpIdentiti == "102356")
						{
							AdminTrue = true;
						}
						else 
						{
							AdminTrue = false;
						}
						return true;
					}
					else 
					{
						return false;
					}
				}
				else
				{
					fin.read(Password, 1024);
					fin.read(Identiti, 1024);

					fin.read(Surname, 1024);
					fin.read(Name, 1024);
					fin.read(Patronymic, 1024);
					fin.read(phone, 1024);
				}
			}
			fin.close();
			delete[] Password;
			delete[] Login;
			delete[] Identiti;
			delete[] Surname;
			delete[] Name;
			delete[] Patronymic;
			delete[] phone;
		}
		return false;
	}

	bool VHOD(int height, int widht)
	{
		string Login = { "" };
		Con.Print_Message_By_Coord(60, height - 37, " !! LOGIN ", widht);
		cin >> Login;
		
		string Password = { "" };
		Con.Print_Message_By_Coord(60, height - 35, " !! PASSWORD ", widht);
		cin >> Password;

		//string Identiti = { "" };
		//Con.Print_Message_By_Coord(60, height - 33, "    Identiti ", widht);
		//cin >> Identiti;

		// Проверка введенных данных

		if (Find("Login.bin", Login, Password))
		{
			return true;
		}
		// Если данные введены верные то допуск к личному кабинету 
		// Администратора или тестируемого взависимости от AdminTrue 

		/*
		Если данные введены не верные то вывод сообщения об ОШИБКЕ и
		возврат на страницу входа или регистрации
		*/

		return false;
	}


	void Start()
	{
		int w = 211, h = 40;

		HANDLE activeBuffer = Con.GetHANDLE();
		//Сначала задаем минимальные значения
		SMALL_RECT zeroWindow = { 0, 0, 100, 100 };
		COORD zBuffer = { 10, 10 };
		SetConsoleWindowInfo(activeBuffer, TRUE, &zeroWindow);
		SetConsoleScreenBufferSize(activeBuffer, zBuffer);

		//А уже потом изменяем значения на нужные нам
		COORD bufferSize = { w, h };
		SMALL_RECT windowSize = { 0, 0, w - 1, h - 1 };
		SetConsoleScreenBufferSize(activeBuffer, bufferSize);
		SetConsoleWindowInfo(activeBuffer, TRUE, &windowSize);

		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
		if (GetConsoleScreenBufferInfo(Con.GetHANDLE(), &consoleInfo))
		{
			int widht = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left;
			int height = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top;
			Con.SetColor(Con.SELECT_COLOR);
			mnu.Print(60, height - 37, widht, Con);

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
							Con.Print_Message_By_Coord(60, height - 35, " REGISTRATION ", widht);

							Con.SetColor(Con.EXE_COLOR);
							Con.Print_Message_By_Coord(60, height - 37, " LOGIN ", widht);
						}
					}
					break;
				case down:
					if (currentidx != 1)
					{
						if (currentidx == 0)
							currentidx++;

						Con.SetColor(Con.MSG_COLOR);
						Con.Print_Message_By_Coord(60, height - 37, " LOGIN ", widht);

						Con.SetColor(Con.EXE_COLOR);
						Con.Print_Message_By_Coord(60, height - 35, " REGISTRATION ", widht);
					}
					break;
				case tab:

					break;
				case enter:
					system("cls");
					if (currentidx == 0)
					{
						if (VHOD(height, widht))	// если login succeeded
						{
							if (AdminTrue)
							{
								Admin1.Start(height, widht);
							}
							else
							{
								Guest1.Start();
							}


							system("cls");
							Con.Print_Message_By_Coord(20, height - 38, " login succeeded", widht);
							mnu.Print(60, height - 37, widht, Con);
						}
						else
						{
							system("cls");
							Con.Print_Message_By_Coord(20, height - 38, " LOGIN FAILED TRY AGAIN ", widht);
							mnu.Print(60, height - 37, widht, Con);
						}
					}
					if (currentidx == 1)
					{
						if (UzerItem1.REGISTRACIA(height, widht))
						{
							system("cls");
							Con.Print_Message_By_Coord(20, height - 38, " REGISTRATION COMPLETED SUCCESSFULLY ", widht);
							mnu.Print(60, height - 37, widht, Con);
						}
						else
						{
							system("cls");
							Con.Print_Message_By_Coord(20, height - 38, " REGISTRATION FAILED TRY AGAIN ", widht);
							mnu.Print(60, height - 37, widht, Con);
						}
					}
					break;
				default:

					break;
				}
				Con.SetColor(Con.MSG_COLOR);

				ch = _getch();
			}

		}
	}

private:
	//int x;
	//int y;
	//int Width;
	//int Height;
	//int From;
	//int To;
	int currentidx;
	bool AdminTrue;
	Console Con;
	MENU mnu;
	UzerItem UzerItem1;
	Guest Guest1;
	Admin Admin1;
	Uzer Uzer1;
	enum keys { esc = 27, Left = 75, Right = 77, up = 72, down = 80, enter = 13
		, tab = 9, del = 53, one = 49, two = 50, nine = 57, six = 54 };

};
