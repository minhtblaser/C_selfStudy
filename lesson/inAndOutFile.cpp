#include<stdio.h>
#include<stdlib.h>
void enter(int a[100], int &n);
void print(int a[100], int n);
void exportFile(int a[100], int n, char file_name[30]);
int main(){
    int a[100];
    int n;
    char file_name[30];
    enter(a,n);
    print(a,n);
    exportFile(a,n,"MANG.out");
    return 0;
}
void enter(int a[100], int &n){
    printf("enter n: ");
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        printf("\na[%d]: ", i+1);
        scanf("%d", &a[i]);
    }
}
void print(int a[100], int n){
    printf("\nyour numbers : ");
    for(int i = 0; i<n; i++){
        printf("%4d", a[i]);
    }
}
void exportFile(int a[100], int n, char file_name[30]){
    FILE *file;
    file = fopen (file_name,"w");
    if(file == NULL){
        exit(1);
    }
    fprintf(file,"The amount of numbers :%d\n",n);
    for(int i = 0; i<n; i++){
        fprintf(file, "%d", a[i]);
    }
    fclose(file);
}