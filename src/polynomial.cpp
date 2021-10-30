#include<stdio.h>
#define MAX 1000
void enterPolynimal(int *n, int coefficient1[]);//1
void enterPolynimal2(int *m, int coefficient2[]);//2
void printPolynimal(int *n, int coefficient1[]);
void findSumof2Poly(int *n, int *m, int coefficient1[], int coefficient2[]);
int main(){
    int n,m;
    int coefficient1[MAX];
    int coefficient2[MAX];
    printf("enter Polynimal 1: ");
    enterPolynimal(&n, coefficient1);
    printPolynimal(&n, coefficient1);
    printf("enter Polynimal 2: ");
    enterPolynimal(&m, coefficient2);
    findSumof2Poly(&n, &m,coefficient1, coefficient2);
    return 0;
}
void enterPolynimal(int *n, int coefficient1[]){
    do{
        printf("\nenter polynimal degree: ");
        scanf("%d", n);
        if (*n < 1){
            printf("\npolynimal degree > 1. Please enter again!!! baby");
        }
    } while ( *n < 1);
    for(int i = *n; i >= 0; i--){
        int temp;
        printf("\nenter coefficient: ");
        scanf("%d", &temp);
        coefficient1[i] = temp;
    }
}
void printPolynimal(int *n, int coefficient1[]){
    printf("\nyour polynimal here: ");
    for(int i = *n; i >= 0; i--){
        if(coefficient1[i] != 0){
            printf("\n%d*x^%d ", coefficient1[i], i);
        }
    }
    printf("\n%d", coefficient1[0]);
}
void enterPolynimal2(int *m, int coefficient2[]){
    do{
        printf("\nenter polynimal degree: ");
        scanf("%d", m);
        if (*m < 1){
            printf("\npolynimal degree > 1. Please enter again!!! baby");
        }
    } while ( *m < 1);
    for(int i = *m; i >= 0; i--){
        int temp;
        printf("\nenter coefficient: ");
        scanf("%d", &temp);
        coefficient2[i] = temp;
    }
}
void findSumof2Poly(int *n, int *m, int coefficient1[], int coefficient2[]){
    int result;
    if(*n > *m){
        result = *n;
    } else {
          result = *m;
    }
    for(int i = 0; i < result; i++){
        result = coefficient1[i] + coefficient2[i];

    }

    printf("\nThe sum of 2 polynimal is %d", result);
}
// anh chỉ em cái lỗi này với
