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
#include <Math.h>       /* Funciones para Calculos de Figuras Geometricas>> DrawEllipse() */

/* Libreria Personalizada */
/*#include "Apple/Coor.h"       /* Coordenadas */
#include "Apple/Modo.h"       /* Modo Grafico */
#include "Apple/Macro.h"      /* Macros */
/*#include "Apple/Screens.h"    /* Pantallas */
#include "Apple/XorFunc.h"    /* Funciones XOR */

/* Funciones Prototipo */

/* Funciones Para El Modo Grafico */
void InitGraph(void);
int huge HighLevelXGA(void);

/* Funciones Para Mostrar las Pantallas */
void Presentacion(void);

/* Funciones Para Figuras en Modo XOR */
void DrawCursor(ControlEje x, ControlEje y);
void DrawCircle(ControlEje x, ControlEje y, short radio);
void DrawLine(ControlEje x, ControlEje y, unsigned short largo);
void DrawTriangle(ControlEje x, ControlEje y, unsigned short Perimetro);
void DrawRectangle(ControlEje x, ControlEje y, unsigned short Perimetro);
void DrawEllipse(ControlEje x, ControlEje y, short xRadio, short yRadio);

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
    ControlEje x=400, y=300;
    unsigned short largo=100;

    InitGraph();

    /*Presentacion();*/

    do {
        DrawCursor(x, y);

        switch(getch())
        {
            case ARRIBA:    --y;     break;
            case ABAJO:     ++y;     break;
            case DERECHA:   ++x;     break;
            case IZQUIERDA: --x;     break;
            case MAS:       ++largo; break;
            case MENOS:     --largo; break;

            case X:
                _xorMode = (_xorMode) ? False : True ;
            break;

            case 97:    exit(0);
        }

    } while (True);
}