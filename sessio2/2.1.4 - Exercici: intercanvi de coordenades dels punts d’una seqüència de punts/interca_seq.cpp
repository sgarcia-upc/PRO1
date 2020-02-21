#include<Punt.hpp>
#include<iostream>

using namespace std;

void intercanvia(Punt &p)
//Pre: cualsevol punt
//Post: no retorna res pero intercambia les cordenades del punt donat
{
    float x = p.coordenadax();
    float y = p.coordenaday();
    p.modificax(y);
    p.modificay(x);
}

int main (){
    Punt a;
    Punt zero;
    cin >> a;
    while (not (a == zero)) {
        cout << "punt original:" << a <<  " --> ";
        intercanvia(a);
        cout << "punt modificat: " << a <<endl;
        cin >> a;
    }
}
