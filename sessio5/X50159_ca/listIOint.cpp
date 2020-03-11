#include "listIOint.hpp"

// Lectura i escriptura de llistes de int
ostream& operator<<(ostream &os, const list<int> &l)
/* Pre: cert */
/* Post: s'han escrit els enters de la llista l
   al canal estandard de sortida */
{
    os << "[";
    for (list<int>::const_iterator it = l.begin(); it != l.end(); ++it) {
        if (it!=l.begin()) os<<",";
        os << (*it);
    }
    os << "]" << endl;
    return os;
}
   
   
istream& operator>>(istream &is, list<int> &l)
/* Pre: cert */
/* Post: la llista l passa a tenir els enters llegits del canal 
   estandard d'entrada */
{
    cout << "Entra el nombre d'elements: ";
    int n;
    is >> n;
    list<int>::iterator it = l.begin();
    while (n>0) {
        int e;
        is >> e;
        l.insert(it,e);
        --n;
    }
    return is;
}

