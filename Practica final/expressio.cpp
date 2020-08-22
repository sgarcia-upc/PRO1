#include "expressio.hpp"
#include <sstream>
#include <string>

using namespace std;


expressio expressio::avalua_postordre (const arbreBin <token> &tree) const
/* Pre: cert */
/* Post: retorna una expressió on si els tokens de tree poden ser avaluats,
 *  s'avaluaran, resultant una expressió més petita */
{
    if (not tree.es_buit()){
        expressio izquierdo = avalua_postordre (tree.fe());
        /* HI: retorna una expressió on si els tokens del fill esquerre de tree
         *  poden ser avaluats, s'avaluaran, resultant una expressió més petita */
        /* Fita: mida de l'arbre */
        expressio derecho = avalua_postordre (tree.fd());
        /* HI: retorna una expressió on si els tokens del fill dret de tree
         *  poden ser avaluats, s'avaluaran, resultant una expressió més petita */
        /* Fita: mida de l'arbre */

        if (tree.arrel().es_operador_unari()){
            return expressio::avalua_operador_unari(tree.arrel(),izquierdo);
        }
        else if (tree.arrel().es_operador_binari()){   /*  == != + - * and or  ** / %  */
            if (tree.arrel() == "+" or tree.arrel() == "-" or tree.arrel() == "*" or tree.arrel() == "/" or tree.arrel() == "**" or tree.arrel() == "%"){
                return expressio::avalua_operador_aritmetic(tree.arrel(), izquierdo, derecho);
            } else if (tree.arrel() == "and" or tree.arrel() == "or"){
                return expressio::avalua_operador_boolea(tree.arrel(), izquierdo, derecho);
            } else if (tree.arrel() == "==" or tree.arrel() == "!="){
                return expressio::avalua_operador_comparacio(tree.arrel(), izquierdo, derecho);
            }
        }
        return expressio(tree.arrel());
    }

    expressio e = expressio(token());
    converteix(tree, e);
    return e;
}


void expressio::postfixa_recursiu (const arbreBin<token> &tree, string &s) const
/* Pre: cert */
/* Post: Retorna un string que conté l'expressió que conté tree amb notació postfixa, cada element separat amb un espai */
{
    if (not tree.es_buit()){
        postfixa_recursiu (tree.fe(), s);
        /* HI: Retorna un string que conté l'expressió que conté el fill esquerre de tree amb notació postfixa, cada element separat amb un espai*/
        /* Fita: mida de l'arbre */
        postfixa_recursiu (tree.fd(), s);
        /* HI: Retorna un string que conté l'expressió que conté el fill dret de tree amb notació postfixa, cada element separat amb un espai*/
        /* Fita: mida de l'arbre */
        s += tree.arrel().to_string() + " ";
    }
}


arbreBin<token> expressio::expandeix_recursiu (const arbreBin<token> &tree, const token &t, const expressio &e) const
/* Pre: t es un operand */
/* Post: retorna un arbreBin<token> igual a tree pero amb els token coincidents amb t remplaçats per e */
{
    arbreBin<token> resultat;

    if (not tree.es_buit()){
        arbreBin<token> expr1 = expandeix_recursiu(tree.fe(),t,e);
        /* HI: retorna un arbreBin<token> igual al fill esquerre de tree pero amb els token coincidents amb t remplaçats per e */
        /* Fita: mida de l'arbre */
        arbreBin<token> expr2 = expandeix_recursiu(tree.fd(),t,e);
        /* HI: retorna un arbreBin<token> igual al fill dret de tree pero amb els token coincidents amb t remplaçats per e */
        /* Fita: mida de l'arbre */

        if (tree.arrel() == t){
            resultat = e.arbre;
        }
        else{
            resultat = arbreBin<token>(tree.arrel(), expr1, expr2);
        }

    }

    return resultat;
}


