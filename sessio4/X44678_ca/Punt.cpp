#include "Punt.hpp"
#include <cmath>
#include <iostream>
using namespace std;

Punt::Punt()
/* Pre: cert */
/* Post: el resultat es un punt de coordenades 0, 0 */
{
  x = 0; 
  y = 0;
}

Punt::Punt(float a, float b)
/* Pre: cert */
/* Post: el resultat es un punt que te com a coordenades a, b */
{
  x = a; 
  y = b;
}

Punt::Punt(const Punt &p)
/* Pre: cert */
/* Post: el resultat es un punt amb les coordenades del punt p */
{
  x = p.x; 
  y = p.y;
}

Punt::~Punt()
/* Post: esborra automaticament els objectes locals en sortir d'un ambit 
   de visibilitat */
{
}

void Punt::modificax(float xn)
/* Pre: cert */
/* Post: la primera coordenada del p.i. passa a ser xn */
{
  x = xn;
}

void Punt::modificay(float yn)
/* Pre: cert */
/* Post: la segona coordenada del p.i. passa a ser yn */
{
  y = yn;
}

float Punt::coordenadax() const
/* Pre: cert */
/* Post: el resultat es la primera coordenada del p.i. */
{
  return x;
}

float Punt::coordenaday() const
/* Pre: cert */
/* Post: el resultat es la segona coordenada del p.i. */
{
  return y;
} 

float Punt::distancia_origen() const
/* Pre: cert */
/* Post: el resultat es la distancia del p.i. a l'origen de 
   coordenades 0, 0 */
{
  return sqrt(x*x + y*y);
}

float Punt::distancia(const Punt &p) const
/* Pre: cert */
/* Post: el resultat es la distancia del p.i. al punt p */
{
  float dx = x - p.x;
  float dy = y - p.y;
  return sqrt(dx*dx + dy*dy);
}

Punt Punt::mig(const Punt &p) const
/* Pre: cert */
/* Post: el resultat es el punt mig entre el p.i. i el punt p */
{
  float cx = (x + p.x)/2;
  float cy = (y + p.y)/2;
  return Punt (cx, cy);
}

bool Punt::operator==(const Punt &p) const
/* Pre: cert */
/* Post: el resultat indica si el p.i. i el punt p son iguals o no */
{
  return x==p.x and y==p.y;
}

Punt Punt::operator+(const Punt &p) const
/* Pre: cert */
/* Post: el resultat es un punt amb les coordenades resultants de sumar
   les coordenades del p.i. amb les del punt p */
{
  return Punt (x + p.x, y + p.y);
}

ostream& operator<<(ostream &os, const Punt &p)
/* Pre: cert */
/* Post: s'han escrit els atributs del punt p al canal estandard de 
   sortida */
{
  os<<"("<<p.x<<", "<<p.y<<")";
  return os;
}

istream& operator>> (istream &is, Punt &p)
/* Pre: estan preparats al canal estandar d'entrada dos reals */
/* Post: el punt p passa a tenir els atributs llegits del canal  
   estandard d'entrada */
{
  is >> p.x >> p.y;
  return is;
}

