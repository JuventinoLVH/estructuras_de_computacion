/* Nombre: PersonaMedieval.cpp
   Autor: Luis Juventino Velasquez H.
   Fecha: 18/03/21
   Descripción: Archivo de implementación de la clase PersonaMedieval
*/

#include"PersonaMedieval.h"

 /*****************************************************************************************
 **********************************   Constructores    ************************************
 *****************************************************************************************/

//*************************************************************************************
PersonaMedieval::PersonaMedieval()
{
    //El reyno es prospero, y 2/9 partes de la población pertenece a la noblesa
    int r = rand()%9;
    esNoble= r<2;

    nombre = NombreAleatoria();
    NormalizarNombre(nombre);
    termino = false;
    r = rand()%100;
    //La mayoria de la gente solo le pide su vendición
    if(r >= 0 && r< 45)
        tAtencion = (rand()%5)+6;
    //Otros tantos le piden consejos
    if(r >= 45 && r< 75)
        tAtencion = (rand()%9)+11;
    //Pero algunos discuten las verdades
    if(r >= 75 && r< 85)
        tAtencion = (rand()%12)+20;
    //El rey esta dispuesto a dar recursos a aquel que le de razones para ello
    if(r >= 85 && r<= 99)
        tAtencion = (rand()%20)+30;
}

//*************************************************************************************
PersonaMedieval::PersonaMedieval(std::string nom,int tAt, bool term,bool nob)
{
    nombre=nom;
    tAtencion=tAt;
    termino=term;
    esNoble=nob;
}

 /*****************************************************************************************
 ********************************   Metodos y funciónes   *********************************
 *****************************************************************************************/

//*************************************************************************************
const std::string & PersonaMedieval::ObtNombre() const
{
    return nombre;
}


const double PersonaMedieval::ObtTAtencion() const
{
    return tAtencion;
}


//*************************************************************************************
bool PersonaMedieval::Termino() const
{
    return termino;
}

//*************************************************************************************
bool PersonaMedieval::EsNoble() const
{
    return esNoble;
}



//*************************************************************************************
void PersonaMedieval::DisminTAtencion(double m/*=2.5*/)
{
    tAtencion-=m;
    if(tAtencion<=0) termino=true;
}


 /*****************************************************************************************
 *********************************   Metodos privados   ***********************************
 *****************************************************************************************/

std::string PersonaMedieval::NombreAleatoria()
{
    //Dos nombres
    std::ifstream archivo("Nombre.txt");
    if(!archivo)
    {
        std::cout<<"El archivo no se encontr\242\n";
        archivo.close();
        return '\0';
    }
    char texto[100];
    std::string nombre;

    //Nombres
    //Ignorar los primeros r nombres
    int r= (rand()%NOMBRES);
    for(int i=0;i<r ;++i) archivo.getline(texto,100);

    archivo.getline(texto,100);
    NormalizarCadena(texto);
    nombre+=texto;
    archivo.close();

    bool segundoNomb = (rand()%2) == 1 ? true : false;
    if(segundoNomb)
    {
        archivo.open("Nombre.txt");
        r= (rand()%NOMBRES);
        for(int i=0;i<r ;++i) archivo.getline(texto,100);

        archivo.getline(texto,100);
        NormalizarCadena(texto);
        nombre+=' ';
        nombre+=texto;
        archivo.close();
    }

    //Apellidos
    archivo.open("Apellido.txt");
    if(!archivo)
    {
        std::cout<<"El archivo no se encontr\242\n";
        archivo.close();
        return '\0';
    }
    archivo.close();

    for(int i=0;i<2;++i)
    {
        archivo.open("Apellido.txt");
        r= (rand()%APELLIDOS);
        for(int j=0;j<r ;j++) archivo.getline(texto,100);

        archivo.getline(texto,100);
        NormalizarCadena(texto);
        nombre+=' ';
        nombre+=texto;
        archivo.close();
    }
    return nombre;
}

 /*****************************************************************************************
 *********************************   Funciones Amigas  ************************************
 *****************************************************************************************/
//*************************************************************************************
std::ostream & operator<<(std::ostream & salida ,const PersonaMedieval & p )
{
    salida<<p.ObtNombre()<<"<- ";
    if(p.esNoble)
        salida<<"Noble";
    else
        salida<<"Plebeyo";

    return salida;

}
