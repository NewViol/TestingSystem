#pragma once

//#include <windows.h>

class MENU
{
public:
	MENU()
	{

	}
	~MENU()
	{

	}

	void Print(int x, int y, int Width, Console& Con1)
	{

		Con1.Print_Message_By_Coord(x, y, " LOGIN ", Width);
		Con1.Print_Message_By_Coord(x, y + 2, " REGISTRATION ", Width);

		//Con1.Print_Message_By_Coord(x, y, " !! LOGIN ", Width);
		//Con1.Print_Message_By_Coord(x, y + 2, " !! PASSWORD ", Width);
		//Con1.Print_Message_By_Coord(x, y + 4, "    Identiti ", Width);
	}
 
private:

};
