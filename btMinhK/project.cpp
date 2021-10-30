#include <stdio.h>
#include <string.h>
#include <stdbool.h>
struct DateTime{
    int day, month, year;
};
struct Marks{
    float web, C, software;
};
struct Student{
    char name[100];
    char gender[10];
    struct Marks marks;
    struct DateTime birthDate;
    int classname;
};
int isLeapYear(int year){
    if(year % 4 == 0) return 1;
    return 0;
}
int isValid(struct DateTime date){
    int is_valid = 1;
    if((date.month < 1 || date.month >12) || date.day < 1){
        is_valid = 1;
    } else {
        switch(date.month){
            case 12: case 1: case 3: case 5: case 7: case 8: case 10:
                if(date.day>31){
                    is_valid = 0;
                }
            break;
            case 4: case 6: case 9: case 11:
                if(date.day > 30){
                    is_valid = 0;
                }
            break;
            case 2: 
                if(isLeapYear(date.year) && date.day > 29){
                    is_valid = 0;
                } else if (isLeapYear(date.year)==0 && date.day > 28){
                    is_valid = 0;
                }
            break;
        }
    }
    return is_valid;
}
void enterStudents(struct Student input[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("\nInformation of student %d", i+1);
        printf("\nenter name: ");
        fflush(stdin);
        gets(input[i].name);
        printf("\nenter date of birth: ");
        do{
        printf("\nenter day: ");
        scanf("%d", &input[i].birthDate.day);
        printf("enter month: ");
        scanf("%d", &input[i].birthDate.month);
        printf("enter year: ");
        scanf("%d", &input[i].birthDate.year);
        if (isValid(input[i].birthDate)==0){
            printf("\nNot valid, please enter again please!!!");
        }
        } while (isValid(input[i].birthDate)==0);
        printf("\nenter gender: ");
        fflush(stdin);
        gets(input[i].gender);
        printf("\nenter marks: ");
       do{
        printf("\nWeb Programming: ");
        scanf("%f",&input[i].marks.web);
        }while(input[i].marks.web >10.0 || input[i].marks.web <0);
        do{
        printf("\nC Programming: ");
        scanf("%f",&input[i].marks.C);
        }while(input[i].marks.C >10.0 || input[i].marks.C <0);
        do{
        printf("\nSoftware Engineering: ");
        scanf("%f",&input[i].marks.software);
        }while(input[i].marks.software >10.0 || input[i].marks.software <0);
        printf("\nenter class name: ");
        scanf("%d", &input[i].classname);
    }
}
void print(struct Student output){
    printf("Name: %s, %s, (%d,%d,%d), class name: %d", output.name, output.gender, output.birthDate.day, output.birthDate.month, output.birthDate.year, output.classname);
}
void printStudents(struct Student output[], int n){
	int i;
    for(i=0; i<n; i++){
        print(output[i]);
        printf("\n");
    }
}
void countGenders(struct Student check[], int n){
    int count_male = 0, count_female = 0;
    int i;
    for(i=0; i<n; i++){
        if(strcmp(check[i].gender,"male") == 0) count_male++;
        else count_female++;
    }
    printf("Male: %d, Female: %d", count_male, count_female);
}
float average(struct Marks check){
    return ((check.web + check.C + check.software)/3.0);
}
void swap(struct Student first, struct Student second){
    struct Student temp = first;
    first = second;
    second = temp;
}
void sortAverage(struct Student output[], int n){ //insertion sort
	int i, j;
    for(i=0; i<n-1; i++){
        for(j=i+1; j<n;j++){
            if(average(output[i].marks) < average(output[j].marks)){
                swap(output[i],output[j]);
            }
        }
    }
}
int checkDay(struct DateTime first, struct DateTime second){
    if(first.year < second.year) return 0;
    else if(first.year > second.year) return 1;
    else{
        if(first.month < second.month) return 0;
        else if(first.month > second.month) return 1;
        else{
            if(first.day < second.day) return 0;
            else if(first.day > second.day) return 1;
            else return 0;
        }
    }
}
void sortByName(struct Student output[], int n){ //insertion sort (increasing)
    char first[100], second[100];
    int i, j;
    for(i=0; i<n-1; i++){
        for(j=i+1; j<n;j++){
            if(strcmp(strlwr(strcpy(first,(output+i)->name)),strlwr(strcpy(second,(output+j)->name)))>0){
                swap(output[i],output[j]);
            }
            else if(strcmp(strlwr(strcpy(first,(output+i)->name)),strlwr(strcpy(second,(output+j)->name)))==0){
                if(checkDay(output[i].birthDate, output[j].birthDate)==1){
                    swap(output[i],output[j]);
                }
            }
        }
    }
}
void findStudent(struct Student find[], int n){
    int check = 0;
    char name[100], temp[100];
    printf("\nenter name need to find: ");
    fflush(stdin);
    gets(name);
    int i;
    for(i=0; i<n; i++){
        strcpy(temp,(find+i)->name);
        if(strcmp(strlwr(temp),strlwr(name))==0){ //change A -> a
            print(find[i]);
            printf("\n");
            check = 1;
        }
    }
    if(check==0) printf("Not found");
}
int main(){
    struct Student student[100];
    int n;
    printf("\nEnter amount: ");
    scanf("%d",&n);
    enterStudents(student, n);
    printStudents(student, n);
    countGenders(student, n);
    printf("\n-->Sort students by average\n");
    sortAverage(student, n);
    printStudents(student, n);
    printf("\n-->Sort students by name\n");
    sortByName(student, n);
    printStudents(student, n);
    findStudent(student, n);
}