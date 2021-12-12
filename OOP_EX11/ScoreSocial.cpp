#include "Score.cpp"
#pragma once 

class ScoreSocial : public Score {
    private:
        double ce;
        double history;
        double geography;
    public:
        ScoreSocial(){}
        ScoreSocial(double math, double literature, double english,
        double ce, double history, double geography) : Score(math,literature,english),
        ce(ce), history(history), geography(geography) {}
        double getCe() const { return ce; }
        double getHistory() const { return history; }
        double getGeography() const { return geography; }
        double pointC(){
            return literature + history + geography;
        }
        double pointSocial(){
            return literature + history + geography;
        }
        double avgPoint(){
            return (literature + history + geography + math + literature + english) / 6;
        }
};