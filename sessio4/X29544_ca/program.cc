#include <iostream>
#include "LlistaIOParInt.hh"
using namespace std;

int main () {
    list <ParInt> l;
    LlegirLlistaParInt(l); 
    int n;
    cin >>n;
    
    list<ParInt>::iterator it = l.begin();

    int suma=0;
    int counter=0;
    while (it != l.end()){
        ParInt pi = *it;
        if (pi.primer() == n){
            suma += pi.segon();
            counter++;
        }       
        ++it;
    }

    cout << n << " " << counter << " " << suma <<endl;
}
