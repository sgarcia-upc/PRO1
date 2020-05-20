#include "arbreBin.hpp"
#include <stack>
#include <list>
#include <iostream>
using namespace std; 

//~ bool orden(unsigned int i, list<int> &c, int anterior)
//~ /* Pre: i = 0; anterior = -999 (un número molt baix per començar la comparació) */
//~ /* Post: retorna false en cas que la llista no sigui endressada */
//~ {
	//~ list<int>::iterator it=c.begin(); 
	//~ if (c.size() > i ){
        //~ if (anterior>*it) return false;
        //~ else{
            //~ anterior=*it; 
            //~ c.erase (it);
            //~ return orden(i,c,anterior);
            //~ /* HI: retorna false en cas que la llista (ara reduida en un element) no sigui endressada */
            //~ /* Fita: la mida de la llista */
        //~ }
    //~ }
    //~ return true;
//~ }

bool orden(const list<int> &l){
// Pre: cert
// Post El resultat indica si la llista l esta isOrdenadaenada de forma creixent
    bool isOrdenada = true;
    list<int>::const_iterator it = l.begin();
    if(it != l.end()){
        int ant = *it;
        ++it;
        while(it != l.end() and isOrdenada){
            if(ant >= *it) isOrdenada = false;
            ant= *it;
            ++it;
        }
    }
    return isOrdenada;
}

void busqueda_binaria (const arbreBin<int> &p, list<int> &llista)
/* Pre: cert */
/* Post: retorna un bool (error), serà cert si l'arbre no es un arbre binari de busueda i fals en cas que ho sigui */
{
	if (not p.es_buit()){
		stack <arbreBin<int> > m; 
		
			m.push(p);
			while (not m.empty()){ 
				arbreBin<int> ar1=m.top();
				m.pop();
				if ( ar1.fe().es_buit() and ar1.fd().es_buit()){
                    llista.insert(llista.end(),ar1.arrel());
				} else if ( not ar1.fe().es_buit() and not ar1.fd().es_buit() ){
					m.push(ar1.fd());
					m.push(arbreBin <int> (ar1.arrel(),arbreBin<int>(),arbreBin<int>()));
					m.push(ar1.fe());
				} else if ( not ar1.fe().es_buit() and ar1.fd().es_buit() ){
					m.push(arbreBin <int> (ar1.arrel(),arbreBin<int>(),arbreBin<int>()));
					m.push(ar1.fe());	
				}else if ( ar1.fe().es_buit() and not ar1.fd().es_buit() ){
					llista.insert(llista.end(),ar1.arrel());
					m.push(ar1.fd()); 
				}
				
			}
	}
}



int main() {
	arbreBin<int> ar; 
	cin >> ar;
	//te meten el arbol
	cout <<ar<< endl; 
    list<int>l;
    busqueda_binaria(ar,l);
    
	if (orden(l)==true) cout<<"L'arbre és un arbre binari de cerca."<<endl;
	else cout<<"L'arbre no és un arbre binari de cerca."<<endl;
}
