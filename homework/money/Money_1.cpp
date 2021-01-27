/* TODO: 
1.viết hàm nhập vào USD và tìm ra VND
2.viết hàm nhập vào VND và tìm ra USD */
void enterMoney(float *input);// nhập số tiền
void enterExchangeRate(float *input);// nhập tỉ giá
float transfer(const float money, const float exchange_rage);// chuyển đổi tiền
void printTransferValue(const float money, const float exchange_rage);// in ra giá trị sau khi chuyển đổi
void menu(const float money, const float exchange_rage);// hàm menu
int main(){
    float money,exchange_rage;
    return 0;
}
// TODO: hoàn thiện các hàm trên
