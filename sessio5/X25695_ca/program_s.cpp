#include <iostream>
#include <stack>
#include <list>
#include "arbreBin.hpp"

using namespace std;


void inordre(const arbreBin<int> &a, list<int> &l)
// Pre: l es una llista buida
// Post: l conte el recorregut en inisOrdenadare de l'arbre a
{
    if (not a.es_buit()){
        stack<arbreBin<int>> p;
        p.push(a);
        while (not p.empty()){
            arbreBin<int> aux = p.top();
            p.pop();
            if (aux.fd().es_buit() and aux.fe().es_buit()){
                l.insert(l.end(), aux.arrel());
            }
            else{
                if (aux.fe().es_buit() and not aux.fd().es_buit()){
                    l.insert(l.end(), aux.arrel());
                    p.push(aux.fd());
                } else {
                    if (not aux.fe().es_buit() and aux.fd().es_buit()){
                        p.push(arbreBin<int>(aux.arrel(), arbreBin<int>(), arbreBin<int>()));
                        p.push(aux.fe());
                    } else {
                        if(not aux.fe().es_buit() and not aux.fd().es_buit()){
                            p.push(aux.fd());
                            p.push(arbreBin<int>(aux.arrel(), arbreBin<int>(), arbreBin<int>()));
                            p.push(aux.fe());
                        }
                    } 
                }
            }
        }
     }
}

bool isOrdenada(const list<int> &l){
// Pre: cert
// Post El resultat indica si la llista l esta isOrdenadaenada de forma creixent
    bool isOrdenada = true;
    list<int>::const_iterator it = l.begin();
    if(it != l.end()){
        int ant = *it;
        ++it;
        while(it != l.end() and isOrdenada){
            if(ant >= *it) isOrdenada = false;
            ant= *it;
            ++it;
        }
    }
    return isOrdenada;
}

int main(){
    arbreBin<int> a;
    cin >> a;
    cout << a <<endl;
    list <int> l;
    inordre(a, l);
    if (isOrdenada(l)){
        cout << "L'arbre és un arbre binari de cerca.";
    } else {
        cout << "L'arbre no és un arbre binari de cerca.";
    }
    cout << endl;
}
