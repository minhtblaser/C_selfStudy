#include <iostream>

using namespace std;

class Student {
    private:
        string name;
        char gender;
        static int count;
    public:
        Student(){
            this->name = "Unknown";
            this->gender = 'u';
            count++;
        };
        Student(string name){
            this->name = name;
            this->gender = 'u';
            count++;
        };
        Student(char gender){
            this->name = "Unknown";
            this->gender = gender;
            count++;
        };
        Student(string name, char gender){
            this->name = name;
            this->gender = gender;
            count++;
        }
        void display(){
            cout << "Name: " << name << endl;
            if (gender == 'u'){
                cout << "Gender: unknown" << endl;
            } else if (gender == 'f'){
                cout << "Gender: female" << endl;
            } else {
                cout << "Gender: male" << endl;
            }
        }
        static int getCount();
};
int Student::count = 0;
int Student::getCount(){
    return count;
}
int main(){
    Student s1;
    s1.display();
    Student s2("MINH");
    s2.display();
    Student s3('f');
    s3.display();
    Student s4("Minh", 'm');
    s4.display();
    cout << Student::getCount() << endl;
    return 0;
}