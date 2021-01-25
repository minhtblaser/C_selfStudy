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
// test
void test_caculator(){
    printf("phep tinh: \n");
    printf("\t -cong 2 so: ");
    assert(add(3,4)==7);
    printf("chinh xac!\n");
    printf("\t -tru 2 so: ");
    assert(subtract(3,4)==-1);
    printf("chinh xac!\n");
    printf("\t -nhan 2 so: ");
    assert(multiply(3,4)==12);
    printf("chinh xac!\n");
    printf("\t -chia 2 so: ");
    assert(divide(3,4)==0.75);
    printf("chinh xac!\n");
    printf("\t -tim max cua 2 so: ");
    assert(findMax(3,4)==4 && findMax(4,4)==4 && findMax(4,3)==4);
    printf("chinh xac!\n");
}