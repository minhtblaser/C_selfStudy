#include "Person.cpp"
#pragma once
class Adult : public Person {
    public: 
        Adult(){}
        Adult(string name, int age, string add, vector<Book>vb) : Person(name, age, add, vb){}
        long moneyPay(){
            return this->getVb().size() * 10000;
        }
        void display()
	    {   
		cout << "Adult!" << endl;
		Person::display();  
	    }
};