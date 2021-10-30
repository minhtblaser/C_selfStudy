#include<stdio.h>
int countPoints2(int n);
void printReslult(int n);
int main(){
    int n;
    printf("enter n: ");
    scanf("%d", &n);
    printReslult(n);
    return 0;
}
// 1 : 1 5 12 22 
// 2 : 1 4 7 10 
// 3 : 3 3 3 
// ta co 
// 1 = a*1^2 + b*1 + c

// 5 = a*2^2 + b*2 + c

// 12 = a*3^2 + b*3 + c
// vay ta co a=3/2 b=-1/2 
// nen ta co 
// kq= (3*n-1)*n/2 
// hoac la (3/2*n-1/2)*n
// #Các ngũ giác tiếp theo được tạo bằng việc thêm 3 cạnh đáy
// #Số điểm trên 3 cạnh đó = 3n-2
int countPoints2(int n)
{
    if (n < 2) return n;
    return (int)(3*n - 1)*n/2;
}
void printReslult(int n){
    int result = countPoints2(n);
    printf("-The number of points is %d", result);
}