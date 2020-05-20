#include <iostream>
#include "arbreBin.hpp"
#include "Punt.hpp"
#include <stack>

using namespace std;

void volteaPunt(const arbreBin<Punt> &a1, arbreBin<Punt> &a2){
//Pre: p es buit, A1 = a1, p = P
//Post: Retornem el abreBin a1 y crearem una replica en a2 amb els punts girats

    if (not a1.es_buit()){
        arbreBin<Punt> esquerra = arbreBin<Punt>();
        if (not a1.fe().es_buit()){
            volteaPunt(a1.fe(), a2);
            // H.I: Retornem agafem fill esquerre de a1 y crearem una replica en a2 amb els punts girats
            //Fita: pasem una branca per tant el abre decreix
            esquerra = a2; 
        } 
        arbreBin<Punt> dreta = arbreBin<Punt>();
        if (not a1.fd().es_buit()){
            volteaPunt(a1.fd(), a2);
            // H.I: Retornem agafem fill dret de a1 y crearem una replica en a2 amb els punts girats
            //Fita: pasem una branca per tant el abre decreix
            dreta = a2; 
        } 

        Punt arrel;
        arrel.modificax(a1.arrel().coordenaday());
        arrel.modificay(a1.arrel().coordenadax());
        a2 = arbreBin<Punt>(arrel, esquerra, dreta);
    }
}

int main (){
    arbreBin<Punt> arbre;
    cin >> arbre;
    arbreBin<Punt> arbre2;
    volteaPunt(arbre, arbre2);
    cout << arbre2 << endl; 
}

