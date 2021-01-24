#include<stdio.h>
#include<assert.h>
void swap(int &first, int &second);// hoán vị sử dụng truyền vào tham chiếu
int add(const int first, const int second);// cộng 2 số
int subtract(const int first, const int second);// trừ 2 số
double multiply(const int first, const int second);// nhân 2 số
float divide(const int first, const int second);// chia 2 số
int findMax(const int first, const int second);// tìm max 2 số
// test function
void test_swap();
void test_caculator();
int main(){
    test_swap();
    test_caculator();
    return 0;
}

void swap(int &first, int &second){
    // TODO: hoàn thiện hàm hoán vị 2 số
}
int add(const int first, const int second){
    // TODO: hoàn thiện hàm tính tổng 2 số
}
int subtract(const int first, const int second){
    // TODO: hoàn thiện hàm tính hiệu 2 số
}
double multiply(const int first, const int second){
    // TODO: hoàn thiện hàm tính tích 2 số
}
float divide(const int first, const int second){
    // TODO: hoàn thiện hàm tính thương 2 số
}
int findMax(const int first, const int second){
    // TODO: hoàn thiện hàm tìm max của 2 số
}
void test_swap(){
    printf("swap:");
    int first = 3, second = 2;
    swap(first, second);
    assert(first==2 && second== 3);
    printf("pass!\n");
}

void test_caculator(){
    printf("caculator: \n");
    printf("\t -add: ");
    assert(add(3,4)==7);
    printf("pass!\n");
    printf("\t -subtract: ");
    assert(subtract(3,4)==-1);
    printf("pass!\n");
    printf("\t -multiply: ");
    assert(multiply(3,4)==12);
    printf("pass!\n");
    printf("\t -divide: ");
    assert(divide(3,4)==0.75);
    printf("pass!\n");
    printf("\t -find max of 2 numbers: ");
    assert(findMax(3,4)==4 && findMax(4,4)==4 && findMax(4,3)==4);
    printf("pass!\n");
}