void expressio::infixa_recursiu (const arbreBin<token> &tree, bool &parentesis, string &s) const
/* Pre: cert */
/* Post: construeix una string amb els nodes de tree en inordre */
{
    if (not tree.es_buit()){

        bool added = false;
        if (parentesis and (tree.arrel().es_operador_binari() or tree.arrel().es_operador_unari())){
            s+="( ";
            added = true;
        }

        parentesis = false;

        pair<int, bool> arrel = tree.arrel().prioritat();

        if (tree.arrel().es_operador_unari()){

            s += tree.arrel().to_string();
            s += " ";

            if (not tree.fe().es_buit()){

                pair<int, bool> fe = tree.fe().arrel().prioritat();

                if (fe.first < arrel.first or (arrel.first == fe.first and (not tree.arrel().es_operador_commutatiu() and not arrel.second))) {
                    parentesis = true;
                }

                infixa_recursiu (tree.fe(), parentesis, s);
                /* HI: construeix una string amb els nodes del fill esquerre de tree en inordre */
                /* Fita: mida de l'arbre*/
            }

        } else {
            if (not tree.fe().es_buit()){

                pair<int, bool> fe = tree.fe().arrel().prioritat();

                if (fe.first < arrel.first or (arrel.first == fe.first and (not tree.arrel().es_operador_commutatiu() and not arrel.second ))) {
                    parentesis = true;
                }

                infixa_recursiu (tree.fe(), parentesis, s);
                /* HI: construeix una string amb els nodes del fill esquerre de tree en inordre */
                /* Fita: mida de l'arbre*/
            }

            s += tree.arrel().to_string();
            s += " ";


            if (not tree.fd().es_buit()){
                pair<int, bool> fd = tree.fd().arrel().prioritat();
                if (fd.first < arrel.first or (arrel.first == fd.first and (not tree.arrel().es_operador_commutatiu() and arrel.second))) {
                    parentesis = true;
                }
                infixa_recursiu (tree.fd(), parentesis, s);
                /* HI: construeix una string amb els nodes del fill dret de tree en inordre */
                /* Fita: mida de l'arbre*/
            }
        }

        if (added){
            s+=") ";
        }
    }

}


void expressio::converteix (const arbreBin<token> &p, expressio &e) const
/* Pre: p=P, p no es buit */
/* Post: transforma l'arbreBin<token> p en la expressió e */
{
    if (not p.es_buit()){

        converteix(p.fe(), e);
        expressio tree1 = e;
        // HI: transforma el fill esquerre de p en la expressió e /
        // fita: mida de l'arbre p /

        converteix(p.fd(), e);
        expressio tree2 = e;
        // HI: transforma el fill dret de p en la expressió e/
        // fita: mida de l'arbre p */


        token x = (p.arrel());
        e = expressio (x,tree1,tree2);
    }
}


