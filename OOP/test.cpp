#include <iostream>
#include <vector>
using namespace std;

class Student
{
private:
	string name;
	double math;
	double physic;
	double chemistry;

public:
	Student() {}
	Student(string name, double math, double physic, double chemistry) : name(name), math(math), physic(physic), chemistry(chemistry) {}

	double getMath() { return math; }

	double getPhysic() { return physic; }

	double getChemistry() { return chemistry; }

	void display()
	{
		cout << "Name: " << name << endl;
		cout << "Point math: " << math << endl;
		cout << "Point physic: " << physic << endl;
		cout << "Point chemistry: " << chemistry << endl;
		cout << "Average: " << avgPoint() << endl;
	}

	double avgPoint()
	{
		return (math + physic + chemistry) / 3;
	}

	static vector<Student> getStudentMaxAvg(vector<Student> vt)
	{
		vector<Student> student;
		student.push_back(vt[0]);

		for (int i = 1; i < vt.size(); i++)
		{
			if (vt[i].avgPoint() > student[0].avgPoint())
			{
				student.clear();
				student.push_back(vt[i]);
			}
			else if (vt[i].avgPoint() == student[0].avgPoint())
			{
				student.push_back(vt[i]);
			}
		}
		return student;
	}

	static vector<Student> getStudentMaxMath(vector<Student> vt)
	{
		vector<Student> student;
		student.push_back(vt[0]);

		for (int i = 1; i < vt.size(); i++)
		{
			if (vt[i].getMath() > student[0].getMath())
			{
				student.clear();
				student.push_back(vt[i]);
			}
			else if (vt[i].getMath() == student[0].getMath())
			{
				student.push_back(vt[i]);
			}
		}
		return student;
	}

	static vector<Student> getStudentMaxPhysic(vector<Student> vt)
	{
		vector<Student> student;
		student.push_back(vt[0]);

		for (int i = 1; i < vt.size(); i++)
		{
			if (vt[i].getPhysic() > student[0].getPhysic())
			{
				student.clear();
				student.push_back(vt[i]);
			}
			else if (vt[i].getPhysic() == student[0].getPhysic())
			{
				student.push_back(vt[i]);
			}
		}
		return student;
	}

	static vector<Student> getStudentMaxChemistry(vector<Student> vt)
	{
		vector<Student> student;
		student.push_back(vt[0]);

		for (int i = 1; i < vt.size(); i++)
		{
			if (vt[i].getChemistry() > student[0].getChemistry())
			{
				student.clear();
				student.push_back(vt[i]);
			}
			else if (vt[i].getChemistry() == student[0].getChemistry())
			{
				student.push_back(vt[i]);
			}
		}
		return student;
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
	cout << "\nStudent has max avgPoint: \n";
	for (int i = 0; i < Student::getStudentMaxAvg(student).size(); ++i)
	{
		count++;
		Student::getStudentMaxAvg(student)[i].display();
	}
	Student::getStudentMaxMath(student);
	cout << "\nStudent has max math: \n";
	for (int i = 0; i < Student::getStudentMaxMath(student).size(); ++i)
	{
		Student::getStudentMaxMath(student)[i].display();
	}
	Student::getStudentMaxPhysic(student);
	cout << "\nStudent has max physic: \n";
	for (int i = 0; i < Student::getStudentMaxPhysic(student).size(); ++i)
	{
		Student::getStudentMaxPhysic(student)[i].display();
	}
	Student::getStudentMaxChemistry(student);
	cout << "\nStudent has max chemistry: \n";
	for (int i = 0; i < Student::getStudentMaxChemistry(student).size(); ++i)
	{
		Student::getStudentMaxChemistry(student)[i].display();
	}
	cout << count;
}