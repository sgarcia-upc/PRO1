#include <iostream>
using namespace std;

class Punt{
// Tipus de modul: dades
// Descripcio del tipus: conte les coordenades cartesianes d'un punt a l'espai 
//                       2D que son dos reals.
    
private:
    float x, y;
    
public:
        
    //Constructors 
    Punt();
    /* Pre: cert */
    /* Post: el resultat es un punt de coordenades 0, 0 */
    Punt(float a, float b);
    /* Pre: cert */
    /* Post: el resultat es un punt que te com a coordenades a, b */
    Punt(const Punt &p);
    /* Pre: cert */
    /* Post: el resultat es un punt amb les coordenades del punt p */
    
    //Destructor 
    ~Punt();
    /* Post: esborra automaticament els objectes locals en sortir d'un ambit 
	   de visibilitat */
   
   
    //Modificadors
    void modificax(float xn);
    /* Pre: cert */
    /* Post: la primera coordenada del p.i. passa a ser xn */
    void modificay(float yn);
    /* Pre: cert */
    /* Post: la segona coordenada del p.i. passa a ser yn */
       
    //Consultors
    float coordenadax() const;
    /* Pre: cert */
    /* Post: el resultat es la primera coordenada del p.i. */
    float coordenaday() const;
    /* Pre: cert */
    /* Post: el resultat es la segona coordenada del p.i. */
    float distancia_origen() const;
    /* Pre: cert */
    /* Post: el resultat es la distancia del p.i. a l'origen de 
	   coordenades 0, 0 */
    float distancia(const Punt &p) const;
    /* Pre: cert */
    /* Post: el resultat es la distancia del p.i. al punt p */
    Punt mig(const Punt &p) const;
    /* Pre: cert */
    /* Post: el resultat es el punt mig entre el p.i. i el punt p */
    bool operator==(const Punt &p) const;
    /* Pre: cert */
    /* Post: el resultat indica si el p.i. i el punt p son iguals o no */
    Punt operator+(const Punt &p) const;
    /* Pre: cert */
    /* Post: el resultat es un punt amb les coordenades resultants de sumar
       les coordenades del p.i. amb les del punt p */
       
    //Lectura i escriptura
    friend ostream& operator<<(ostream &os, const Punt &p);
    /* Pre: cert (completem els detalls de format quan coneguem la 
       implementacio) */
    /* Post: s'han escrit els atributs del punt p al canal estandard de 
       sortida */
    friend istream& operator>>(istream &is, Punt &p);
    /* Pre: cert */
    /* Post: el punt p passa a tenir els atributs llegits del canal  
       estandard d'entrada */
};

