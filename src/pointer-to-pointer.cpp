// writte program to find max value in array by pointer to pointer 
#include<stdio.h>
void enterNumbers(int &n, int **ptr_ptr);
void printNumbers(int &n, int **ptr_ptr);
void printMaxNumber(int &n, int **ptr_ptr);
int findMaxNumber(int &n, int **ptr_ptr);
int main(){
    int a[100];
    int *pa;
    int **ptr_ptr;
    pa = a;
    ptr_ptr = &pa;
    int n;
    printf("enter the amount of numbers in array: ");
    scanf("%d", &n);
    enterNumbers(n , ptr_ptr);
    printNumbers(n, ptr_ptr);
    printMaxNumber(n, ptr_ptr);
    return 0;
}
void enterNumbers(int &n,  int **ptr_ptr){
    for(int i = 0; i<n; i++){
        printf("number a[%d]: ", i+1);
        scanf("%d", &ptr_ptr[i]);
    }
}
void printNumbers(int &n, int **ptr_ptr){
    printf("\n------------your data-----------\n");
    for(int i = 0; i<n; i++){
        printf("%4d", ptr_ptr[i]);
    }
}
int findMaxNumber(int &n, int **ptr_ptr){
    int max_number =  &ptr_ptr; 
    for(int i = 0; i < n; i++){
        max_number = &ptr_ptr[0];
        if(max_number < ptr_ptr[i]){
            max_number = &ptr_ptr[i];
        }
    }
    return max_number;    
}
void printMaxNumber(int &n, int **ptr_ptr){
    int result_max = findMaxNumber(n, ptr_ptr);
    printf("\nyour result is here: %d", result_max);
}
