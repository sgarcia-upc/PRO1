#ifndef CAMI_HPP
#define CAMI_HPP
#include "Punt.hpp"
#include <vector>

class Cami {
// Representa un recorregut format per una llista de punts tals que 
// cada parella de punts consecutiva en la llista es veina verticalment
// o horitzontalment.

    
private:
    vector<Punt> punts; // cada parella de punts consecutiva 
                        // en el vector, es veina verticalment
                        // o horitzontalment.
    int npunts;         // ha de valer entre 0 i punts.size()-1
    static const int MAX_PUNTS = 50;
    
public:
        
    //Constructors 
    Cami();
    /* Pre: cert */
    /* Post: el resultat es un cami buit (de longitud 0) */
    
    Cami(const Cami &b);
    /* Pre: cert */
    /* Post: el reseultat es un cmai nou copia de cami b*/
    
    //Destructor per defecte
    ~Cami();
    
    //Modificadors
    void allargar(const Punt &p, bool &b); 
    /* Pre: el p.i. no esta ple i el punt p ha de ser valid per allargar el 
            cami */
    /* Post: s'ha afegit el punt p al parametre implicit */
    
    //Consultors
    int longitud() const;
    /* Pre: cert */
    /* Post: el resultat es el nombre de punts del p.i. */
    bool conte_punt(const Punt &p) const;
    /* Pre: cert */
    /* Post: el resultat indica si el punt p es troba dins el p.i. o no */
    Punt consultar_punt(int i) const;
    /* Pre: 1 <= i <= nombre de punts del p.i. */
    /* Post: el resultat es el punt i-essim del p.i. */
    bool extensible(const Punt &p) const;
    /* Pre: cert */
    /* Post: el resultat indica si el punt p es pot afegir al final del 
       p.i. */
       
    //Lectura i escriptura
    void llegir_cami();
    /* Pre: cert (completem els detalls de format quan
       coneguem la implementacio) */
    /* Post: el p.i. conte el conjunt de punts, llegits pel canal 
       estandard d'entrada, que formen un cami */
    void escriure_cami() const;
    /* Pre: cert */
    /* Post: s'han escrit pel canal estandard de sortida els punts del p.i */
};
#endif
