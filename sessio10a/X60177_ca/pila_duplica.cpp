#include <iostream>
#include "pila.hpp"

void Pila::duplica(){
/* Pre: cert */
/* Post: Duplica els elements del p.i., cada element
   duplicat es situa al costat de l'original. */

    node_pila *actual = primer_node;    
    while (actual != NULL){
        node_pila * copia = new node_pila;
        copia->info = actual->info;
        copia->seguent = actual->seguent;
        actual->seguent = copia;
        altura += 1;
        actual = copia->seguent;
    }

}
