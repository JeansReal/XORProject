/* Libreria que Contiene Macros para el Modo Grafico */

/* Definicion de Constantes y Macros */
#define NONE		-1
/* Dirrecionales */
#define ARRIBA      72
#define ABAJO       80
#define DERECHA     77
#define IZQUIERDA   75
/* Teclas De Control */
#define ENTER   	13
#define ESC     	27
#define TAB    		9
/* Teclas de Manejo de Hule */
#define MAS     	43
#define MENOS   	45
/* Color XOR Default */
#define Color   	40  /* Rojo en XGA */

/* Macros Para Funcion XOR */

/* Macro Para Pintar Pixel en XOR */            /* Refactorizando Para Obtener Mas Velocidad */
#define PixelXor(x, y)  (_xorMode) ? putpixel(x, y, Color ^ getpixel(x, y)) : putpixel(x, y, Color) ;

/* Macro Para Determinar Columnas de Arreglos Unidimensionales Dinamicos */
#define TamArray(Array) sizeof(Array)/sizeof(Array[0])

/* Macros Para Funciones De Estilo */
#define Relleno(Trama, Color)           setfillstyle(Trama, Color)
#define Linea(Estilo, Grosor, Color)    setcolor(Color), setlinestyle(Estilo, 0, Grosor)

/* Macro Para Pintar, Trazar y Rellenar Arreglos de Graficos en Coordenadas */
#define Fill(Array)		fillpoly(TamArray(Array) / 2, Array)
#define Draw(Array)		drawpoly(TamArray(Array) / 2, Array)