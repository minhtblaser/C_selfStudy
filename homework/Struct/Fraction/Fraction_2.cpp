#include<stdio.h>
#include<math.h>
#include<string.h>
#include<assert.h>
typedef struct Fraction {
    int numerator, denominator;
};
void enter(Fraction &input);// nhập phân số
// test
void test_enter();
int main(){
    test_enter();
    return 0;
}
void enter(Fraction &input){
    // TODO: hoàn thiện hàm nhập một phân số
}

void test_enter(){
    Fraction fraction;
    printf("<--->nhập phân số: \n");
    fraction = {.numerator = 0, .denominator = 0};
    enter(fraction);
    printf("-mẫu số nhập vào khác 0: ");
    assert(fraction.denominator!=0);
    printf("chính xác!\n");
    printf("- thử nhập 3/4 (phân số có tử số bằng 3, mẫu số bằng 4): \n");
    enter(fraction);
    printf("--> nhập phân số: chính xác!\n");
}