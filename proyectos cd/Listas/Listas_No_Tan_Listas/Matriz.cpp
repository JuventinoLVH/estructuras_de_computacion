/* Nombre:Matriz.cpp
   Autor: Luis Juventino Velasquez Hidalgo
   Fecha: 5/2/21
   Descripción: Archivo de implementación de la clase matriz
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
/** \brief Función que captura de forma segura un número entero
 *
 * \param solicitud Mensaje de solicitud para la captura
 * \return Entero capturado
 */
int CapturaEntero(const char solicitud []);


//*************************************************************************************
 /** \brief Destruye una matriz
 *
 *  \param matriz la matriz a destruir
 *  \param r el número de renglones
 *
 */void Obliterar(double ** matriz, int r);

//*************************************************************************************
/** \brief Función que intercambia 2 renglones de una funcion
 *
 * \param double la matriz
 * \param renglon1 el numero del renglon a intercambiar
 * \param renglon2 el segundo renglon a intercambiar
 * \param m el numero de columnas de la matriz
 *
 */
void IntercambiarReng(double ** matriz ,int renglon1 ,int renglon2 ,int m);

//*************************************************************************************
/** \brief Función que multiplica un renglon por un escalar
 *
 * \param double la matriz
 * \param renglon1 el numero del renglon a multiplicar
 * \param k el escalar
 * \param m el numero de columnas de la matriz
 *
 */
void MultiplicarRenglon(double ** matriz ,int renglon1 ,double k ,int m);

//*************************************************************************************
/** \brief Función que le suma a un renglon, otro renglon multiplicado por un escalar
 *
 * \param matriz la matriz
 * \param renglonSuma renglon a modificar
 * \param renglonMultiplo renglon que va a ser multiplicado
 * \param k el escalar por el cual se va a multiplicar renglonMultiplo
 * \param m numero de columnas de la matriz
 *
 */
void SumarMultiplosRenglones(double ** matriz ,int renglonSuma ,int renglonMultiplo ,double k ,int m);

 /*****************************************************************************************
 ********************************** Constructores *****************************************
 *****************************************************************************************/

//*************************************************************************************
Matriz::Matriz(int r , int c) : matriz(NULL)
{
    if(r<=0 || c<=0) throw std::logic_error("Dimensi\242n fuera de rango...");
    reng=r;
    col=c;
    matriz=CrearMatriz(reng,col);

    for(unsigned int i=0;i<reng;++i)
        for(unsigned int j=0;j<col;++j)
            matriz[i][j]=0;

}


//*************************************************************************************
Matriz::Matriz(const Matriz & mtz) : matriz(NULL)
{

    reng=mtz.reng;
    col=mtz.col;
    matriz=CrearMatriz(reng,col);
    for(unsigned int i=0;i<reng;++i)
        for(unsigned int j=0;j<col;++j)
            matriz[i][j]=mtz[i][j];
}

//*************************************************************************************
Matriz::~Matriz()
{
    Obliterar(matriz,reng );
}


 /*****************************************************************************************
 *****************************       Operadores      **************************************
 *****************************************************************************************/

//*************************************************************************************
Matriz & Matriz::operator= (const Matriz & mtz)
{
    if(this == &mtz) return *this;
    if(matriz != NULL)
        Obliterar(matriz,reng);

    reng=mtz.reng;
    col=mtz.col;
    matriz=CrearMatriz(reng,col);
    for(unsigned int i=0;i<reng;++i)
        for(unsigned int j=0;j<col;++j)
            matriz[i][j]=mtz[i][j];
    return *this;
}


//*************************************************************************************
bool Matriz::operator== (const Matriz & mtz)
{
    if(reng != mtz.reng || col!=mtz.col) return false;
    for(unsigned int i=0;i<reng;++i)
    {
        for(unsigned int j=0;j<col;++j)
        {
            if(matriz[i][j] != mtz.matriz[i][j])
                return false;
        }
    }
    return true;
}


//*************************************************************************************
bool Matriz::operator!= (const Matriz & mtz)
{
    return !(*this==mtz);
}


//*************************************************************************************
Matriz Matriz::operator+(const Matriz & mtz) const
{
    if(mtz.reng != reng || mtz.col != col) throw std::logic_error("Las dimensiones son diferentes...");

    Matriz res(reng,col);
    for(unsigned int i=0;i<reng;++i)
        for(unsigned int j=0;j<col;++j)
            res[i][j]=mtz[i][j]+matriz[i][j];
    return res;
}


//*************************************************************************************
Matriz Matriz::operator-(const Matriz & mtz) const
{
    if(mtz.reng != reng || mtz.col != col) throw std::logic_error("Las dimensiones son diferentes...");

    Matriz res(reng,col);
    for(unsigned int i=0;i<reng;++i)
        for(unsigned int j=0;j<col;++j)
            res[i][j]=matriz[i][j]-mtz[i][j];
    return res;
}


