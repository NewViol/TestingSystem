#pragma once
#include <iostream>

#include "Question.h";

using namespace std;

class TestItem
{
public:
	TestItem()
	{

	}
	TestItem(const vector<Question> questions2, const double score1, const double percents1
		, const string key1, string name1)
		: nameTest{ name1 }, questions1{ questions2 }, score{ score1 }, percents{ percents1 }, key{ key1 }
	{

	}
	TestItem(string name1) : nameTest{ name1 }
	{

	}

	~TestItem()
	{

	}


	void Start(int height, int widht)
	{
		RefreshQuestion(height - 37, widht);
		char ch = 0;
		int H = -37;
		currentidx = 0;
		int CatSize;
		while (ch != esc)
		{
			switch (ch)
			{
			case up:
				CatSize = questions1.size();
				if ((currentidx != 0) && (0 < CatSize))
				{
					if (currentidx > 0)
						currentidx--;

					Con.SetColor(Con.MSG_COLOR);
					questions1[currentidx + 1].Print(2, height + H, widht, Con);

					H -= 2;
					Con.SetColor(Con.EXE_COLOR);
					questions1[currentidx].Print(2, height + H, widht, Con);
				}
				break;
			case down:
				CatSize = questions1.size();
				if ((currentidx <= (CatSize - 2)) && (0 < CatSize))
				{
					currentidx++;

					Con.SetColor(Con.MSG_COLOR);
					questions1[currentidx - 1].Print(2, height + H, widht, Con);

					H += 2;
					Con.SetColor(Con.EXE_COLOR);
					questions1[currentidx].Print(2, height + H, widht, Con);
				}
				break;
			case Right:

				AddQuestion(height - 38, widht);
				RefreshQuestion(height - 37, widht);
				break;
			case Left:

				//Del—ategory(currentidx);
				//Refresh—ategory(height - 37, widht);
				break;
			case enter:
				CatSize = questions1.size();
				if (0 < CatSize)
				{
					questions1[currentidx].Start(height, widht);
					RefreshQuestion(height - 37, widht);
				}
				break;
			default:

				break;
			}
			Con.SetColor(Con.MSG_COLOR);
			ch = _getch();
		}
	}
	void AddQuestion(int height, int widht)
	{
		string nameQuestion = {""};
		Con.Print_Message_By_Coord(15, height, "¬‚Â‰ËÚÂ ‚ÓÔÓÒ ", widht);
		//cin.ignore(32767, '\n');
		//getline(cin, name—ategor);
		cin >> nameQuestion;
		Question QuestionIt{ nameQuestion };
		questions1.push_back(QuestionIt);
		system("cls");
	}
	void RefreshQuestion(int height, int widht)
	{
		system("cls");
		cout << "	" << nameTest << endl;
		for (int i = 0; i < questions1.size(); i++)
		{
			Con.SetColor(Con.MSG_COLOR);
			questions1[i].Print(2, height, widht, Con);
			height += 2;
		}
	}

	//		AddQuestion();

	//void AddQuestion(int number1)
	//{
	//	//int y = 1;
	//	//int num = 1;
	//	//while (y != 0)
	//	//{
	//		//Question Question2;
	//		//Question2.Start(num);

	//		//questions.push_back(Question2);

	//	//	cout << "ƒÓ·‡‚ËÚ¸ Â˘∏ ‚ÓÔÓÒ? (ƒ‡ - 1, ÕÂÚ - 0)" << endl;
	//	//	cin >> y;
	//	//	num++;
	//	//}
	//}
	void Print(int x, int height, int widht, Console Con1)
	{
		Con1.Print_Message_By_Coord(x, height, nameTest, widht);
		//for (int i = 0; i < questions.size(); i++)
		//{
		//	questions[i].Print();
		//}
		//cout << endl;
	}



	void SetScore(const double score1)
	{
		score = score1;
	}
	double GetScore()
	{
		return score;
	}

	void SetPercents(const double percents1)
	{
		percents = percents1;
	}
	double GetPercents()
	{
		return percents;
	}

	void SetKey(const string key1)
	{
		key = key1;
	}
	string GetKey()
	{
		return key;
	}

	void SetNameTest(const string TestName)
	{
		nameTest = TestName;
	}
	string GetName()
	{
		return nameTest;
	}

private:
	int currentidx;
	string nameTest;
	double score;
	double percents;
	string key;

	vector<Question> questions1;
	Console Con;
	enum keys {
		esc = 27, Left = 75, Right = 77, up = 72, down = 80, enter = 13
		, tab = 9, del = 53, one = 49, two = 50, nine = 57, six = 54
	};
};



class —ategoryItem
{
public:
	—ategoryItem()
	{

	}

	—ategoryItem(string NameCategory1) : NameCategory{ NameCategory1 }
	{

	}

