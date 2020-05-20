#include <iostream>
#include "expressio.hpp"

using namespace std;

int main (){
    cout << "input: ";
    expressio e = expressio(token());
    e.llegir_postfixa(cin);
    cout << e.postfixa() << endl;
    e = e.expandeix(token("a"), expressio(token(3)));
    cout << "out: ";
    cout << e.postfixa();
}

