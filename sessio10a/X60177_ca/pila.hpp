#ifndef _PILA_HPP
#define _PILA_HPP
#include <iostream>
using namespace std;

class Pila {
  public: 
    Pila();
    /* Pre: cert */
    /* Post: El p.i. és una pila sense cap element */
     
    Pila(const Pila& p); // Constructor per còpia
    /* Pre: cert */
    /* Post: El p.i. és una còpia de p */

    ~Pila(); // Destructor
    /* Pre: cert */
    /* Post: S'ha destruit el contingut del p.i. */

    Pila& operator=(const Pila& p); // Operador assignació
    /* Pre: cert */
    /* Post: El p.i. original s'ha destruit i ara el p.i. és una còpia de p,
              excepte si el p.i. i p eren el mateix objecte. */
    
    void empilar(const int &x);
    /* Pre: cert */
    /* Post: El p.i. és com el p.i. original amb x afegit com a darrer element. */

    void desempilar();
    /* Pre: El p.i. és una pila no buida */
    /* Post: El p.i. és com el p.i. original però sense el darrer element afegit. */

    int cim() const;
    /* Pre: El p.i. és una pila no buida */
    /* Post: Retorna el darrer element afegit al p.i. */

    bool es_buida() const;
    /* Pre: cert */
    /* Post: Retorna si el p.i. és una pila buida o no. */

    int mida() const;
    /* Pre: cert */
    /* Post: Retorna el nombre d’elements del p.i. */

    void duplica();
    /* Pre: cert */
    /* Post: Duplica els elements del p.i., cada element duplicat es situa al costat de l'original. */

    friend ostream& operator<<(ostream& os, const Pila &p);
    /* Pre: cert */
    /* Post: S'han escrit els enters de la pila p al canal os. */

    friend istream& operator>>(istream& is, Pila &p);
    /* Pre: p és buida; el canal is conté la mida de la pila i els elements d'una pila P. */
    /* Post: p = P */

  private:
    struct node_pila {
      int info;           // Informació dins de cada 'node_pila'
      node_pila *seguent; // Punter al següent 'node_pila'. NULL indica final de la cadena
    };

    int altura;             // Altura de la pila
    node_pila* primer_node; // Apunta al node_pila del cim de la pila
                 
    static void esborra_pila(node_pila* n);
    // Mètode privat de classe per alliberar memòria; allibera la cadena de 
    // nodes que s'inicia en el node_pila n. 
     
    static node_pila* copia_pila(const node_pila* origen);
    // Mètode privat de classe per realitzar còpies; còpia tota la cadena de nodes a partir
    // del node_pila apuntat per origen i retorna un punter al node_pila inicial de la còpia.
};
#endif
