#include "expressio.hpp"
#include <sstream>
#include <string>

using namespace std;


void expressio::postfixa_recursiu (const arbreBin<token> &tree, string &s) const
/* Pre: tree = TREE */
/* Post: retorna una string amb els nodes de tree en postordre */
{
	if (not tree.es_buit()){

		if (not tree.fe().es_buit()){
			postfixa_recursiu (tree.fe(),s);
		}

		if (not tree.fd().es_buit()){
			postfixa_recursiu (tree.fd(),s);
		}

		s += tree.arrel().to_string();
        s += " ";
	}
}

void expressio::infixa_recursiu (const arbreBin<token> &tree, bool &parentesis, string &s) const
/* Pre: tree = TREE */
/* Post: retorna una string amb els nodes de tree en inordre */
{
	if (not tree.es_buit()){

        bool added = false;
        if (parentesis and (tree.arrel().es_operador_binari() or tree.arrel().es_operador_unari())){
            s+="( ";
            added = true;
        }

        parentesis = false;

        pair<int, bool> arrel = tree.arrel().prioritat();

		if (not tree.fe().es_buit()){

            pair<int, bool> fe = tree.fe().arrel().prioritat();

            if (fe.first < arrel.first or (arrel.first == fe.first and not tree.arrel().es_operador_commutatiu() and not arrel.second )) {
                parentesis = true;
            }  

			infixa_recursiu (tree.fe(), parentesis, s);
		}

		s += tree.arrel().to_string();
		s += " ";


		if (not tree.fd().es_buit()){
            pair<int, bool> fd = tree.fd().arrel().prioritat();
            if (fd.first < arrel.first or (arrel.first == fd.first and not tree.arrel().es_operador_commutatiu() and arrel.second )) {
                parentesis = true;
            }  
			infixa_recursiu (tree.fd(), parentesis, s);
		}

		if (added){
		    s+=") ";
		}
	}

}


void expressio::show() const
/*Pre: true */
/*Post: mostra per pantalla la nostra expressio */
{
	cout<<arbre;
}

expressio expressio::converteix (const arbreBin<token> &p) const
/* Pre: p=P */
/* Post: el resultat es un arbre identic al fill esquerre del p.i, perÃ² en comptes de ser de tokens Ã©s d'expressions */
{
    expressio tree = expressio(p.arrel()); //es un arbre buit
    if (not p.es_buit()){
        //list <Punt> llista;
        expressio tree1 = converteix(p.fe());
        // HI: el resultat es un arbre identic al fill esquerre de p, perÃ² en comptes de ser de tokens Ã©s d'expressions/
        // fita: mida de l'arbre p /
        expressio tree2 = converteix(p.fd());
        // HI: el resultat es un arbre identic al fill dret de p perÃ² en comptes de ser de tokens Ã©s d'expressions/
        // fita: mida de l'arbre p */
        token x = (p.arrel());
        tree = expressio (x,tree1,tree2);
    }
    return tree;
}


void expressio::get_operands (const arbreBin<token> &a, list <token> &llista) const
/* Pre: llista és una list buida  */
/* Post: retorna una llista dels nodes de l'arbre que siguin operands (fulles) */
{
	if (not a.es_buit()){
		stack <arbreBin<token>> m;
		m.push(a);
		if (not m.empty()){
			arbreBin <token> ar1 = m.top();
			m.pop();

			//caso base:
			if ( ar1.fe().es_buit() and ar1.fd().es_buit() ) llista.insert(llista.end(),ar1.arrel());

			//otros casos:
			else if ( not ar1.fe().es_buit() and not ar1.fd().es_buit() ){
				get_operands(ar1.fe(), llista);
				/* HI: retorna una llista dels nodes de l'ar1 branca esquerra que siguin operands (fulles) */
				/* fita: mida de ar1 */
				get_operands (arbreBin <token> (ar1.arrel(),arbreBin<token>(),arbreBin<token>()),llista);
				/* HI: retorna la llista amb l'arrel de ar1 */
				/* fita: mida de ar1 */
				get_operands(ar1.fd(), llista);
				/* HI: retorna una llista dels nodes de l'ar1 branca dreta que siguin operands (fulles) */
				/* fita: mida de ar1 */
			}else if ( not ar1.fe().es_buit() and ar1.fd().es_buit() ){
				get_operands(ar1.fe(), llista);
				/* HI: retorna una llista dels nodes de l'ar1 branca esquerra que siguin operands (fulles) */
				/* fita: mida de ar1 */
				get_operands (arbreBin <token> (ar1.arrel(),arbreBin<token>(),arbreBin<token>()),llista);
				/* HI: retorna la llista amb l'arrel de ar1 */
				/* fita: mida de ar1 */
			} else if ( ar1.fe().es_buit() and not ar1.fd().es_buit() ){
				get_operands (ar1.fd(), llista);
				/* HI: retorna una llista dels nodes de l'ar1 branca dreta que siguin operands (fulles) */
				/* fita: mida de ar1 */
			}
		}
	}
}


