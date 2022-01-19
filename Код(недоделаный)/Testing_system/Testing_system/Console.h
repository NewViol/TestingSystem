#pragma once

#include <iostream>
#include <Windows.h>

using namespace std;

class Console
{
public:
	const int EXE_COLOR = 10;
	const int SELECT_COLOR = 11;

	const int MSGBOX_COLOR = 7;
	const int MSG_COLOR = 15;

	Console()
	{
		con_hendle = GetStdHandle(STD_OUTPUT_HANDLE);
		//int text_color = 15;
		//int back_color = 0;
		//int dir_color = back_color + text_color;

		//text_color = 9;
		//back_color = 0;
		//int file_color = back_color + text_color;

		//text_color = 15;
		//back_color = 4;
		//int select_color_dir = back_color + text_color;

		//text_color = 8;
		//back_color = 3;
		//int select_color_file = back_color + text_color;
	}
	~Console()
	{

	}
	void Print_Message_By_Coord(int x, int y, const string& message, int shirina)
	{
		COORD con_coord = { x, y };
		SetConsoleCursorPosition(con_hendle, con_coord);
		int len = message.length();
		int count = shirina;
		if (len < shirina)
			count = shirina - len;
		f_Ochistka_M(con_coord, 1, shirina, ' ');
		cout << message;
	}

	void f_Ochistka_M(COORD con_coord, int visota, int chirina, char fill)
	{
		CONSOLE_SCREEN_BUFFER_INFO screen;
		DWORD written;
		int y = con_coord.Y;
		GetConsoleScreenBufferInfo(con_hendle, &screen);
		for (int i = 0; i < visota; i++)
		{
			con_coord.Y = y + i;
			FillConsoleOutputCharacterA(con_hendle, fill, chirina, con_coord, &written);
		}
	}

	HANDLE GetHANDLE()
	{
		return con_hendle;
	}

	void SetColor(int color)
	{
		SetConsoleTextAttribute(con_hendle, color);
	}

private:
	HANDLE con_hendle;

};

