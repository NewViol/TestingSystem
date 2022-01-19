#pragma once
#include <iostream>
#include "Answer.h"
#include <string>
#include <vector>
#include <string.h>

using namespace std;

//void vvod_stroki(char* string, int size)
//{
//    fgets(string, size, stdin);
//    if (string[0] == '\n')
//    {
//        fgets(string, size, stdin);
//    }
//    string[strlen(string) - 1] = '\0';
//}

class Question
{
public:
	Question() : answers{ }, NameQuestion{ "" }, number{ 0 }
	{

	}
	Question(vector<Answer> answers1, string question1, int number1)
		: answers{ answers1 }, NameQuestion{ question1 }, number{ number1 }
	{

	}
	Question(string question1) : NameQuestion{ question1 }
	{

	}
	//Question(string question1, int number1)
	//{
	//    question = question1;
	//    number = number1;
	//    AddAnswers();
	//}
	~Question()
	{

	}

	void SetAnsw(vector<Answer> dop_answ)
	{
		answers = dop_answ;
	}
	vector<Answer> GetAnsw()
	{
		return answers;
	}

	void SetNameQuestion(string dop_ques)
	{
		NameQuestion = dop_ques;
	}
	string GetNameQuestion()
	{
		return NameQuestion;
	}

	void SetNum(int dop_num)
	{
		number = dop_num;
	}
	int GetNum()
	{
		return number;
	}


	void Start(int height, int widht)// int number1, 
	{
		RefreshAnswers(height - 37, widht);
		char ch = 0;
		int H = -37;
		currentidx = 0;
		int CatSize;
		while (ch != esc)
		{
			switch (ch)
			{
			case up:
				CatSize = answers.size();
				if ((currentidx != 0) && (0 < CatSize))
				{
					if (currentidx > 0)
						currentidx--;

					Con.SetColor(Con.MSG_COLOR);
					answers[currentidx + 1].Print(2, height + H, widht, Con);

					H -= 2;
					Con.SetColor(Con.EXE_COLOR);
					answers[currentidx].Print(2, height + H, widht, Con);
				}
				break;
			case down:
				CatSize = answers.size();
				if ((currentidx <= (CatSize - 2)) && (0 < CatSize))
				{
					currentidx++;

					Con.SetColor(Con.MSG_COLOR);
					answers[currentidx - 1].Print(2, height + H, widht, Con);

					H += 2;
					Con.SetColor(Con.EXE_COLOR);
					answers[currentidx].Print(2, height + H, widht, Con);
				}
				break;
			case Right:

				AddAnswers(height - 38, widht);
				RefreshAnswers(height - 37, widht);
				break;
			case Left:

				//DelÑategory(currentidx);
				//RefreshÑategory(height - 37, widht);
				break;
			case enter:
				CatSize = answers.size();
				if (0 < CatSize)
				{
					answers[currentidx].Start(height, widht);
					RefreshAnswers(height - 37, widht);
				}
				break;
			default:

				break;
			}
			Con.SetColor(Con.MSG_COLOR);
			ch = _getch();
		}
	}

	void AddAnswers(int height, int widht)
	{
		string nameAnswer = { "" };
		Con.Print_Message_By_Coord(15, height, "Ââåäèòå Îòâåò ", widht);
		//cin.ignore(32767, '\n');
		//getline(cin, nameÑategor);
		cin >> nameAnswer;
		Answer AnswerIt{ nameAnswer };
		answers.push_back(AnswerIt);
		system("cls");
	}
	void RefreshAnswers(int height, int widht)
	{
		system("cls");
		cout << "	" << NameQuestion << endl;
		for (int i = 0; i < answers.size(); i++)
		{
			Con.SetColor(Con.MSG_COLOR);
			answers[i].Print(2, height, widht, Con);
			height += 2;
		}
	}

	//void AddAnswers()
	//{
	//	int y = 1;
	//	int num = 1;
	//	while (y != 0)
	//	{
	//		cout << "Ââåäèòå òåêñò îòâåòà" << endl;
	//		string Answer1;
	//		getline(cin, Answer1);
	//		cout << "Ýòî ïðàâèëüíûé îòâåò? (Äà - 1, Íåò - 0)" << endl;
	//		int IsCor = 0;
	//		cin >> IsCor;
	//		if (IsCor == 1)
	//		{
	//			Answer dop_answ(Answer1, num, true);
	//			answers.push_back(dop_answ);
	//		}
	//		else if (IsCor == 0)
	//		{
	//			Answer dop_answ(Answer1, num, false);
	//			answers.push_back(dop_answ);
	//		}
	//		else
	//		{
	//			cout << "Error" << endl;
	//			cout << "Îòâåò ÍÅáûë äîáàâëåí" << endl;
	//		}

	//		cout << "Äîáàâèòü åù¸ îòâåò? (Äà - 1, Íåò - 0)" << endl;
	//		cin >> y;
	//		num++;
	//	}
	//}


	void Print(int x, int height, int widht, Console Con1)
	{
		Con1.Print_Message_By_Coord(x, height, NameQuestion, widht);
		//cout << number << ". " << NameQuestion << endl;
		//for (int i = 0; i < answers.size(); i++)
		//{
		//	answers[i].Print();
		//}
		//cout << endl;
	}

private:
	int currentidx;
	string NameQuestion;
	int number;

	Console Con;
	vector<Answer> answers;

	enum keys {
		esc = 27, Left = 75, Right = 77, up = 72, down = 80, enter = 13
		, tab = 9, del = 53, one = 49, two = 50, nine = 57, six = 54
	};


};
