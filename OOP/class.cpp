#include <iostream>
#include <cstring>
using namespace std;

class Student
{
private:
    char id[10];
    char name[100];
    int age;
    float mark;
    char address[100];
    static int count; // way 1 
public:
    // Student();
    Student(char *name, char *address, char *id, int age, float mark);
    void showInfo();
    void setId(char *id);
    void setName(char *name);
    void setAddress(char *address);
    void setAge(int age);
    void setMark(float mark);
    //get information
    int getAge();
    float getMark();
    char *getName();
    char *getAddress();
    char *getId();
    static int getCount(); // way 1
    // static int count; way 2
};
int Student::count = 0;
int Student::getCount(){
    return count;
}
// Student::Student()
// { // default create
//     cout << "\nCall no para constructor"<< endl;
//     this->name[0] = '\0';
//     this->address[0] = '\0';
//     this->id[0] = '\0';
//     this->age = 0;
//     this->mark = 0;
//     count++;
// }
Student::Student(char *name, char *address, char *id, int age, float mark)
 {
     strcpy_s(this->name, 99, name);
     strcpy_s(this->address, 99, address);
     strcpy_s(this->id, 99, id);
     this->age = age;
     this->mark = mark;
     count++;
 }
void Student::showInfo()
{
    cout << "Name: " << name << endl;
    cout << "ADDRESS: " << address << endl;
    cout << "Id: " << id << endl;
    cout << "Age: " << age << endl;
    cout << "Mark: " << mark << endl;
}
void Student::setId(char *id){
    strcpy_s(this->id,99,id);
}
void Student::setName(char *name){
    strcpy_s(this->name,99,name);
}
void Student::setAddress(char *address){
    strcpy_s(this->address,99,address);
}
void Student::setAge(int age){
    this->age = age;
}
void Student::setMark(float mark){
    this->mark = mark;
}
//get information
int Student::getAge(){
    return this->age;
}
float Student::getMark(){
    return this->mark;
}
char *Student::getName(){
    return this->name;
}
char *Student::getAddress(){
    return this->address;
}
char *Student::getId(){
    return this->id;
}
int main()
{
    char *name = new char[100];
    strcpy_s(name, 99, "Trinh Ngoc Minh");
    char *id = new char[100];
    strcpy_s(id, 99, "12345");
    char *address = new char[100];
    strcpy_s(address, 99, "28/2, duong 25, khu pho Long Hoa");
    Student s1(name, address, id, 19, 9.8); // 5 paras
    s1.showInfo();
    // Student s1; // goi ham tao 0 tham so 
    cout << Student::getCount() << endl;
    // cout << s1.count << endl;  way 2
    return 0;
}
