
class Point {
    private:
        int x, y;
    public:
        Point(){

        }
        Point(int x, int y){
            this->x = x;
            this->y = y;
        }
        int getX(){
            return this->x;
        }
        void setX(int x){
            this->x = x;
        }
        int getY(){
            return this->y;
        }
        void setY(int y){
            this->y = y;
        }
};