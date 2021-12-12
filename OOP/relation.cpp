#include<bits/stdc++.h>

using namespace std;

class point {
    private:
        int x, y;
    public:
        point(){

        }
        point(int x, int y){
            this->x = x;
            this->y = y;
        }
        void setX(int x) { this->x = x; }
        void setY(int y) { this->y = y; }
        int getX() { return x; }
        int getY() { return y; }
};
class line  {
    private:
        point end;
        point begin;
    public:
        line(point begin, point end){
            this->end = end;
            this->begin = begin;
        }
        line(int x1, int y1, int x2, int y2){
            this->end = point(x2, y2);
            this->begin = point(x1, y1);
        }
        void setEnd(point end){
            this->end = end;
        }
        void setBegin(point begin){
            this->begin = begin;
        }
        point getEnd(){ return end;}
        point getBegin() {return begin;}
        double getLength(){
            return sqrt(pow(end.getX() - begin.getX(), 2) + pow(end.getY() - begin.getY(), 2));
        }
};
int main(){
    point begin(1,1);
    point end(2,3);
    line line1(begin,end);
    cout << line1.getLength() << endl;
    return 0;
}