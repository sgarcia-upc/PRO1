#include "Punt.hpp"
#include "queueIOpunt.hpp"
#include "stackIOpunt.hpp"
#include <queue>


using namespace std;


void convertir_en_pila(queue<Punt> &c,stack<Punt> &p)
//Pre: pila ha de estar buida
//Post: pila conte tots el puest de la qua qp de manera que el primer element de c es el cim de qp i aixi succesivament c es buidara
{
    stack<Punt> aux;
    while (not c.empty()){
        aux.push(c.front());
        c.pop();
    }

    while (not aux.empty()){
        p.push(aux.top());
        aux.pop();
    }
}

int main (){
    queue<Punt> qp;

    while (cin>>qp){
        cout << qp;
        stack<Punt> pila;
        convertir_en_pila(qp, pila);
        cout << pila;
    }

    
    
}
