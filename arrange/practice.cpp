#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

struct Employee{
    int id;
    char name[100];
    int age;
};
Employee *enter();
void printEmploy(Employee *sources);
void enterList(Employee **&sources, int n);
void printList(Employee **sources, int n);
void interChangeSort(Employee **&sources, int n);
void quickSort(Employee **&sources, int left, int right);
int main(){
    Employee **list;
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;
    enterList(list,n);
    cout << "======Data======\n";
    printList(list,n);
    interChangeSort(list,n);
    cout << "\n=====Data after arranging by age========\n";
    printList(list,n);
    quickSort(list,0,n-1);
    cout << "\n=====Data after arranging by name (quick sort)========\n";
    printList(list,n);
    delete list;
    return 0;
}
Employee *enter(){
    Employee *sources = new Employee;
    cout <<"-Enter id: ";
    cin>>sources->id;
    cin.ignore();
    cout<<"-Enter name: ";
    gets(sources->name);
    cout<<"-Enter age: ";
    cin>>sources->age;
    return sources;
}
void printEmploy(Employee *sources){
    cout << sources->id << "\t" << sources->name << "\t" << sources->age << "\n";
}
void enterList(Employee **&sources, int n){
    sources = new Employee *[n];
    for(int i = 0; i<n; i++){
        cout << "\nInformation employ " << i + 1 << "\n";
        *(sources+i) = enter();
    }
}
void printList(Employee **sources, int n){
    for(int i = 0; i < n; i++){
        Employee *employ = *(sources+i);
        printEmploy(employ);
    }
}
void interChangeSort(Employee **&sources, int n){
    int i,j;
    for(i = 0; i < n-1; i++){
        for(j = i+1; j < n; j++){
            Employee *employi = *(sources+i);
            Employee *employj = *(sources+j);
            if((employi->age) > (employj->age)){
                //declare variable to store
                int id = employi->id;
                char name[100];
                strcpy(name,employi->name);
                int age = employi->age;
                //point to address then add value/copy
                employi->id = employj->id;
                strcpy(employi->name, employj->name);
                employi->age = employj->age;
                //swap value
                employj->id = id;
                strcpy(employj->name, name);
                employj->age = age;
            }
        }
    }
}
void quickSort(Employee **&sources, int left, int right){
    if(left >= right) return;
    Employee *pivot = *(sources+((left+right)/2));
    int i = left, j = right;
    do{
        while(strcmp((*(sources+i))->name , pivot->name) < 0) i++;
        while(strcmp((*(sources+j))->name , pivot->name) > 0) j--;
        if(i<=j){
                Employee * employi = *(sources+i);
                Employee * employj = *(sources+j);
                //declare variable to store
                int id = employi->id;
                char name[100];
                strcpy(name,employi->name);
                int age = employi->age;
                //point to address then add value/copy
                employi->id = employj->id;
                strcpy(employi->name, employj->name);
                employi->age = employj->age;
                //swap value
                employj->id = id;
                strcpy(employj->name, name);
                employj->age = age;
                i++;
                j--;
        }
    }while(i<j);
    quickSort(sources,left,j);
    quickSort(sources,i,right);
}