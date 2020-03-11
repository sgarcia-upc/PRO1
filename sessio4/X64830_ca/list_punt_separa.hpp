#include <list>
#include "Punt.hpp"

void separa(list<Punt> &lp, float x, list<Punt> &lp1, list<Punt> &lp2);
/* Pre: lp1 i lp2 estan buides */
/* Post:
   lp1 conté els punts de lp amb la coordenada x estrictament menor que x,
   lp2 conté els punts de lp amb la coordenada x estrictament major que x,
   lp està buida.*/
