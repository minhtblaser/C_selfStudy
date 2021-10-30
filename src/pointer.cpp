#include<stdio.h>
#include<stdlib.h>
int main(){
    int *array;// khai báo mảng động
    int size = 4;// bậc
    array = (int*)malloc(size*sizeof(int));// cấp phát bộ nhớ
    if(array){
        //TODO: Nhập array
        //TODO:  xuất array
        //...
    }
    return 0;
;}