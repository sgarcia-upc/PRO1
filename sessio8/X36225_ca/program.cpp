#include "cua_elimina.hpp"
#include "queueIOpunt.hpp"
using namespace std;

int main(){
    queue<Punt> c;
    cin  >> c;
    cout << c;
    Punt p;
    while (cin >> p) {
    	queue<Punt> c2 = elimina_punts(c, p);
    	cout << c2;
    }
}
