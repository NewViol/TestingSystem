#pragma once

#include <iostream>
#include <fstream>
#include <list>

#include "Console.h"
#include "Admin.h"
#include "Guest.h"

using namespace std;

class UzerItem
{
public:
	UzerItem() : Login{ "" }, Password{ "" }, Identiti{ "" }
		, Surname{ "" }, Name{ "" }, Patronymic{ "" }, Phone{ "" }
	{

	}
	UzerItem(string Login1, string Password1, string Identiti1
		, string Surname1, string Name1, string Patronymic1, string Phone1
	) : Login{ Login1 }, Password{ Password1 }, Identiti{ Identiti1 }
		, Surname{ Surname1 }, Name{ Name1 }, Patronymic{ Patronymic1 }, Phone{ Phone1 }
	{

	}
	~UzerItem()
	{

	}
	bool REGISTRACIA(int height, int widht)
	{
		Con.Print_Message_By_Coord(60, height - 37, " !! LOGIN ", widht);
		cin >> Login; // проверка есть ли в файле записи с таким логином !!!!!!!!

		Con.Print_Message_By_Coord(60, height - 35, " !! PASSWORD ", widht);
		cin >> Password; // проверка что бы введенных символов было не меньше 8 !!!!!!!!

		Con.Print_Message_By_Coord(60, height - 33, " !! Identiti ", widht);
		cin >> Identiti;// проверка 


		Con.Print_Message_By_Coord(60, height - 31, " !! Surname ", widht);
		cin >> Surname;// проверка 

		Con.Print_Message_By_Coord(60, height - 29, " !! Name ", widht);
		cin >> Name;// проверка 

		Con.Print_Message_By_Coord(60, height - 27, " !! Patronymic ", widht);
		cin >> Patronymic;// проверка 

		Con.Print_Message_By_Coord(60, height - 25, " !! Phone ", widht);
		cin >> Phone;// проверка 


		// Если все данные введены коректно, регестрируем данного пользователя 
		// ( сохраняем все его данные в файл )
		ofstream fout("Login.bin", ios_base::binary | ios_base::out | ios_base::app);
		if (fout.is_open())
		{
			fout.write(Login.c_str(), 1024);
			fout.write(Password.c_str(), 1024);
			fout.write(Identiti.c_str(), 1024);

			fout.write(Surname.c_str(), 1024);
			fout.write(Name.c_str(), 1024);
			fout.write(Patronymic.c_str(), 1024);
			fout.write(Phone.c_str(), 1024);
			fout.close();
		}

		if (Identiti == "102356")
		{

		}
		else
		{

		}

		return true;
	}
	string GetLogin()
	{
		return Login;
	}

	string GetPassword()
	{
		return Password;
	}
	string GetIdentiti()
	{
		return Identiti;
	}
	string GetSurname()
	{
		return Surname;
	}
	string GetName()
	{
		return Name;
	}
	string GetPatronymic()
	{
		return Patronymic;
	}
	string GetPhone()
	{
		return Phone;
	}
	friend bool operator ==(const UzerItem& oper1, const UzerItem& oper2)
	{
		return oper1.Login == oper2.Login;
	}
	friend bool operator ==(const UzerItem& oper1, const string& oper2)
	{
		return oper1.Login == oper2;
	}

	//	friend bool operator ==(const UzerItem& oper1, const int& oper2)
//	{
//		return oper1.Login == oper2;
//	}

private:
	string Login;
	string Password;
	string Identiti;

	string Surname;
	string Name;
	string Patronymic;
	string Phone;
	Console Con;

};

//class FunctorLogin
//{
//public:
//	bool operator ()(UzerItem& oper1, UzerItem& oper2)
//	{
//		return oper1.GetLogin() < oper2.GetLogin();
//	}
//};


class Uzer
{
public:
	Uzer()
	{

	}
	~Uzer()
	{

	}
	//string GetIdentiti() 
	//{
	//	return Identiti;
	//}
	void Read(string Name_File)
	{
		ifstream fin(Name_File);
		if (fin.is_open())
		{
			//char str[1024];
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
				fin.read(Password, 1024);
				fin.read(Identiti, 1024);
				string tmpIdentiti = Identiti;

				fin.read(Surname, 1024);
				fin.read(Name, 1024);
				fin.read(Patronymic, 1024);
				fin.read(phone, 1024);
				Uzer1.push_back(UzerItem
					{ Login, Password, Identiti, Surname, Name, Patronymic, phone });
			}
			fin.close();
		}
	}



	void Add(UzerItem GuestItem1)
	{
		Uzer1.push_back(GuestItem1);
	}
	void Delete(string Login)
	{
		Read("Login.bin");
		int i = 0;
		list<UzerItem>::iterator trt = Uzer1.begin();
		for (; trt != Uzer1.end(); trt++)
		{
			if (Login == (*trt).GetLogin())
			{
				if ("102356" != (*trt).GetIdentiti())	// проверка на то что это НЕ АДМИН
				{
					Uzer1.remove((*trt));
				}
				else
				{
					return;
				}
				break;
			}
		}

		ofstream fout("Login.bin", ios_base::binary | ios_base::out);
		if (fout.is_open())
		{
			trt = Uzer1.begin();
			for (; trt != Uzer1.end(); trt++)
			{
				fout.write((*trt).GetLogin().c_str(), 1024);
				fout.write((*trt).GetPassword().c_str(), 1024);
				fout.write((*trt).GetIdentiti().c_str(), 1024);

				fout.write((*trt).GetSurname().c_str(), 1024);
				fout.write((*trt).GetName().c_str(), 1024);
				fout.write((*trt).GetPatronymic().c_str(), 1024);
				fout.write((*trt).GetPhone().c_str(), 1024);
				fout.close();
			}
		}
	}


private:
	list<UzerItem> Uzer1;

};


