#include "Score.cpp"
#include "ScoreNatural.cpp"
#include "ScoreSocial.cpp"

using namespace std;

int main(){
    Score *score[3];
    score[0] = new ScoreNatural(3,5,5,2,1,6);
    score[0]->display();
    score[1] = new ScoreSocial(3,4,5,6,7,8);
    score[1]->display();
    score[2] = new ScoreSocial(7,8,9,10,5,8);
    score[2]->display();
    return 0;
}