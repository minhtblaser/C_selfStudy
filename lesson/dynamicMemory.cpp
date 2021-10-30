#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
void enterNumbers(int &number,  int *ptr);
void printNumbers(int number, int *ptr);
int findMaxNumber(int &number,  int *ptr);
void printMaxNumber(int &number,  int *ptr);
int findMinNumber(int &number,  int *ptr);
void printMinNumber(int &number,  int *ptr);
void arrangeNumber(int &number, int *ptr);
bool check_Number(int x);
void printPrimeNumbers(int &number,  int *ptr);
void printAveragePrimeNumber(int &number,  int *ptr);
int findSecondMax(int &number, int *ptr);
int findSecondMin(int &number, int *ptr);
void printReslult(int &number,  int *ptr);
void addNewNumber(int &number, int *ptr);
void deleteNumber(int &number, int *ptr);
void enterDate(int &day, int &month, int &year);
bool isLeapYear(int year);
bool isValid(int day, int month, int year);
void printDate(int &day, int &month, int &year);
void findNext(int &day, int &month, int &year);
void menu(int &number,  int *ptr, int day, int month, int year);
int main(){
    int number;
    int *ptr;
    int day, month, year;
    ptr = (int*)calloc(number, sizeof(int));
    enterNumbers(number,ptr);
    menu(number,ptr, day, month, year);
    free(ptr);
    return 0;
}
void menu(int &number,  int *ptr, int day, int month, int year){
    char choice;
        do{
            printf("\n------------------------Menu--------------------\n");
            printf("1. Print Numbers\n");
            printf("2. Find max number and min number.\n");
            printf("3. Arrange number according to max -> min.\n");
            printf("4. Find prime numbers in array.\n");
            printf("5. Caculate prime numbers in array.\n");
            printf("6. Print the second max and second min in the array.\n");
            printf("7. Delete or add new number.\n");
            printf("8. The next day.\n");
            printf("9. Exit by click ESC\n");
            printf("-------------------------------------------------\n");
            printf("what is your choice?\n");
            choice = getch();
            switch (choice){
                case 49: 
                {
                    printNumbers(number,ptr);
                    break;
                }
                case 50: 
                {   
                    printMinNumber(number,ptr);
                    printMaxNumber(number,ptr);
                    break;
                }
                case 51:
                {
                    arrangeNumber(number,ptr);
                    printNumbers(number,ptr);
                    break;     
                }
                case 52:
                {
                    printPrimeNumbers(number,ptr);
                    break;
                }
                case 53:
                {
                    printAveragePrimeNumber(number,ptr);
                    break;
                }
                case 54:
                {
                    printReslult(number,ptr);
                    break;
                }
                case 55:
                {
                    char choice_update;
                    do{
                        printf("1. Add new number.");
                        printf("\n2. Delete number.\n");
                        choice_update = getch();
                        switch(choice_update){
                            case 49: 
                            {
                                addNewNumber(number, ptr);
                                printNumbers(number, ptr);
                                break;
                            }
                            case 50: 
                            {
                                deleteNumber(number, ptr);
                                printNumbers(number, ptr);
                                break;
                            }
                        }
                    }while( choice_update != 49 && choice_update != 50);
                    break;
                }
                case 56:
                {
                    enterDate(day, month, year);
                    findNext(day, month, year);
                    printDate(day,month, year);
                    break;
                }
            }
        } while (choice != 27);
}

