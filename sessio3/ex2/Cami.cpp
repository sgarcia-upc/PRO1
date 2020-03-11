#include "Cami.hpp"

Cami::Cami()
/* Pre: cert */
/* Post: el resultat es un cami buit (de longitud 0) */
{
    npunts = 0;
    punts = vector<Punt>(MAX_PUNTS);
}        

Cami::Cami(const Cami &b )
{
    npunts = b.npunts;
    punts = b.punts;
}        
Cami::~Cami(){
    cout << "Me mueeeeroooo...."<<endl;
}

void Cami::allargar(const Punt &p, bool &b) 
/*  Pre : c e r t 
     Post : b i n d i c a s i e l punt r e b u t e s pot a f e g i r a l
    p . i . ; s i b é s c e r t , e l punt s ’ ha a f e g i t a l p . i . i
*/
{
    b=false;
    if (extensible(p)){
        punts[npunts] = p;
        ++npunts;
        b = true;
    }

}
    
int Cami::longitud() const
/* Pre: cert */
/* Post: el resultat es el nombre de punts del p.i. */
{
    return npunts;
}

bool Cami::conte_punt(const Punt &p) const
/* Pre: cert */
/* Post: el resultat indica si el punt p es troba dins el p.i. o no */
{
    bool b = false;
    int i = 0;
    int nump = npunts;
    while (i < nump and not b) {
        if (punts[i] == p) b = true;
        else ++i;
    }
    return b;
}
    
Punt Cami::consultar_punt(int i, bool b) const
/* Pre: 1 <= i <= nombre de punts del p.i. */
/* Post: el resultat es el punt i-essim del p.i. */
{
    
    return punts[i-1];
}
    
bool Cami::extensible(const Punt &p) const
/* Pre: cert */
/* Post: el resultat indica si el punt p es pot afegir al final del p.i. */
{   
	bool b = false;
    if (npunts > 0 and npunts < MAX_PUNTS) {
        Punt darrer = punts[npunts-1];
        bool horit = darrer.coordenaday() == p.coordenaday();
        bool vert = darrer.coordenadax() == p.coordenadax();
        bool sobre = (darrer.coordenaday()-1 == p.coordenaday()) and vert;
        bool sota = (darrer.coordenaday()+1 == p.coordenaday()) and vert;
        bool esq = (darrer.coordenadax()-1 == p.coordenadax()) and horit;
        bool dreta = (darrer.coordenadax()+1 == p.coordenadax()) and horit;
        b = sobre or sota or esq or dreta;
    }
    else b = npunts < MAX_PUNTS;
	return b;
}
       
void Cami::llegir_cami()
/* Pre: estan preparats al canal estandard d'entrada un enter entre
   0 i MAX_PUNTS, que representa el nombre d'elements que llegirem,
   i les dades de tal nombre de punts */
/* Post: el p.i. conte el conjunt de punts, llegits pel canal 
   estandard d'entrada, que formen un cami */
{
    cout << "Nombre de punts: " << endl;
    int n;
    cin >> n;
    Punt p;
    for (int i = 0; i < n; ++i) {
        cin >> p;
        cout << p;
        if (extensible(p)) {
            bool b;
            allargar(p, b);
        }
        cout << endl;
    }
}
       
void Cami::escriure_cami() const
/* Pre: cert */
/* Post: s'han escrit pel canal estandard de sortida els punts del p.i */
{
    cout << "[";
    for (int i = 0; i < npunts; ++i) cout << " " << punts[i];
    cout << " ]" << endl;
}

