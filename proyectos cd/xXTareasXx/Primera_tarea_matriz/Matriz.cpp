/* Nombre:.cpp
   Autor:
   Fecha:
   Descripción:
*/
#include"Matriz.h"


//*************************************************************************************
 /** \brief Crea una matriz en memoria dinamica
 *
 * \param r el número de renglones
 * \param c el número de columnas
 * \return la direccion de un arreglo de punteros
 * \exception std::bad_alloc si no se queda espacio para la matriz
 *
 */double ** CrearMatriz(int r, int c);

//*************************************************************************************
 /** \brief Destruye una matriz
 *
 *  \param matriz la matriz a destruir
 *  \param r el número de renglones
 *
 */void Obliterar(double ** matriz, int r );


 /*****************************************************************************************
 ********************************** Constructores *****************************************
 *****************************************************************************************/

//*************************************************************************************
Matriz::Matriz(int r , int c) : matriz(NULL),reng(r),col(c)
{
    if(r<=0 || c<=0) throw std::logic_error("Dimensi\242n fuera de rango");

    matriz=CrearMatriz(reng,col);

    for(int i=0;i<reng;++i)
        for(int j=0;j<col;++j)
            matriz[i][j]=0;

}


//*************************************************************************************
Matriz::Matriz(const Matriz & mtz)
{
    *this = mtz;
}

//*************************************************************************************
Matriz::~Matriz()
{
    Obliterar(matriz,reng);
}


 /*****************************************************************************************
 *****************************       Operadores      **************************************
 *****************************************************************************************/

//*************************************************************************************
Matriz & Matriz::operator= (const Matriz & mtz)
{

}


//*************************************************************************************
Matriz Matriz::operator+(const Matriz & mtz) const
{
    if(mtz.reng != reng || mtz.col != col) throw std::logic_error("Las dimensiones son diferentes");

    Matriz res(reng,col);
    for(int i=0;i<reng;++i)
        for(int j=0;j<col;++j)
            res[i][j]=mtz[i][j]+matriz[i][j];
    return res;
}


//*************************************************************************************
Matriz Matriz::operator-(const Matriz & mtz) const
{
    if(mtz.reng != reng || mtz.col != col) throw std::logic_error("Las dimensiones son diferentes");

    Matriz res(reng,col);
    for(int i=0;i<reng;++i)
        for(int j=0;j<col;++j)
            res[i][j]=mtz[i][j]-matriz[i][j];
    return res;
}


//*************************************************************************************
Matriz Matriz::operator*(const Matriz & mtz) const
{
    if(col != mtz.reng ) throw std::logic_error("Las dimensiones no concuerdan");

    Matriz res(reng,mtz.col);
    for(int i=0;i<res.reng;++i)
        for(int j=0;j<res.col;++j)
            for(int k=0;k<col;++k)
                res[i][j]+=mtz[i][k]*matriz[k][j];
    return res;
}


//*************************************************************************************
Matriz Matriz::operator*(double n) const
{

}


//*************************************************************************************
const double *  Matriz::operator[](int i) const
{
    return this->matriz[i];
}

//*************************************************************************************
double *  Matriz::operator[](int i)
{
    return this->matriz[i];
}


 /*****************************************************************************************
 *********************************        Metodos      ************************************
 *****************************************************************************************/


//*************************************************************************************
Matriz Matriz::Tranpuesta() const
{
    return *this;
}


//*************************************************************************************
Matriz Matriz::Inversa(const Matriz & mtz) const
{

}


//*************************************************************************************
Matriz Matriz::CambiarDimension(int r,int c)
{
    if(r==reng && c==col) return *this;
    if(r<=0 || c<=0) throw std::logic_error("Dimensi\242n fuera de rango");

    double ** mtzAux=CrearMatriz(r,c);

    for(int i=0;i<r; ++i)
        for(int j=0; j<c; ++j)
            mtzAux[i][j]= (i< reng && j<col) ? matriz[i][j] : 0;

    Obliterar(matriz,reng);
    matriz=mtzAux;
    col=c;
    reng=r;
    return *this;
}



 /*****************************************************************************************
 ******************        Funciones externas y amigas      *******************************
 *****************************************************************************************/

//*************************************************************************************
std::ostream & operator<<(std::ostream & salida, const Matriz &mtz)
{
    salida<<'\n';
    for(int i=0;i<mtz.reng;++i)
    {
        salida<<'|';
        for(int j=0;j<mtz.col;++j)
        {
            salida<<mtz[i][j]<<" ";
        }
        salida<<"|\n";
    }

    return salida;
}

//*************************************************************************************
std::istream & operator>>(std::istream & entrada, Matriz &mtz)
{

    for(int i=0;i<mtz.reng;++i)
    {
        for(int j=0;j<mtz.col;++j)
        {
            std::cout<<"Componente"<<'['<<i+1<<"]["<<j+1<<"]: ";
            entrada>>mtz[i][j];
        }
    }
    return entrada;
}


 /*****************************************************************************************
 *************************       Funciones Auxiliares      ********************************
 *****************************************************************************************/

//*************************************************************************************
double ** CrearMatriz(int r, int c)
{
    double ** mtzAux;
    int numRenglones=0;
    try
    {
        mtzAux = new double*[r];
        while(numRenglones<r)
        {
            mtzAux[numRenglones]=new double[c];
            ++numRenglones;
        }
    }
    catch(std::bad_alloc & e)
    {
        if(mtzAux==NULL) throw e;

        for(int i=0;i<numRenglones; ++i)
            delete mtzAux[i];
        delete mtzAux;

        throw e;
    }
    return mtzAux;
}

//*************************************************************************************
void Obliterar(double ** matriz, int r)
{
    for(int i=0;i<r ;++i)
        delete matriz[r];
    delete matriz;
}
