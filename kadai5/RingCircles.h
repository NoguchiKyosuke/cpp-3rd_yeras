#pragma once

#include <stdio.h>
using namespace std;
#include <vector>
#include "RingCirclesException.h"
#include "svg.h"

#define M_PI 3.14159265358979323846

template <class T> class RingCircles {
private:
    int x, y;
    std::vector<T *> circles; // 環状に配置する円の要素

public:
    RingCircles () { // 引数を指定しない構築子 
        x = y = 200;
    } 

    RingCircles (int x, int y) {  // 引数を指定する構築子
        this->x = x; this->y = y;
    }

    void setCircles (int n) { // 円の個数の指定
        if (n < 4){
            throw RingCirclesException("Error in RingCircles ... the number of circles is too small!");
        }else if (n > 100){
            throw RingCirclesException("Error in RingCircles ... the number of circles is too large!");
        }else{
            for (int i = 0; i < n; i++){
                circles.push_back(new T());
            }
        }
    }

    void setPosition (int x, int y) { 
        this->x = x;   // this->x はメンバ変数の x であり，引数 x とは異なる変数！
        this->y = y; 
        for(long unsigned int i=0; i < circles.size(); i++){
            circles[i]->setPosition(this->x + 100*cos(2*M_PI*i/circles.size()), this->y + 100*sin(2*M_PI*i/circles.size()));
            circles[i]->setRadius(sqrt((100*100 + 100*100 - 2*100*100*cos(2*M_PI/circles.size())))/2);
        }
    }

    void draw (svg* svgObj) {
        for (long unsigned int i=0; i < circles.size(); i++){
            circles[i]->draw(svgObj);
        }
    }
};
