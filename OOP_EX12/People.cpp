#include <bits/stdc++.h>
#pragma once 

using namespace std;

class People {
    private:
        string name;
        int age;
        string job;
        string id;
    public:
        People(){}
        People(string name, int age, string job, string id) : name(name), age(age), job(job), id(id) {}
        string getName() { return name; }
        void setName(string name) { this->name = name;}
        string getJob()  { return job; }
        void setJob(string job) { this->job = job;}
        string getId()  { return id; }
        void setId(string id) { this->id = id;}
        int getAge()  { return age; }
        void setAge(int age) { this->age = age;}
        void display(){
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Job: " << job << endl;
            cout << "Id: " << id << endl;
        }
};