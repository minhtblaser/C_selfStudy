#include "Person.cpp"
#include <iostream>

using namespace std;

class Student : public Person {
    private:
        float gpa;
    public:
        Student(string name, int age, string address, float gpa) : Person(name, age, address){
            this->gpa = gpa;
        }
        void setGpa(float gpa){
            this->gpa = gpa;
        }
        float getGpa(){
            return this->gpa;
        }
        void display() {
            Person::display();
            cout << "GPA: " << gpa << endl;
        }
};