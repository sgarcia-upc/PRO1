#include <iostream>
#include "arbreBin.hpp"
#include "listIOint.hpp"

using namespace std;


bool findPath(arbreBin<int> ar, list<int>& l, int x) 
//Pre: l is empty
//Post: retorna true si troba un cami en ar on sigui x si no retornara false, l sera el recorregut fins a x desde adalt
{ 
    if (not ar.es_buit()) {

        if (ar.arrel() == x){ 
            return true; 
        } else {
            l.insert(l.end(), ar.arrel());     
        }
        
          
        if (findPath(ar.fe(), l, x))
        //H.I: retorna true si troba un cami en ar.fe() on sigui x si no retornara false, l sera el recorregut fins a x desde adalt
        //Fita: arbre es mes petit
            return true; 

        else if (findPath(ar.fd(), l, x)) 
        //H.I: retorna true si troba un cami en ar.fe() on sigui x si no retornara false, l sera el recorregut fins a x desde adalt
        //Fita: arbre es mes petit
            return true; 
          
        l.pop_back(); 
    }

    return false;             
} 



int main (){
    arbreBin<int> ar, ar2;
    cin >> ar;
    cout << ar<<endl;
    int j;
    while (cin >> j){
        list<int> l;
        if (not findPath(ar, l, j)) l.clear();
        l.reverse();
        cout << l;
    }
}

