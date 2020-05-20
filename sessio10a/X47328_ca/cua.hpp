#ifndef _CUA_HPP
#define _CUA_HPP
#include <iostream>
using namespace std;

class Cua {
  public: 
     Cua();
     /* Pre: cert */
     /* Post: El p.i. és una cua sense cap element */
     
     Cua(const Cua& c); // Constructor per còpia
     /* Pre: cert */
     /* Post: El p.i. és una còpia de c */

     ~Cua(); // Destructor
     /* Pre: cert */
     /* Post: S'ha destruit el contingut del p.i. */

     Cua& operator=(const Cua& c); // Operador assignació
     /* Pre: cert */
     /* Post: El p.i. original s'ha destruit i ara el p.i. és una còpia de c,
              excepte si el p.i. i c eren el mateix objecte. */
    
     void encuar(const int &x);
     /* Pre: cert */
     /* Post: El p.i. és com el p.i. original amb x afegit com a darrer element. */

     void desencuar();
     /* Pre: El p.i. és una cua no buida */
     /* Post: El p.i. és com el p.i. original però sense el primer element afegit. */

     int primer() const;
     /* Pre: El p.i. és una cua no buida */
     /* Post: Retorna el primer element afegit al p.i. */

     bool es_buida() const;
     /* Pre: cert */
     /* Post: Retorna si el p.i. és una cua buida o no. */

     int mida() const;
     /* Pre: cert */
     /* Post: Retorna el nombre d’elements del p.i. */

     void encuar_preferencia(const int &elem);
     /* Pre: El p.i. conte una cua C */
     /* Post: El p.i. passa a ser el resultat d'afegir elem a C al davant del primer
        element igual que ell, si n'hi ha algun; altrament, s'afegeix al darrere de tot. */

     friend ostream& operator<<(ostream& os, const Cua &c);
     /* Pre: cert */
     /* Post: S'han escrit els enters de la cua c al canal os. */

     friend istream& operator>>(istream& is, Cua &c);
     /* Pre: c és buida; el canal is conté la mida de la cua i els elements d'una cua C. */
     /* Post: c = C */

  private:
     struct node_cua {
        int info;          // Informació dins de cada 'node_cua'
        node_cua *seguent; // Punter al següent 'node_cua'. NULL indica final de la cadena
     };

     int longitud;          // Longitud de la cua
     node_cua* primer_node; // Apunta al front de la cua
     node_cua* ultim_node;  // Apunta al final de la cua
                 
     static void esborra_cua(node_cua* n);
     // Mètode privat de classe per alliberar memòria; allibera la cadena de 
     // nodes que s'inicia en el node_cua n. 
     
     static node_cua* copia_cua(const node_cua* origen, node_cua* &u);
     // Mètode privat de classe per realitzar còpies; còpia tota la cadena de nodes a partir
     // del node_cua apuntat per origen i retorna un punter al node_cua inicial de la còpia,
     // i u apunta a l'últim node. Si origen és NULL, u i el punter retornat són NULL.
};
#endif
