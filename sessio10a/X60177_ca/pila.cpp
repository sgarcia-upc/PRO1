#include "pila.hpp"

// -------------------------
// MÈTODES PRIVATS DE CLASSE
// -------------------------

void Pila::esborra_pila(node_pila* n) {
   if (n != NULL) {
      esborra_pila(n->seguent);
      delete n;
   }
}

Pila::node_pila* Pila::copia_pila(const node_pila* origen) {
   node_pila *desti = NULL;
   if (origen != NULL) {
      desti = new node_pila;
      desti->info = origen->info;
      // copia la resta de la cadena
      desti->seguent = copia_pila(origen->seguent);
   }
   return desti;
}

// -------------------------
// MÈTODES PÚBLICS
// -------------------------
Pila::Pila() : altura(0), primer_node(NULL) { }

Pila::Pila(const Pila& p) {
   altura = p.altura;
   primer_node = copia_pila(p.primer_node);
}

Pila::~Pila() {
   esborra_pila(primer_node);
}

Pila& Pila::operator=(const Pila& p) {
   if (this != &p) {
      node_pila *aux = copia_pila(p.primer_node); 
      esborra_pila(primer_node);
      primer_node = aux;
      altura = p.altura;
   }
   return *this;
}

void Pila::empilar(const int &x) {
   node_pila *n = new node_pila;
   n->info = x;
   n->seguent = primer_node;
   primer_node = n;
   ++altura;
}

void Pila::desempilar() {
   node_pila *n = primer_node;
   primer_node = primer_node->seguent;
   delete n;
   --altura;
}

int Pila::cim() const {
   return primer_node->info;
}

bool Pila::es_buida() const {
   return primer_node == NULL;
}

int Pila::mida() const {
   return altura;
}

ostream& operator<<(ostream& os, const Pila &p) {
   Pila::node_pila *n = p.primer_node;
   while (n != NULL) {
      os << n->info;
      n = n->seguent;
      if (n != NULL) os << "|";
   }
   os << "]" << endl;
   return os;
}

istream& operator>>(istream &is, Pila &p) {
   int n;
   is >> n;
   for (int i = 0; i < n ; ++i) {
      int e;
      is >> e;
      p.empilar(e);
   }
   return is;
}
