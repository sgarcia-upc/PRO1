#include "pila_concatena.hpp"
#include "stackIOint.hpp"
using namespace std;

int main() {
	bool seguir = true;
	while (seguir) {
		stack<int> p1, p2;
		cin >> p1;
		cin >> p2;
		cout << "pila 1: " << p1;
		cout << "pila 2: " << p2;
		stack<int> cp1p2;
		concatena_piles(p1, p2, cp1p2);
		cout << "pila concatenació: " << cp1p2 << endl;
		string s;
		cin >> s;
		seguir = s == "----------";
	}
}
