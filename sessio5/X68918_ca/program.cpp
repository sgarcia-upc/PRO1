#include <iostream>
#include "arbreBin.hpp"
#include <stack>

using namespace std;


bool checkSumaFills(arbreBin<int> &a){
//Pre: true
//Post: commprova si l'abreBinari d'enters anomenat a que per tot node el seu valor és igual a la suma dels valors dels nodes (arrels) del fill esquerre i del fill dret.
    bool error = false;
    if (not a.es_buit()){
        stack<arbreBin<int>> p;
        p.push(a);
        while (not p.empty() and not error){
            arbreBin<int> aux = p.top();
            p.pop();
            
            int sumaTotal = 0;

            if (aux.fe().es_buit() and aux.fd().es_buit())
                sumaTotal = aux.arrel();
                

            if (not aux.fe().es_buit()){
                p.push(aux.fe());
                sumaTotal += aux.fe().arrel();
            }

            if (not aux.fd().es_buit()){
                p.push(aux.fd());
                sumaTotal += aux.fd().arrel();
            }


            if (sumaTotal != aux.arrel()){
                error = true;
            }
        }
       
    }
    return error;
}

int main(){
    arbreBin<int> a;
    cin >> a;
    cout << a << endl;
    bool error = checkSumaFills(a);
    if (error){
        cout << "L'arbre no compleix la propietat 'Suma dels fills'." <<endl;
    } else {
        cout << "L'arbre compleix la propietat 'Suma dels fills'." <<endl;
    }
}
