#include <iostream>
#include "expressio.hpp"

using namespace std;

int main (){

    expressio efd = expressio("+");
    expressio efe = expressio("+");
    expressio ef = expressio("+", efd, efe);

    expressio effd = expressio("+");
    expressio e = expressio("+", ef, effd);

    e.show();
    
}