void enterNumbers(int &number,  int *ptr){
    printf("enter the amount of numbers: ");
    scanf("%d", &number);
    ptr = (int *) realloc(ptr,number*sizeof(int));
    if (ptr == NULL)
    {
        printf("Co loi! khong the cap phat bo nho.");
        exit(0);
    }
    for(int i = 0; i < number; i++){
        printf("a[%d]: ",i+1);
        scanf("%d", (ptr+i));
    }
}
void printNumbers(int number,  int *ptr){
    printf("\nyour numbers: ");
    for(int i = 0; i < number; i++){
        printf("%4d", *(ptr+i));
    }
}
int findMaxNumber(int &number,  int *ptr){
    int max_number = *(ptr+0);
    for(int i = 0; i < number; i++){
        if(max_number < *(ptr+i)){
            max_number = *(ptr+i);
        }
    }
    return max_number;
}
void printMaxNumber(int &number,  int *ptr){
    int result_max = findMaxNumber(number,ptr);
    printf("\nThe max number is %d", result_max);
}
int findMinNumber(int &number,  int *ptr){
    int min_number = *(ptr+0);
    for(int i = 0; i < number; i++){
        if(min_number >*(ptr+i)){
            min_number = *(ptr+i);
        }
    }
    return min_number;
}
void printMinNumber(int &number,  int *ptr){
    int result_min = findMinNumber(number,ptr);
    printf("\nThe min number is %d", result_min);
}
void arrangeNumber(int &number, int *ptr){
    int temp;
    for(int i = 0; i < number-1; i++){
        for(int j = i+1; j < number; j++){
            if(*(ptr+i)<*(ptr+j)){
                temp = *(ptr+i);
                *(ptr+i) = *(ptr+j);
                *(ptr+j) = temp;
            }
        }
    }
}
bool check_Number(int x){
    if(x<2){
        return false;
    } 
    for(int i = 2; i <= sqrt(x); i++){
        if (x % i == 0){
            return false;
            }
        }
    return true;
}
void printPrimeNumbers(int &number,  int *ptr){
    printf("\nThe prime numbers in array: ");
    for(int i = 0; i < number;i++){
        if(check_Number(*(ptr+i)) == true){
            printf("%4d", *(ptr+i));
        }
    }
}
void printAveragePrimeNumber(int &number,  int *ptr){
    int count = 0;
    float sum = 0, average = 0;
    for(int i = 0; i < number;i++){
        if(check_Number(*(ptr+i)) == true){
            count++;
            sum += *(ptr+i);
        }
    }
    average = (float)sum/count;
    printf("\nThe average of primeNumbers: %.2f", average);
}
int findSecondMax(int &number, int *ptr){
    int max1 = findMinNumber(number,ptr);
    int max2 = *(ptr+0);
    for(int i = 1; i < number; i++){
        if(max2 < *(ptr+i) && *(ptr+i) != max1){
            max2 = *(ptr+i);
        }
    }
    return max2;
}
int findSecondMin(int &number, int *ptr){
    int min1 = findMaxNumber(number,ptr);
    int min2 = *(ptr+0);
    for(int i = 1; i < number; i++){
        if(min2 > *(ptr+i) && *(ptr+i) != min1){
            min2 = *(ptr+i);
        }
    }
    return min2;
}
void printReslult(int &number,  int *ptr){
    int result_max2 = findSecondMax(number,ptr);
    int result_min2 = findSecondMin(number,ptr);
    if(result_max2 == result_min2){
        printf("\nNot value required.");
    } else {
        printf("\nThe second max: %d\nThe second min: %d", result_max2, result_min2);
    }
}
void addNewNumber(int &number, int *ptr){
    int newNumber;
    int position_add;
    printf("\nEnter new number: ");
    scanf("%d", &newNumber);
    do{
        printf("\nEnter posiont: ");
        scanf("%d", &position_add);
    } while (position_add < 0 && position_add > number);
    for(int i = number; i>position_add;i--){
        *(ptr+i) = *(ptr+i-1);
    }
    *(ptr+position_add) = newNumber;
    //create new memory.
    number++;
}
void deleteNumber(int &number, int *ptr){
    int position_delete;
    printf("\nEnter delete number: ");
    scanf("%d", &position_delete);
    for(int i = position_delete; i<number - 1 ;i++){
        *(ptr+i) = *(ptr + i + 1);
    }
    //delete memory;
    number--;
}
void enterDate(int &day, int &month, int &year){
    do{
        printf("\nenter day: ");
        scanf("%d", &day);
        printf("\nenter month: ");
        scanf("%d", &month);
        printf("\nenter year: ");
        scanf("%d", &year);
        if(!isValid(day,month,year)){
           printf("enter again please!! ");
        }
    } while(!isValid(day, month, year));
}
bool isLeapYear (int year){
    return year%4 == 0;
}
bool isValid(int day, int month, int year){
    bool is_valid = true;
    if(month < 1 || month>12 || day <1){
        is_valid = false;
    } else {
        switch (month)
        {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if(day > 31){
                is_valid = false;
                break;
            }
            break;
        case 4: case 6: case 9: case 11: 
            if(day > 30){
                is_valid = false;
            }
            break;
        case 2: 
            if(isLeapYear(year) && day>29){
                is_valid = false;
            } else if (!isLeapYear(year) && day > 28){
                is_valid = false;
            }
            break;
        }
    }
    return is_valid;
}
void printDate(int &day, int &month, int &year){
    printf("\nyour the next day: %d/%d/%d", day, month, year);
}
void findNext(int &day, int &month, int &year){
    if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month ==12) && day == 31){
        month++;
        day = 1;
    } else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day == 30)){
        month++;
        day = 1;
    } else if ((isLeapYear(year) == true) && day == 29 && month == 2){
        month++;
        day = 1;
    } else if ((isLeapYear(year) == false) && day == 28 && month == 2){
        month++;
        day = 1;
    } else if (month == 12){
        year++;
        month = 1;
    } else {
        day++;
    }
}