	~—ategoryItem()
	{

	}
	void Del—ategoryItem()
	{

	}
	void Start(int height, int widht)
	{
		RefreshTest(height - 37, widht);
		char ch = 0;
		int H = -37;
		currentidx = 0;
		int CatSize;
		while (ch != esc)
		{
			switch (ch)
			{
			case up:
				CatSize = Test1.size();
				if ((currentidx != 0) && (0 < CatSize))
				{
					if (currentidx > 0)
						currentidx--;

					Con.SetColor(Con.MSG_COLOR);
					Test1[currentidx + 1].Print(2, height + H, widht, Con);

					H -= 2;
					Con.SetColor(Con.EXE_COLOR);
					Test1[currentidx].Print(2, height + H, widht, Con);
				}
				break;
			case down:
				CatSize = Test1.size();
				if ((currentidx <= (CatSize - 2)) && (0 < CatSize))
				{
					currentidx++;

					Con.SetColor(Con.MSG_COLOR);
					Test1[currentidx - 1].Print(2, height + H, widht, Con);

					H += 2;
					Con.SetColor(Con.EXE_COLOR);
					Test1[currentidx].Print(2, height + H, widht, Con);
				}
				break;
			case Right:

				AddTest(height - 38, widht);
				RefreshTest(height - 37, widht);
				break;
			case Left:

				//Del—ategory(currentidx);
				//Refresh—ategory(height - 37, widht);
				break;
			case enter:
				CatSize = Test1.size();
				if (0 < CatSize)
				{
					Test1[currentidx].Start(height, widht);
					RefreshTest(height - 37, widht);
				}
				break;
			default:

				break;
			}
			Con.SetColor(Con.MSG_COLOR);
			ch = _getch();
		}
	}
	void AddTest(int height, int widht)
	{
		string nameTest;
		Con.Print_Message_By_Coord(15, height, "¬‚Â‰ËÚÂ Ì‡Á‚‡ÌËÂ ÌÓ‚Ó„Ó ÚÂÒÚ‡ ", widht);
		//cin.ignore(32767, '\n');
		//getline(cin, name—ategor);
		cin >> nameTest;
		TestItem TestIt{ nameTest };
		Test1.push_back(TestIt);
		system("cls");
	}
	void RefreshTest(int height, int widht)
	{
		system("cls");
		cout << "	" << NameCategory << endl;
		for (int i = 0; i < Test1.size(); i++)
		{
			Con.SetColor(Con.MSG_COLOR);
			Test1[i].Print(2, height, widht, Con);
			height += 2;
		}
	}

	void Print(int x, int height, int widht, Console Con1)
	{
		Con1.Print_Message_By_Coord(x, height, NameCategory, widht);
	}

private:
	int currentidx;
	string NameCategory;
	string NumberTests;
	string key;

	vector<TestItem> Test1;
//	Start<TestItem> Starttmpl;

	Console Con;
	enum keys {
		esc = 27, Left = 75, Right = 77, up = 72, down = 80, enter = 13
		, tab = 9, del = 53, one = 49, two = 50, nine = 57, six = 54
	};
};


class —ategory
{
public:
	—ategory()
	{

	}
	~—ategory()
	{

	}

	void Start(int height, int widht)
	{
		Refresh—ategory(height - 37, widht);
		char ch = 0;
		int H = -37;
		currentidx = 0;
		int CatSize;
		while (ch != esc)
		{
			switch (ch)
			{
			case up:
				CatSize = —ategory1.size();
				if ((currentidx != 0) && (0 < CatSize))
				{
					if (currentidx > 0)
						currentidx--;

					Con.SetColor(Con.MSG_COLOR);
					—ategory1[currentidx + 1].Print(2, height + H, widht, Con);

					H -= 2;
					Con.SetColor(Con.EXE_COLOR);
					—ategory1[currentidx].Print(2, height + H, widht, Con);
				}
				break;
			case down:
				CatSize = —ategory1.size();
				if ((currentidx <= (CatSize - 2)) && (0 < CatSize))
				{
					currentidx++;

					Con.SetColor(Con.MSG_COLOR);
					—ategory1[currentidx - 1].Print(2, height + H, widht, Con);

					H += 2;
					Con.SetColor(Con.EXE_COLOR);
					—ategory1[currentidx].Print(2, height + H, widht, Con);
				}
				break;
			case Right:

				Add—ategory(height - 38, widht);
				Refresh—ategory(height - 37, widht);
				break;
			case Left:

				Del—ategory(currentidx);
//				Refresh—ategory(height - 37, widht);
				break;
			case enter:
				CatSize = —ategory1.size();
				if (0 < CatSize)
				{
					—ategory1[currentidx].Start(height, widht);
					Refresh—ategory(height - 37, widht);
				}
				break;
			default:

				break;
			}
			Con.SetColor(Con.MSG_COLOR);
			ch = _getch();
		}
	}
	void Add—ategory(int height, int widht)
	{
		string name—ategor;
		Con.Print_Message_By_Coord(15, height, "¬‚Â‰ËÚÂ Ì‡Á‚‡ÌËÂ ÌÓ‚ÓÈ Í‡ÚÂ„ÓËË ", widht);
		//cin.ignore(32767, '\n');
		//getline(cin, name—ategor);
		cin >> name—ategor;
		—ategoryItem —ategoryIt{ name—ategor };
		—ategory1.push_back(—ategoryIt);
		system("cls");
	}

	void Del—ategory(int CurIdx)
	{
//		—ategory1.erase(—ategory1.begin() + CurIdx);
	}

	void Refresh—ategory(int height, int widht)
	{
		system("cls");
		cout << " ‡ÚÂ„ÓËË :" << endl;
		for (int i = 0; i < —ategory1.size(); i++)
		{
			Con.SetColor(Con.MSG_COLOR);
			—ategory1[i].Print(2, height, widht, Con);
			height += 2;
		}
	}

	void Save()
	{

	}

	void Print()
	{

	}

private:
	int currentidx;
	vector<—ategoryItem> —ategory1;
	enum keys {
		esc = 27, Left = 75, Right = 77, up = 72, down = 80, enter = 13
		, tab = 9, del = 53, one = 49, two = 50, nine = 57, six = 54
	};
	Console Con;
};


