#include<stdio.h>
#include<stdlib.h>
void enter(int &first, int &second);// NOTE: nhập vào 2 số sử dụng tham chiếu
void enter(int *first, int *second);// NOTE: nhập vào 2 số sử dụng con trỏ
void swap(int *first, int *second);// NOTE: hoán vị 2 số
int add(const int first, const int second);// NOTE: tính tổng 2 số
int sub(const int first, const int second);// NOTE: tính hiệu 2 số
int mul(const int first, const int second);// NOTE: tính tích 2 số
float divide(const int first, const int second);// NOTE: tính thương 2 số
void print(const int first,const int second);// NOTE: in ra 2 số
void printCaculator(const int first,const int second);// NOTE: in biểu thức
int main(){
    /* nhập vào 2 số sử dụng biến chứa giá trị
     int first, second;// chua gia tri
    // enter(first, second); // cach 1
    enter(&first, &second); */
    int *first, *second; // khai bao
    // cap phat bo nho first,second
    first = (int*)(malloc(sizeof(int)));
    second = (int*)(malloc(sizeof(int)));
    // su dung
    enter(*first, *second);
    print(*first,*second);
    swap(first, second);
    print(*first,*second);
    printCaculator(*first,*second);
    return 0;
}
void enter(int &first, int &second){
    printf("nhap vao so thu nhat: ");
    scanf("%d",&first);// NOTE: truyen dia chi
    printf("nhap vao so thu hai: ");
    scanf("%d",&second);
}
void enter(int *first, int *second){// con trỏ chứa địa chỉ
    if(first == NULL || second == NULL){
        printf("chua cap phat bo nho cho first va second!");
    }
    else{
        printf("nhap vao so thu nhat: ");
        scanf("%d",first);// NOTE: truyen dia chi
        printf("nhap vao so thu hai: ");
        scanf("%d",second);
    }
}
void swap(int *first, int *second){
    int temp = *first;
    *first = *second;
    *second = temp;
}
void print(const int first,const int second){
    printf("{first: %d,second: %d}\n",first,second);
}
int add(const int first, const int second){
    return first + second;
}
int sub(const int first, const int second){
    return first - second;
}
int mul(const int first, const int second){
    return first * second;
}
float divide(const int first, const int second){
    return (float)first/second;
}
void printCaculator(const int first,const int second){
    int sum = add(first,second);
    int diff = sub(first,second);
    int multiply = mul(first,second);
    float division = divide(first,second);
    printf("--------------------\n");
    print(first,second);
    printf("caculator:{sum: %d, different:%d, multiply:%d, division:%.2f}",sum,diff,multiply,division);
}