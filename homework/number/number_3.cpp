#include<stdio.h>
#include<assert.h>
void enter(int &first, int &second);
void swap(int &first, int &second);// hoán vị sử dụng truyền vào tham chiếu
// test function
void test_enter();
void test_swap();
int main(){
    int first = 0,second = 0;
    test_enter();
    test_swap();
    return 0;
}
void enter(int &first, int &second){
    // TODO: hoàn thiện hàm nhập 2 số
}
void swap(int &first, int &second){
    // TODO: hoàn thiện hàm hoán vị 2 số
}
// test
void test_enter(){
    int first = 0, second = 0;
    printf("nhap first va second(second phai khac 0):");
    enter(first, second); 
    assert(second!=0);
    printf("chinh xac!\n");
}
void test_swap(){
    int first = 5,second = 4;
    printf("hoan vi 2 so:");
    swap(first, second);
    assert(first== 4 && second== 5);
    printf("chinh xac!\n");
}

