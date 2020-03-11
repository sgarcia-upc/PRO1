#include "list_punt_separa.hpp"
#include "listIOpunt.hpp"
using namespace std;

int main(){
  list<Punt> lp;
  cin >> lp;
  cout << lp;
  float x;
  while (cin >> x) {
    list<Punt> lpa(lp), lp1, lp2;
    separa(lpa, x, lp1, lp2);
    cout << x << endl;
    cout << lp1;
    cout << lp2;
    if (not lpa.empty())
      cout << "Error: La llista, desprès de separar-la, no està buida.";
  }
}
