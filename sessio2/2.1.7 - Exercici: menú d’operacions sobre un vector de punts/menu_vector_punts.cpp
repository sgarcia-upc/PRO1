#include <Punt.hpp>
#include<vector>

pair<bool, int> cercalineal(const vector<Punt> &v, Punt x)
/* Pre: cert */
/* Post: el resultat es un boolea que indica si x es troba dins de v */
{
    pair<bool, int> meh(false, 0);
    int i = 0;
    bool trobat = false;

    while (i<int(v.size()) and not trobat ) {
        if (v[i]==x){
            trobat = true;
        }
        else ++i;
    }

    meh.first = trobat;
    meh.second = i;

    return meh;
}


void llegeixVectorPunt(vector<Punt> &v, int mida){
    for (int x=0; x < mida; x++){
        Punt l;
        cin >> l;
        v.push_back(l);
    }
}

void mostrarVectorPunts(vector<Punt> v){
    for (int x=0; x < int(v.size()); x++)
        cout << " " << v[x];
    cout << endl;
}

void PuntProperLlunya(const vector<Punt> &v, Punt &prop, Punt &lluny)
/* Pre: cert */
/* Post: el resultat es un boolea que indica si x es troba dins de v */
{
    pair<Punt, Punt> meh;
    prop = v[0];
    lluny = v[0];


    float dpp = prop.distancia_origen();
    float dpl = dpp;

    for (int x=0; x < int(v.size()); x++){

        float di = v[x].distancia_origen();

        if (di > dpl or (di == dpl and v[x].coordenadax() < lluny.coordenadax()))
        {
            lluny = v[x];
            dpp = di;
        }

        if (di < dpp or (di == dpp and v[x].coordenadax() < lluny.coordenadax()))
        {
            prop = v[x];
            dpl = di;
        }
    }
}



int main(){

    int option = -77;
    vector<Punt> v;

    while (option != -6){
        switch (option){
            case(-1): {// llegir vector de punts
                int mida;
                cin >> mida;
                llegeixVectorPunt(v, mida);
                break;
            }

            case(-2): {// escriure vector punts
                mostrarVectorPunts(v); 
                break;
            }

            case (-3): { //intercanvia les cordenades de tots els punts del vector
                break;
            }

            case(-4): { //donat un punt dir si es troba dins del vector
                Punt a;
                cin >> a;
                cercalineal(v, a);
                break;
            }

            case(-5): { // obtenir punt mes proper y punt mes llunya
                Punt proper, llunya;
                PuntProperLlunya(v, proper, llunya);
                break;
            }
            default: {
                cout << "Opcio no valida";
            }

        }

        cout << "Option: ";
        cin >> option;
    }

}
