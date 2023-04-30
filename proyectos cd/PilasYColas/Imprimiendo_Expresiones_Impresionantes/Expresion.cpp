/* Nombre: Expresion.cpp
   Autor: Luis Juventino Velasquez H.
   Fecha: 28/Feb/2020
   Descripción: Archivo de implementación de la clase Expresion
*/

#include "Expresion.h"

 /*****************************************************************************************
 **********************************   Constructores    ************************************
 *****************************************************************************************/

//*************************************************************************************
Expresion::Expresion()
{
    exprFija.clear();
    exprPosFija.clear();
    exprValida=false;
}


//*************************************************************************************
Expresion::Expresion(const std::string & cad)
{
    exprPosFija.clear();
    exprFija=cad;
    Validar();
}

 /*****************************************************************************************
 ********************************   Metodos y funciónes   *********************************
 *****************************************************************************************/

//*************************************************************************************
void Expresion::Capturar()
{
    char expraux[500];

    scanf("%s",expraux);
    exprFija=expraux;

    Validar();
}


//*************************************************************************************
void Expresion::Imprimir(std::ostream & salida) const
{
    salida<<exprFija;
}


//*************************************************************************************
void Expresion::ImprimirPolacoInverso() const
{
    if(!EsValida()) throw SyntaxError();
    std::cout<<exprPosFija;
}


//*************************************************************************************
double Expresion::Evaluar() const
{
    if(!EsValida()) throw SyntaxError();

    Pila<double> numeros;
    std::string numAux;
    char aux;
    double n1,n2;

    numAux.clear();
    int siz = exprPosFija.size();
    for(int i=0;i<siz;++i)
    {
        aux = exprPosFija[i];
        if(simbOperador(aux))
        {


            n2=numeros.ConocerElemento();
            if(n2== 0 && aux == '/')
                throw std::logic_error("Se intento dividir enre 0...");

            numeros.Desapilar();
            n1=numeros.ConocerElemento();
            numeros.Desapilar();
            numeros.Apilar(RealizarOperacion(n1,n2,aux));
        }

        if(aux==',')
        {
            const char *numChar = numAux.c_str();
            n1 = std::atof(numChar);
            numeros.Apilar(n1);
            numAux.clear();
        }

        if(simbNumero(aux))
            numAux+=aux;
    }
    return numeros.ConocerElemento();
}


//*************************************************************************************
bool Expresion::EsValida() const
{
    return exprValida;
}

 /*****************************************************************************************
 ************************************   Excepciónes   *************************************
 *****************************************************************************************/

//*************************************************************************************
const char * Expresion::SyntaxError::what() const throw()
{
    return "Error en la sintaxis de la expresi\242n";
}

 /*****************************************************************************************
 *********************************   Metodos privados   ***********************************
 *****************************************************************************************/

//*************************************************************************************
void Expresion::Validar()
{
    std::cout<<exprFija<<'\n';
    exprValida=false;
    if(exprFija.size()== 0) return ;
    if(!CorchetesValanceados()) return; // si no están los corchetes balanceados, no podemos hacer nada más


    char aux;
    std::string eFijaSEsp;
    int siz=exprFija.size();
    eFijaSEsp.clear();
    for(int i=0;i<siz;++i)
    {
        aux=exprFija[i];
        if(aux!=' ')
            eFijaSEsp+=exprFija[i];
        if(!simbAgrAb(aux) && !simbAgrCer(aux) && aux!=' '  && !simbNumero(aux) && !simbOperador(aux))
            return;

    }


    siz=eFijaSEsp.size();
    bool puntoDec=false;
    /*la lógica de validar es inductiva, si tienes una cadena valida entonces solo tienes que validar
        que el siguiente caracter esté en orden con el anterior*/
    for(int i=0;i<siz;++i)
    {
        aux=eFijaSEsp[i];

        if(!simbNumero(aux) && puntoDec)
            puntoDec=false;

        if(simbAgrAb(aux))
        {
            if( i!=0 && ( i== siz-1 || simbNumero(eFijaSEsp[i-1]) || simbAgrCer(eFijaSEsp[i-1])) )
                return;
        }

        if(simbAgrCer(aux))
        {
            if( ( simbAgrAb(eFijaSEsp[i-1]) || simbOperador(eFijaSEsp[i-1])) )
                return;
        }

        if(simbOperador(aux))
        {
            if(simbMasMenos(aux))
            {
                if( siz == 1 || i==siz-1)
                    return;
            }
            else
            {
                if(i==0 ||  simbOperador(eFijaSEsp[i-1]) || simbAgrAb(eFijaSEsp[i-1]) || i==siz-1 )
                    return;
            }
        }

        if(simbNumero(aux) )
        {
            if( i != 0 && simbAgrCer(eFijaSEsp[i-1]))
                return;

            if(aux=='.')
            {
                if(siz == 1)
                    return;
                if(puntoDec)
                    return; //tiene 2 puntos décimales

                if( (i==0 || !simbNumero(eFijaSEsp[i-1]))  && (i== siz-1 ||  !simbNumero(eFijaSEsp[i+1])) )
                    return; //Es un punto solito, flotando en el espacio, sin nada que hacer
            }

        }

    }

    exprValida  =true;
    Polacolizar();
}


