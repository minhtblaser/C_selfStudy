#include "Score.cpp"
#pragma once 

class ScoreNatural : public Score {
    private:
        double physic;
        double chemistry;
        double biology;
    public:
        ScoreNatural(){}
        ScoreNatural(double math, double literature, double english,
        double physic, double chemistry, double biology) : Score(math,literature,english),
        physic(physic), chemistry(chemistry), biology(biology){}
        double getPhysic() const { return physic; }
        double getChemistry() const { return chemistry; }
        double getBiology() const { return biology; }
        double pointA(){
            return physic + math + chemistry;
        }
        double pointB(){
            return math + chemistry + biology;
        }
        double pointNatural(){
            return physic + chemistry + biology;
        }
        double avgPoint(){
            return (physic + chemistry + biology + math + literature + english) / 6;
        }
};