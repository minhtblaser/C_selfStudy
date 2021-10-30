#include <stdio.h>
#include <string.h>
struct DateTime{
    int day, month, year;
};
struct Marks{
    float web, C, software;
};
struct Student{
    char name[100];
    char gender[10];
    Marks marks;
    DateTime birthDate;
    int classname;
};
bool isLeapYear(int year);
bool isValid(DateTime date);
bool checkDate(DateTime date1, DateTime date2);
void enterDateTime(DateTime &input);
void enterMarks(Marks &input);
void enter(Student &input);
void enterStudents(Student input[], int &n);
void print(Student output);
void printStudents(Student output[], int n);
void countGenders(Student check[], int n);
float average(Marks check);
void sortAverage(Student output[], int n);
void findStudent(Student find[], int n);
void ascSortByNameDes(Student source[], int n);
void ascSortByNameAsc(Student source[], int n);
int main(){
    Student student[100];
    int n,choice;
    enterStudents(student, n);
    printStudents(student, n);
    countGenders(student, n);
    printf("\n-->Sort students by average\n");
    sortAverage(student, n);
    printStudents(student, n);
    do{
        printf("\n1.Sort desc:\n");
        printf("2.Sort asc:");
        printf("\nYour choise: ");
        fflush(stdin);
        scanf("%d",&choice);
        switch (choice){
            case 1: 
                ascSortByNameDes(student,n);
                printStudents(student, n);
                break;
            case 2: 
                ascSortByNameAsc(student,n);
                printStudents(student, n);
                break;
        }
    }while(choice != 0);
    return 0;
}
bool isLeapYear(int year){
    return year % 4 == 0;
}
bool isValid(DateTime date){
    bool is_valid = true;
    if((date.month < 1 || date.month >12) || date.day < 1){
        is_valid = false;
    } else {
        switch(date.month){
            case 12: case 1: case 3: case 5: case 7: case 8: case 10:
                if(date.day>31){
                    is_valid = false;
                }
            break;
            case 4: case 6: case 9: case 11:
                if(date.day > 30){
                    is_valid = false;
                }
            break;
            case 2: 
                if(isLeapYear(date.year) && date.day > 29){
                    is_valid = false;
                } else if (!isLeapYear(date.year) && date.day > 28){
                    is_valid = false;
                }
            break;
        }
    }
    return is_valid;
}
void enterDateTime(DateTime &input){
    do{
        printf("\nenter day: ");
        scanf("%d", &input.day);
        printf("enter month: ");
        scanf("%d", &input.month);
        printf("enter year: ");
        scanf("%d", &input.year);
        if (!isValid(input)){
            printf("\nNot valid, please enter again please!!!");
        }
    } while (!isValid(input));
}
void enterMarks(Marks &input){
    do{
    printf("\nWeb Programming: ");
    scanf("%f",&input.web);
    }while(input.web >10.0 || input.web <0);
    do{
    printf("\nC Programming: ");
    scanf("%f",&input.C);
    }while(input.C >10.0 || input.C <0);
    do{
    printf("\nSoftware Engineering: ");
    scanf("%f",&input.software);
    }while(input.software >10.0 || input.software <0);
}
void enter(Student &input){
    fflush(stdin);
    printf("\nenter name: ");
    gets(input.name);
    printf("\nenter date of birth: ");
    enterDateTime(input.birthDate);
    printf("\nenter gender: ");
    fflush(stdin);
    gets(input.gender);
    printf("\nenter marks: ");
    enterMarks(input.marks);
    printf("\nenter class name: ");
    scanf("%d", &input.classname);
}
void enterStudents(Student input[], int &n){
    printf("\nEnter amount: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\nInformation of student %d", i+1);
        enter(input[i]);
    }
}
void print(Student output){
    printf("Name: %s, %s, (%d,%d,%d), class name: %d", output.name, output.gender, output.birthDate.day, output.birthDate.month, output.birthDate.year, output.classname);
}
void printStudents(Student output[], int n){
    for(int i=0; i<n; i++){
        print(output[i]);
        printf("\n");
    }
}
void countGenders(Student check[], int n){
    int count_male = 0, count_female = 0;
    for(int i=0; i<n; i++){
        if(strcmp(check[i].gender,"male") == 0) count_male++;
        else count_female++;
    }
    printf("Male: %d, Female: %d", count_male, count_female);
}
float average(Marks check){
    return ((check.web + check.C + check.software)/3.0);
}
void sortAverage(Student output[], int n){ //insertion sort
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n;j++){
            if(average(output[i].marks) < average(output[j].marks)){
                Student temp = output[i];
                output[i] = output[j];
                output[j] = temp;
            }
        }
    }
}
void findStudent(Student find[], int n){
    bool check = false;
    char name[100], temp[100];
    printf("\nenter name need to find: ");
    fflush(stdin);
    gets(name);
    for(int i=0; i<n; i++){
        strcpy(temp,(find+i)->name);
        if(strcmp(strlwr(temp),strlwr(name))==0){
            print(find[i]);
            printf("\n");
            check = true;
        }
    }
    if(!check) printf("Not found");
}
void ascSortByNameDes(Student source[], int n){
    Student temp;
    for(int pre=0; pre < n-1; pre++){
        for(int next = pre+1; next < n; next++){
            if(strcmp(source[pre].name, source[next].name) == -1){
                temp = source[pre];
                source[pre] = source[next];
                source[next] = temp;
            } else if (strcmp(source[pre].name, source[next].name) == 0){
                if(checkDate(source[pre].birthDate, source[next].birthDate)){
                    temp = source[pre];
                    source[pre]  = source[next];
                    source[next] = temp;
                }
            }
        }
    }
}
void ascSortByNameAsc(Student source[], int n){
    Student temp;
    for(int pre=0; pre < n-1; pre++){
        for(int next = pre+1; next < n; next++){
            if(strcmp(source[pre].name, source[next].name) == 1){
                temp = source[pre];
                source[pre] = source[next];
                source[next] = temp;
            } else if (strcmp(source[pre].name, source[next].name) == 0){
                if(!checkDate(source[pre].birthDate, source[next].birthDate)){
                    temp = source[pre];
                    source[pre]  = source[next];
                    source[next] = temp;
                }
            }
        }
    }
}
bool checkDate(DateTime date1, DateTime date2){
    bool is_valid = false;
    if(date1.year < date1.year){
        is_valid = true;
    }
    if(date1.year == date2.year){
        if(date1.month < date2.month){
            is_valid = true;
        } else if(date1.month == date2.month){
            if(date1.day < date2.day){
                is_valid = true;
            }
        }
    }
    return is_valid;
} 