//*************************************************************************************
void Expresion::Polacolizar()
{
    exprPosFija.clear();
    std::string eFijaSEsp;
    int siz=exprFija.size();

    eFijaSEsp.clear();
    for(int i=0;i<siz;++i)
    {
        if(exprFija[i]!=' ')
            eFijaSEsp+=exprFija[i];
    }


    Pila<char>operaciones;
    siz=eFijaSEsp.size();
    std::string num;
    num.clear();
    char aux,opMonarioEnEspera='\0';
    for(int i=0;i<siz;++i)
    {
        std::cout<<operaciones<<'\n';
        aux=eFijaSEsp[i];

        if(!num.empty() && !(simbNumero(aux)))
        {
            exprPosFija+=num;
            exprPosFija+=','; //Los números tienen una coma al final
            num.clear();
            if(opMonarioEnEspera != '\0')
                exprPosFija+=opMonarioEnEspera;
            opMonarioEnEspera='\0';
        }

        if(simbAgrAb(aux))
            operaciones.Apilar(aux);

        if(simbAgrCer(aux))
        {
            while(!simbAgrAb( operaciones.ConocerElemento() ) )
            {
                exprPosFija+=operaciones.ConocerElemento();
                operaciones.Desapilar();
            }
            operaciones.Desapilar(); //se desapila el '('
            if(!operaciones.EstaVacia() && operaciones.ConocerElemento() == '!') //La siguiente operacion es binaria
            {
                operaciones.Desapilar();
                exprPosFija+=operaciones.ConocerElemento();
                operaciones.Desapilar();
            }
        }

        if(simbOperador(aux))
        {
            if(simbMasMenos(aux))
            {
                if(i==0 || simbAgrAb(eFijaSEsp[i-1]) || simbOperador(eFijaSEsp[i-1]) ) //Es monario
                {
                    if(opMonarioEnEspera != '\0')
                    {
                        if(opMonarioEnEspera == aux) // ley de los signos
                            opMonarioEnEspera='+';
                        else
                            opMonarioEnEspera='-';
                    }
                    else
                    {
                        exprPosFija+="0,";
                        opMonarioEnEspera=aux;
                    }

                    if(simbAgrAb(eFijaSEsp[i+1]))
                    {
                        operaciones.Apilar(opMonarioEnEspera);
                        operaciones.Apilar('!'); // '!' denota una operación unitaria;
                        opMonarioEnEspera='\0';
                    }
                }
                else //No es monario
                {
                    if(!operaciones.EstaVacia()  && operaciones.ConocerElemento() != '(' &&
                    Prioridad(operaciones.ConocerElemento()) >= Prioridad(aux) &&
                        !(aux=='^' && operaciones.ConocerElemento() == '^') )
                    {
                        exprPosFija+=operaciones.ConocerElemento();
                        operaciones.Desapilar();
                    }
                    operaciones.Apilar(aux);
                }
            }
            else
            {
                if(!operaciones.EstaVacia()  && operaciones.ConocerElemento() != '(' &&
                    Prioridad(operaciones.ConocerElemento()) >= Prioridad(aux) &&
                        !(aux=='^' && operaciones.ConocerElemento() == '^') )
                {
                    exprPosFija+=operaciones.ConocerElemento();
                    operaciones.Desapilar();
                }
                operaciones.Apilar(aux);
            }
        }

        if(simbNumero(aux))
        {
            num+=aux; //recordemos que la cadena está bien escrita
        }

    }

    if(!num.empty()) //Si estába leyendo un número, lo meto a la notación
    {
        exprPosFija+=num;
        exprPosFija+=','; //Los números tienen una coma al final
        num.clear();
        if(opMonarioEnEspera != '\0')
            exprPosFija+=opMonarioEnEspera;
        opMonarioEnEspera='\0';
    }


    while(!operaciones.EstaVacia())
    {
        exprPosFija+=operaciones.ConocerElemento();
        operaciones.Desapilar();
    }
}


