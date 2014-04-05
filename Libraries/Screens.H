/* Libreria que Contiene Esqueletos de Pantallas y Funciones de Animacion */

void Presentacion(void)
{
    #define Arco Linea(Continua, Gruesa, 45) , arc(521, 415, 9, 138, 67) , arc(521, 417, 9, 138, 67) ;

    ControlEje x=0, y=0, fino=0;
    Iteracion i=0, j=0;
    Boolean borde1 = False, borde2 = False;

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

/* Funcion de Reforzamiento para el Marco, lo Divide por Partes para poder animarlo! */
enum ActiveButton DrawButton(ControlEje x1, ControlEje y1, ControlEje x2, ControlEje y2, Boolean Status, enum ActiveButton btnId)
{
    Relleno(Solido, btnStyle[Status].bkColor);
    Linea(Continua, btnStyle[Status].lineStyle, btnStyle[Status].lineColor);

    bar(x1, y1, x2, y2) , rectangle(x1, y1, x2, y2) ;

    setcolor(btnStyle[Status].lblColor);
    settextstyle(5, 0, 0);

    /* Dibujos y Etiquetas Representativas de las Figuras */
    switch (btnId)
    {
        case btnLine:
            line(910,100,1010,60);
            outtextxy(925, 100, "Linea");
        break;

        case btnRec:
            rectangle(910,200,1010,266);
            settextstyle(5, 0, 3);
            outtextxy(910, 265, "Rectangulo");
        break;

        case btnCircle:
            circle(960,357,33);
            outtextxy(920, 385, "Circulo");
        break;

        case btnEllipse:
            ellipse(960,480,0,360,50,25);
            outtextxy(920, 515, "Ellipse");
        break;

        case btnPolygon:
            moveto(910,660) , lineto(960,580) , lineto(1010,660) , lineto(910,660) ;
            outtextxy(905, 655, "Poligono");
        break;
    }

    return btnId;
}

/* Funcion que Realiza Animaciones de Botones */
enum ActiveButton SelectedButton(ControlEje x, ControlEje y)
{
    enum ActiveButton onHover = NONE;

   /* Si el Cursor esta encima de algun boton */
    if (x >= 900 && x <= getmaxx())
        if (y >= 40 && y <= 173)
            onHover = DrawButton(900, 40, 1020, 173, True, btnLine);
        else if (y >= 174 && y <= 308)
            onHover = DrawButton(900, 173, 1020, 308, True, btnRec);
        else if (y >= 309 && y <= 441)
            onHover = DrawButton(900, 308, 1020, 441, True, btnCircle);
        else if (y >= 442 && y <= 574)
            onHover = DrawButton(900, 441, 1020, 574, True, btnEllipse);
        else if (y >= 575 && y <= 707)
            onHover = DrawButton(900, 574, 1020, 707, True, btnPolygon);

    return onHover;
}

/* Funcion que Retorna la Figura Seleccionada*/
enum ActiveShape SelectedShape(ControlEje x, ControlEje y)
{
    /* Si EL Cursor esta dentro del boton de alguna figura y no hay figura activas */
    if (x >= 900 && x <= getmaxx())
        if (y >= 40 && y <= 173)
        {
            DrawButton(900, 40, 1020, 173, False, Line);
            return Line;
        }
        else if (y >= 174 && y <= 308)
        {
            DrawButton(900, 173, 1020, 308, False, Rectangle);
            return Rectangle;
        }
        else if (y >= 309 && y <= 441)
        {
            DrawButton(900, 308, 1020, 441, False, Circle);
            return Circle;
        }
        else if (y >= 442 && y <= 574)
        {
            DrawButton(900, 441, 1020, 574, False, Ellipse);
            return Ellipse;
        }
        else if (y >= 575 && y <= 707)
        {
            DrawButton(900, 574, 1020, 707, False, Polygon);
            return Polygon;
        }

    return NONE;    /* Si Presiono Enter Sobre Otro Espacio */
}

/* Funcion que Contiene el Marco Principal */
void Frame(void)
{
    Relleno(Solido, 23);

    bar(900,40,getmaxx()+1,getmaxy()+1);    /* Parte Derecha */
    bar(0,0,getmaxx()+1,40);                /* Parte Arriba */
    bar(0,708,getmaxx()+1,getmaxy()+1);     /* Parte Abajo */

    /* Restaurar */
    Relleno(Solido,36);
    bar(0,40,50,707);

    /* Parte Central */
    Relleno(Solido,15);
    bar(50,40,900,707);

    /*Botones de Eleccion de Figura*/
    DrawButton(900, 40,  1020, 173, False, btnLine);
    DrawButton(900, 173, 1020, 308, False, btnRec);
    DrawButton(900, 308, 1020, 441, False, btnCircle);
    DrawButton(900, 441, 1020, 574, False, btnEllipse);
    DrawButton(900, 574, 1020, 707, False, btnPolygon);
	
	/*Botones de Barra de Modificacion*/
    Relleno(Solido,20);
	bar(100,720,400,755);/*Boton de seleccion de las imagenes*/
	bar(450,720,550,755);/*Boton de Seleccion de modos*/
	bar(600,720,850,755);/*Boton de Modificacion de las figuras*/

    /*Exit and Clean*/
    bar(0,0,15,15);

    /* Borde Botones Inferiores */
    Linea(Continua, Gruesa, 0);
	rectangle(100,720,400,755);
	rectangle(450,720,550,755);
	rectangle(600,720,850,755);

    /*Enunciados*/
    settextstyle(5, 0, 0);
    outtextxy(120, 710, "Imagen de Fondo");
    outtextxy(460, 710, "Modo");
    outtextxy(620, 710, "Figura de Hule");
}

void Landscape1(void)
{
    /*Fondo de la imagen */
    Relleno(Solido,2);
    bar(876, 621,118, 129);
    /*Cielo*/
    Relleno(Solido,53);
    bar(118, 129,876,200);
    /*Musgo*/
	Relleno(Solido,2);
    bar(118,200,876,222);
    /*Puente*/
    Relleno(Solido,7);
    Fill(puente);
    Relleno(Solido,54);
    Fill(orilla_del_Rio);
    Relleno(Solido,25);
    Fill(borde_puente);
    Relleno(Solido,55);
    Fill(rio);
    Relleno(Solido,23);
    Fill(sombra);
    Relleno(Solido,53);
    Fill(behind_bridge);
    Relleno(Solido,6);
    Fill(colina1);
    Relleno(Solido,120);
    Fill(colina2); 
    Relleno(Solido,240);
    Fill(piedra1);
    Relleno(Solido,240);
    Fill(piedra2);
    Relleno(Solido,240);
    Fill(piedra3);

    getch();
}