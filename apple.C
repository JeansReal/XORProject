***REMOVED***
***REMOVED***
***REMOVED***
***REMOVED***
***REMOVED***
/*      Profesor>> Grevin Silva.            */
***REMOVED***

/* Ficheros de Cabezera o Librerias */
#include <StdIo.h>      /* Funciones para salida de datos>> printf() */
#include <Conio.h>      /* Validacion de Control de Teclas>> kbhit() */
#include <Graphics.h>   /* Para Usar El Entorno Grafico de Borland */ 
#include <Dos.h>        /* Animaciones>> delay() , sleep() , sound() , nosound() */
#include <Alloc.h>      /* Asignacion de Memoria Dinamica>> malloc() , free() */
#include <StdLib.h>     /* Comandos del sistema>> system() , abort() , exit() */


/* Libreria Personalizada */
#include "Coor.h"       /* Coordenadas */
#include "Modo.h"       /* Modo Grafico */
#include "Macro.h"      /* Macros */


/* Funciones Prototipo */
/* Funciones Para El Modo Grafico */
void InitGraph(void);
int huge HighLevelXGA(void);

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

/** Cuerpo Principal **/
void main(void)
{
    int x=0, y=0;

    InitGraph();

    /* Android */
    setcolor(10);
    fillpoly(22,cabeza);
    fillpoly(32,cuerpezito);
    fillpoly(22,brazito);

    /* Apple */
    setcolor(53);
    drawpoly(11,hoja);
    drawpoly(44,manzana);
    
    /* gotas de la manzana */
    setcolor(53);
    drawpoly(12,first_drop);    /*primera gota del pipi*/
    drawpoly(9,second_drop);    /*segunda gota del pipi*/
    drawpoly(9,third_drop);     /*tercera gota del pipi*/

    /* Ojito */
    setcolor(10);
    fillellipse(450,297,5,5);


    setcolor(42);
    do {
        arc(520, 415, 0, 130, 60);
        arc(520, 416, 0, 130, 60);
        arc(520, 417, 0, 130, 60);
        arc(520, 418, 0, 130, 60);

        delay(50);
        x++;

        if (x<30)
            y--;
        else
            y++;

        setfillstyle(1,0);
        bar(480+x, 370+y, 495+x, 380+y);

    } while (x!=100);

    getch();
}