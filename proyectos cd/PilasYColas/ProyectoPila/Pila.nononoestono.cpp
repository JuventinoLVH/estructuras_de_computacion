/* Nombre:.cpp
   Autor:
   Fecha:
   Descripción:
*/



::Pila()
{
    tope=-1;
}

T ConocerElemento()const
{
    if(EstaVacia() ) throw PilaVacia();
}

void Pila::AgregarElemento(T val)
{
    if( EstaLlena() )   throw PilaLlena();

    elemento[++tope]=val;
}

bool Pila::EstaLlena() const
{
    return (tope == TAMMAX-1);
}

bool Pila::EstaVacia() const
{
    return tope == -1;
}


void Pila::EliminarElemento()
{
    if(EstaVacia() ) throw PilaVacia();
}

void Pila::Imprimir() const
{
    std::cout<<"<";
    for(int i=0;i<=tope;++i)
        std::cout<<elemento[i]<<", ";
    std::cout<<"\b\b>";
}

const char * Pila::PilaLlena::what() const throw()
{
    return "Pila llena";
}

const char * Pila::PilaVacia::what() const throw()
{
    return "No hay nada";
}
