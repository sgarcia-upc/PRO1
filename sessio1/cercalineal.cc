#include <iostream>
#include <vector>
using namespace std;

bool cercalineal(const vector<int> &v, int x)
/* Pre: cert */
/* Post: el resultat es un boolea que indica si x es troba dins de v */
{
  bool trobat = false;
  int i = 0;
  while (i<int(v.size()) and not trobat) {
    if (v[i]==x) trobat = true;
    else ++i;
  }
  return trobat;
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
    cout << "Entra el valor a buscar: ";
    int elem;
    cin >> elem;
    bool res = cercalineal(ve, elem);
    if (res) cout << "El valor es troba en el vector." << endl;
    else cout << "El valor no es troba en el vector." << endl;
  }
}
