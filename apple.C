***REMOVED***
***REMOVED***
***REMOVED***
***REMOVED***
***REMOVED***
***REMOVED***
***REMOVED***

/* No Incluir Librerias Mas de 1 Vez */
#pragma once

/* Ficheros de Cabezera o Librerias */
#include <StdIo.h>      /* Funciones para salida de datos>> printf() */
#include <Conio.h>      /* Validacion de Control de Teclas>> kbhit() */
#include <Graphics.h>   /* Para Usar El Entorno Grafico de Borland */ 
/*#include <Dos.h>        /* Animaciones>> delay() , sleep() , sound() , nosound() */
/*#include <Alloc.h>      /* Asignacion de Memoria Dinamica>> malloc() , free() */
#include <StdLib.h>     /* Comandos del sistema>> system() , abort() , exit() */

/* Libreria Personalizada */
/*#include "Apple/Coor.h"       /* Coordenadas */
#include "Apple/Modo.h"       /* Modo Grafico */
#include "Apple/Macro.h"      /* Macros */
/*#include "Apple/Screens.h"    /* Pantallas */
#include "Apple/XorFunc.h"    /* Funcions XOR */


/* Funciones Prototipo */

/* Funciones Para El Modo Grafico */
void InitGraph(void);
int huge HighLevelXGA(void);

/* Funciones Para Mostrar las Pantallas */
void Presentacion(void);

/* Funciones Para Figuras en Modo XOR */
void DrawCircle(ControlEje x, ControlEje y, short radio);
void DrawLine(ControlEje x, ControlEje y, unsigned short largo);
void DrawTriangle(ControlEje x, ControlEje y, unsigned short Perimetro);
void DrawRectangle(ControlEje x, ControlEje y, unsigned short Perimetro);

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

void DrawEllipse(ControlEje originX, ControlEje originY, short radio);

/** Cuerpo Principal **/
void main(void)
{
    Direccional Tecla=0;

    int x=500,y=350;
    unsigned short largo=60;

    InitGraph();

    /*Presentacion();*/

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

        DrawEllipse(x, y, largo);

    } while (False);
}

void DrawEllipse(ControlEje x, ControlEje y, short radio)
{
    short i = 0;
    short d = radio;

    for (; i < radio; i++)
    {
        if (d < 0)
            d += (2 * i);
        else {
            radio-=4;
            d += (2 * i) - (2 * radio);
        }

        PixelXor(x + i, y + radio);
        PixelXor(x - radio, y - i);
        PixelXor(x + radio, y - i);
        PixelXor(x - radio, y + i);
        PixelXor(x + radio, y + i);
        PixelXor(x - i, y - radio);
        PixelXor(x + i, y - radio);
        PixelXor(x - i, y + radio);
    }
}