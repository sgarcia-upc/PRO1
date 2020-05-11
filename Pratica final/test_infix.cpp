#include <iostream>
#include "expressio.hpp"

using namespace std;

int main (){

    expressio e = expressio(token("L"));
    e.llegir_postfixa(cin);
    e.show();
    cout << endl;
    cout << endl;
    cout << "POSTFIXA: " << e.postfixa() << endl;
    cout << "INFIXA: " << e.infixa() << endl;
}

