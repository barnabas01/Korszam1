#include <iostream>  // iostream package a cout-hoz
#include <cmath>     // cmath a koszinusz "cos()" függvényhez


//midpointos integrálás
double integrate(auto function, int n, double x0, double x1){
    // itt egy lambda függvényként írtam be a függvényünket, bár lehetett volna csak egyből a for loop-ba beírni, de talán 
    // így átláthatóbb és szükség esetén könnyebben átírható, továbbá egy általános integráló függvényt is könnyen
    // lehetne csinálni az egészből, hogyha az "integrate" függvény egyik paramétereként megadható lenne a "function" függvény

    double h = (x1-x0)/n; // a h a lépés nagysága
    double h2 = h/2;      // itt előre elmentem a h/2-t hogy ne kelljen később n-szer megcsinálni a számolást
    double S = 0;         // a nagy S lesz a változó amiben összeszummázzuk az integrált

    for(int i=0; i < n; i++){
        S += h*function(x0+i*h+h2); 
        // akár ki lehetne emelni a h-val való szorzást a szummázás utánra is, ezzel csökkentve a számolások mennyiségét,
        // de inkább nem úgy csináltam mert akkor nagy "n"-ekre lehet a szumma túl nagy lesz és elvesztünk pontosságot
    }
    return S;
}

double prec = 0.00001;
int n = 100000;
auto func1 = [](double x){return cos(x)*exp(-(x*x));}; 
double func1_x0 = -1.0;
double func1_x1 = 3.0;
double func1ref = 1.34638795680345037669816;
auto func2 = [](double x){return sin(x)*x*x;};
double func2_x0 = -3.5;
double func2_x1 = 2.1;
double func2ref = -2.30104;

int main(){
    double result1 = integrate(func1,n,func1_x0,func1_x1);
    if(std::abs(func1ref-result1) < prec){
        std::cout<<"passed test 1"<<std::endl;
    } 
    else{
        std::cout<<"failed on test 1"<<std::endl;
    }
    double result2 = integrate(func2,n,func2_x0,func2_x1);
    if(std::abs(func2ref-result2) < prec){
        std::cout<<"passed test 2"<<std::endl;
    } 
    else{
        std::cout<<"failed on test 2"<<std::endl;
    }
    return 0;
}
