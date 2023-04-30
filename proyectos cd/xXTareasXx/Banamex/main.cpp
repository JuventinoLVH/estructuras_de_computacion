#include<iostream>
#include<ctime>
#include"Utileria.h"
#include"Banco.h"


#define MINUTOS 2.5 //Cuantos minutos equivale un segundo de vida real

using namespace std;

//****************************************************************************************
/** \brief Imprime la hora en formato
*
* \param h la cantidad de horas
* \param m la cantidad de minutos
*
*/void ImprHora(int h, int m);

//****************************************************************************************
/** \brief Simula que el tiempo ha pasado
*
* \param h la cantidad de horas
* \param m la cantidad de minutos
*
*/void SimularTiempo(int & h, double & m);

//****************************************************************************************
/** \brief Imprime los datos del banco
*
* \param b el banco a imprimir
* \param h la hora del día
*
*/void ImprEstadoBanco(Banco b, int h);

//****************************************************************************************
/** \brief Añade una persona al banco, la probabilidad de que aparezca varia segun la hora
*
* \param b el banco al que entrará la persona
* \param h la hora del día
*
*/void AparecerPersona(Banco & b ,int h);

 /*****************************************************************************************
 *************************************     Main     ***************************************
 *****************************************************************************************/
//****************************************************************************************
int main()
{

    srand(time(NULL));
    CambiaCursor(APAGADO);

    int horas=6;
    double minutos=0;
    Banco Banormex;
    Persona aux;

    while(horas < 16)
    {
        ImprHora(horas,minutos);

        cout<<"\n\n\t";
        ImprEstadoBanco(Banormex , horas);

        if(horas>=8)
        {
            if(Banormex.cajaLibre())
                Banormex.Siguiente();
            else
                Banormex.AtenderEnCaja(MINUTOS);
        }

        AparecerPersona(Banormex,horas);



        SimularTiempo(horas,minutos);
        system("cls");

    }
    while(!Banormex.cajaLibre())
    {
        ImprHora(horas,minutos);

        cout<<"\n\n\t";

        ImprEstadoBanco(Banormex , horas);
        if(horas>=8)
        {
            if(Banormex.cajaLibre())
                Banormex.Siguiente();
            else
                Banormex.AtenderEnCaja(MINUTOS);
        }

        SimularTiempo(horas,minutos);
        system("cls");

    }

    ImprHora(horas,minutos);
    cout<<"\n\n\t";
    ImprEstadoBanco(Banormex,horas);
    cout<<"\nHoy se atendi\242 a: \n";
    Banormex.ImprAtendidos();

    system("pause");
    return 0;
}

 /*****************************************************************************************
 ********************************   Metodos y funciónes   *********************************
 *****************************************************************************************/

//****************************************************************************************
void ImprEstadoBanco(Banco b, int h)
{
    Persona aux;
    if(h >= 8 && h < 16)
    {
        if(b.cajaLibre())
        {
            cout<<"El banco est\240 abierto, esperando cliente...";
        }
        else
        {
            aux = b.PersonaEnCaja();
            cout<<"La caja est\240 ocupada, atendiendo a: "<<aux.getNombre()<<
                "\t\ttiempo estimado para terminar de atenderlo/a: "<<aux.getTAtencion();
        }

    }
    else
    {
        if(b.cajaLibre())
            cout<<" El banco est\240 cerrado HORARIO: 6:00am - 4:00pm";
        else
            cout<<" El banco est\240 por cerrar, esperando a: "<<(b.PersonaEnCaja()).getNombre()<<
                "\t\ttiempo estimado para terminar de atenderlo/a: "<<aux.getTAtencion();
    }
    cout<<"\n\n\nClientes en espera:\n";
    b.ImpCola();
}


//****************************************************************************************
void AparecerPersona(Banco & b ,int h)
{
    Persona nuevaP;
    //posibilidad del 9% de que alguien venga en la madrugada
    if(h >= 6 && h<8)
    {
        if(rand()%100 < 8)
            b.FormarPersona(nuevaP);
    }
    //la probabilidad aumenta cuando abren
    if(h >= 8 && h<10)
    {
        if(rand()%100 < 38)
            b.FormarPersona(nuevaP);
    }
    //La probabilidad baja al mediodia
    if(h >= 10 && h<14)
    {
        if(rand()%100 < 16)
            b.FormarPersona(nuevaP);
    }
    //Cercana a la hora de cierre, la probabilidad es casi 0
    if(h >= 14 && h<16)
    {
        if(rand()%100 < 4)
            b.FormarPersona(nuevaP);
    }
}


//****************************************************************************************
void SimularTiempo(int & h, double & m)
{
    //escala de tiempo 1 seg. : 2.5 min.  =  4 min. : 10 h.
    Sleep(1000);
    m+=MINUTOS;
    if(m>=60)
    {
        ++h;
        if(h > 24) h =0;
        m-=60;
    }
}


//****************************************************************************************
void ImprHora(int h, int m)
{
    bool mat = h <= 12 ? true : false;
    cout<< (mat ? h : h-12) <<':';
    if(m<10) cout<<'0';
    cout<<m<<' ';
    cout<< (mat ? "AM" : "PM");
}
