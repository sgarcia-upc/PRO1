#include "list_punt_separa.hpp"

void separa(list<Punt> &lp, float x, list<Punt> &lp1, list<Punt> &lp2)
/* Pre: lp1 i lp2 estan buides */
/* Post:
   lp1 conté els punts de lp amb la coordenada x estrictament menor que x,
   lp2 conté els punts de lp amb la coordenada x estrictament major que x,
   lp està buida.*/
{
    for (list<Punt>::iterator it = lp.begin(); it!= lp.end(); ++it){
        if ((*it).coordenadax() < x){
            lp1.insert(lp1.end(),*it);
        } else if ((*it).coordenadax() > x) {
            lp2.insert(lp2.end(),*it);
        }
    }
    lp.clear(); 
}
