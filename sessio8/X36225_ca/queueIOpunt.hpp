#include <queue>
#include <iostream>
#include "Punt.hpp"
using namespace std;

//Lectura i escriptura de cues de Punt

ostream& operator<<(ostream&, queue<Punt>);
/* Pre: cert */
/* Post: s'han escrit els punts de la cua
   al canal estàndard de sortida */

istream& operator>>(istream&, queue<Punt> &);
/* Pre: cert */
/* Post: la cua passa a tenir els punts llegits del canal 
   estàndard d'entrada */
