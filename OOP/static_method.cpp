#include <iostream>

using namespace std;

class Math {
    public:
        static int add(int x, int y){
            return x+y;
        }
        static int abs(int x){
            return x < 0 ? -x : x;
        }
        static int abstract(int x, int y){
            return x - y;
        }
        static int min(int x, int y){
            return x < y ? x : y;
        }
        static int max(int x, int y){
            return x > y ? x : y;
        }
        static int pow(int x, int y){
            int power = 1;
            for(int i = 0 ; i < y; i++){
                power *= x;
            }
        return power;
        }
};

int main(){
    cout << Math::add(3,5) << endl;
    cout << Math::abstract(3,5) << endl;
    cout << Math::abs(-5) << endl;
    cout << Math::min(3,5) << endl;
    cout << Math::max(3,5) << endl;
    cout << Math::pow(3,5) << endl;
    return 0;
}