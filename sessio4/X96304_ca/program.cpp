#include "Punt.hpp"
#include "stackIOpunt.hpp"
#include <stack>
#include <iostream>

using namespace std;

bool findPuntInStack (stack<Punt> sp, Punt &p)
//Pre: Pila de punts no buida i  un punt a buscar
//Post: El resultat indica si p es troba al stack o no
{
    bool found = false;
    while (not sp.empty() and not found) {
        if (sp.top() == p){
            found = true;
        } 
        sp.pop();
    }

    return found;
}

int main () {

    stack <Punt> sp;
    cin >> sp;
    cout << sp; 

    Punt p;
    while (cin>>p){
        bool found = findPuntInStack(sp, p);
        if (found) {
            cout << "El punt "<< p << " es troba en la pila." <<endl; 
        } else {
            cout << "El punt "<< p << " no es troba en la pila." <<endl; 
        }
    }
    
}
