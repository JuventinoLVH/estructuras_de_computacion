/*
 Nombre: Utileria.cpp
 Autor: Luis J. Velasquez Hidalgo
 Fecha: 02/03/2020
 Descripción: Funciones de utileria
*/

#include "Utileria.h"

//************************************************************************************************************************
int CapturaEntero(const char solicitud [])
{
    int n;
    while(true){
        std::cout << solicitud;
        std::cin >> n;

        if(std::cin.bad()){
            std::cout << "Ocurri\242 un error irrecuperable en el flujo de entrada\n";
            system("pause");
            exit(1);
        }
        if(std::cin.fail()){
            std::cout << "Error: no es un n\243mero. Introduzca de nuevo...\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            continue;
        }
        return n;
    }
}


//************************************************************************************************************************
void NormalizarCadena(char *cadena)
{
    int indiceNormal=0;
    for(int i=0;cadena[i];i++)
    {
        switch(cadena[i])
        {
            case -62:
                switch(cadena[++i])
                {
                    case -95:
                        cadena[indiceNormal++]=173;
                        break;
                    case -65:
                        cadena[indiceNormal++]=168;
                        break;
                    case -80:
                        cadena[indiceNormal++]=248;
                        break;
                    case -84:
                        cadena[indiceNormal++]=170;
                        break;
                    case -67:
                        cadena[indiceNormal++]=250;
                        break;
                }
                break;

            case -61:
                switch(cadena[++i])
                {
                    case -79:
                        cadena[indiceNormal++]=164;
                        break;
                    case -111:
                        cadena[indiceNormal++]=165;
                        break;
                    case -95:
                        cadena[indiceNormal++]=160;
                        break;
                    case -87:
                        cadena[indiceNormal++]=130;
                        break;
                    case -83:
                        cadena[indiceNormal++]=161;
                        break;
                    case -77:
                        cadena[indiceNormal++]=162;
                        break;
                    case -70:
                        cadena[indiceNormal++]=163;
                        break;
                    case -127:
                        cadena[indiceNormal++]=181;
                        break;
                    case -119:
                        cadena[indiceNormal++]=144;
                        break;
                    case -115:
                        cadena[indiceNormal++]=214;
                        break;
                    case -109:
                        cadena[indiceNormal++]=224;
                        break;
                    case -102:
                        cadena[indiceNormal++]=233;
                        break;

                }
                break;
            case -30:
                switch(cadena[++i])
                {
                    case -106:
                        switch(cadena[++i])
                        {
                            case -120:
                                cadena[indiceNormal++]=219;
                                break;
                            case -110:
                                cadena[indiceNormal++]=177;
                                break;
                            case -111:
                                cadena[indiceNormal++]=176;
                                break;
                            case -109:
                                cadena[indiceNormal++]=178;
                                break;
                            case -124:
                                cadena[indiceNormal++]=220;
                                break;
                            case -128:
                                cadena[indiceNormal++]=223;
                                break;
                            case -116:
                                cadena[indiceNormal++]=-37;
                                break;
                            case -112:
                                cadena[indiceNormal++]=-37;
                                break;
                            case -96:
                                cadena[indiceNormal++]=-2;
                                break;
                        }
                        break;
                    case -107:
                        switch(cadena[++i])
                        {
                            case -108:
                                cadena[indiceNormal++]=201;
                                break;
                            case -112:
                                cadena[indiceNormal++]=205;
                                break;
                            case -111:
                                cadena[indiceNormal++]=186;
                                break;
                            case -105:
                                cadena[indiceNormal++]=187;
                                break;
                            case -102:
                                cadena[indiceNormal++]=200;
                                break;
                            case -99:
                                cadena[indiceNormal++]=188;
                                break;
                        }
                        break;

                    case -108:
                        switch(cadena[++i])
                        {
                            case -126:
                                cadena[indiceNormal++]=179;
                                break;
                            case -108:
                                cadena[indiceNormal++]=192;
                                break;
                            case -116:
                                cadena[indiceNormal++]=218;
                                break;
                            case -128:
                                cadena[indiceNormal++]=196;
                                break;
                            case -112:
                                cadena[indiceNormal++]=191;
                                break;
                            case -104:
                                cadena[indiceNormal++]=217;
                                break;
                        }
                        break;
                }
                break;
            default:
                cadena[indiceNormal++]=cadena[i];
                break;
        }
    }
    cadena[indiceNormal]='\0';
}


//************************************************************************************************************************
void EstablecerColor(WORD colorEst)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorEst);
}


//*************************************************************************************************************************
void EstablecerColor(Color colorFondo, Color colorTexto)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (colorFondo)*16 + colorTexto);
}


//*************************************************************************************************************************
WORD ObtenerColorOriginal()
{
    HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
    GetConsoleScreenBufferInfo(hConsoleHandle, ConsoleInfo);
    WORD original = ConsoleInfo->wAttributes;
    delete ConsoleInfo;
    return original;
}


//*************************************************************************************************************************
void EstablecerTamVentana(SHORT ancho, SHORT alto)
{
	_COORD coord = {--ancho, --alto};
	_SMALL_RECT rect = {0,0,ancho,alto};
	HANDLE hConsola = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(hConsola, coord);
	SetConsoleWindowInfo(hConsola, true, &rect);
}


//*************************************************************************************************************************
void gotoxy(short x,short y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {x,y};
    SetConsoleCursorPosition(handle,coord);
}


//*************************************************************************************************************************
void CambiaCursor(estadoCursor estado, modoCursor modo)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConCurInf;

    ConCurInf.dwSize = modo;
    ConCurInf.bVisible = estado;

    SetConsoleCursorInfo(hOut, &ConCurInf);
}
