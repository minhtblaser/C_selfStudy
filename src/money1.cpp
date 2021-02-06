#include<stdio.h>
void enterMoney(float *input);// nhập số tiền
void enterExchangeRate(float *input);// nhập tỉ giá
float transfer(const float input_money, const float input_rate);// chuyển đổi tiền
void printTransferValue(const float input_money, const float input_rate);// in ra giá trị sau khi chuyển đổi
void menu(float input_money, float input_rate);// hàm menu
int main(){
    float input_money, input_rate;
    menu(input_money, input_rate);       
    return 0;    
}
void menu (float input_money, float input_rate){
    int choice;
    do{
        printf("\n----------------------menu----------------------------");
        printf("\n1. convert money from VND to USD.");
        printf("\n2. convert money from USD to VND.");
        fflush(stdin);
        printf("\nwhat is your choice? ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0: break;
        case 1:{
            enterMoney(&input_money);
            enterExchangeRate(&input_rate);
            printTransferValue(input_money,input_rate);    
            break;
        }
        case 2:{
            enterMoney(&input_money);
            enterExchangeRate(&input_rate);
            printTransferValue(input_money, input_rate);   
            break;
        }
        default: printf("\nyour choice is non-valid");
            break;
        }
    } while (choice);
}
void enterMoney(float *input){
    printf("enter your money: ");
    scanf("%f", input);    
}
void enterExchangeRate(float *input){
    printf("\nenter rate_money: ");
    scanf("%f", input);
}
float transfer(const float input_money, const float input_rate){
    float result_exchange = input_money * input_rate;
    return result_exchange;
}
void printTransferValue(const float input_money, const float input_rate){
    float result_final = transfer(input_money, input_rate); 
    printf("\nyour money: %.2f", result_final);
}