#include<iostream>
#include<cmath>
#include<random>
#include<tuple>
#include<ctime>
#include "mc.h"

int main(){
    srand(time(0));

    double ref = 5.568322182; //kézzel kiszámoltam az integrál értékét, és ez jött ki
    
    double integral = MonteCarlo(
        [](auto x, auto y, auto z){return exp(-x*x-y*y-z*z); },
        [](auto x, auto y, auto z)->bool{return x*x+y*y+z*z<16.0; },
        -4.0, 4.0, -4.0, 4.0, -4.0, 4.0
    );

    if(abs(integral-ref)<0.01){
        std::cout<<integral<<" passed"<<std::endl;
    }
    else{
        std::cout<<integral<<" failed"<<std::endl;
    }
    return 0;
}
