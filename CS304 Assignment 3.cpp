// CS304 Assignment 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#define DEBUG		//for debugging... Comment this line to enter normal mode.
using namespace std;

//Declarations...

class player
{
private:
	string name_;
	string code_;
	int age_{};
protected:
	bool setName(const string&);
	const string getName() const;
	bool setCode(const string&);
	string getCode() const;
	bool setAge(const int&);
	int getAge() const;
public:
	virtual ~player();
	player();
	virtual bool setData(const string& name,const string& code,const int& age, const int& runs, const int& overs_OR_innings);
	virtual void display() const;
};



class bowler: public player
{
private:
	int runs_conceded_;
	int total_overs_;
	double bowling_average_;
	bool calculateBowlingAverage();
public:
	bowler();
	virtual bool setData(const string& name,const string& code,const int& age, const int& runs, const int& overs_OR_innings);
	virtual void display() const;
};



class batsman: public player
{
private:
	int innings_played_;
	int runs_scored_;
	double batting_average_;
	bool calculateBattingAverage();
public:
	batsman();
	virtual bool setData(const string& name,const string& code,const int& age, const int& runs, const int& overs_OR_innings);
	virtual void display() const;
};


int main()
{
	int number_of_players = 0, iterator = -1, age, innings, runs, overs;
	char choice;
	string name, player_code;
	bool control_flag = true;
#ifndef DEBUG
	cout << "How many bowlers and batsman data you want to enter ? ";
	cin >> number_of_players;
	player **p = new player*[number_of_players];
	cout << endl << endl;
	do
	{
		iterator++;
		cout << "Enter choice: B for batsman, L for Bowler:" ;
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 'B':
		case 'b':
			cout << "Enter fowling data for batsman:" << endl << "Enter Name: ";
			cin >> name;
			cout << endl << "Enter PlayerCode: " ;
			cin >> player_code;
			cout << endl << "Enter Age: ";
			cin >> age;
			cout << endl << "Enter Innings: ";
			cin >> innings;
			cout << endl << "Enter runs: ";
			cin >> runs;
			cout << endl;
			p[iterator] = new batsman();
			p[iterator]->setData(name,player_code,age,runs,innings);
			//TODO: creating object...
			break;
		case 'L':
		case 'l':
			cout << "Enter fowling data for bowler:" << endl << "Enter Name: ";
			cin >> name;
			cout << endl << "Enter PlayerCode: " ;
			cin >> player_code;
			cout << endl << "Enter Age: ";
			cin >> age;
			cout << endl << "Enter Total Overs: ";
			cin >> overs;
			cout << endl << "Enter runs conceded: ";
			cin >> runs;
			cout << endl;
			p[iterator] = new bowler();
			p[iterator]->setData(name,player_code,age,runs,overs);
			//TODO: creating object...
			break;
		default:
			cout << "Invalid input. Try again.." << endl << endl;
		}
		cout << "Do you want to enter more data (Y for yes, N for no): ";
		cin >> choice;
		cout << endl;
		if (!(choice == 'Y' || choice == 'y'))
		{
			control_flag = false;
		}
	}
	while (control_flag && iterator <= number_of_players);
#endif

