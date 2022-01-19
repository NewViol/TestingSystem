//#pragma once
//#include <iostream>
//#include "Question.h";
//#include "Console.h"
//
//using namespace std;
//
//
//template<class testing1>
//class Start
//{
//public:
//	Start()
//	{
//
//	}
//	~Start()
//	{
//
//	}
//
//	void Start1(int height, int widht)
//	{
//		RefreshVectorTmp(height - 37, widht);
//		char ch = 0;
//		int H = -37;
//		currentidx = 0;
//		int CatSize;
//		while (ch != esc)
//		{
//			switch (ch)
//			{
//			case up:
//				CatSize = VectorTmp.size();
//				if ((currentidx != 0) && (0 < CatSize))
//				{
//					if (currentidx > 0)
//						currentidx--;
//
//					Con.SetColor(Con.MSG_COLOR);
//					VectorTmp[currentidx + 1].Print(2, height + H, widht, Con);
//
//					H -= 2;
//					Con.SetColor(Con.EXE_COLOR);
//					VectorTmp[currentidx].Print(2, height + H, widht, Con);
//				}
//				break;
//			case down:
//				CatSize = VectorTmp.size();
//				if ((currentidx <= (CatSize - 2)) && (0 < CatSize))
//				{
//					currentidx++;
//
//					Con.SetColor(Con.MSG_COLOR);
//					VectorTmp[currentidx - 1].Print(2, height + H, widht, Con);
//
//					H += 2;
//					Con.SetColor(Con.EXE_COLOR);
//					VectorTmp[currentidx].Print(2, height + H, widht, Con);
//				}
//				break;
//			case Right:
//
//				AddVectorTmp(height - 38, widht);
//				RefreshVectorTmp(height - 37, widht);
//				break;
//			case Left:
//
//				//DelÑategory(currentidx);
//				//RefreshÑategory(height - 37, widht);
//				break;
//			case enter:
//				CatSize = VectorTmp.size();
//				if (0 < CatSize)
//				{
//					VectorTmp[currentidx].Start(height, widht);
//					RefreshVectorTmp(height - 37, widht);
//				}
//				break;
//			default:
//
//				break;
//			}
//			Con.SetColor(Con.MSG_COLOR);
//			ch = _getch();
//		}
//	}
//	void AddVectorTmp(int height, int widht, string Name)
//	{
//		string nameTmpp;
//		Con.Print_Message_By_Coord(15, height, Name, widht);
//		//cin.ignore(32767, '\n');
//		//getline(cin, nameÑategor);
//		cin >> nameTmpp;
//		testing1 TestIt{ nameTmpp };
//		VectorTmp.push_back(TestIt);
//		system("cls");
//	}
//	void RefreshVectorTmp(int height, int widht)
//	{
//		system("cls");
//		cout << "	" << NameTmp << endl;
//		for (int i = 0; i < VectorTmp.size(); i++)
//		{
//			Con.SetColor(Con.MSG_COLOR);
//			VectorTmp[i].Print(2, height, widht, Con);
//			height += 2;
//		}
//	}
//
//	void Print(int x, int height, int widht, Console Con1)
//	{
//		Con1.Print_Message_By_Coord(x, height, NameTmp, widht);
//	}
//
//private:
//	int currentidx;
//	string NameTmp;
//
//	vector<testing1> VectorTmp;
//	Console Con;
//	enum keys {
//		esc = 27, Left = 75, Right = 77, up = 72, down = 80, enter = 13
//		, tab = 9, del = 53, one = 49, two = 50, nine = 57, six = 54
//	};
//
//};
//
