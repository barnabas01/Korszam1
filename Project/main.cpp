#include<iostream>
#include<cmath>
#include<random>    
#include<tuple>
#include<ctime>
#include "mc.h"

int main(){

    double ref1 = 5.568322182; //kézzel kiszámoltam az integrál értékét, és ez jött ki
    double ref2 = (4.0/3.0)*3.14159265358979323846;
    
    double integral1 = MonteCarlo(
        [](double x, double y, double z){return exp(-x*x-y*y-z*z); },
        [](double x, double y, double z)->bool{return x*x+y*y+z*z<16.0; },
        -4.0, 4.0, -4.0, 4.0, -4.0, 4.0
    );
    double integral2 = MonteCarlo(
        [](double x, double y, double z){return 1.0; },
        [](double x, double y, double z)->bool{return x*x+y*y+z*z<1.0; },
        -1.0, 1.0, -1.0, 1.0, -1.0, 1.0
    );

    if(abs(integral1-ref1)<0.001){
        std::cout<<"gauss on sphere r=4: "<<integral1<<" passed"<<std::endl;
    }
    else{
        std::cout<<"gauss on sphere r=4: "<<integral1<<" failed"<<std::endl;
    }

    if(abs(integral2-ref2)<0.001){  
        std::cout<<"unit shpere volume: "<<integral2<<" passed"<<std::endl;
    }
    else{
        std::cout<<"unit shpere volume: "<<integral2<<" failed"<<std::endl;
    }

    return 0;
}
