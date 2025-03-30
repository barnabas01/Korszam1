#include "vector2.h"
#include <iostream>
using std::cout, std::endl;
int main()
{
    Vector2<double> v1 = {1.2,2.7};
    Vector2<double> v2 = {-3.72,0.6};
    Vector2<double> v3 = {1,2};
    double a = 2.8;
    Vector2<double> addref = {-2.52,3.3};
    Vector2<double> subref = {4.92,2.1};
    double lenref = 2.9546573405;
    Vector2<double> normref = {-0.2620013523,0.0422582826};
    Vector2<double> skref = {3.36,7.56};
    Vector2<double> add2ref = {2.2,4.7};
    Vector2<double> sub2ref = {-4.72,-1.4}; 
    Vector2<double> divref = {-1.3285714286,0.3214285714};
    double tolerance = 0.00001;

    cout<<"v1="<<v1<<endl;
    cout<<"v2="<<v2<<endl;
    cout<<"v3="<<v3<<endl;
    cout<<"a="<<a<<endl;
    cout<<endl;

    Vector2<double> tempvec = v1+v2;
    cout<<"v1+v2 = "<<tempvec;
    if (abs(tempvec.x-addref.x) < tolerance && abs(tempvec.y-addref.y) < tolerance){cout<<"   passed"<<endl;}
    else{cout<<"   failed"<<endl;}

    tempvec = v1-v2;
    cout<<"v1-v2 = "<<tempvec;
    if (abs(tempvec.x-subref.x) < tolerance && abs(tempvec.y-subref.y) < tolerance){cout<<"   passed"<<endl;}
    else{cout<<"   failed"<<endl;}

    double temp = v2.length();
    cout<<"v1.length() = "<<temp;
    if (abs(temp-lenref) < tolerance){cout<<"   passed"<<endl;}
    else{cout<<"   failed"<<endl;}

    tempvec = v2.normalize();
    cout<<"v2.normalize() = "<<tempvec;
    if (abs(tempvec.x-normref.x) < tolerance && abs(tempvec.y-normref.y) < tolerance){cout<<"   passed"<<endl;}
    else{cout<<"failed"<<endl;}

    tempvec = a*v1;
    Vector2<double> tempvec2 = v1*a;
    cout<<"a*v1 = "<<tempvec<<" = v1*a = "<<tempvec2;
    if (abs(tempvec.x-skref.x) < tolerance && abs(tempvec.y-skref.y) < tolerance && abs(tempvec2.x-skref.x) < tolerance && abs(tempvec2.y-skref.y) < tolerance)
    {cout<<"   passed"<<endl;}
    else{cout<<"   failed"<<endl;}

    tempvec = v2/a;
    cout<<"v2/a = "<<tempvec;
    if (abs(tempvec.x-divref.x) < tolerance && abs(tempvec.y-divref.y) < tolerance){cout<<"   passed"<<endl;}
    else{cout<<"failed"<<endl;}

    v1 += v3;
    cout<<"v1 += v3 -> v1="<<v1;
    if (abs(v1.x-add2ref.x) < tolerance && abs(v1.y-add2ref.y) < tolerance){cout<<"   passed"<<endl;}
    else{cout<<"failed"<<endl;}

    v2 -= v3;
    cout<<"v2 -= v3 -> v2 = "<<v2;
    if (abs(v2.x-sub2ref.x) < tolerance && abs(v2.y-sub2ref.y) < tolerance){cout<<"   passed"<<endl;}
    else{cout<<"failed"<<endl;}

    Vector2<double> v4{};
    cout<<"Enter v4:"<<endl;
    std::cin>>v4;
    cout<<"v4 = "<<v4<<endl;
    cout<<"If those are the numbers you typed in (and you didnt get an error message) then this passes aswell."<<endl;

    return 0;
}