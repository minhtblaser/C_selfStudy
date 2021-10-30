#include <iostream> 

using namespace std;

class Person {
    private:
        string name;
        int dob;
    public:
        Person(string name, int dob){
            this->name = name;
            this->dob = dob;
        }
        void setName(string name){
            this->name = name;
        }
        string getName(){
            return this->name;
        }
        void setDob(int dob){
            this->dob = dob;
        }
        int getDob(){
            return this->dob;
        }
};
class Student : public Person {
    private:
        float gpa;
    public:
        Student(string name, int dob, float gpa) : Person(name, dob){
            this->gpa = gpa;
        }
        void setGpa(float gpa){
            this->gpa = gpa;
        }
        float getGpa(){
            return this->gpa;
        }
        void display() {
            cout << "Name: " << getName() << endl;
            cout << "Date of birth : " << getDob() << endl;
            cout << "GPA: " << gpa << endl;
        }
};

int main(){
    Student s("Minh", 2002, 9.9);
    s.display();
    return 0;
}