#ifdef DEBUG
	cout << "\t\t\t\t************************DEBUGGING MODE*********************" << endl << endl;
	cout << "\t\t\t\tValues are being added automatically into the program." << endl << endl;
	cout << "\t\t\t\tComment preprocessor directive #define DEBUG to enter normal mode" << endl << endl;

	cout << "How many bowlers and batsman data you want to enter ? 2" << endl << endl;
	number_of_players = 2;
	player **p = new player*[number_of_players];
	cout << "Enter choice: B for batsman, L for Bowler: B" << endl << endl;
			cout << "Enter fowling data for batsman:" << endl << endl << "Enter Name: Kamran";
			name = "Kamran";
			cout << endl << endl << "Enter PlayerCode: BT7" ;
			player_code = "B17";
			cout << endl << endl << "Enter Age: 23";
			age = 23;
			cout << endl << endl << "Enter Innings: 10";
			innings = 10;
			cout << endl << endl << "Enter runs: 500";
			runs = 500;
			cout << endl << endl;
			//TODO: creating object...
			p[0] = new batsman();
	p[0]->setData(name,player_code,age,runs,innings);
			cout << "Do you want to enter more data (Y for yes, N for no): Y" << endl << endl;
			cout << "Enter fowling data for bowler:" << endl << endl << "Enter Name: Imran";
			name = "Imran";
			cout <<endl << endl << "Enter PlayerCode: BW2" ;
			player_code = "BW2";
			cout << endl << endl << "Enter Age: 27";
			age = 27;
			cout << endl << endl << "Enter Total Overs: 48";
			overs = 48;
			cout << endl << endl << "Enter runs conceded: 230";
			runs = 230;
			cout << endl << endl;
			//TODO: creating object...
			p[1] = new bowler();
			p[1]->setData(name,player_code,age,runs,overs);
			cout << "Do you want to enter more data (Y for yes, N for no): N" << endl << endl;
	iterator = 1;
#endif

	for (int i = 0;i <= iterator; i++)
	{
		p[i]->display();
		cout << endl << endl;
	}
    return 0;
}


//Definitions...


player::~player()
{
}

player::player()
{
	
}

bool player::setName(const string& name)
{
	name_ = name;
	return true;
}

const string player::getName() const
{
	return name_;
}

bool player::setCode(const string& code)
{
	code_ = code;
	return true;
}

string player::getCode() const
{
	return code_;
}

bool player::setAge(const int& age)
{
	if(age > 14)
	{
		age_ = age;
		return true;
	}
	return false;
}

int player::getAge() const
{
	return age_;
}

bool player::setData(const string& name, const string& code, const int& age, const int& runs, const int& overs_OR_innings)
{
	//will be overridden by derived classes.
	return true;
}

void player::display() const
{
	//will be overridden by derived classes.
}


void bowler::display() const
{
	cout << "Displaying Bowler Information" << endl;
	cout << "-----------------------------------" << endl << endl;
	cout << "Bowler Name: " << player::getName() << endl;
	cout << "Bowler Code: " << player::getCode() << endl;
	cout << "Bowler Age: " << player::getAge() << endl;
	cout << "Bowling Average: " << bowling_average_ << endl;
}


bowler::bowler()
{
}

bool batsman::setData(const string& name, const string& code, const int& age, const int& runs, const int& overs_OR_innings)
{

	if(player::setName(name) == true &&
		player::setCode(code) == true &&
		player::setAge(age) == true &&
		runs > 0 && overs_OR_innings > 0)
	{
		runs_scored_ = runs;
		innings_played_ = overs_OR_innings;
		if (calculateBattingAverage())
		{
			return true;	
		}
	}
	return false;
}

bool bowler::calculateBowlingAverage()
{
	if (total_overs_ != 0)
	{
		bowling_average_ = runs_conceded_ / total_overs_;
		return true;
	}
	return false;
}

void batsman::display() const
{
	cout << "Displaying Batsman Information" << endl;
	cout << "-----------------------------------" << endl << endl;
	cout << "Batsman Name: " << player::getName() << endl;
	cout << "Batsman Code: " << player::getCode() << endl;
	cout << "Batsman Age: " << player::getAge() << endl;
	cout << "Batting Average: " << batting_average_ << endl;
}

batsman::batsman()
{
}

bool bowler::setData(const string& name, const string& code, const int& age, const int& runs, const int& overs_OR_innings)
{

	if( player::setName(name) == true &&
		player::setCode(code) == true &&
		player::setAge(age) == true &&
		overs_OR_innings > 0 && runs > 0)
	{
		total_overs_ = overs_OR_innings;
		runs_conceded_ = runs;
		if (calculateBowlingAverage())
		{
			return true;
		}
	}
	return false;
}

bool batsman::calculateBattingAverage()
{
	if (runs_scored_ != 0)
	{
		batting_average_ = runs_scored_ / innings_played_;
		return true;
	}
	return false;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
