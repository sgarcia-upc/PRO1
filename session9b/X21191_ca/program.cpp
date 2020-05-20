#include <iostream>
#include <vector>

using namespace std;

int mitjana_menor(const vector<int> &v, int k)
/* Pre: 0 < k <= v.size() */
/* Post: Retorna l'index del primer element del subvector v de
   llargada k amb una mitjana menor; si hi ha mes d'un subvector
   amb una mitjana menor, retorna el que tingui un index menor */
{

    int suma = 0;
    for (int i = 0; i < k; i++){
        suma += v[i];
    }

    int res = 0;
    int i = 0;
    int suma_aux = suma;
    for (int j=k; j < int(v.size()); j++){
        suma_aux += - v[i] + v[j];
        i++;
        if (suma_aux < suma){
            suma = suma_aux;
            res = i;
        }
    }
    return res;
}

int main (){

    int n,j;
    cin >>n;

    vector<int> l;
    for (int i=0; i<n; i++){
        cin >> j;
        l.push_back(j); 
    }

    cout << "[";
    cout << l[0];
    for (unsigned int i=1; i < l.size(); i++){
       cout << "," << l[i];
    }
    cout << "]"<<endl ;

    while (cin >> n){
        cout << mitjana_menor(l, n) <<endl; 
    }
}

