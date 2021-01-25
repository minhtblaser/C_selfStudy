// TODO: hoàn thiện những nội dung có trong todo
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
void enter(int &size);// nhập vào số lượng phần tử
void enterValues(int *array, int size);// nhập vào giá trị các phần tử
// void test
void test_enter(int size);
void test_enter(int *array, int size);
int main(){
    int *array,size =0;
    test_enter(size);
    size = 3;
    array = (int*) (malloc(size*sizeof(int)));
    test_enter(array,size);
    return 0;
}
void enter(int &size){
    // TODO: hoàn thiện hàm nhập vào số lượng phần tử
}
void enterValues(int *array, int size){
    // TODO: hoàn thiện hàm nhập mảng
}
// test 
void test_enter(int size){
    printf("<---> nhap vao so luong phan tu: \n");
    enter(size);
    printf("\t-so luong phan tu lon hon 0:");
    assert(size>0);
    printf("chinh xac!\n",size);
}
void test_enter(int *array, int size){
    printf("<---> nhap vao gia tri cac phan tu trong mang:\n");
    printf("nhap vao 3 phan tu lan luot la -2 5 1:\n");
    enterValues(array,size);
    printf("\t -nhap gia tri cua mang:");
    assert(array[0]==-2 && array[1]== 5 && array[2]== 1);
    printf("chinh xac!\n");
}