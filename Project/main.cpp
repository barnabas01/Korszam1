#include<iostream>
#include<cmath>
#include<random>    
#include<tuple>
#include<ctime>
#include "mc.h"
#include<fstream>

int main(){

    double ref1 = 5.568322182; //kézzel kiszámoltam az integrál értékét, és ez jött ki
    double ref2 = (4.0/3.0)*3.14159265358979323846;
    int n = 100000;
    double integral1 = MonteCarlo(
        [](double x, double y, double z){return exp(-x*x-y*y-z*z); },
        [](double x, double y, double z)->bool{return x*x+y*y+z*z<16.0; },
        -4.0, 4.0, -4.0, 4.0, -4.0, 4.0,
        n
    );
    double integral2 = MonteCarlo(
        [](double x, double y, double z){return 1.0; },
        [](double x, double y, double z)->bool{return x*x+y*y+z*z<1.0; },
        -1.0, 1.0, -1.0, 1.0, -1.0, 1.0,
        n
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

    int n_start = 100;
    int n_end = 100000;
    int sample = 100;
    int num = 100;
    double step = (double)(n_end-n_start)/num;
    std::fstream file("output.txt");
    for(int i=0;i<num;i++){
        int current = n_start + (int)(i*step);
        file<<current<<" ";
        for(int j=0;j<sample;j++){
            double sphere = MonteCarlo(
            [](double x, double y, double z){return exp(-x*x-y*y-z*z); },
            [](double x, double y, double z)->bool{return x*x+y*y+z*z<16.0; },
            -4.0, 4.0, -4.0, 4.0, -4.0, 4.0,
            current
            );
            file<<sphere<<" ";
        }
        std::cout<<((double)i/num)*100<<std::endl;
        file<<"\n";
    }
    file.close();
    return 0;
}
