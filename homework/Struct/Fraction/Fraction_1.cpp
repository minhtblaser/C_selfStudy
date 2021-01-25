#include<stdio.h>
#include<math.h>
#include<string.h>
#include<assert.h>
enum CompareResult{
    LARGER  = 1, EQUAL = 0, SMALLER = -1
};
typedef struct Fraction {
    int numerator, denominator;
};
int gcd(int first, int second);// ước chung lớn nhất
Fraction compact (Fraction fraction);// rút gọn phân số
Fraction plus(Fraction first, Fraction second);// cộng hai phân số
Fraction minus(Fraction first, Fraction second);// trừ 2 phân số
Fraction multiply(Fraction first, Fraction second);// nhân 2 phân số
Fraction divide(Fraction first, Fraction second);// chia 2 phân số
CompareResult compare(Fraction first, Fraction second);// so sánh 2 phân số
// test
void test_compact();
void test_caculator();
void test_compare();
int main(){
    test_compact();
    test_caculator();
    test_compare();
    return 0;
}

int  gcd(int first, int second){
    // TODO: hoàn thiện hàm tìm ước số chung. Hàm trả về ước số chung của 2 số, không yêu cầu rút gọn phân số
    return 0;
}
Fraction compact (Fraction fraction){
    Fraction result;
    // TODO: hoàn thiện hàm rút gọn 1 phân số. kết quả sau khi rút gọn lưu vào biến result
    return result;
}   
Fraction plus(Fraction first, Fraction second){
    Fraction result;
    //TODO: hoàn thiện hàm tính tổng 2 phân số, không yêu cầu rút gọn phân số, không yêu cầu rút gọn phân số
    return result;
}
Fraction minus(Fraction first, Fraction second){
    Fraction result;
    // TODO: hoàn thiện hàm hiệu 2 phân só, không yêu càu rút gọn phân số
    return result;
}
Fraction multiply(Fraction first, Fraction second){
    Fraction result;
    // TODO: hoàn thiện hàm nhân 2 phân số, không yêu cầu rút gọn phân số
    return result;
}
Fraction divide(Fraction first, Fraction second){
    Fraction result;
    // TODO: hoàn thiện hàm chia 2 phân số, không yêu cầu rút gọn phân số
    return result;
}
/** hàm so sánh tương quan của hai phân số:
 * - nếu bằng nhau. trả về EQUAL
 * - nếu phân số thứ 1 lớn hơn phân số thứ 2. trả về LARGER
 * - nếu phân số thứ 1 nhỏ hơn phân số thứ 2. trả về SMALLER
 **/
CompareResult compare(Fraction first, Fraction second){
    // TODO: hoàn thiện hàm so sánh 2 phân số
    return EQUAL;
}
void test_compare(){
    printf("<---> so sánh 2 phân số: \n");
    Fraction first = {.numerator = 1, .denominator = 4};
    Fraction second = {.numerator = 2, .denominator = 3};
    Fraction thirst = {.numerator = 11, .denominator = 44};
    printf("\t -phân số thứ nhất < phân số thứ 2:");
    assert(compare(first,second)==SMALLER);
    printf("chính xác!\n");
    printf("\t -phân số thứ nhất > phân số thứ 2:");
    assert(compare(second,first)==LARGER);
    printf("chính xác!\n");
    printf("\t -phân số thứ nhất = phân số thứ 2:");
    assert(compare(first,thirst)==EQUAL);
    printf("chính xác!\n");
    
}
void test_compact(){
    printf("<--->rút gọn phân số: \n");
    printf("\t- ước chung lớn nhất: ");
    assert(gcd(3,4)==1 && gcd(3,9)==3 && gcd(6,3)==3 && gcd(3,3)==3);
    printf("chính xác!\n");
    printf("\t-rút gọn phân số: ");  
    Fraction first = {.numerator = 3, .denominator = 4};
    Fraction second = {.numerator = 9, .denominator = 12};  
    assert(compare(first, compact(second))==EQUAL);
    first = {.numerator = 1, .denominator = 3};
    second = {.numerator =1, .denominator = 3};
    assert(compare(first, compact(second))==EQUAL);
    printf("chính xác!\n");
}
void test_caculator(){
    printf("<--->phép toán trên phân số: \n");
    // plus
    printf("\t- cộng:");
    Fraction first = {.numerator = 2, .denominator = 3};
    Fraction second = {.numerator = 1, .denominator = 4};
    Fraction result = {.numerator = 11,.denominator = 12};
    assert(compare(result,plus(first,second))==EQUAL);
    printf("chính xác!\n");
    // minus
    printf("\t- trừ:");
    result = {.numerator = 5,.denominator = 12};
    assert(compare(result,minus(first,second))==EQUAL);
    printf("chính xác!\n");
    // multiply
    printf("\t- nhân:");
    result = {.numerator = 2,.denominator = 12};
    assert(compare(result,multiply(first,second))==EQUAL);
    printf("chính xác!\n");
       // devide
    printf("\t- chia:");
    result = {.numerator = 8,.denominator = 3};
    assert(compare(result,divide(first,second))==EQUAL);
    printf("chính xác!\n");
}
