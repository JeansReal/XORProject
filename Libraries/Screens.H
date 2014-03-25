/* Libreria que Contiene Esqueletos de Pantallas */

void Presentacion(void)
{
    #define Arco Linea(Continua, Gruesa, 45) , arc(521, 415, 9, 138, 67) , arc(521, 417, 9, 138, 67) ;

    ControlEje x=0, y=0, fino=0;
    Iteracion i=0, j=0;
    Bandera borde1=False, borde2=False;

    /* Android */
    setcolor(10);
    drawpoly(22,cabeza);
    drawpoly(32,cuerpezito);
    drawpoly(22,brazito);

    /* Ojito */
    circle(450,297,5);

    /* Apple */
    setcolor(53);
    drawpoly(11,hoja);
    drawpoly(44,manzana);
    
    /* gotas de la manzana */
    drawpoly(12,first_drop);   /* primera gota del pipi */
    drawpoly(9,second_drop);   /* segunda gota del pipi */
    drawpoly(9,third_drop);    /* tercera gota del pipi */


    /* Simulacion de Inundacion de Manzanita */

    /* Primer Arco */
    Arco;
    /* Tipo de Relleno para Simular el Corte del Arco */
    Relleno(Solido, 0);

    do {
        x++;

        /* Variables para Controlar el Movimiento de Cortado del arco!, Movimiento vertical del bar! */
        y += (x <= 24) ? -1 : (x >= 62) ? 1 : True ;
        
        /* Variable para Redimensionar el Bar cuando este se acerca a las hojas de la manzana */
        fino += (x >= 105) ? 1 : True ;

        /* Si el efecto recorrio todo el arco, reiniciar :) */
        (x == 118) ? x = y = fino = 0 : False ;

        /* Remarca el arco cada 19 cuadros para Simular efecto de caida */
        if ((x % 19) == 0)
            Arco;

        delay(28);

        /* Realiza el corte sobre el arco */
        bar(469+x, 365+y, 485-fino+x, 375+y);




        /* This Shit don't works properly */

        if (getpixel(586 + i, 495 + j) == 53)
            borde1 = True;
        if (getpixel(586 - i, 495 + j) == 53)
            borde2 = True;

        if ((borde1 == borde2) == True)
        {
            borde1 = borde2 = False;
            j++;
            i = 0;
        }

        /* si el color no es el borde de la manzana */
        if (getpixel(586 + i, 495 - j) != 53 )
            if (borde1 != True)
                putpixel(586 + i, 495 - j, 52); /* Derecha */
        if (getpixel(586 - i, 495 - j) != 53 )
            if (borde2 != True)
                putpixel(586 - i, 495 - j, 52); /* Izquierda */

        i++;

    } while (!kbhit()); /* Use a flag to stop iterations*/
}