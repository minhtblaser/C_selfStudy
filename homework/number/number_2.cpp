#include<stdio.h>
#include<assert.h>
void swap(int *first, int *second); // hàm swap sử dụng con trỏ
// test 
void test_swap();
int main(){
    int first = 3, second = 5;
    test_swap();
    return 0;
}
void swap(int *first, int *second){
    // TODO: hoàn thiện hàm hoán vị 2 số
}
void test_swap(){
    int first = 3, second = 5;
     printf("hoan vi 2 so:");
    swap(&first, &second);
    assert(first== 5 && second== 3);
    printf("chinh xac!\n");
}