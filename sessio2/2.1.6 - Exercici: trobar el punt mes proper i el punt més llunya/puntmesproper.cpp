#include <iostream>
#include <Punt.hpp>
#include <vector>
using namespace std;

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

int main (){
    int mida;
    cin >> mida;

    vector<Punt> v;
    llegeixVectorPunt(v, mida);
    
    mostrarVectorPunts(v);
    
    Punt prop, lluny;
    PuntProperLlunya(v, prop, lluny);

    cout << "El punt mes proper a l'origen es "<<prop << " i el punt mes llunya a l'origen es " << lluny << endl;
}
