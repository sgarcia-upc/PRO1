#include <iostream>
#include <vector>
using namespace std;

typedef vector <vector<int> > Matriu;

Matriu suma(const Matriu &m1, const Matriu &m2) {
/* Pre: m1 i m2 tenen la mateixa dimensio */
/* Post: el resultat es la suma de m1 i m2 */
  Matriu s(int(m1.size()),vector<int>(int(m1[0].size())));

  for (int i=0; i<int(m1.size()); i++)
    for (int j=0; j<int(m1[i].size()); j++)
      s[i][j] = m1[i][j] + m2[i][j];
  return s;
}

void llegeix_matriu(Matriu &m) {
  for (int i=0; i < int(m.size()); i++) {
    for (int j=0; j < int(m[i].size()); j++) {
    	//cout<<"Element ["<<i<<"]["<<j<<"]=";
      cin>>m[i][j];
    }
  }
}

void mostra_matriu(const Matriu &m) {
  for (int i=0; i<int(m.size()); i++) {
    for (int j=0; j<int(m[i].size()); j++)
      cout<<m[i][j]<<' ';
      //despres de cada fila, salt de linia
    cout<<endl;
  }    
}

int main() {
  //cout << "Entra el nombre de files (>0): ";
  int files;
  cin >> files;
  //cout << "Entra el nombre de columnes (>0): ";
  int columnes;
  cin >> columnes;
  Matriu m1(files,vector<int>(columnes));
  cout << "Primera matriu: " << endl;
  llegeix_matriu(m1);
  mostra_matriu(m1);
  Matriu m2(files,vector<int>(columnes));
  cout << "Segona matriu: " << endl;
  llegeix_matriu(m2);
  mostra_matriu(m2);
  cout << "Matriu suma: " << endl;
  Matriu m3 = suma(m1, m2);
  mostra_matriu(m3);
}
