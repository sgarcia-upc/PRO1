#include "stackIOint.hpp"

//Lectura i escriptura de piles de int

ostream& operator<<(ostream& os, stack<int> p)
/* Pre: cert */
/* Post: s'han escrit els enters de la pila p
   al canal est�ndard de sortida */
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

istream& operator>>(istream &is, stack<int> &p)
/* Pre: cert */
/* Post: la pila p passa a tenir els enters llegits del canal 
   est�ndard d'entrada */
{
    int n;
    is >> n;
    for (int i = 0; i < n ; ++i) {
        int e;
        is >> e;
        p.push(e);
    }
    return is;
}

