#include<stdio.h>
void enter(int a[100][100], int &n, int &m);
void print(int a[100][100], int n, int m);
void printSum (int a[100][100], int n, int m);
void findMaxNumber(int a[100][100], int n ,int m);
int maxMul(int a[][100],int n, int m);
int maxMul_2(int a[][100],int n, int m);
int main(){
    int a[100][100];
    int n,m;
    enter(a,n,m);
    print(a,n,m);
    printSum(a,n,m);
    findMaxNumber(a,n, m);
    if((m % 2 == 0) && (n % 2 == 0)){
        int max = maxMul(a,n,m);
        printf("\nCot nho nhat trong mang la: %d", max);
    } else {
        int max_2 = maxMul_2(a,n,m);
        printf("\nCot nho nhat trong mang la: %d", max_2);
    }
    return 0; 
}
void enter(int a[100][100], int &n, int &m){
    printf("Nhap cot: ");
    scanf("%d", &n);
    printf("\nNhap hang: ");
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("a[%d][%d]: ",i,j);
            scanf("%d", &a[i][j]);
        }
    }
}
void print(int a[100][100], int n, int m){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
            printf("%d \t", a[i][j]);
        printf("\n");
        }
}
void printSum (int a[100][100], int n, int m){
    int sum  = 0; i
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            sum += a[i][j];
        }
    }
    printf("\nTong gia tri cua ma tran: %d", sum);
}
void findMaxNumber(int a[100][100], int n ,int m){
    int max = a[0][0];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(max < a[i][j]){
                max = a[i][j];
            }
        }
    }
    printf("\nGia tri cua max la %d", max);
}
int maxMul(int a[][100],int n, int m)
{
	int d;
	int max = (a[0][0] * a[0+1][0]);
	for(int i=0;i<m;i++) 
	{
        for (int j = 0; j<n; j++){
	        int t = a[i][j] * a[i+1][j];
		    if(max > t)
		    {
			max = t;
			d = j;
		    }
	    }
    }
	return d;
}
int maxMul_2(int a[][100],int n, int m){
    int d;
	int max = (a[0][0] * a[0+1][0]);
	for(int i=0;i<m/m;i++) // chi duyet mot lan qua mot hang, neu nhieu lan se sai.
	{
        for (int j = 0; j<n; j++){
	        int t = a[i][j] * a[i+1][j];
		    if(max > t)
		    {
			max = t;
			d = j;
		    }
	    }
    }
	return d;
}