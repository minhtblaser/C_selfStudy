#include <iostream>
#pragma once

using namespace std;

class Person {
    private:
        string name;
        int age;
        string address;
    public:
    Person(string name, int age, string address){
        this->name = name;
        this->age = age;
        this->address = address;
    }
    void setName(string name){
        this->name = name;
    }
    string getName(){
        return this->name;
    }
    void setAddress(string address){
        this->address = address;
    }
    string getAddress(){
        return this->address;
    }
    void setAge(int age){
        this->age = age;
    }
    int getAge(){
        return this->age;
    }
    void display(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Address: " << address << endl;
    }
};

