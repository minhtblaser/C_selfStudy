#include<stdio.h>
#include<assert.h>
int add(const int first, const int second);// cộng 2 số
int subtract(const int first, const int second);// trừ 2 số
double multiply(const int first, const int second);// nhân 2 số
float divide(const int first, const int second);// chia 2 số
int findMax(const int first, const int second);// tìm max 2 số
// test function
void test_caculator();
int main(){
    test_caculator();
    return 0;
}
int add(const int first, const int second){
    // TODO: hoàn thiện hàm tính tổng 2 số
    return 0;
}
int subtract(const int first, const int second){
    // TODO: hoàn thiện hàm tính hiệu 2 số
    return 0;
}
double multiply(const int first, const int second){
    // TODO: hoàn thiện hàm tính tích 2 số
    return 0;
}
float divide(const int first, const int second){
    // TODO: hoàn thiện hàm tính thương 2 số
    return 0;
}
int findMax(const int first, const int second){
    // TODO: hoàn thiện hàm tìm max của 2 số
    return 0;
}
// test
void test_caculator(){
    printf("phép tính: \n");
    printf("\t -cộng 2 số: ");
    assert(add(3,4)==7);
    printf("chính xác!\n");
    printf("\t -trừ 2 số: ");
    assert(subtract(3,4)==-1);
    printf("chính xác!\n");
    printf("\t -nhân 2 số: ");
    assert(multiply(3,4)==12);
    printf("chính xác!\n");
    printf("\t -chia 2 số: ");
    assert(divide(3,4)==0.75);
    printf("chính xác!\n");
    printf("\t -tìm max 2 số: ");
    assert(findMax(3,4)==4 && findMax(4,4)==4 && findMax(4,3)==4);
    printf("chính xác!\n");
}