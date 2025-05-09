#include<cmath>
#include<random>
#include<tuple>
#include "mc.h"

int n = 10000000; // number of points that will be randomly chosen for the intergral
double rand_range(std::mt19937& mt, const double& min, const double& max)
{
    double num = (double)mt()/4294967295; //that is the maximum value of an unsigned 32 bit integer. This way i get back a number between 0 and 1
    double val = num*(max-min)+min;
    return val;
}

std::tuple<double,double,double> rand_point(std::mt19937& mt, const double& x_min, const double& x_max, const double& y_min, const double& y_max, const double& z_min, const double& z_max)
{
    double x = rand_range(mt, x_min, x_max);
    double y = rand_range(mt, y_min, y_max);
    double z = rand_range(mt, z_min, z_max);
    return std::make_tuple(x, y, z);
}

double MonteCarlo(double (*integrand)(double,double,double), bool (*range)(double,double,double), const double& x_min, const double& x_max, const double& y_min, const double& y_max, const double& z_min, const double& z_max)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    int in_range_n = 0;
    double sum = 0;
    for(int i = 0; i<n; i++)
    {
        double x, y, z;
        std::tie(x,y,z) = rand_point(mt,x_min, x_max, y_min, y_max, z_min, z_max);
        if(range(x ,y ,z)){
            in_range_n++;
            sum += integrand(x, y, z);
        }
    }
    
    double total_volume = (x_max-x_min)*(y_max-y_min)*(z_max-z_min);
    double int_volume = total_volume*((double)in_range_n/n);
    double int_avg = sum / in_range_n;  
    double integral = int_volume*int_avg;
    return integral;
}
