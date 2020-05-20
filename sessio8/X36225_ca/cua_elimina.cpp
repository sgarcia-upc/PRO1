#include "cua_elimina.hpp"
#include "queueIOpunt.hpp"

using namespace std;

void elimina_punts_aux(queue <Punt> &c, queue<Punt> &x, const Punt &p)
//Pre: cert
//Post x = elements de c on no son iguals a p, c es buidara
{
    if (not c.empty()){
        if (not (c.front() == p))
            x.push(c.front());
        c.pop();       
        elimina_punts_aux(c,x,p);
        //H.I: x = elements de c-1 on no son iguals a p
        //FITA: c -1 element
    }
}

queue<Punt> elimina_punts(queue<Punt> c, Punt p)
/* Pre: c = C i p = P */
/* Post: retorna la cua C on s'han eliminat totes les aparicions del punt P */
{
    queue<Punt> e;
    elimina_punts_aux(c,e, p);
    return e;
}
