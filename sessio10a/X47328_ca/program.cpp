#include "cua.hpp"
using namespace std;

int main() {
    Cua c;
    cin  >> c;
    cout << c;
    int n;
    while (cin >> n) {
    	c.encuar_preferencia(n);
    	if (n >= 0)
    		cout << c;
    }
}
