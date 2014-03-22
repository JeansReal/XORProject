/* Libreria que Contiene Macros para el Modo Grafico */

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