//*************************************************************************************
bool Expresion::CorchetesValanceados() const
{
    Pila<char> memoria;
    int siz = exprFija.size();
    for(int i=0; i < siz ;++i)
    {
        if(simbAgrAb(exprFija[i] ))
            memoria.Apilar(exprFija[i] );

        if(simbAgrCer(exprFija[i]))
        {
            if(!memoria.EstaVacia() && mismoGrupo(memoria.ConocerElemento() , exprFija[i]) )
                memoria.Desapilar();
            else
                return false;
        }
    }
    return memoria.EstaVacia();
}


//*************************************************************************************
bool Expresion::simbAgrAb(char c) const
{
    if(c == '(') return true;
    if(c == '[') return true;
    if(c == '{') return true;

    return false;
}


//*************************************************************************************
bool Expresion::simbAgrCer(char c) const
{
    if(c == ')') return true;
    if(c == '}') return true;
    if(c == ']') return true;

    return false;
}


//*************************************************************************************
bool Expresion::simbMasMenos(char c) const
{
    if(c == '+' ) return true;
    if(c == '-' ) return true;

    return false;
}


//*************************************************************************************
int Expresion::Prioridad(char c) const
{
    if(c == '+' ) return 1;
    if(c == '-' ) return 1;
    if(c == '*' ) return 2;
    if(c == '/' ) return 2;
    if(c == '^' ) return 3;
    if(simbAgrAb(c) || simbAgrCer(c) ) return 4;

    return 0;
}


//*************************************************************************************
bool Expresion::simbOperador(char c) const
{
    if(c == '+' ) return true;
    if(c == '-' ) return true;
    if(c == '*' ) return true;
    if(c == '/' ) return true;
    if(c == '^' ) return true;

    return false;
}


//*************************************************************************************
bool Expresion::simbNumero(char c) const
{
    return (c == '.' || (c >= '0' && c<='9'));
}


//*************************************************************************************
bool Expresion::mismoGrupo(char abertura , char cerradura) const
{
    if(abertura == '(' && cerradura != ')')
        return false;
    if(abertura == '{' && cerradura != '}')
        return false;
    if(abertura == '[' && cerradura != ']')
        return false;

    return true;
}


//*************************************************************************************
double Expresion::RealizarOperacion(double n1, double n2, char op) const
{
    double res;
    switch(op)
    {
        case '+':
            res= n1+n2;
            break;

        case '-':
            res=n1-n2;
            break;

        case '*':
            res=n1*n2;
            break;

        case '/':
            res=n1/n2;
            break;

        case '^':
            res=pow(n1,n2);
            break;
    }
    return res;
}

 /*****************************************************************************************
 ***************************   Funciones externas y amigas   ******************************
 *****************************************************************************************/

//*************************************************************************************
std::ostream & operator<<(std::ostream & salida,const Expresion & e)
{
    e.Imprimir(salida);
    return salida;
}

//*************************************************************************************
std::istream & operator>>(std::istream & entrada, Expresion & e)
{
    e.Capturar();
    return entrada;
}