expressio::expressio(const token &t)
// Pre: t = TK és un token operand
// Post: Crea una expressió formada per operand TK
{
	arbre = arbreBin<token>(t, arbreBin<token>(), arbreBin<token>());
}

expressio::expressio(const token &t, const expressio &e)
// Pre: t = TK és un token operador unari, e = E
// Post: Crea una expressió formada per l'operador unari TK aplicat a l'expressió E
{
	//TODO: hay que hacer algo en check de expressio e ? (pregunta)
	arbre = arbreBin<token>(t, e.arbre, arbreBin<token>());
}

expressio::expressio(const token &t, const expressio &e1, const expressio &e2)
// Pre: t = TK és un token operador binari, e1 = E1, e2 = E2
// Post: Crea una expressió formada per l'operador binari TK aplicat a les expressions E1 i E2
{
	arbre = arbreBin<token>(t, e1.arbre, e2.arbre);
}

expressio::expressio(const expressio &e)
// Pre: e = E
// Post: Crea una expressió a partir de l'expressió E (constructor per còpia)
{
	arbre = e.arbre;
}

expressio& expressio::operator=(const expressio &e)
// Pre: e = E
// Post: Al p.i. se li ha assignat l'expressió E (operador assignació)
{
	arbre = e.arbre;
	return *this;
}

expressio::~expressio()
// Pre: True
// Post: S'ha destruït l'expressió del p.i. (destructora)
{
}

token expressio::arrel() const
// Pre: True
// Post: Retorna el token de l'arrel del p.i.
{
	return arbre.arrel();
}

expressio expressio::fe() const
// Pre: L'arrel del p.i. és un operador
// Post: Retorna l'expressió de l'esquerra del p.i.
{
	return converteix(arbre.fe());
}

expressio expressio::fd() const
// Pre: L'arrel del p.i. és un operador binari
// Post: Retorna l'expressió de la dreta del p.i.
{
	return converteix(arbre.fd());
}

bool expressio::es_operand() const
// Pre: True
// Post: Retorna si l'expressió del p.i. és un operand
//   (o sigui que l'arbre binari que conté l'expressió és una fulla)
//el primer constructor de expressio nos da una expresion que es un arbol sin hijos (o sea, un operand)
{
	return (arbre.fe().es_buit() and arbre.fd().es_buit());
}

list<token> expressio::operands() const
// Pre: True
// Post: Retorna una llista dels tokens operands de l'expressió del p.i., d'esquerra a dreta
{
	list<token>lista;
	get_operands(arbre,lista);
	return lista;
}


void expressio::llegir_infixa(istream& is)
// Pre: El canal is conté una expressió en notació infixa i sense errors.
// Post: El p.i. conté l'expressió llegida del canal is.
{
    //primero de todo vamos a declarar una string linea (que es la que nos van a meter) y dos stacks, una de expressio y la otra de token
	//~ string linea;
	//~ stack <expressio> operands;
	//~ stack <token> operadors;

	//~ while (getline(cin, linea)) {  //te meten la linea por el canal de entrada, trataremos a la linea como una string
		//~ istringstream ss(linea);
		//~ token x;
		//~ while (ss >> x){

		//~ //cuando el operadores.top() sea ')' vas a empezar a operar bajando por la stack hasta que el top de la stack sea '(', una vez ahí haces un ultimo pop() y sigues operando

		//~ //si nos encontramos con que acaban de cerrar una operación con peréntesis la calcularemos primero de todo, antes de seguir metiendo nada en las stacks
		//~ if (x == ')'){
			//~ while (operadors.top().es_operador()){
				//~ expressio dalt = operadors.top();
				//~ if (dalt.es_operador_binari()){ //si es u operador binario lo que haremos será coger los 2 elementos de la pila y crear un mini arbolito con ellos y el token
					//~ expressio primer = operands.top();
					//~ operands.pop();
					//~ expressio segon = operands.top();
					//~ operands.pop();
					//~ if (dalt.es_commutatiu()) operands.push(expressio(x,primer,segon)); //si es un operador conmutativo da igual el orden de los operandos
					//~ else operands.push(expressio(x,segon,primer)); //peeeero si no es un operador conmutativo no, y tal cual los leamos van a ir en orden
				//~ operadors.pop();
				//~ }
			//~ }
			//~ operadors.pop();
		//~ }

		//~ //si no hay parénteis actua con normalidad
		//~ else if (x.es_operador_binari() and operands.size()==2){
			//~ expressio primer = operands.top();
			//~ operands.pop();
			//~ expressio segon = operands.top();
			//~ operands.pop();
			//~ if (operadors.top().es_commutatiu()) operands.push(expressio(x,primer,segon)); //si es un operador conmutativo da igual el orden de los operandos
			//~ else operands.push(expressio(x,segon,primer)); //peeeero si no es un operador con
			//~ operadors.pop();
		//~ }else if (x.es_operador_unari()){ //cogeremos solo el primer elemento de la pila
				//~ operands.push(expressio(x,pila.top()));
				//~ operadors.pop();
		//~ }else{ // si no es un operador será un operando, entonces llo convertiremos a expressio y pa la stack

			//~ expressio convertit = expressio(x) //convertimos cada token de la linea a expressio y lo metmos en la stack
			//~ operands.push(convertit);
			//~ }
			//~ }
		//~ }
	//~ }
}

