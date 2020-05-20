#include <iostream>
#include "pila_concatena.hpp"

using namespace std;

void concatena_piles(stack<int> &p, stack<int> &q, stack<int> &concatp)
/* Pre: p = P i q = Q i concatp es buida */
/* Post: concatp conte a dalt els elements de P en  el mateix ordre, 
         i a sota els elements de Q en el mateix ordre */

{
    concatp = q;
    if (not p.empty()){
        int j = p.top();
        concatp.push(p.top());
        p.pop();
        concatena_piles(p,q,concatp); 
        /* HI: concatp conte a dalt els elements de P-1  en 
           el mateix ordre, i a sota els elements de Q en el mateix
           ordre, tambe tenim el element p.top() dins de concatp */
        // FITA: mida de p
        concatp.push(j);
    }
}
 

