#include <iostream>
#include <stack>
#include <list>
#include "arbreBin.hpp"

using namespace std;

void inordre(const arbreBin<int> &a, list<int> &f)
/*Pre: l es una llista buida */
/* Post: l conte el recorregut en inordre d el'arbre a */
{
	if(not a.es_buit()){
		if(a.fe().es_buit() and a.fd().es_buit()){
			f.insert(f.end(), a.arrel());
		}
		else if(a.fe().es_buit() and not a.fd().es_buit()){
			inordre(arbreBin<int>(a.arrel(),arbreBin<int>(),arbreBin<int>()), f);
            //H.I l conte el recorregur del un abre amb un arrel
            //Fita: es pasa una branca endins per tant l'arbre decreix
			inordre(a.fd(), f);
            //H.I l conte el recorregur del fill dret d'a
            //Fita: es pasa una branca endins per tant l'arbre decreix
		}
		else if(not a.fe().es_buit() and a.fd().es_buit()){
			inordre(a.fe(), f);
            //H.I l conte el recorregur del fill esquerre d'a
            //Fita: es pasa una branca endins per tant l'arbre decreix
			inordre(arbreBin<int>(a.arrel(),arbreBin<int>(),arbreBin<int>()), f);
            //H.I l conte el recorregur del un abre amb un arrel
            //Fita: es pasa una branca endins per tant l'arbre decreix
		}
		else {
			inordre(a.fe(), f);
            //H.I l conte el recorregur del fill esquerre d'a
            //Fita: es pasa una branca endins per tant l'arbre decreix
			inordre(arbreBin<int>(a.arrel(),arbreBin<int>(),arbreBin<int>()), f);
            //H.I l conte el recorregur del un abre amb un arrel
            //Fita: es pasa una branca endins per tant l'arbre decreix
			inordre(a.fd(), f);
            //H.I l conte el recorregur del fill dret d'a
            //Fita: es pasa una branca endins per tant l'arbre decreix
		}
    }
		
}

void isOrdenada(const list<int> &l, list<int>::const_iterator &it, bool &ord, int &ant){
// Pre: cert
// Post El ord indica si la llista l esta isOrdenadaenada de forma creixent
    if(it != l.end() and ord){
        if (ant >= *it) ord = false;
        ant = *it;
        isOrdenada(l,++it,ord,ant);
        //H.I: El ord indica si la llista l esta isOrdenadaenada de forma creixent
        //FITA: l'iterador s'aproxima al final;
    }
}

int main(){
    arbreBin<int> a;
    cin >> a;
    cout << a <<endl;
    list <int> l;
    inordre(a, l);

    list<int>::const_iterator it = l.begin();
    bool b = true;
    if (not l.empty()){
        int i = *l.begin()-1;
        isOrdenada(l, it, b, i);
    }

    
    if (b){
        cout << "L'arbre és un arbre binari de cerca.";
    } else {
        cout << "L'arbre no és un arbre binari de cerca.";
    }
    cout << endl;
}
