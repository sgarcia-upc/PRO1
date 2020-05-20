#include "llista_elem_central.hpp"
#include "listIOint.hpp"
using namespace std;

int main(){
    list<int> li;
    cin >> li;
    cout << li;
	if (li.size()%2 == 0)
		cout << "Error: La llista ha de tenir un nombre senar d'elements.";
	else
		cout << "L'element central és " << elem_central(li) << endl;
}
