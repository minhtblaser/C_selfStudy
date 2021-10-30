#include <iostream>

using namespace std;

class Student {
    private:
        int id;
        string name;
        int age;
        string address;
    public:
        Student(int id, string name, int age, string address){
            this->id = id;
            this->name = name;
            this->age = age;
            this->address = address;
        }
        int getId();
        string getName();
        int getAge();
        string getAddress();
};

int Student::getId(){
    return id;
}
int Student::getAge(){
    return age;
}
string Student::getName(){
    return name;
}
string Student::getAddress(){
    return address;
}


int main(){
    Student  p(1001, "Quynh", 24, "Ha Noi");
	cout << "Id: " << p.getId() << endl;
	cout << "Name: " << p.getName() << endl;
	cout << "Age: " << p.getAge() << endl;
	cout << "Address: " << p.getAddress() << endl;
    return 0;
}