#include "calculadora.hpp"
#include <list> 

calculadora::calculadora()
// Pre: true
// Post: Crea una calculadora amb totes les memòries buides
{
    mem.push_back(expressio(token("a")));
    mem.push_back(expressio(token("b")));
    mem.push_back(expressio(token("c")));
    mem.push_back(expressio(token("d")));
    mem.push_back(expressio(token("e")));
    mem.push_back(expressio(token("f")));
    mem.push_back(expressio(token("g")));
    mem.push_back(expressio(token("h")));
    mem.push_back(expressio(token("i")));
    mem.push_back(expressio(token("j")));
    mem.push_back(expressio(token("k")));
    mem.push_back(expressio(token("l")));
    mem.push_back(expressio(token("m")));
    mem.push_back(expressio(token("n")));
    mem.push_back(expressio(token("o")));
    mem.push_back(expressio(token("p")));
    mem.push_back(expressio(token("q")));
    mem.push_back(expressio(token("r")));
    mem.push_back(expressio(token("s")));
    mem.push_back(expressio(token("t")));
    mem.push_back(expressio(token("u")));
    mem.push_back(expressio(token("v")));
    mem.push_back(expressio(token("w")));
    mem.push_back(expressio(token("x")));
    mem.push_back(expressio(token("y")));
    mem.push_back(expressio(token("z")));
}


calculadora::calculadora(const calculadora &c)
// Pre: c = C
// Post: Crea una calculadora a partir de la calculadora C (constructor per còpia)
{
    mem = c.mem;
}


calculadora& calculadora::operator=(const calculadora &c)
// Pre: c = C
// Post: Al p.i. se li ha assignat la calculadora C (operador assignació)
{
    mem = c.mem;
    return *this;
}


calculadora::~calculadora()
// Pre: True
// Post: S'ha destruït la calculadora del p.i. (destructora)
{
}


int calculadora::transformar (const char &v)const
// Pre: True
// Post: transforma el char v en un enter
{
   return v-97;
}


bool calculadora::es_buida(char v) const
// Pre: v = V és un caràcter entre 'a' i 'z'
// Post: Indica si la memòria V conté una expressió formada per
//       una única variable el nom de la qual és V
{
    string s = string(1, v);
    return (mem[transformar(v)].arrel() == expressio(token(s)).arrel());
}


void calculadora::guarda(char v, const expressio &e)
// Pre: v = V és un caràcter entre 'a' i 'z', e = E
// Post: Guarda a la memòria V l'expressió E
{
    mem[transformar(v)] = e;
}


void calculadora::elimina(char v)
// Pre: v = V és un caràcter entre 'a' i 'z'
// Post: Elimina l'expressió de la memòria V
{
    string s = string(1, v);
    //cout << "ELIMINA" << v;
    mem[transformar(v)] = expressio(token(s));
}


expressio calculadora::mostra(char v) const
// Pre: v = V és un caràcter entre 'a' i 'z'
// Post: Retorna l'expressió de la memòria V sense avaluar-la
{
    return mem[transformar(v)];
}


vector<token> calculadora::memoria_utilitzada(const list<token> llista_operands) const
{

    list<token>::const_iterator it = llista_operands.begin();
    vector<token> mem_utilitzada;
    while (it != llista_operands.end()){
        if ((*it).es_variable() and ((*it).to_string().size() == 1 and ((*it).to_string()[0] >= 'a' and ((*it).to_string()[0] <= 'z')))){
            mem_utilitzada.push_back(*it);
        }
        ++it;
    }

    return mem_utilitzada;
}


expressio calculadora::expandeix(const expressio &e) const
// Pre: e = E
// Post: Retorna una expressió fruit d'expandir i avaluar l'expressió E
//       usant les memòries del p.i. tot el que es pugui
//       Si es detecta una circularitat retorna una expressió
//       amb sola variable de nom "ERROR_expressions_circulars"
{
    expressio resultat = e;
    list<token> operands = resultat.operands();
    vector<token> checked;
    while(not operands.empty()){

        list<token>::iterator it = operands.begin();

        // si es una variable
        if ((*it).es_variable() and (*it).to_string().size() == 1 and (*it).to_string()[0] >= 'a' and (*it).to_string()[0] <= 'z'){
            if(not es_buida((*it).to_string()[0])){
                // si la memoria no es buida
                for (int i = 0; i < int(checked.size()); i++){
                    if (checked[i] == (*it)){
                        // si ja esta esta comprobat es que tenim circularitat
                        return expressio(token("ERROR_expressions_circulars"));
                    }
                }
                checked.push_back((*it));

                resultat = resultat.expandeix((*it), mem[transformar((*it).to_string()[0])]);
                operands = resultat.operands();

            } else {
                // si esta buit s'esborra
                operands.erase(it);
            }
        }
        else{
            // si no es variable s'esborra
            operands.erase(it);
        }

    }
    return resultat;
}


expressio calculadora::expandeix(char v) const
// Pre: v = V és un caràcter entre 'a' i 'z'
// Post: Retorna l'expressió de la memòria V expandint-la
//       usant les memòries del p.i. tot el que es pugui
//       Si es detecta una circularitat retorna una expressió
//       amb sola variable de nom "ERROR_expressions_circulars"
{
    return expandeix(mem[transformar(v)]);
}


expressio calculadora::avalua(char v) const
// Pre: v = V és un caràcter entre 'a' i 'z'
// Post: Retorna l'expressió de la memòria V expandint-la i avaluant-la
//       usant les memòries del p.i. tot el que es pugui
//       Si es detecta una circularitat retorna una expressió
//       amb sola variable de nom "ERROR_expressions_circulars"
{
    return avalua(mem[transformar(v)]);
}


expressio calculadora::avalua(const expressio &e) const
// Pre: e = E
// Post: Retorna una expressió fruit d'expandir i avaluar l'expressió E
//       usant les memòries del p.i. tot el que es pugui
//       Si es detecta una circularitat retorna una expressió
//       amb sola variable de nom "ERROR_expressions_circulars"
{
    expressio g = expandeix(e);
    return g.avalua();
}

