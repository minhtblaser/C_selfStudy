#include "Employee.cpp"
#include <iostream>

using namespace std;

class PartTimeEmployee : public Employee {
    private:
        int workingHours;
    public:
        PartTimeEmployee(string name, int PaymentHours, int workingHours) : Employee(name, PaymentHours){
            this->workingHours = workingHours;
        }
        int calculateSalary(){
            return workingHours * getPaymentHours();
        }

};