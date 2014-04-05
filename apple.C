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
#include <Dos.h>        /* Animaciones>> delay() , sleep() , sound() , nosound() */
/*#include <Alloc.h>      /* Asignacion de Memoria Dinamica>> malloc() , free() */
#include <StdLib.h>     /* Comandos del sistema>> system() , abort() , exit() */
#include <Math.h>       /* Funciones para Calculos de Figuras Geometricas>> DrawEllipse() */
#include <String.h>     /* Funcion Para Llenar Bloque de Memoria>> memset() */

/* Libreria Personalizada */
#include "Apple/Coor.h"       /* Coordenadas */
#include "Apple/Macro.h"      /* Macros */
#include "Apple/Modo.h"       /* Modo Grafico */
#include "Apple/Screens.h"    /* Pantallas */
#include "Apple/XorFunc.h"    /* Funciones XOR */

/* Funciones Prototipo */

/* Funciones Para El Modo Grafico */
void InitGraph(void);
int huge HighLevelXGA(void);
/* Funciones Para Mostrar las Pantallas */
void Presentacion(void);
/* Funcion Para Animar Controles */
enum ActiveButton DrawButton(ControlEje x1, ControlEje y1, ControlEje x2, ControlEje y2, Boolean Status, enum ActiveButton btnId);
/* Funcion Que Anima el Boton Seleccionado */
enum ActiveButton SelectedButton(ControlEje x, ControlEje y);
/* Funcion Que Calcula Figura Seleccionada */
enum ActiveShape SelectedShape(ControlEje x, ControlEje y);
/* Funcion Que Contiene el Marco de Trabajo */
void Frame(void);
/* Funciones que Contienen Imagenes de Fondo */
void Landscape1(void);

/* Funciones Para Figuras en Modo XOR */
void DrawCursor(ControlEje x, ControlEje y);
void DrawCircle(ControlEje x, ControlEje y, short radio);
void DrawLine(ControlEje x, ControlEje y, unsigned short largo);
void DrawTriangle(ControlEje x, ControlEje y, unsigned short Perimetro);
void DrawRectangle(ControlEje x, ControlEje y, unsigned short Perimetro);
void DrawEllipse(ControlEje x, ControlEje y, short xRadio, short yRadio);

/** Cuerpo Principal **/
void main(void)
{
    Direccional Tecla = 0;
    ControlEje x = 800, y = 100;
    unsigned short largo = 100;

    InitGraph();

    /*Presentacion();*/

    Frame();

    do {
        DrawCursor(x, y);

        /* Si Una Figura fue Seleccionada la Pinta */
        if (_activeShape != NONE)
            switch (_activeShape)
            {
                case Line:      DrawLine(x, y, largo);                break;
                case Rectangle: DrawRectangle(x, y, largo);           break;
                case Circle:    DrawCircle(x, y, largo);              break;
                case Ellipse:   DrawEllipse(x, y, largo, largo/2);    break;
                case Polygon:   DrawTriangle(x, y, largo);            break;
            }

        /* Movimiento de Los Ejes */
        Tecla = getch();
        switch (Tecla)
        {
            case ARRIBA:    y-=5;     break;
            case ABAJO:     y+=5;     break;
            case DERECHA:   x+=5;     break;
            case IZQUIERDA: x-=5;     break;
            case MAS:       largo+=5; break;
            case MENOS:     largo-=5; break;

            case TAB:
                _xorMode = (_xorMode) ? False : True ;
            break;

            case ENTER:
                if (_activeShape != NONE) /* Si Hay una Figura Seleccionada */
                    _activeShape = NONE;
                else {
                    _activeShape = SelectedShape(x, y);

                    if (_activeShape != NONE)   /* Si Seleccion Algo, Centrar Cursor */
                        x = 475 , y = 373 ;
                }
            break;

            case ESC:
            case 97:    exit(0);
        }

        _hoverButton = SelectedButton(x, y);

    } while (True);
    /* closegraph(); */
}

/* Funcion que Guarda en un Fichero una Accion */
void SaveStep(void)
{
    Iteracion i = 0, j = 0;

    DataBase = fopen(DataBasePath, "a+");

    if (DataBase == NULL)
    {
        /* Have No Idea!! */
    } else {
        for (i = 0; i < 200; i++)
            for (j = 0; j < 300; j++)
                fprintf(DataBase, "%d\n", getpixel(j,i));
        exit(0);
    }
}

typedef struct DataTable {
    ControlEje x1, y1, x2, y2;
    unsigned short Pixel;
} DataBaseConexion;

void CalcAmountOfMemory(void)
{

}

struct DataTable *MemoryConstructor(Cantidad RegistrosSolicitados)
{
    /* Variable de tipo Puntero Para Acceder a la Estructura */
    struct DataTable *Memoria_De_Registros = NULL;

    /* Calculando el espacio de Memoria Solicitado */
    Cantidad MemoriaRequerida = (sizeof(struct DataTable) * RegistrosSolicitados);

    /* Asignacion de Memoria a la Estructura */
    Memoria_De_Registros = (struct DataTable *) malloc(MemoriaRequerida);

    /* Si Se Logro Asignar la Memoria */
    if (Memoria_De_Registros != NULL)
    {
        memset(&Memoria_De_Registros, '', TamArray(Memoria_De_Registros));
    } else {
        /* No Idea!! about what to do! */
    }

    return Memoria_De_Registros;
}