/* Nombre:.cpp
   Autor:
   Fecha:
   Descripción:
*/


#include"Vector.h"
/*******************************************************************************************
********************************************************************************************
**********************     Constructores y destructores      *******************************
********************************************************************************************
*******************************************************************************************/
Vector::Vector()
{
    EstablecerDimension(1);
    componente[0]=0;
}
//*************************************************************************************
Vector::Vector(const Vector &v)
{
    EstablecerDimension(v.dim);
    for(int i=0;i<dim;i++) componente[i]=v.componente[i];
}
//*************************************************************************************
Vector::Vector(int dim)
{
    EstablecerDimension(dim);
    for(int i=0;i<dim;i++) componente[i]=0;
}
//*************************************************************************************
Vector::Vector(int dim, double valorIn)
{
    EstablecerDimension(dim);
    for(int i=0;i<dim;i++) componente[i]=valorIn;
}
//*************************************************************************************
Vector::~Vector()
{
    delete componente;  //<<<<--------------------------------------------------------------------------
    //Ahora tenemos que cambiar el operador '=' porque los dos apuntadores terminarian apuntando al mismo arreglo
}


/*******************************************************************************************
********************************************************************************************
**************************************     Set     *****************************************
********************************************************************************************
*******************************************************************************************/
void Vector::EstablecerComponente(int i,double comp)
{
    if(i < 0 || i >= dim) throw std::out_of_range("\249ndice fuera de rango");

    componente[i]=comp;
}
//*************************************************************************************
void Vector::EstablecerDimension(int dim)
{
    if(dim < 0) throw std::logic_error("Dimensi\242n fuera de rango");

    componente = new double [dim]; //<<<<------------------------------------------------Esta funcion regresa un error----
    this->dim=dim;
}


/*******************************************************************************************
********************************************************************************************
**************************************     Get     *****************************************
********************************************************************************************
*******************************************************************************************/
int Vector::ObtenerDimencion() const
{
    return dim;
}
//*************************************************************************************
double Vector::ObtenerComponente(int i) const
{
    if(i < 0 || i >= dim) throw std::out_of_range("\249ndice fuera de rango");

    return componente[i];
}



/*******************************************************************************************
********************************************************************************************
********************************     Miselanian     ****************************************
********************************************************************************************
*******************************************************************************************/
void Vector::Imprimir() const
{
    std::cout<<"(";
    for(int i=0;i<dim;i++) std::cout<<componente[i]<<", ";

    std::cout<<"\b\b)";
}
//*************************************************************************************
void Vector::Captura()
{
    for(int i=0;i<dim;i++)
    {
        std::cout<<"Componente# "<<i+1;
        std::cin>>componente[i];
    }
}
//*************************************************************************************
Vector Vector::Sumar(const Vector &v) const
{
    if(dim != v.dim) throw std::logic_error("Dimensiones incompatibles");

    Vector res(dim);

    for(int i=0;i<dim;i++)
        res.componente[i]=(componente[i])+(v.componente[i]);
    return res;
}
//*************************************************************************************
Vector Vector::Resta(const Vector &v) const
{
    if(dim != v.dim) throw std::logic_error("Dimensiones incompatibles");

    Vector res(dim);

    for(int i=0;i<dim;i++)
        res.componente[i]=componente[i]-v.componente[i];
    return res;
}
//*************************************************************************************
Vector Vector::Multiplicar(double escalar) const
{
    Vector res(dim);

    for(int i=0;i<dim;i++) res.componente[i]=componente[i]*escalar;
    return res;
}
//*************************************************************************************
#include<cmath>
double Vector::ObtenerMagnitud() const
{
    double suma=0;

    for(int i=0;i<dim;i++) suma+=componente[i]*componente[i];
    return std::sqrt(suma);
}
