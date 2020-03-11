#include "Cami.hpp"

using namespace std;

//Aquest main es per provar la classe Cami.

int main(){ 
    Cami c;
    
    c.llegir_cami();
    
    cout << "Cami actual: ";
    if (c.longitud()==0) cout << "cami buit" << endl;
    else c.escriure_cami();
    
    cout << "Longitud actual del cami: " << c.longitud() << endl;
    
    cout << "Entra un punt: " << endl;
    Punt p;
    cin >> p;
    if (c.longitud()>0) {
      if (c.conte_punt(p)) 
        cout << "El punt " << p << " es troba al cami." <<endl;
      else cout << "El punt " << p << " no es troba al cami." << endl;
    }
    else cout << "El cami esta buit." << endl;  
}