//*************************************************************************************
Matriz Matriz::operator*(const Matriz & mtz) const
{
    if(col != mtz.reng ) throw std::logic_error("Las dimensiones no concuerdan...");

    Matriz res(reng,mtz.col);
    for(unsigned int i=0;i<res.reng;++i)
        for(unsigned int j=0;j<res.col;++j)
            for(unsigned int k=0;k<col;++k)
                res[i][j]+=matriz[i][k]*mtz[k][j];
    return res;
}


//*************************************************************************************
Matriz Matriz::operator*(double n) const
{
    Matriz res(reng,col);
    for(unsigned int i=0;i<res.reng;++i)
        for(unsigned int j=0;j<res.col;++j)
                res[i][j]=matriz[i][j]*n;
    return res;
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
    Matriz res(col,reng);
    for(unsigned int i=0;i<res.reng;++i)
        for(unsigned int j=0;j<res.col;++j)
                res[i][j]=matriz[j][i];
    return res;
}


//*************************************************************************************
Matriz Matriz::Inversa() const
{
    if(reng!=col) throw std::logic_error("Las dimenciones no son correctas...");

    double tol=10.E-10;
    Matriz matAux(reng,col*2);

    for(unsigned int i=0;i<reng;++i)
        for(unsigned int j=0;j<col;++j)
            matAux[i][j]=matriz[i][j];
    for(unsigned int i=0;i<reng;++i)
    {
        for(unsigned int j=0;j<col;++j)
            matAux[i][j+col]=0;
        matAux[i][i+col]=1;
    }

    bool esInvertible;
    for(unsigned int i=0;i<reng;i++)
    {
        double abs = (matAux[i][i] < 0) ? -matAux[i][i] : matAux[i][i];
        if(abs <tol)
        {
            esInvertible=false;
            for(unsigned int j=i+1;j<reng;j++)
            {
                if(abs>tol)
                {
                    esInvertible=true;
                    IntercambiarReng(matAux.matriz,i,j,reng*2);
                    break;
                }
            }
            if(!esInvertible)
                throw std::logic_error("No existe su inversa...");
        }
        MultiplicarRenglon(matAux.matriz,i,1/matAux[i][i],2*reng);

        for(unsigned int j=0;j<i;j++)
            SumarMultiplosRenglones(matAux.matriz,j,i,-matAux[j][i],reng*2);
        for(unsigned int j=i+1;j<reng;j++)
            SumarMultiplosRenglones(matAux.matriz,j,i,-matAux[j][i],reng*2);
    }

    Matriz matrizRes(reng,reng);
    for(unsigned int i=0;i<reng;i++)
    {
        for(unsigned int j=0;j<reng;j++)
            matrizRes[i][j]= matAux[i][j+reng];
    }

    return matrizRes;
}


//*************************************************************************************
Matriz Matriz::CambiarDimension(unsigned int r,unsigned int c)
{
    if(r<=0 || c<=0) throw std::logic_error("Dimensi\242n fuera de rango...");
    if(r==reng && c==col) return *this;

    double ** mtzAux=CrearMatriz(r,c);

    for(unsigned int i=0;i<r; ++i)
        for(unsigned int j=0; j<c; ++j)
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
Matriz operator*(double n,const Matriz & mtz)
{
    Matriz res(mtz.reng,mtz.col);
    for(unsigned int i=0;i<res.reng;++i)
        for(unsigned int j=0;j<res.col;++j)
                res[i][j]=mtz[i][j]*n;
    return res;
}

//*************************************************************************************
std::ostream & operator<<(std::ostream & salida, const Matriz &mtz)
{
    for(unsigned int i=0;i<mtz.reng;++i)
    {
        salida<<"\n|";
        for(unsigned int j=0;j<mtz.col;++j)
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
    int r,c;
    r=CapturaEntero("N\243mero de renglones: ");
    c=CapturaEntero("N\243mero de columnas: ");
    mtz.CambiarDimension(r,c);
    for(unsigned int i=0;i<mtz.reng;++i)
    {
        for(unsigned int j=0;j<mtz.col;++j)
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
        delete [] matriz[i];
    delete [] matriz;
}

//*************************************************************************************************************************
void IntercambiarReng(double ** matriz ,int renglon1 ,int renglon2 ,int m)
{
    double aux;
    for(int j=0;j<m;j++)
    {
        aux=matriz[renglon1][j];
        matriz[renglon1][j]=matriz[renglon2][j];
        matriz[renglon2][j]=aux;
    }
}

//*************************************************************************************************************************
void MultiplicarRenglon(double ** matriz ,int renglon1 ,double k ,int m)
{
    for(int i=0;i<m;i++)
        matriz[renglon1][i]*=k;
}

//*************************************************************************************************************************
void SumarMultiplosRenglones(double ** matriz ,int renglonSuma ,int renglonMultiplo ,double k ,int m)
{
    for(int i=0;i<m;i++)
        matriz[renglonSuma][i]+=matriz[renglonMultiplo][i]*k;
}
