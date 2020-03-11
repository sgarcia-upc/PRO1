#include "Cami.hpp"

using namespace std;

//Aquest main es per provar la classe Cami.

void addDot(Cami &c){
    cout << "Punt a afegir: ";
    Punt p;
    cin >> p;
    cout << p << endl;

    if (c.extensible(p)){
        c.allargar(p);
    } else {
        cout << "El cami no pot ser extes amb el punt " << p <<endl;    
    }
}


void getDotOfPath(Cami &c){
    int p;
    cout << "Posicio del punt a consultar [1-" << c.longitud() << "]: ";
    cin >> p;
    
    cout << p <<endl;
    if (p > 1 and p < c.longitud()){
        cout << c.consultar_punt(p) <<endl;
    } else {
        cout << "Posicio no valida." << endl;
    }

}

void showPath (Cami &c){
    cout <<"Cami actual: " ;
    c.escriure_cami();
}

void showInversePath(Cami &c){
    Cami b;
    for (int i=1; i <= c.longitud(); i++){
        Punt p = c.consultar_punt(i);
        float x = p.coordenadax();
        float y = p.coordenaday();
        p.modificax(y);
        p.modificay(x);
        b.allargar(p); 
    }

    b.escriure_cami();

}

int main(){ 
    Cami c;
    
    c.llegir_cami();
    
    int option = 0;

    bool exit = false;
    while (exit == false){
        cout << "Opcio: "; 
        cin >> option; 
        cout << option << endl;

        switch (option){
            case -1: // add 
                addDot(c);
                break;;

            case -2: // get Dot of X position
                getDotOfPath(c);
                break;;

            case -3: // inverse cami
                showInversePath(c);
                break;;


            case -4: // showCami
                showPath(c);
                break;;

            case -5: // Exit
                exit = true;
                break;;

            default:
                cout << "Opcio no valida." << endl;
                break;;

        }



    }

    
}
