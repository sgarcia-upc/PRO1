#include <iostream>
#include <vector>
using namespace std;

void intercanvia_maxim_minim(vector<int>& meh){
    int max = 0;
    int min= 0;
    int aux = 0;
    for (int x=0; x < meh.size(); x++){
        if (max < meh[x]){
            max = x;
        }  

        if (min > meh[x]){
            min = x;
        } 
    } 

    //cout << min << max << endl;
    
    aux = meh[max];
    meh[max] = meh[min];
    meh[min] = aux; 
}

void llegeix_vector(vector<int>& v, int mida) 
/* Pre: mida > 0 */
/* Post: v conte "mida" valors enters llegits per canal estandard d'entrada */
{
  v = vector<int>(mida); 
  for (int i = 0; i < mida; ++i) cin >> v[i];
}

void mostra_vector(const vector<int>& v) 
/* Pre: cert */
/* Post: s'han escrit els valors de v pel canal estandard de sortida */
{
  for (int i = 0; i < int(v.size()); ++i) cout << " " << v[i];
    cout << endl; 
}

int main() {
  vector<int> ve;
  cout << "Entra la mida del vector (>0): ";
  int mida;
  cin >> mida;
  if (mida<=0) cout << "Mida del vector no valida." << endl;
  else {
    llegeix_vector(ve, mida);
    cout << "Vector: " << endl;
    mostra_vector(ve);
    intercanvia_maxim_minim(ve);
    mostra_vector(ve);
  }
}

