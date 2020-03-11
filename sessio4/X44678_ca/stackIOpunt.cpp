#include "stackIOpunt.hpp"
#include "Punt.hpp"

// Lectura i escriptura de piles de int

ostream& operator<<(ostream& os, stack<Punt> p)
/* Pre: cert */
/* Post: s'han escrit els punts de la pila p
   al canal estàndard de sortida */
{
    int n = p.size();
    for (int i = 0; i < n; ++i) {
        os << p.top();
        if (i < n-1) os << "|";
        p.pop();
    }
    os << "]" << endl;
    return os;
}

istream& operator>>(istream &is, stack<Punt> &p)
/* Pre: cert */
/* Post: la pila p passa a tenir els punts llegits del canal 
   estàndard d'entrada */
{
    int n;
    is >> n;
    for (int i = 0; i < n ; ++i) {
        Punt e;
        is >> e;
        p.push(e);
    }
    return is;
}
