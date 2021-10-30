#include <bits/stdc++.h>
// Trinh Ngoc Minh
// 6151071073
using namespace std;


class Student{
    private:
        char id[50], name[50], class_subject[50];
        int year;
        float GPA;
    public:
        friend istream& operator>>(istream&, Student &input);
        friend ostream& operator<<(ostream&, Student output);
        bool operator>(Student source1);
        bool operator<(Student source1);
        float getGPA();
        
};
float Student::getGPA(){
    return GPA;
}
void findStudent(Student source[], int n){
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if(source[i].getGPA() < 1){
            count++;
        }
    }
    cout << "The number of students in warning: " << count << endl;
}
istream& operator>>(istream&is, Student &input){
    cin.ignore();
    cout << "enter id: ";
    is.getline(input.id,50);
    fflush(stdin);
    cout << "enter name: ";
    is.getline(input.name,50);
    cout << "enter year: ";
    is >> input.year;
    fflush(stdin);
    cout << "enter class: ";
    is.getline(input.class_subject,50);
    cout << "enter GPA: ";
    is >> input.GPA;
    return is;
}
ostream& operator<<(ostream &os, Student output){
    os << output.id << "\t" << output.name << "\t" << output.year << "\t" <<output.class_subject << "\t" <<output.GPA << endl;
    return os;
}
bool Student::operator>(Student source1){
    return year > source1.year;
}
bool Student::operator<(Student source1){
    return GPA < source1.GPA;
}
void sortByGPA(Student source[], int n){
    for(int i = 0; i <n-1; i++){
        for(int j = i+1 ; j <n; j++){
            if(source[i] < source[j]){
                Student temp = source[i];
                source[i] = source[j];
                source[j] = temp;
            }
        }
    }
}
void sortByYear(Student source[], int n){
    for(int i = 0; i <n-1; i++){
        for(int j = i+1 ; j <n; j++){
            if(source[i] > source[j]){
                Student temp = source[i];
                source[i] = source[j];
                source[j] = temp;
            }
        }
    }
}
void printStudents(Student source[], int n){
    for(int i = 0; i < n; i++){
        cout << i + 1<< "\t";
        cout << source[i] << endl;
    }
}
int main(){
    Student source[100];
    int n;
    cout <<"Enter the number of students: ";
    cin >> n;
    for(int i=0; i<n; i++){
        cout << "Student " << i+1 << endl;
        cin >> source[i];
    }
    for(int i = 0; i <n; i++){
        cout << i + 1<< "\t";
        cout << source[i] << endl;
    }
    // sắp xếp theo điểm
    cout << "\nsort by GPA\n";
    sortByGPA(source, n);
    printStudents(source, n);
    // sap xep theo nam
    cout << "\nsort by year\n";
    sortByYear(source, n);
    printStudents(source, n);
    findStudent(source,n);
    return 0;
}