#include <stdio.h>
void enter(int *pa, int &n);
void printValue(int *pa, int n);
void printPlus(int *pa, int n);
void addNewValue(int &position, int &number, int *pa, int n);
void deleteValue(int &position, int &number, int *pa, int n);
int plus(int *pa, int n);
int main(){
    int a[100];
    int *pa;
    pa = a; //create 400 byte memory for data
    int n;
    int position, number;
    enter(pa,n);
    printValue(pa,n);
    printPlus(pa, n);
    addNewValue(position,number,pa,n);
    printValue(pa,n);
    deleteValue(position, number, pa, n);
    printValue(pa,n);
    return 0;
}
void enter(int *pa, int &n){
    printf("enter a number: ");
    scanf("%d", &n);
    for(int i = 0; i<n;i++){
        printf("\nenter a[%d]: ", i+1);
        scanf("%d", &pa[i]);
    }
}
void printValue(int *pa, int n){
    printf("\n------------------------------\n");
    printf("\n the list of number: \n");
    for(int i =0; i<n;i++){
        printf("%4d", pa[i]);
    }
}
int plus(int *pa, int n){
    int S = 0;
    for (int i =0; i<n; i++){
        S += pa[i];
    }
    return S;
}
void printPlus(int *pa, int n){
    int result_sum = plus(pa,n);
    printf("\nThe sum of numbers in array is %d", result_sum);
}
void addNewValue(int &position, int &number, int *pa, int n){
    do{
    printf("\nenter the postion which you want to add: ");
    scanf("%d", &position);
    if(position>n && position <0)
    {
        printf("\nthe position doesn't exist");
    }
    }while(position>n && position <0);
    printf("\nenter new value: ");
    scanf("%d", &number);
    for (int i = n-1; i>position;i--){
        pa[i] = pa[i-1];
    }
    pa[position] = number;
}
void deleteValue(int &position, int &number, int *pa, int n){
    do{
    printf("\nenter the postion which you want to delte: ");
    scanf("%d", &position);
    if(position>n && position <0)
    {
        printf("the position doesn't exist");
    }
    }while(position>n && position <0);
    printf("\nenter new value: ");
    scanf("%d", &number);
    for(int i = position; i<n-1; i++){
        pa[i] = pa[i+1];
    }
}