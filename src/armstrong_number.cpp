#include<stdio.h>
#include<math.h>
bool check_Number(int n);
int countDigit(int n);
int main(){
	int n;
	printf("enter number: ");
	scanf("%d", &n);
	if(check_Number(n)==true){
		printf("\nThis is armstrong number ");
	} else {
		printf("\nThis is no armstrong number");
	}
	return 0;	
};
int countDigit(int n){
	int count = 0;
	while(n>0){
		n /= 10;
		count++;
	}
	return count;
}
bool check_Number(int n){
	int temp = n, last, sum = 0;
	int numDigit = countDigit(n);
	while(temp > 0){
			last = temp % 10;
			temp /= 10;
			sum += pow(last, numDigit);
	}
	if (sum == n){
		return true;
	}else{
		return false;
	}
}
