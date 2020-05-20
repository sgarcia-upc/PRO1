#include "token.hpp"
#include <sstream>
#include <string>

using namespace std;

bool token::es_operador () const
//Pre: true
//Post: retorna true en cas que el token sigui de tipus operador
{
    if (tipus == "operador") return true;
    else return false;
}


bool token::equals ( const token &t) const
//Pre: true
//Post: Indica si el token del p.i. és igual al token TK
{
    if (tipus == t.tipus){
        if (tipus== "enter") return enter == t.enter;
        if (tipus== "boolea") return boolea == t.boolea;
        if (tipus== "variable") return variable == t.variable;
        else return operador == t.operador;
    }else{
        return false;
    }
}


void token::crear_desde_string (const string &s)
// Pre: s = S
// Post: Crea un token a partir del string S (descriu un operador o un operand)
{
    if (s=="not" or s=="and" or s=="or" or s=="==" or s=="!=" or s=="+" or s=="-" or s=="*" or s=="/" or s=="%" or s=="**"){
        operador = s;
        tipus = "operador";
    }else if (s=="F"){
        boolea = false; //esto tiene que ir siempre antes de que comprovemos si es una variable, ergo "T" y "F" no pueden ser nunca variables
        tipus = "boolea";
    }else if (s=="T"){
        boolea = true;
        tipus = "boolea";
    }else if (((s[0]>='A') and (s[0]<='Z')) or ((s[0]>='a') and (s[0]<='z')) or s[0] == ')' or s[0] == '(' ){
        variable = s;
        tipus = "variable";
    }else{

        int num,suma=0;
        unsigned int mul=1;
        //esto va a convertirnos una string a numero y lo vamos a guardar en el entero del token
        int end = 0;
        if (s[0]=='-') end = 1;
        for (int i=s.size()-1; i>=end; i--){
            if (i>=0){
                num = s[i]-'0';
                num=num*mul;
                suma=suma+num;
                mul=mul*10;
            }
        }
        if (end == 1) suma = suma * -1;
        enter = suma;
        tipus = "enter";
    }
}


token::token()
// Pre: true
// Post: Crea un token enter de valor 0
{
    enter = 0;
    tipus = "enter";
}


token::token(int i)
// Pre: i = I
// Post: Crea un token a partir de l'enter I
{
    enter = i;
    tipus = "enter";
}


token::token(bool b)
// Pre: b = B
// Post: Crea un token a partir del booleà B
{
    boolea = b;
    tipus = "boolea";
}


token::token(string s)
// Pre: s = S
// Post: Crea un token a partir del string S (descriu un operador o un operand)
{
    crear_desde_string(s);
}


token::token(const char s[])
// Pre: s = S
// Post: Crea un token a partir del vector de caràcters S (descriu un operador o un operand)
{
    crear_desde_string((string)s);
}


token::token(const token &t)
// Pre: t = TK
// Post: Crea un token a partir del token TK (constructor per còpia)
{
    if (t.es_enter()) enter=t.enter;
    if (t.es_operador()) operador=t.operador;
    if (t.es_boolea()) boolea=t.boolea;
    if (t.es_variable()) variable=t.variable;
    tipus = t.tipus;
}


token& token::operator=(const token &e)    //pues no sé cómo coños poner esto pa que no me de error
// Pre: t = TK
// Post: Al p.i. se li ha assignat el token TK (operador assignació)
{
    tipus = e.tipus;
    enter = e.enter;
    operador = e.operador;
    boolea = e.boolea;
    variable = e.variable;
    return (*this);
}


token::~token()
// Pre: True
// Post: S'ha destruït el token del p.i. (destructora)
{
}


bool token::es_operador_unari() const
// Pre: true
// Post: Indica si el p.i. és un operador unari
{
    //el operador unari es solamente el not
    if (es_operador() and operador=="not") return true;
    else return false;
}


bool token::es_operador_binari() const
// Pre: true
// Post: Indica si el p.i. és un operador binari
{
    //los operadores binarios son todos menos el not
    if (es_operador() and operador != "not") return true;
    else return false;
}


bool token::es_operador_commutatiu() const
// Pre: true
// Post: Indica si el p.i. és un operador commutatiu
{
    if (operador == "+" or operador == "*" or operador == "and" or operador == "or" or operador == "==" or operador == "!=") return true;
    else return false;
}


bool token::es_boolea() const
// Pre: true
// Post: Indica si el p.i. és una constant booleana
{
    if (tipus == "boolea") return true;
    else return false;
}


bool token::es_enter() const
// Pre: true
// Post: Indica si el p.i. és una constant entera
{
    if (tipus == "enter") return true;
    else return false;
}


bool token::es_variable() const
// Pre: true
// Post: Indica si el p.i. és una variable
{
    if (tipus=="variable") return true;
    else return false;
}


pair<int, bool> token::prioritat() const
// Pre: true
// Post: Indica el nivell de prioritat a 'first' i si l'associativitat és d'esquerra a dreta a 'second' del p.i.
// Considerem que els operands tenen el màxim nivell de prioritat
// D'esquerra a dreta: true
{
    pair <int, bool> par;
    if (operador == "or"){
        par.first=1;
        par.second=true;
    }
    else if (operador == "and"){
        par.first=2;
        par.second=true;
    }
    else if (operador == "not"){
        par.first=3;
        par.second=false;
    }
    else if (operador == "==" or operador=="!="){
        par.first=4;
        par.second=true;
    }
    else if (operador == "+" or operador=="-"){
        par.first=5;
        par.second=true;
    }
    else if (operador == "*" or operador == "/" or operador == "%"){
        par.first=6;
        par.second=true;
    }
    else if (operador == "**"){
        par.first=7;
        par.second=false;
    }
    else{ //operando son todos los numeros o variables participantes en una expresión matemática
        par.first=8;
        par.second = true;
    }
    return par;
}


int token::to_int() const
// Pre: El p.i. és un token número enter
// Post: Retorna el valor enter del p.i.
{
    return enter;
}


bool token::to_bool() const
// Pre:  El p.i. és un token booleà
// Post: Retorna el valor booleà true o false del p.i.
{
    return boolea;
}


string token::to_string() const
// Pre: true
// Post: Retorna el valor del p.i. convertit en string
{
    if (es_enter()) return std::to_string(enter);
    else if (es_operador()) return operador;
    else if (es_boolea()){
        if (boolea) return "T";
        else return "F";
    }
    else return variable;
}


bool token::operator==(const token &t) const
// Pre: t = TK
// Post: Indica si el token del p.i. és igual al token TK
{
    return equals(t);
}


bool token::operator!=(const token &t) const
// Pre: t = TK
// Post: Indica si el token del p.i. és diferent al token TK
{
    return not equals(t);
}


istream& operator>>(istream& is, token &t)
// Pre: El canal is conté un string amb un contingut d'un token TK
// Post: t = TK
{
    string s;
    is >> s;
    t.crear_desde_string(s);
    return is;
}


ostream& operator<<(ostream& os, const token &t)
// Pre: t = TK
// Post: S'ha escrit al canal os el contingut del token TK
{
    if (t.es_enter()) os << t.enter;
    if (t.es_operador()) os << t.operador;
    if (t.es_boolea()){
        if (t.boolea) os << "T";
        else os << "F";
    }
    if (t.es_variable()) os << t.variable;
    return os;
}

