#include "Person.cpp"
#include <iostream>

using namespace std;

class Teacher : public Person {
    private:
        float salary;
    public:
        Teacher(string name, int age, string address, float salary) : Person(name, age, address){
            this->salary = salary;
        }
        void setSalary(float salary) {
            this->salary = salary;
        }
        float getSalary(){
            return this->salary;
        }
        void display() {
            Person::display();
            cout << "Salary: " << salary << endl;
        }
};