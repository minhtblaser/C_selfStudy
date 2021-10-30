#include "Employee.cpp"
#include <iostream>

using namespace std;

class FullTimeEmployee : public Employee {
    public:
        FullTimeEmployee(string name, int PaymentHours) : Employee(name, PaymentHours){
        }
        int calculateSalary(){
            return 8 * getPaymentHours();
        }

};