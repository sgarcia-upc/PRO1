#include <iostream>
#include "llista_elem_central.hpp"

int elem_central_aux(const list<int> &l, int n, list<int>::const_iterator it){
//Pre: l = L la mida de L es senar
//Post el resultat es l'element central de L
    if (n == l.size()/2){
        return *it; 
    }
    return elem_central_aux(l, ++n, ++it);
    //H.I: el resultat es l'element central de L
    //FITA: n augmenta 1 cuan arrivi a l.size()/2 parara
}

int elem_central(const list<int> &l)
/* Pre: l = L i la mida de L és senar */
/* Post: El resultat es l'element central de L */
{
    list<int>::const_iterator it = l.begin();
    int n = 0;
    return elem_central_aux(l, n, it);
}

