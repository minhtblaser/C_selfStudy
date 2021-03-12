#include <stdio.h>
void enter(int *pa, int &n);
void printValue(int *pa, int &n);
void printPlus(int *pa, int &n);
void addNewValue(int &position_add, int &number_add, int *pa, int &n);// FIXME: sắp xếp lại thứ tự các biến
void deleteValue(int &position_delete,int *pa, int &n);
int plus(int *pa, int &n);
int main(){
    int a[100];
    int *pa;
    pa = a; //create 400 byte memory for data//REVIEW: cấp phát bộ nhớ, không dùng như thế này
    int n;
    int position_add, number_add;
    int position_delete;
    enter(pa,n);
    printValue(pa,n);
    printPlus(pa,n);
    addNewValue(position_add,number_add,pa,n);
    printValue(pa,n);
    deleteValue(position_delete, pa, n);
    printValue(pa,n);
    return 0;
}
void enter(int *pa, int &n){
    printf("enter a number: ");
    scanf("%d", &n);
    for(int i = 0; i<n;i++){
        printf("\nenter a[%d]: ", i);
        scanf("%d", &pa[i]);
    }
}
void printValue(int *pa, int &n){
    printf("\n------------------------------\n");
    printf("\n the list of number: \n");
    for(int i =0; i<n;i++){
        printf("%4d", pa[i]);
    }
}
int plus(int *pa, int &n){
    int S = 0;
    for (int i =0; i<n; i++){
        S += pa[i];
    }
    return S;
}
void printPlus(int *pa, int &n){
    int result_sum = plus(pa,n);
    printf("\nThe sum of numbers in array is %d", result_sum);
}
void addNewValue(int &position_add, int &number_add, int *pa, int &n){
    do{
    printf("\nenter the postion which you want to add: ");
    scanf("%d", &position_add);
    if(position_add>n || position_add <0)
    {
        printf("\nthe position doesn't exist");
    }
    }while(position_add>n || position_add<0);
    printf("\nenter new value: ");
    scanf("%d", &number_add);
    for (int i = n; i>position_add;i--){
        pa[i] = pa[i-1];
    }
    pa[position_add] = number_add;
    n++; // create new memmory
}
void deleteValue(int &position_delete, int *pa, int &n){
    // NOTE: vị trí xóa được nhập bên ngoài
    // do{
    // printf("\nenter the postion which you want to delte: ");
    // scanf("%d", &position_delete);
    if(position_delete>n || position_delete <0)
    {
        printf("the position doesn't exist");
    }
    }while(position_delete>n || position_delete <0);
    for(int i = position_delete; i<n-1; i++){
        pa[i] = pa[i+1];
    }
    n--; // delete memmory
}