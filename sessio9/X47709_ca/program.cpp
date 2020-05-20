#include <iostream>
#include "arbreBin.hpp"

using namespace std;

void genera_arbre_suma(const arbreBin<int> &a1, arbreBin<int> &a2){
//Pre: true
//Post: a2 = arbre de suma de a1
    if (not a1.es_buit()){

        arbreBin<int> fe = arbreBin<int>();

        int suma = a1.arrel();
        if (not a1.fe().es_buit()){
            genera_arbre_suma(a1.fe(), a2);
            //H.I: a2 = arbre de suma de a1.fe()
            //Fita: a1 decreix
            fe = a2; 
            suma += fe.arrel();
        }

        arbreBin<int> fd = arbreBin<int>();
        if (not a1.fd().es_buit()){
            genera_arbre_suma(a1.fd(), a2);
            //H.I: a2 = arbre de suma de a1.fd()
            //Fita: a1 decreix
            fd = a2;
            suma += fd.arrel();
        }
    
        a2 = arbreBin<int> (suma, fe, fd);
        
    }

}

int main (){

    arbreBin<int>a,b;
    cin >>a;
    genera_arbre_suma(a, b);
    cout << b << endl;
}

