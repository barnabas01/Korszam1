#include <iostream>  // iostream package a cout-hoz
#include <cmath>     // cmat a koszinusz "cos()" függvényhez
using namespace std; // behívom az std namespace-t mert lusta vagyok 3 helyre odaírni azt hogy std:: (a két cout meg az endl elé)


//midpoint féle integrálás
double integrate(int n, double x0, double x1){
    auto function = [](double x){return cos(x)*exp(-(x*x));}; 
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

int main(){
    cout.precision(16);                // a feladat leírása alapján átállítom a "cout" pontosságát
    cout<<integrate(10000,-1,3)<<endl; // meghívjuk a függvényt, és kiiratjuk az eredményt (és egy új sort)
    return 0;
}
