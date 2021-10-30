#include <iostream>
#pragma once  

using namespace std;

class Employee {
    private:
        string name;
        int PaymentHours;
    public:
        Employee(string name, int PaymentHours){
            this->name = name;
            this->PaymentHours = PaymentHours;
        }
        void setName(string name){
            this->name = name;
        }
        string getName(){
            return this->name;
        }
        void setPaymentHours(int PaymentHours){
            this->PaymentHours = PaymentHours;
        }
        int getPaymentHours(){
            return this->PaymentHours;
        }
        virtual int calculateSalary() = 0;
};
