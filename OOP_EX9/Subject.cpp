#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Subject {
private:
	string nameSub;
	double point;
	int numberCredit;
	long money;
public:
	Subject() {}
	Subject(string name, double point, int n, long m) : nameSub(name), numberCredit(n), money(m), point(point) {}
	string getNameSub()
	{
		return nameSub;
	}
	int getNumberCredit()
	{
		return numberCredit;
	}
	long getMoney()
	{
		return money;
	}
	double getPoint()
	{
		return point;
	}
	void display()
	{
		cout << "Name Subject: " << nameSub << endl;
		cout << "Number Credit: " << numberCredit << endl;
		cout << "Money Of One Credit: " << money << endl;
	}
};