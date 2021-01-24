#include<stdio.h>
#include<assert.h>
void swap(int *first, int *second); // hàm swap sử dụng con trỏ
// test 
void test_swap();
int main(){
    test_swap();
    return 0;
}
void swap(int *first, int *second){
    // TODO: hoàn thiện hàm hoán vị 2 số
}
void test_swap(){
    printf("swap: ");
    int first = 3, second = 2;
    bool swap_success = false;
    swap(&first, &second);
    assert(first == 2 && second ==3);
    printf("pass!\n");
}