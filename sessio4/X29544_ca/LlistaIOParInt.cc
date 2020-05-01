#include "LlistaIOParInt.hh"


void LlegirLlistaParInt(list<ParInt>& l){
    ParInt n;
    while (n.llegir()){
        l.push_back(n);
    }

}


