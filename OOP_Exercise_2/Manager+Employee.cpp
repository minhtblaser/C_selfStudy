#include <iostream>

using namespace std;  

class Employee {
    private:
        string name;
        int salary; //
    public:
        Employee(string name, int salary)
        {
            this->name = name;
            this->salary = salary;
        }
        void setName(string name){
            this->name = name;
        }
        string getName(){
            return this->name;
        }
        void setSalary(int salary){
            this->salary = salary;
        }
        int getSalary(){
            return this->salary;
        }
        void display(){
            cout << "Name: " << name << endl;
            cout << "Salary: " << salary << endl;
        }
};
class Manager : public Employee {
    private:
        int bonus;
    public:
        Manager(string name, int salary, int bonus):Employee(name, salary){
            this->bonus = bonus;
        }
        int getBonus(){
            return bonus;
        }
        void setBonus(int bonus){
            this->bonus = bonus;
        }
        int getSalary(){
            return Employee::getSalary() + bonus;
        }
        void display(){
            cout<< "Name: " << getName() << endl;
            cout<< "Salary: " << getSalary() << endl;
        }
};

int main(){
    Employee s("Tri", 10000);
    s.display();
    Manager m("Minh", 10000, 5000);
    m.display();
    return 0;
}
