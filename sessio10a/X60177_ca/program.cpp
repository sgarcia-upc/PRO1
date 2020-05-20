#include "pila.hpp"
using namespace std;

int main() {
	bool seguir = true;
	while (seguir) {
		Pila p1;
		cin >> p1;
		cout << p1;
		p1.duplica();
		cout << p1;
		string s;
		cin >> s;
		seguir = s == "----------";
	}
}
