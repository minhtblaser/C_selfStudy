/* TODO: 
1.viết hàm nhập vào USD và tìm ra VND
2.viết hàm nhập vào VND và tìm ra USD */
#include<stdio.h>
void enterMoney(float *input);// nhập số tiền
void enterExchangeRate(float *input);// nhập tỉ giá
float transfer(const float money, const float exchange_rate);// chuyển đổi tiền
void printTransferValue(const float money, const float exchange_rate);// in ra giá trị sau khi chuyển đổi
void menu(const float money, const float exchange_rate);// hàm menu
int main(){
    float money,exchange_rate;
    enterMoney(&money);
    enterExchangeRate(&exchange_rate);
    printTransferValue(money, exchange_rate);
    return 0;
}
// TODO: hoàn thiện các hàm trên
void enterMoney(float *input){
    printf("số tiền muốn chuyển:");
    scanf("%f",input);
}
void enterExchangeRate(float *input){
    printf("tỉ giá:");
    scanf("%f",input);
}
float transfer(const float money, const float exchange_rate){
    return money*exchange_rate;
}
void printTransferValue(const float money, const float exchange_rate){
    printf("kết quả: %.2f",transfer(money, exchange_rate));
}