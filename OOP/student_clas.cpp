#include <bits/stdc++.h>

using namespace std;

class Student
{
private:
    string name;
    double math;
    double physic;
    double chemistry;

public:
    Student()
    {
    }
    Student(string name, double math, double physic, double chemistry)
    {
        this->name = name;
        this->math = math;
        this->physic = physic;
        this->chemistry = chemistry;
    }
    double getMath()
    {
        return math;
    }
    double getPhysic()
    {
        return physic;
    }
    double getChemistry()
    {
        return chemistry;
    }
    double avgPoint()
    {
        return (math + physic + chemistry) / 3;
    }
    void display()
    {
        cout << "\n------------------------\n";
        cout << "Name: " << name << endl;
        cout << "Point math: " << math << endl;
        cout << "Point physic: " << physic << endl;
        cout << "Point chemistry: " << chemistry << endl;
        cout << "Average: " << avgPoint() << endl;
    }
    static vector<Student> getStudentMaxAvg(vector<Student> student)
    {
        double max = student[0].avgPoint();
        vector<Student> max_student;
        for (int i = 1; i < student.size(); ++i)
        {
            if (max < student[i].avgPoint())
            {
                max = student[i].avgPoint();
            }
        }
        for (int i = 0; i < student.size(); ++i)
        {
            if (max == student[i].avgPoint())
            {
                max_student.push_back(student[i]);
            }
        }
        return max_student;
    }
    static vector<Student> getStudentMaxMath(vector<Student> student)
    {
        double max = student[0].getMath();
        vector<Student> max_student;
        for (int i = 1; i < student.size(); ++i)
        {
            if (max < student[i].getMath())
            {
                max = student[i].getMath();
            }
        }
        for (int i = 0; i < student.size(); ++i)
        {
            if (max == student[i].getMath())
            {
                max_student.push_back(student[i]);
            }
        }
        return max_student;
    }
    static vector<Student> getStudentMaxPhysic(vector<Student> student)
    {
        double max = student[0].getPhysic();
        vector<Student> max_student;
        for (int i = 1; i < student.size(); ++i)
        {
            if (max < student[i].getPhysic())
            {
                max = student[i].getPhysic();
            }
        }
        for (int i = 0; i < student.size(); ++i)
        {
            if (max == student[i].getPhysic())
            {
                max_student.push_back(student[i]);
            }
        }
        return max_student;
    }
    static vector<Student> getStudentMaxChemistry(vector<Student> student)
    {
        double max = student[0].getChemistry();
        vector<Student> max_student;
        for (int i = 1; i < student.size(); ++i)
        {
            if (max < student[i].getChemistry())
            {
                max = student[i].getChemistry();
            }
        }
        for (int i = 0; i < student.size(); ++i)
        {
            if (max == student[i].getChemistry())
            {
                max_student.push_back(student[i]);
            }
        }
        return max_student;
    }
};
int main()
{
    int count = 0;
    vector<Student> student;
    student.push_back(Student("Minh", 10, 8, 10));
    student.push_back(Student("Anh", 9, 9, 8));
    student.push_back(Student("Dat", 1, 1, 1));
    student.push_back(Student("An", 5, 2, 9));
    for (int i = 0; i < student.size(); ++i)
    {
        student[i].display();
    }
    Student::getStudentMaxAvg(student);
    cout << "\nStudent has max avgPoint: ";
    for (int i = 0; i <  Student::getStudentMaxAvg(student).size(); i++)
    {
        count++;
        Student::getStudentMaxAvg(student)[i].display();
    }
    Student::getStudentMaxMath(student);
    cout << "\nStudent has max math: ";
    for (int i = 0; i <  Student::getStudentMaxMath(student).size(); ++i)
    {
        Student::getStudentMaxMath(student)[i].display();
    }
    Student::getStudentMaxPhysic(student);
    cout << "\nStudent has max physic: ";
    for (int i = 0; i <  Student::getStudentMaxPhysic(student).size(); ++i)
    {
        Student::getStudentMaxPhysic(student)[i].display();
    }
    Student::getStudentMaxChemistry(student);
    cout << "\nStudent has max chemistry: ";
    for (int i = 0; i <  Student::getStudentMaxChemistry(student).size(); ++i)
    {
        Student::getStudentMaxChemistry(student)[i].display();
    }
    cout << count;
}