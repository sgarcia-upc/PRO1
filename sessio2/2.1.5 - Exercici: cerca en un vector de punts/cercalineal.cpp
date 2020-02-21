#include <iostream>
#include <Punt.hpp>
#include <vector>
using namespace std;

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

void intercanvia(vector<Punt> &v)
//Pre: cualsevol punt
//Post: no retorna res pero intercambia les cordenades del punt donat
{
	for (int x=0; x < int(v.size()); x++){
		Punt p = v[x];
		float x = p.coordenadax();
		float y = p.coordenaday();
		p.modificax(y);
		p.modificay(x);
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
    Punt abuscar;
    cin >>abuscar;
    pair <bool, int> res = cercalineal(v, abuscar);
    if (res.first){
        cout << "Trobat a: " << res.second <<endl;
    }else {
        cout << "El punt no està en el vector.";
    }
}
