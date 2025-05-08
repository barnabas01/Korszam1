#ifndef MC_H
#define MC_H

#include<tuple>

double rand_range(double,double);
std::tuple<double,double,double> rand_point(double, double, double, double, double, double);
double MonteCarlo(auto, auto, double, double, double, double, double, double);

#endif