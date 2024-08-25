#include <iostream>
#include <time.h>
#include <cstdlib>
#include <windows.h>
using namespace std;
#include "rlutil.h"
#include "visual.h"
#include "calculos.h"
#include "utilidades.h"
#include "singleplayer.h"
#include "multiplayer.h"

//-lwinmm

const int tamanio = 6;

int main(){

    char nombre[3][10]={{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{'N','a','d','i','e',' ',' ',' ',' ',' '}};
    int puntajeMax=0;
    int *posPuntajeMax=&puntajeMax;
    int seleccionMenu; //seleccion menu es la variable que condiciona la eleccion del switch

    PlaySound(TEXT("K-on.wav"), NULL, SND_ASYNC);
    while(true){
        seleccionMenu = menu();//seleccionMenu le pide a la funcion "menu" la opcion seleccionada por el usuario
        switch (seleccionMenu){
            case 1:
                system("cls");
                PlaySound(TEXT("jazz.wav"), NULL, SND_ASYNC);
                singleplayer(nombre, tamanio,puntajeMax,posPuntajeMax);
                system("cls");
                PlaySound(TEXT("K-on.wav"), NULL, SND_ASYNC);
                break;
            case 2:
                system("cls");
                PlaySound(TEXT("jazz.wav"), NULL, SND_ASYNC);
                multiplayer(nombre, tamanio,puntajeMax,posPuntajeMax);
                system("cls");
                PlaySound(TEXT("K-on.wav"), NULL, SND_ASYNC);
                break;
            case 3:
                system("cls");
                puntajeMaxVisual(nombre,puntajeMax);
                PlaySound(TEXT("K-on.wav"), NULL, SND_ASYNC);
                break;
            case 4:
                system("cls");
                rlutil::locate(50,10);
                cout<< char(173)<<"Gracias por jugar!";
                PlaySound(TEXT("gameover.wav"), NULL, SND_SYNC);
                return 0;
            default:
                return 0;
                break;
        }
    }
    return 0;
}
