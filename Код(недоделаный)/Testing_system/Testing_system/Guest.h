#pragma once

#include <iostream>
#include <list>

class GuestItem
{
public:
	GuestItem() : Login { "" }, Password { "" }, Identiti { "" }
		, Surname { "" }, Name { "" }, Patronymic { "" }, Phone { "" }
	{

	}
	GuestItem(string Login1, string Password1, string Identiti1
		, string Surname1, string Name1, string Patronymic1, string Phone1
	) : Login{ Login1 }, Password{ Password1 }, Identiti{ Identiti1 }
		, Surname{ Surname1 }, Name{ Name1 }, Patronymic{ Patronymic1 }, Phone{ Phone1 }
	{

	}
	~GuestItem()
	{

	}

	string GetLogin() 
	{
		return Login;
	}

private:
	string Login = { "" };
	string Password = { "" };
	string Identiti = { "" };

	string Surname = { "" };
	string Name = { "" };
	string Patronymic = { "" };
	string Phone = { "" };

};


class Guest
{
public:
	Guest()
	{

	}
	~Guest()
	{

	}

	void Read(string Name_File)
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
				fin.read(Password, 1024);
				fin.read(Identiti, 1024);
				string tmpIdentiti = Identiti;

				fin.read(Surname, 1024);
				fin.read(Name, 1024);
				fin.read(Patronymic, 1024);
				fin.read(phone, 1024);
				if (tmpIdentiti != "102356")
				{
					
					Guest1.push_back(GuestItem
						{ Login, Password, Identiti, Surname, Name, Patronymic, phone });
				}
			}
			fin.close();
		}
	}

	void Start()
	{


	}

	void Add(GuestItem GuestItem1)
	{
		Guest1.push_back(GuestItem1);
	}

	void Delete(string Login)
	{
		list<GuestItem>::iterator trt = Guest1.begin();
		for (; trt != Guest1.end(); trt++)
		{
			if (Login == (*trt).GetLogin())
			{
//				Guest1.remove((*trt));
			}
		}
	}

private:
	list<GuestItem> Guest1;

};
