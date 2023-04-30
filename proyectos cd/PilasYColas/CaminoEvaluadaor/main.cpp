

#include <iostream>
#include "Pila.h"

using namespace std;

bool EsOperador(char op);
double RealizarOperacion(double n1, double n2, char op);

int main()
{
    Pila<double> numeros;
    double n1,n2;
    char expresion[2349];
    cin>>expresion;
    for(int i=0; expresion[i] != '\0' ;i++)
    {
        if(expresion[i] >= '0' && expresion[i] <= '9')
            numeros.Apilar(expresion[i]-'0');
        if(EsOperador(expresion[i]))
        {
            n2=numeros.ConocerElemento();
            numeros.Desapilar();
            n1=numeros.ConocerElemento();
            numeros.Desapilar();
            numeros.Apilar(RealizarOperacion(n1,n2,expresion[i]));
        }
    }
    cout<<numeros.ConocerElemento();
    return 0;
}

bool EsOperador(char op)
{
    if(op == '+') return true;
    if(op == '-') return true;
    if(op == '*') return true;
    if(op == '/') return true;
    return false;
}

double RealizarOperacion(double n1, double n2, char op)
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
    }
    return res;
}
