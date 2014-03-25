/* Libreria que Contiene Macros para el Modo Grafico */

/* Definicion de Constantes y Macros */
#define EXIT_SUCCESS    0
#define EXIT_FAILURE    1
/* Dirrecionales */
#define ARRIBA      72
#define ABAJO       80
#define DERECHA     77
#define IZQUIERDA   75
/* Teclas De Control */
#define ENTER   13
#define ESC     27
#define DELETE  8
#define TAB     9
/* Teclas de Manejo de Hule */
#define MAS 	43
#define MENOS	45

/* Macros Para Funcion XOR */

/* Macro Adaptable a la Cantidad de colores de la Resolucion */
#define RESMAXCOLORS (getmaxcolor() + 1) / 2

/* Macro que Retorna el Color XOR de la Posicion */
#define ColorXor(x, y) RESMAXCOLORS ^ getpixel(x, y)

/* Macro Para Pintar Pixel en XOR */
#define PixelXor(x, y) putpixel(x, y, ColorXor(x, y))


/* Macro Para Determinar Columnas de Arreglos Unidimensionales Dinamicos */
#define TamArray(Arreglo)              sizeof(Arreglo)/sizeof(Arreglo[0])


/* Macros Para Funciones De Estilo */
#define Relleno(Trama, Color)           setfillstyle(Trama, Color)
#define Linea(Estilo, Grosor, Color)    setcolor(Color), setlinestyle(Estilo, 0, Grosor)


/* Macro Para Pintar, Trazar y Rellenar Arreglos de Graficos en Coordenadas */
#define Fill(Array)                                         fillpoly(TamArray(Array)/2, Array)
#define Draw(Array)                                         drawpoly(TamArray(Array)/2, Array)
#define PintarFigura(Tra, Col_R, Est, Gro, Col_L, Array)   	Relleno(Tra, Col_R), Linea(Est, Gro, Col_L), Fill(Array)
#define TrazarLineas(Estilo, Grosor, Color, Array)         	Linea(Estilo, Grosor, Color), Draw(Array)
#define Inundar(Trama, Color, x, y, Borde)                  Relleno(Trama, Color), floodfill(x, y, Borde)