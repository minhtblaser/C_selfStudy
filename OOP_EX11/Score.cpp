#include <bits/stdc++.h>
#pragma once

using namespace std;

class Score {
    protected:
        double math;
        double literature;
        double english;
    public:
        Score(){}
        Score(double math, double literature, double english) : math(math), literature(math), english(english){}
        double getMath() const { return math; }
        double getLiterture() const { return literature;}
        double getEnglish() const { return english; }
        virtual double pointA(){
            return 0;
        }
        virtual double pointB(){
            return 0;
        }
        virtual double pointC(){
            return 0;
        }
        virtual double pointD(){
            return math+english+literature;
        }
        virtual double avgPoint() = 0;
        virtual void display(){
            cout << "Avg = " << avgPoint() << endl;
        }
        static double getMaxAvg(vector<Score*>vt){
            double max = vt[0]->avgPoint();
            for(int i=1; i<vt.size(); ++i){
                if(max < vt[i]->avgPoint()){
                    max = vt[i]->avgPoint();
                }
            }
            return max;
        }
        static double getMinAvg(vector<Score*>vt){
            double min = vt[0]->avgPoint();
            for(int i=1; i<vt.size(); ++i){
                if(min > vt[i]->avgPoint()){
                    min = vt[i]->avgPoint();
                }
            }
            return min;
        }
        bool isPass(){
            if(avgPoint()>5){
                return true;
            } else {
                return false;
            }
        }
        static double getMaxPointA(vector<Score*>vt){
            double max = vt[0]->pointA();
            for(int i=1; i<vt.size(); ++i){
                if(max < vt[i]->avgPoint()){
                    max = vt[i]->pointA();
                }
            }
            return max;
        }
        static double getMaxPointD(vector<Score*>vt)
	{
		double max = vt[0]->pointD();
		for (int i = 1; i < vt.size(); i++)
		{
			if (vt[i]->pointD() > max)
			{
				max = vt[i]->pointD();
			}
		}
		return max;
	}
        static double getMaxPointB(vector<Score*>vt){
            double max = vt[0]->pointB();
            for(int i=1; i<vt.size(); ++i){
                if(max < vt[i]->pointB()){
                    max = vt[i]->pointB();
                }
            }
            return max;
        }
        static double getMaxPointC(vector<Score*>vt){
            double max = vt[0]->pointC();
            for(int i=1; i<vt.size(); ++i){
                if(max < vt[i]->pointC()){
                    max = vt[i]->pointC();
                }
            }
            return max;
        }
};