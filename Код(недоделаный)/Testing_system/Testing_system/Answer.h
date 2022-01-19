#pragma once
#include <iostream>
#include <string>

using namespace std;

class Answer
{
public:
    Answer() : IsCorrect{ false }, number{ 0 }, Nameanswer{ "" }
    {

    }

    Answer(string answer1, int number1, bool IsCorrect1)
        : IsCorrect{ IsCorrect1 }, number{ number1 }, Nameanswer{ answer1 }
    {

    }

    Answer(string answer1) : Nameanswer{ answer1 }
    {

    }

    void Start(int height, int widht)
    {
        IsCorrect = true;
    }
    void Print(int x, int height, int widht, Console Con1)
    {
        Con1.Print_Message_By_Coord(x, height, Nameanswer, widht);
        //cout << number << ". " << Nameanswer << endl;
        //for (int i = 0; i < answers.size(); i++)
        //{
        //	answers[i].Print();
        //}
        //cout << endl;
    }

    void SetAnsw(string dop_ans)
    {
        Nameanswer = dop_ans;
    }
    string GetAnsw() 
    {
        return Nameanswer;
    }

    void SetNum(int dop_num) 
    {
        number = dop_num;
    }
    int GetNum() 
    {
        return number;
    }

    void SetIsCorrct(bool IsCor) 
    {
        IsCorrect = IsCor;
    }
    int GetIsCorrect() 
    {
        return IsCorrect;
    }

    void Print() 
    {
        if (IsCorrect == true) 
        {
            cout << number << ") " << Nameanswer << "(Правильный)" << endl;
        }
        else 
        {
            cout << number << ") " << Nameanswer << "(Не правильный)" << endl;
        }
    }
    ~Answer() 
    {

    }
private:
    string Nameanswer;
    int number;
    bool IsCorrect;

};