#ifndef MC_H
#define MC_H

#include<functional>
#include<tuple>

double rand_range(std::mt19937&, const double&, const double&);
std::tuple<double,double,double> rand_point(std::mt19937&, const double&, const double&, const double&, const double&, const double&, const double&);
double MonteCarlo(std::function<double(double,double,double)> integrand, std::function<bool(double,double,double)> range, const double& x_min, const double& x_max, const double& y_min, const double& y_max, const double& z_min, const double& z_max, int n);

#endif