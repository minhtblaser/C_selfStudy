#include "Person.cpp"
#pragma once
class Children : public Person {
    public: 
        Children(){}
        Children(string name, int age, string add, vector<Book>vb) : Person(name, age, add, vb){}
        long moneyPay(){
            return this->getVb().size() * 5000;
        }
        void display()
	    {   
		cout << "Children!" << endl;
		Person::display();  
	    }
};