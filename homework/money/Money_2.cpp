/* 
1. đếm số cách có thể chia một số tiền nhập vào thành các dạng tờ tiền: 1000, 2000, 5000. 
- điều kiện nhập vào là số tiền đó phải là bội số của 1000
2. Liệt kê tất cả các cách có thể chia một số tiền nhập vào thành các dạng tờ tiền: 1000, 2000, 5000.
 */
bool isValid(const double money);// kiểm tra số tiền nhập vào hợp lệ
void enter(double *money);// nhập số tiền
int countNumbersOfWaysToDivide(const double money);// tìm số cách chia
void digitsWaysToDivide(const double money);// liệt kê các cách chia tiền
int main(){
    int money;
    return 0;
}
// TODO: hoàn thiện các hàm