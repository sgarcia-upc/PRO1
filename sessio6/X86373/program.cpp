#include <iostream>
#include <queue>
#include "arbreBin.hpp"

using namespace std;

bool sonBranquesIguals(const arbreBin<int> &a1, const arbreBin<int> &a2){
//Pre: true
//Post: Retorna si els arbres a1 y a2 son iguals

    // if both tree are empty we return true
    if (a1.es_buit() and a2.es_buit()) return true;
    if (a1.es_buit() or a2.es_buit()) return false;


    // Si la arrels dels dos arbres son iguals
    if (a1.arrel()==a2.arrel()){


        //comprovarem un altre cop amb la branca esquerra de a1 y la branca detra de a2.
        if (sonBranquesIguals(a1.fe(),a2.fd())){
        // H.I: retorna si branca esquerra a1 es igual a la branca dreta de a2
        //Fita: com anem una branca en dins de tots dos arbres cuan no tinguem mes branques acabara

            //comprovarem el cas contrari de amunt branca detra de a1 amb la branca esquerra de a2.
            return sonBranquesIguals(a1.fd(), a2.fe());
            // H.I: retorna si branca dreta a1 es igual a la branca esquerra de a2
            //Fita: com anem una branca en dins de tots dos arbres cuan no tinguem mes branques acabara
       }
    }
    return false;
}

int main (){

    arbreBin<int> arbre;
    cin >> arbre;
    cout << arbre << endl;
    bool simetric = true;

    if (arbre.es_buit())
        simetric = true;
    else if (arbre.fd().es_buit() and arbre.fe().es_buit())
        simetric = true;
    else if (arbre.fd().es_buit() or  arbre.fe().es_buit())
        simetric = false;
    else if (sonBranquesIguals(arbre.fe(), arbre.fd()))
        simetric = true;
    else
        simetric = false;


    if (simetric)
        cout << "L'arbre és simètric";
    else
        cout << "L'arbre no és simètric.";

    cout << endl;
}

