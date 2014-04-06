/* Libreria que Contiene Funciones y Enumeraciones y Estructuras para el Modo Grafico */

/* Declaracion de Nuevos Tipos de Datos */
typedef int Graph;
typedef unsigned short Iteracion, ControlEje, Boolean, Cantidad, Direccional;
typedef char* String;

/* Enumeraciones Para Control de Funciones y Validaciones */
enum Boolean { False, True };

enum Button { btnLine, btnRec, btnCircle, btnEllipse, btnPolygon } _hoverButton = NONE;
enum ActiveShape { Line, Rectangle, Circle, Ellipse, Polygon } _activeShape = NONE;

/* Enumeracion Para el Macro Linea>> Que Representa Funcion setlinestyle(Estilo,Trama,Grosor) */
enum Estilos_De_Linea { Continua, Punteada, Centrada, Guiones };
enum Grosor_De_Linea { Fina, Gruesa = 3 };

/* Enumeracion Para el Macro Relleno>> Que Representa Funcion setfillstyle(Trama,Color)*/
enum Tramas_De_Relleno {
    Vacio, Solido,
    Ln_Hor,
    Ln_Dia, Ln_Dia_G,
    Ln_Dia_I_G, Ln_Dia_I,
    Cuadricula, X_Cuadricula,
    Intervalo,
    Punteado, Punteado_C
};

/* Estructura que Simula una Clase con Atributos Predeterminados para en Control de Estilo de los Botones */
struct ButtonStyle {
    Graph bkColor, lineColor;
    Graph lblColor, lineStyle;
} btnStyle[2] = {
        /* False */             /* True */
    { 20, 0, 0, Gruesa } , { 40, 47, 15, Fina }
};

/* Estructura que Contiene Los Limites de Movimiento del Cursor cuando mueve una Figura*/
struct CursorLimitMovement {
    ControlEje x1, y1, x2, y2;
} Limit[2] = {
        /* False */             /* True */
    { 0, 0, 1024, 768 } , { 50, 40, 900, 707 }
};

/* Variables Globales */
Boolean _xorMode = True;    /* Variable Para Controlar Modo XOR */
FILE *DataBase = NULL;
String DataBasePath = "C:/DataBase.txt";

/*Iniciando Modo Grafico 1024*768 A>> 256 Colores*/
int huge HighLevelXGA(void)
{
    return 4;
}

void InitGraph(void)
{
    Graph driver=DETECT, mode=0, error=0;
    /*detectgraph(&driver, &mode);*/

    /* Instalar Driver Para el Modo Grafico de Alto Nivel */
    installuserdriver("SVGA256", HighLevelXGA);
    initgraph(&driver, &mode, "");

    /* Validamos Si el Modo Grafico Inicio Sin Problemas */
    error = graphresult();
    if (error != grOk)
    {
        printf("Error Al Iniciar El Modo Grafico\nError #>> %s\n\n", grapherrormsg(error));
        system("Pause") , abort() ;
    } else {
        cleardevice();
        graphdefaults();
        setviewport(0, 0, getmaxx()+1, getmaxy()+1, 1);
    }
}