***REMOVED***
***REMOVED***
***REMOVED***
***REMOVED***
***REMOVED***
***REMOVED***
***REMOVED***

/* No Incluir Librerias Mas de 1 Vez */
#pragma

/* Ficheros de Cabezera o Librerias */
#include <StdIo.h>      /* Funciones para salida de datos>> printf() */
#include <Conio.h>      /* Validacion de Control de Teclas>> kbhit() */
#include <Graphics.h>   /* Para Usar El Entorno Grafico de Borland */ 
#include <Dos.h>        /* Animaciones>> delay() , sleep() , sound() , nosound() */
#include <Alloc.h>      /* Asignacion de Memoria Dinamica>> malloc() , free() */
#include <StdLib.h>     /* Comandos del sistema>> system() , abort() , exit() */

#include <math.h>

/* Libreria Personalizada */
#include "Apple/Coor.h"       /* Coordenadas */
#include "Apple/Modo.h"       /* Modo Grafico */
#include "Apple/Macro.h"      /* Macros */
#include "Apple/Screens.h"    /* Pantallas */

#include <land1.h> /*image No 1*/
#include <board.h> /*board showing image No 1 */

void landscape1();
void board();

/* Funciones Prototipo */

/* Funciones Para El Modo Grafico */
void InitGraph(void);
int huge HighLevelXGA(void);

/* Funciones Para Mostrar las Pantallas */
void Presentacion(void);


/* Funcion para Precision de Graficos */
#include <Mouse.h>
void Mouse(void)
{
    mver();
    mlimit(1,1,getmaxx()+1,getmaxy()+1,1);
    do {
        gotoxy(1,1) , printf("X=%3d\nY=%3d", mxpos(1), mypos(1));
        putpixel(mxpos(1), mypos(1), 15);
    } while(!kbhit());
}
/* Macro Para Realizar "Depuracion" */
#define Pausa   getch() , abort() ;


/** Cuerpo Principal **/
void main(void)
{
    Direccional Tecla=0;

    int x=500,y=350;
    unsigned short largo=20;
    int i=0;


    InitGraph();

    Presentacion();

    
/*
    do {
        Tecla=getch();

        switch(Tecla)
        {
            case ARRIBA:    --y;     break;
            case ABAJO:     ++y;     break;
            case DERECHA:   ++x;     break;
            case IZQUIERDA: --x;     break;
            case MAS:       ++largo; break;
            case MENOS:     --largo; break;
            case ESC:       exit(0);
        }


    } while (False);*/

    getch();


   board();




}

void unalinea(int x,int y, int i, int largo)
{
    PixelXor(x, y);     /* Centro */
    for (i = 0; i < largo; ++i)
    {
        PixelXor(x + i, y); /* Derecha */
        PixelXor(x - i, y); /* Izquierda */
    }
}
