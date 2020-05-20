#include "cua.hpp"

 void Cua::encuar_preferencia(const int &elem)
 /* Pre: El p.i. conte una cua C */
 /* Post: El p.i. passa a ser el resultat d'afegir elem a C
 al davant del primer element igual que ell, si n'hi ha
 algun; altrament, s'afegeix al darrere de tot. */
{
    if (longitud>0){
        bool added = false;
        node_cua *actual = primer_node;

        while(actual != NULL and added == false){

            if (actual -> info == elem and actual != ultim_node){
                added = true;

                node_cua *nou = new node_cua;
                nou->info = elem;
                nou->seguent = actual -> seguent;

                actual -> seguent = nou;
                longitud++;
            }   

            actual = actual->seguent;
        }
        if (added == false ){
            encuar(elem);
        }
    }
    else {
       encuar(elem); 
    }
}
