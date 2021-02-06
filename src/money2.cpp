#include <stdio.h>
bool isValid (const int money);
void enterMoney(int *money);
void printWays(const int money);
int countNumbersWaytoDivedMoney(const int money);
int main(){
    int money;
    enterMoney(&money);
    printWays(money);
    return 0;
}
bool isValid (const int money){
    if(money % 1000 == 0){
        return true;    
    } else {
        return false;
    }
}
void enterMoney(int *money){
    do{
    printf("enter your money: ");
    scanf("%d", money);    
    if(isValid(*money) == false ){
        printf("your money is non-valid to convert");
    }
    } while (!isValid(*money));
}
int countNumbersWaytoDivedMoney(const int money){
    int n5 = money;//5000d 
    int n2 = money;//2000d
    int n1 = money;//1000d
    for(int i = 0; i<n5; i++){
        for(int j = 0; j<n2; j++){
            for(int k = 0; k<n1; k++){
                if((5000*i + 2000*j + 1000*k) == money){
                    return i+j+k;
                } 
            }
        }
    }
}
void printWays(const int money){
    int ways_to_convertMoney = countNumbersWaytoDivedMoney(money);
    printf("we have %d ways to convert money", ways_to_convertMoney);
}
