bool es_operador ()
//Pre: true
//Post: retorna true en cas que el token sigui de tipus operador
{
	if (tipus == "operador") return true; 
	else return false;
}



bool equals ( const token &t)
//Pre: true
//Post: Indica si el token del p.i. és igual al token TK
{	
	if (tipus == t.tipus){
		if (tipus== "enter") return enter == t.enter;
		if (tipus== "boolea") return boolea == t.boolea;
		if (tipus== "variable") return variable == t.variable;
		if (tipus== "operador") return operador == t.operador;
	}else{
		return false;
	}
}



void crear_desde_string (const string &s)
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
	}else if (((s[0]>='A') and (s[0]<='Z')) or ((s[0]>='a') and (s[0]<='z'))){
		variable = s;
		tipus = "variable";
	}else{
			
		int num,suma=0;
		unsigned int mul=1;
		//esto va a convertirnos una string a numero y lo vamos a guardar en el entero del token
		for (int i=s.size()-1; i>=0; i--){ 
			if (i>=0){ 
				num = s[i]-'0';
				num=num*mul;
				suma=+num;
				mul=mul*10;
			}
		}
		enter = suma;
		tipus = "enter";		
	}
		
}
