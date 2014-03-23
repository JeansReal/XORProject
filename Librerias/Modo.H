/* Libreria que Contiene Funciones y Enumeraciones para el Modo Grafico */

/* Declaracion de Nuevos Tipos de Datos */
typedef int Graph;
typedef short Iteracion, ControlEje, Color, Bandera;

/* Enumeraciones Para Control de Funciones y Validaciones */
enum Boolean { True, False };

/* Enumeracion Para el Macro Linea>> Que Representa Funcion setlinestyle(Estilo,Trama,Grosor) */
enum Estilos_De_Linea { Continua, Punteada, Centrada, Guiones };
enum Grosor_De_Linea { Fina, Gruesa = 3 };

/* Enumeracion Para el Macro Relleno>> Que Representa Funcion setfillstyle(Trama,Color)*/
enum Tramas_De_Relleno {
    Vacio, Solido, 
    L_Hor, 
    L_Dia, L_Dia_G,
    L_Dia_I_G, L_Dia_I,
    Cuadricula, X_Cuadricula,
    Intervalo, 
    Punteado, Punteado_C
};

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
    installuserdriver("SVGA256", HighLevelXGA());
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