#include<cmath>
#include<random>
#include<tuple>
#include "mc.h"

int n = 10000000; // number of points that will be randomly chosen for the intergral
int rand_res = 10000000; // determines the number of possible values each coordinate can recieve when generating a random point

double rand_range(double min, double max)
{
    int num = rand() % rand_res;
    double val = min + ((max-min)/rand_res)*num;
    return val;
}

std::tuple<double,double,double> rand_point(double x_min, double x_max, double y_min, double y_max, double z_min, double z_max)
{
    double x = rand_range(x_min, x_max);
    double y = rand_range(y_min, y_max);
    double z = rand_range(z_min, z_max);
    return std::make_tuple(x, y, z);
}

double MonteCarlo(auto integrand, auto range, double x_min, double x_max, double y_min, double y_max, double z_min, double z_max)
{
    int in_range_n = 0;
    double sum = 0;
    for(int i = 0; i<n; i++)
    {
        double x, y, z;
        std::tie(x,y,z) = rand_point(x_min, x_max, y_min, y_max, z_min, z_max);
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
