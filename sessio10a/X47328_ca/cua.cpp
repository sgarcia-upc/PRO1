#include "cua.hpp"

// -------------------------
// MÈTODES PRIVATS DE CLASSE
// -------------------------

void Cua::esborra_cua(node_cua* n) {
   if (n != NULL) {
      esborra_cua(n->seguent);
      delete n;
   }
}

Cua::node_cua* Cua::copia_cua(const node_cua* origen, node_cua* &u) {
   node_cua *desti = NULL;
   if (origen == NULL)
      u = NULL;
   else {
      desti = new node_cua;
      desti->info = origen->info;
      // copia la resta de la cadena
      desti->seguent = copia_cua(origen->seguent, u);
      if (desti->seguent == NULL) u = desti;
   }
   return desti;
}

// -------------------------
// MÈTODES PÚBLICS
// -------------------------
Cua::Cua() : longitud(0), primer_node(NULL), ultim_node(NULL) { }

Cua::Cua(const Cua& c) {
   longitud = c.longitud;
   primer_node = copia_cua(c.primer_node, ultim_node);
}

Cua::~Cua() {
   esborra_cua(primer_node);
}

Cua& Cua::operator=(const Cua& c) {
   if (this != &c) {
      node_cua *un;
      node_cua *pn = copia_cua(c.primer_node, un); 
      esborra_cua(primer_node);
      primer_node = pn;
      ultim_node = un;
      longitud = c.longitud;
   }
   return *this;
}

void Cua::encuar(const int &x) {
   node_cua *n = new node_cua;
   n->info = x;
   n->seguent = NULL;
   if (primer_node == NULL) primer_node = n;
   else ultim_node->seguent = n;
   ultim_node = n;
   ++longitud;
}

void Cua::desencuar() {
   node_cua *n = primer_node;
   if (primer_node->seguent == NULL) {
      primer_node = NULL;
      ultim_node = NULL;
   } else
      primer_node = primer_node->seguent;
   delete n;
   --longitud;
}

int Cua::primer() const {
   return primer_node->info;
}

bool Cua::es_buida() const {
   return primer_node == NULL;
}

int Cua::mida() const {
   return longitud;
}

ostream& operator<<(ostream& os, const Cua &c) {
   os << "<";
   Cua::node_cua *n = c.primer_node;
   while (n != NULL) {
      os << n->info;
      n = n->seguent;
      if (n != NULL) os << "|";
   }
   os << "<" << endl;
   return os;
}

istream& operator>>(istream &is, Cua &c) {
   int n;
   is >> n;
   for (int i = 0; i < n ; ++i) {
      int e;
      is >> e;
      c.encuar(e);
   }
   return is;
}