void expressio::get_operands (const arbreBin<token> &a, list <token> &llista) const
/* Pre: llista és una list buida  */
/* Post: construeix una llista dels nodes de l'arbre que siguin operands (fulles) */
{
    if (not a.es_buit()){
        arbreBin <token> ar1 = a;
        //caso base:
        if ( ar1.fe().es_buit() and ar1.fd().es_buit()) {
            if (ar1.arrel().es_enter() or ar1.arrel().es_boolea() or ar1.arrel().es_variable()) llista.insert(llista.end(),ar1.arrel());

        //otros casos:
        }else if ( not ar1.fe().es_buit() and not ar1.fd().es_buit() ){
            get_operands(ar1.fe(), llista);
            /* HI: retorna una llista dels nodes de l'ar1 branca esquerra que siguin operands (fulles) */
            /* fita: mida de ar1 */
            get_operands (arbreBin <token> (ar1.arrel(),arbreBin<token>(),arbreBin<token>()),llista);
            /* HI: retorna la llista amb l'arrel de ar1 */
            /* fita: mida de ar1 */
            get_operands(ar1.fd(), llista);
            /* HI: retorna una llista dels nodes de l'ar1 branca dreta que siguin operands (fulles) */
            /* fita: mida de ar1 */
        } else if ( not ar1.fe().es_buit() and ar1.fd().es_buit() ){
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
    expressio e = expressio(arbre.arrel());
    converteix(arbre.fe(), e);
    return e;
}

expressio expressio::fd() const
// Pre: L'arrel del p.i. és un operador binari
// Post: Retorna l'expressió de la dreta del p.i.
{
    expressio e = expressio(arbre.arrel());
    converteix(arbre.fd(), e);
    return e;
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
    stack <token> operadors;
    stack <arbreBin<token>> operands;
    string s;
    while (is>>s and s != "->"){
        token t = token(s);
        if (t.to_string()=="("){
            operadors.push(t);
        }else if (t.to_string() == ")"){
            while (operadors.top().to_string() != "("){
                if (operadors.top().es_operador_binari()){
                    arbreBin<token> dreta = operands.top();
                    operands.pop();
                    arbreBin<token>esquerra = operands.top();
                    operands.pop();
                    arbreBin<token> tree = arbreBin<token>(operadors.top(),esquerra,dreta);
                    operands.push(tree);
                }
                else{
                    arbreBin<token>esquerra = operands.top();
                    operands.pop();
                    arbreBin<token> tree = arbreBin<token>(operadors.top(),esquerra,arbreBin<token>());
                    operands.push(tree);
                }
                operadors.pop();
            }
            operadors.pop(); // Eliminem el parentesis ( de la pila
        }
        else if (t.es_enter() or t.es_boolea() or t.es_variable()){
            operands.push(arbreBin<token>(t, arbreBin<token>(), arbreBin<token>()));
        }
        else if (t.es_operador_binari() or t.es_operador_unari()){
            if (not operadors.empty()){
                while (not operadors.empty() and (operadors.top().to_string() != "(" and (t.prioritat().first<operadors.top().prioritat().first or (t.prioritat().first == operadors.top().prioritat().first and t.prioritat().second == true)))){
                    if (operadors.top().es_operador_binari()){
                        arbreBin<token> dreta = operands.top();
                        operands.pop();
                        arbreBin<token>esquerra = operands.top();
                        operands.pop();
                        arbreBin<token> tree = arbreBin<token>(operadors.top(),esquerra,dreta);
                        operands.push(tree);
                    }
                    else{
                        arbreBin<token>esquerra = operands.top();
                        operands.pop();
                        arbreBin<token> tree = arbreBin<token>(operadors.top(),esquerra,arbreBin<token>());
                        operands.push(tree);
                    }
                    operadors.pop();
                }
            }
            operadors.push(t);
        }
    }
    while (not operadors.empty()){
        if (operadors.top().es_operador_binari()){
            arbreBin<token> dreta = operands.top();
            operands.pop();
            arbreBin<token> esquerra = operands.top();
            operands.pop();
            arbreBin<token> tree = arbreBin<token>(operadors.top(),esquerra,dreta);
            operadors.pop();
            operands.push(tree);
        }
        else{
            arbreBin<token> esquerra = operands.top();
            operands.pop();
            arbreBin<token> tree = arbreBin<token>(operadors.top(),esquerra,arbreBin<token>());
            operadors.pop();
            operands.push(tree);
        }
    }
    arbre = operands.top();
}

void expressio::llegir_postfixa(istream& is)
// Pre: El canal is conté una expressió en notació postfixa i sense errors.
// Post: El p.i. conté l'expressió llegida del canal is.
{

    stack <arbreBin<token>> pila;
    string linea;
    string s;
    while (is>>s and s != "->"){
        token x = token(s);
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
            arbreBin<token> tree = arbreBin <token> (x,pila.top(), arbreBin<token>());  //esto nos genera un arbol
            pila.pop();
            pila.push(tree);
        }
        else{ // si no es un operador será un operando, entonces llo convertiremos a expressio y pa la stack
            pila.push(arbreBin<token>(x,arbreBin<token>(),arbreBin<token>()));
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
    return s;        //tenemos que recorrer el arbol en postordre, leyendo primero el hijo izquierd, luego la raíz y luego el hijo derecho
}

string expressio::postfixa() const
// Pre: True
// Post: Retorna un string que conté l'expressió del p.i. amb notació postfixa,
//   cada element separat amb un espai
{
    string s;
    postfixa_recursiu(arbre,s);
    return s;    //tenemos que recorrer el arbol en postordre, leyendo primero los hijos y la raíz
}

expressio expressio::avalua_operador_unari(token op, expressio e)
// Pre: op = OP és un operador unari, e = E
// Post: Retorna l'expressió resultat d'avaluar l'operador OP sobre l'expressió E
{
    if (op.to_string() == "not"){
        if (e.arrel().es_boolea()) return expressio(token(not e.arrel().to_bool()));
    }
    return expressio(op,e);
}

expressio expressio::avalua_operador_boolea(token op, expressio e1, expressio e2)
// Pre: op = OP és un operador binari booleà, e1 = E1, e2 = E2
// Post: Retorna l'expressió resultat d'avaluar l'operador OP sobre les expressions E1 i E2
{
    if (op.to_string() == "and"){
        if (e1.arrel().es_boolea() and e2.arrel().es_boolea()){
            return expressio(token(e1.arrel().to_bool() and e2.arrel().to_bool()));
        }
        if (e1.arrel().es_boolea()){
            if (not(e1.arrel().to_bool())){
                return expressio(token(false));
            }else{
                return e2;
            }
        }
        if (e2.arrel().es_boolea()){
            if (not(e2.arrel().to_bool())){
                return expressio(token(false));
            }else{
                return e1;
            }
        }

    } else if (op.to_string() == "or"){
        if (e1.arrel().es_boolea() and e2.arrel().es_boolea()){
            return expressio(token(e1.arrel().to_bool() or e2.arrel().to_bool()));
        }
        if (e1.arrel().es_boolea()){
            if (e1.arrel().to_bool()){
                return expressio(token(true));
            }else{
                return e2;
            }
        }
        if (e2.arrel().es_boolea()){
            if (e2.arrel().to_bool()){
                return expressio(token(true));
            }else{
                return e1;
            }
        }
    }

    return expressio(op,e1,e2);
}

expressio expressio::avalua_operador_comparacio(token op, expressio e1, expressio e2)
// Pre: op = OP és un operador binari de comparació, e1 = E1, e2 = E2
// Post: Retorna l'expressió resultat d'avaluar l'operador OP sobre les expressions E1 i E2
{

    if (op.to_string() == "=="){
        if (e1.arrel().es_enter() and e2.arrel().es_enter()){
            return expressio(token(e1.arrel().to_int()==e2.arrel().to_int()));
        }
        else if (e1.arrel().es_boolea() and e2.arrel().es_boolea()){
            return expressio(token(e1.arrel().to_bool()==e2.arrel().to_bool()));
        }
        else if (e1.arrel().es_variable() and e2.arrel().es_variable()){
            if (e1.arrel().to_string() == e2.arrel().to_string()){
                return expressio(token(true));
            }
        }

    } else if (op.to_string() == "!="){
        if (e1.arrel().es_enter() and e2.arrel().es_enter()){
            return expressio(token(e1.arrel().to_int()!=e2.arrel().to_int()));
        }
        else if (e1.arrel().es_boolea() and e2.arrel().es_boolea()){
            return expressio(token(e1.arrel().to_bool()!=e2.arrel().to_bool()));
        }
        else if (e1.arrel().es_variable() and e2.arrel().es_variable()){
            if (e1.arrel().to_string() == e2.arrel().to_string()){
                return expressio(token(false));
            }
        }
    }

    return expressio(op,e1,e2);
}

int expressio::power(const int x, const int y)
// Pre: cert
// Post: resultat x elevat a y
{
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return power(x, y / 2) * power(x, y / 2);
        //H.I: resultat x elevat a y/2 multiplicat per el resultat de x elevat y/2
        //fita: mida de y
    else
        return x * power(x, y / 2) * power(x, y / 2);
        //H.I: resultat x elevat a y/2 multiplicat per el resultat de x elevat y/2 multiplicat per x
        //fita: mida de y
}

expressio expressio::avalua_operador_aritmetic(token op, expressio e1, expressio e2)
// Pre: op = OP és un operador binari aritmètic, e1 = E1, e2 = E2
// Post: Retorna l'expressió resultat d'avaluar l'operador OP sobre les expressions E1 i E2
{
    if (e1.arrel().es_enter() and e2.arrel().es_enter()){
        if (op.to_string()=="+") return expressio(token(e1.arrel().to_int() + e2.arrel().to_int()));
        if (op.to_string()=="-") return expressio(token(e1.arrel().to_int() - e2.arrel().to_int()));
        if (op.to_string()=="*") return expressio(token(e1.arrel().to_int() * e2.arrel().to_int()));
        if (op.to_string()=="/") return expressio(token(e1.arrel().to_int() / e2.arrel().to_int()));
        if (op.to_string()=="**") return expressio(token(power(e1.arrel().to_int(),e2.arrel().to_int())));
        if (op.to_string()=="%") return expressio(token(e1.arrel().to_int() % e2.arrel().to_int()));
    }
    if (op.to_string()=="*"){
        if (e1.arrel().es_enter()){
            if (e1.arrel().to_int()==0){
                return expressio(token(0));
            }
            if (e1.arrel().to_int()==1) return e2;
        } else if (e2.arrel().es_enter()){
            if (e2.arrel().to_int()==0){
                return expressio(token(0));
            }
            if (e2.arrel().to_int()==1) return e1;
        }
    } else if (op.to_string()=="+"){
        if (e1.arrel().es_enter()){
            if (e1.arrel().to_int()==0){
                return e2;
            }
        } else if (e2.arrel().es_enter()){
            if (e2.arrel().to_int()==0){
                return e1;
            }
        }
    } else if (op.to_string()=="-"){
        if (e2.arrel().es_enter()){
            if (e2.arrel().to_int()==0){
                return e1;
            }
        }
    } else if (op.to_string()=="/"){
        if (e1.arrel().es_enter()){
            if (e1.arrel().to_int()==0){
                return e1; //PERQUE JA ÉS ZERO
            }
        } else if (e2.arrel().es_enter()){
            if (e2.arrel().to_int()==1){
                return e1;
            }
        }
    } else if (op.to_string()=="%"){
        if (e1.arrel().es_enter()){
            if (e1.arrel().to_int()==0){
                return e1; //PERQUE JA ÉS ZERO
            }
        } else if (e2.arrel().es_enter()){
            if (e2.arrel().to_int()==1){
                return expressio(token(0));
            }
        }

    } else if (op.to_string()=="**"){
        if (e1.arrel().es_enter()){
            if (e1.arrel().to_int()==0){
                return e1; //PERQUE JA ÉS ZERO
            } else if (e1.arrel().to_int()==1){
                return e1;//PERQUE JA ÉS 1
            } else if (e2.arrel().es_enter()){
                if (e2.arrel().to_int()==0){
                    return expressio(token(1));
                } else if (e2.arrel().to_int()==1){
                    return e1;
                }
            }
        }
    }
    return expressio(op,e1,e2);
}


expressio expressio::avalua() const
// Pre: True
// Post: Retorna l'expressió resultant d'avaluar l'expressió del p.i. tot el que es pugui
{
    //cout << arbre << endl;
    expressio e = avalua_postordre(arbre);
    //cout << e.arbre << endl;;
    return e;
}


expressio expressio::expandeix(token t, const expressio &e) const
// Pre: t = TK és un token operand, e = E
// Post: Retorna l'expressió resultant de canviar tots els tokens TK de l'expressió del p.i. per l'expressió E
{
    // magia negra
    // creamos un arbol con el contenido que queremos
    arbreBin<token> ar = expandeix_recursiu(arbre, t, e);
    expressio k = expressio(token("tamal"));
    // y aqui viene la magia...
    // igualamos la expression con un "tamal" al arbol perfecto
    k.arbre = ar;
    // asi es como la restriccion de no tener una expression vacia nos la saltamos y creamos una expression justo como queremos, con magia
    return k;
}

