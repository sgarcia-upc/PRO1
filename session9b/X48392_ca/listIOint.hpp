#include <list>
#include <iostream>
using namespace std;

// Lectura i escriptura de llistes de int

ostream& operator<<(ostream &os, const list<int> &l);
/* Pre: cert */
/* Post: s'han escrit els enters de la llista l
   al canal estàndard de sortida */

istream& operator>>(istream &is, list<int> &l);
/* Pre: cert */
/* Post: la llista l passa a tenir els enters llegits del canal 
   estàndard d'entrada */
