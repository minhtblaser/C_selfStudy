// Trinh Ngoc Minh
// 6151071073
#include <bits/stdc++.h>

using namespace std;

class Student
{
private:
    string name;
    float mark_math, mark_literals;
public:
    void getInformation();
    void setName(string name);
    void setMath(float mark_math);
    void setLiter(float mark_literals);
    float getMath();
    float getLiterals();
    float getAverage();
    string getName();
    void classifyStudent();
    void display();
};
void Student::getInformation(){
    fflush(stdin);
    cout << "Name: ";
    getline(std::cin,name);
    cout << "Math: ";
    cin >> mark_math;
    cout << "Literals: ";
    cin >> mark_literals;
}
void Student::setName(string name){
    this->name = name;
}
void Student::setMath(float mark_math){
    this->mark_math = mark_math;
}
void Student::setLiter(float mark_literals){
    this->mark_literals = mark_literals;
}
string Student::getName(){
    return name;
}
float Student::getMath(){
    return mark_math;
}
float Student::getLiterals(){
    return mark_literals;
}
float Student::getAverage(){
    return (getMath()+getLiterals())/2;
}
void Student::classifyStudent(){
    if(getAverage()>=8){
        cout << "classify: Excellent\n";
    } else if (getAverage()>=7 && getAverage()<8){
        cout << "classify: Good\n";
    } else if (getAverage() >= 5 && getAverage() <7){
        cout << "classify: Normal\n";
    } else {
        cout << "classify: Bad\n";
    }
}
void Student::display()
{
    cout << "Name: " << getName() << endl;
    cout << "Literals: " << getLiterals() << endl;
    cout << "Math: " << getMath() << endl;
    cout << "Average: " << getAverage() << endl;
    classifyStudent();
}
int main()
{
    Student s1,s2,s3;
    s1.getInformation();
    s2.getInformation();
    s3.getInformation();
    cout << "\nDATA STUDENT\n";
    s1.display();
    cout << endl;
    s2.display();
    cout << endl;
    s3.display();
    return 0;
}
