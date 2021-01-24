// TODO: hoàn thiện những nội dung có trong todo
#include<stdio.h>
#include<assert.h>
void swap(int &first, int &second);
int findMax(int *array, int size);
bool hasSameValues(int *first, int first_size, int *second, int second_size);// kiểm tra giá trị của 2 mảng có tương tự nhau hay không?
void ascSort(int *array, int size);
// test function
void test_swap();
void test_findMax();// viết hàm test để kiểm tra giá trị max
void test_hasSameValues();
void test_ascSort();
int main(){
    test_swap();
    test_findMax();
    test_hasSameValues();
    test_ascSort();
    return 0;
}
void swap(int &first, int &second){
    // TODO: hoàn thiện hàm swap
}
int findMax(int *array, int size){
    // TODO: hoàn thiện hàm tìm max
}
bool hasSameValues(int *first, int first_size, int *second, int second_size){
    // TODO: hoàn thiện hàm kiểm tra 2 mảng first và second có cùng giá trị hay không?
}
void ascSort(int *array, int size){
    // TODO: hoàn thiện hàm sắp xếp một mảng
}
void test_swap(){
    printf("swap: ");
    int first = 3, second = 2;
    bool swap_success = false;
    swap(first, second);
    assert(first == 2 && second ==3);
    printf("pass!\n");
}
void test_findMax(){
    printf("find max:");
    int array[13] = {3,3,4,2,5,6,6,43,7,5,3,6,4};
    assert(findMax(array,13)==43);
    printf("pass!\n");
}
void test_hasSameValues(){
    printf("has Same Values: ");
    int first[13] = {3,3,4,2,5,6,6,43,7,5,3,6,4};
    int second[13] = {3,3,4,2,5,6,6,43,7,5,3,6,4};    
    assert(hasSameValues(first,13,second,13));
    printf("pass!\n");
}
void test_ascSort(){
    printf("asc sort: ");
    int array[5] = {3,2,4,4,1};
    int sorted[5] = {1,2,3,4,4};
    ascSort(array,5);
    assert(hasSameValues(array,5,sorted,5));
    printf("pass!\n");
}