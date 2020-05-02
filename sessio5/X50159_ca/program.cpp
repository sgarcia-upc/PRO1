#include <iostream>
#include <queue>
#include <list>
#include "arbreBin.hpp"
#include "listIOint.hpp"

using namespace std;

void amplada (const arbreBin<int> &a, list<int> &l){
//Pre: l ha de ser una llista buida
//Post: Es recorrera el arbre binari a seguint el recurregut per amplada y el valor de cada node es ficara a la llista l
    if (not a.es_buit()){

        queue<arbreBin<int>> c;
        c.push(a);
        while (not c.empty()){
            arbreBin<int> aux = c.front();
            c.pop();
            l.insert( l.end(), aux.arrel() );

            if (not aux.fe().es_buit()){
                c.push(aux.fe());
            }

            if (not aux.fd().es_buit()){
                c.push(aux.fd());
            }
        }
    }

}

int main(){
    arbreBin<int> a;
    cin >> a;
    cout << a << endl <<endl;
    list <int> l;
    amplada(a, l);
    cout << "Amplada: " << l;
}
