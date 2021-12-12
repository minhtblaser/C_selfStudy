#pragma once
#include "People.cpp"
class Family : public People{
private:
	string nameF;
	string status;
	string add;
	vector<People> p;
public:
	Family()
	{
		nameF = p[0].getName();
	}
	Family(string nameF,string status,string add, vector<People>p) :nameF(nameF),status(status), add(add), p(p)
	{
		nameF = p[0].getName();
	}
	string getNameF()
	{
		return nameF;
	}
	string getStatus()
	{
		return status;
	}
	string getAdd()
	{
		return add;
	}
	vector<People> getP()
	{
		return p;
	}
	void display()
	{
		cout << "Householder's name: " << nameF << endl;
		cout << "Number Member: " << p.size() << endl;
		cout << "Address: " << add << endl;
		cout << "Status: " << status << endl;
		cout << "List Information Member" << endl;
		for (int i = 0; i < p.size(); i++)
		{
			p[i].display();
		}
	}
	static vector<Family> getPoorHousehold(vector<Family>fa)
	{
		vector<Family> v;
		for (int i = 0; i < fa.size(); i++)
		{
			if (fa[i].getStatus() == "poor")
			{
				v.push_back(fa[i]);
			}
		}
		return v;
	}
	static vector<Family> findFamilySurename(vector<Family>fa, string surename)
	{
		vector<Family> v;
		for (int i = 0; i < fa.size(); i++)
		{
			if (fa[i].getNameF() == surename)
			{
				v.push_back(fa[i]);
			}
		}
                return v;
	}
};