void expressio::llegir_postfixa(istream& is)
// Pre: El canal is conté una expressió en notació postfixa i sense errors.
// Post: El p.i. conté l'expressió llegida del canal is.
{

	stack <arbreBin<token>> pila;
	string linea;

    //cout << "EXPRESSIO: ";
	while (getline(is, linea)) {
		istringstream ss(linea);
		token x;
		while (ss >> x){      //mirar si se puede con los elementos de la stack
			if (x.es_operador_binari()){ //si es u operador binario lo que haremos será coger los 2 elementos de la pila y crear un mini arbolito con ellos y el token
				arbreBin<token> primer = pila.top();
				pila.pop();
				arbreBin<token> segon = pila.top();
				pila.pop();
				arbreBin <token> tree;
                tree = arbreBin <token> (x,segon,primer);
				pila.push(tree);
			}
			else if (x.es_operador_unari()){ //cogeremos solo el primer elemento de la pila
				arbreBin<token>tree = arbreBin <token> (x,pila.top(), arbreBin<token>());  //esto nos genera un arbol
				pila.pop();
				pila.push(tree);
			}

			else{ // si no es un operador será un operando, entonces llo convertiremos a expressio y pa la stack
			    pila.push(arbreBin<token>(x,arbreBin<token>(),arbreBin<token>()));
			}
		}
	}
	//aquí solo nos quedará una rbol en la stack
	arbre = pila.top();
}



string expressio::infixa() const
// Pre: True
// Post: Retorna un string que conté l'expressió del p.i. amb notació infixa
//   amb el mínim nombre de parèntesis, cada element separat amb un espai
{
    string s;
    bool parentesis = false;
    infixa_recursiu(arbre, parentesis, s);
    s.pop_back();
    return s;		//tenemos que recorrer el arbol en postordre, leyendo primero el hijo izquierd, luego la raíz y luego el hijo derecho
}

string expressio::postfixa() const
// Pre: True
// Post: Retorna un string que conté l'expressió del p.i. amb notació postfixa,
//   cada element separat amb un espai
{
	string s;
	postfixa_recursiu(arbre,s);
    s.pop_back();
	return s;	//tenemos que recorrer el arbol en postordre, leyendo primero los hijos y la raíz
}

static expressio avalua_operador_unari(token op, expressio e)
// Pre: op = OP és un operador unari, e = E
// Post: Retorna l'expressió resultat d'avaluar l'operador OP sobre l'expressió E
{
	if (op.to_string() == "not"){
		if (e.es_operand()) return expressio(token(not e.arrel().to_bool()));
	}
	return e; //si l'operador no es un not o e (expressio) no es un operand retornem l'expressio tal qual
}

static expressio avalua_operador_boolea(token op, expressio e1, expressio e2)
// Pre: op = OP és un operador binari booleà, e1 = E1, e2 = E2
// Post: Retorna l'expressió resultat d'avaluar l'operador OP sobre les expressions E1 i E2
{

}

static expressio avalua_operador_comparacio(token op, expressio e1, expressio e2)
// Pre: op = OP és un operador binari de comparació, e1 = E1, e2 = E2
// Post: Retorna l'expressió resultat d'avaluar l'operador OP sobre les expressions E1 i E2
{

}

static expressio avalua_operador_aritmetic(token op, expressio e1, expressio e2)
// Pre: op = OP és un operador binari aritmètic, e1 = E1, e2 = E2
// Post: Retorna l'expressió resultat d'avaluar l'operador OP sobre les expressions E1 i E2
{

}

expressio expressio::avalua() const
// Pre: True
// Post: Retorna l'expressió resultant d'avaluar l'expressió del p.i. tot el que es pugui
{

}

expressio expressio::expandeix(token t, const expressio &e) const
// Pre: t = TK és un token operand, e = E
// Post: Retorna l'expressió resultant de canviar tots els tokens TK de l'expressió del p.i. per l'expressió E
{

}
