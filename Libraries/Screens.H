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

Boolean CanMoveRight(ControlEje x)
{
    
}

/* Funcion de Reforzamiento para el Marco, lo Divide por Partes para poder animarlo! */
enum Button DrawButton(ControlEje x1, ControlEje y1, ControlEje x2, ControlEje y2, Boolean Status, enum Button btnId)
{
    struct ButtonsStyle *btnStyle = NULL;
    Graph btnLineWidth = 0, btnLineStyle = 0;

    /* Selecciona el Estilo del Boton */
    switch (btnId)
    {
        case btnLine:       case btnRec:
        case btnCircle:     case btnEllipse:    case btnPolygon:
            btnStyle = btnFigStyle;
        break;

        case btnImages:     case btnXor:        case btnHule:
            btnStyle = btnMenuStyle;
        break;

        case btnRestore:
            btnStyle = btnRestoreStyle;
        break;

        case btnExit:
            btnStyle = btnExitStyle;
        break;

        case btnClean:
            btnStyle = btnCleanStyle;
        break;
    }

    (Status)  ? btnLineWidth = Fina   , btnLineStyle = Guiones  :
    (!Status) ? btnLineWidth = Gruesa , btnLineStyle = Continua : False ;

    /* Definiendo Estilo para Marco de Boton */
    Relleno(Solido, btnStyle[Status].bkColor);
    Linea(btnLineStyle, btnLineWidth, btnStyle[Status].lineColor);
    bar(x1, y1, x2, y2) , rectangle(x1, y1, x2, y2) ;


    /* Define Estilo, Dibujo y Etiquetas del Boton */
    Linea(Continua, btnLineWidth, btnStyle[Status].lblColor);

    (btnId == btnRestore) ? settextstyle(1, 1, 5) :
    (btnId == btnRec)     ? settextstyle(5, 0, 3) :
    (btnId == btnExit || btnId == btnClean)    ? settextstyle(1, 0, 1) : settextstyle(5, 0, 0) ;

    switch (btnId)
    {
        case btnLine:
            line(910,100,1010,60);
            outtextxy(925, 100, "Linea");
        break;

        case btnRec:
            rectangle(910,200,1010,266);
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

        case btnRestore:
            outtextxy(0, 170, "R e s t a u r a r");
        break;

        case btnImages:
            outtextxy(120, 710, "Imagen de Fondo");
        break;

        case btnXor:
            outtextxy(460, 710, "Modo");
        break;

        case btnHule:
            outtextxy(620, 710, "Figura de Hule");
        break;

        case btnExit:
            outtextxy(6, 0, "X");
        break;

        case btnClean:
            outtextxy(1008, 0, "L");
        break;
    }

    return btnId;
}

/* Funcion que Retorna el Evento del Boton */
enum Button ButtonEvents(Boolean Active, enum Button btnId)
{
    switch (btnId)
    {
        case btnLine:    return DrawButton(900,  40, 1020, 173, Active, btnLine);
        case btnRec:     return DrawButton(900, 173, 1020, 308, Active, btnRec);
        case btnCircle:  return DrawButton(900, 308, 1020, 441, Active, btnCircle);
        case btnEllipse: return DrawButton(900, 441, 1020, 574, Active, btnEllipse);
        case btnPolygon: return DrawButton(900, 574, 1020, 707, Active, btnPolygon);
        case btnRestore: return DrawButton(  3,  40,   50, 707, Active, btnRestore);
        case btnImages:  return DrawButton(100, 720,  400, 755, Active, btnImages);
        case btnXor:     return DrawButton(450, 720,  550, 755, Active, btnXor);
        case btnHule:    return DrawButton(600, 720,  850, 755, Active, btnHule);
        case btnExit:    return DrawButton(  1,   1,   20,  22, Active, btnExit);
        case btnClean:   return DrawButton(1002,  1, 1022,  22, Active, btnClean);
        default:         return NONE;
    }
}

/* Funcion que Realiza Animaciones de Botones */
enum Button HoverButton(ControlEje x, ControlEje y)
{
    enum Button static onHover = NONE, onChange = NONE;

    /* Si el Cursor esta sobre uno de los botones y el boton esta desactivado */

    /* Botones Laterales Derechos */
    if (x >= 900 && x <= 1024 && y >= 40 && y <= 707)
        (y >= 40  && y <= 173 && onHover != btnLine)    ? onHover = ButtonEvents(True, btnLine)    :
        (y >= 174 && y <= 308 && onHover != btnRec)     ? onHover = ButtonEvents(True, btnRec)     :
        (y >= 309 && y <= 441 && onHover != btnCircle)  ? onHover = ButtonEvents(True, btnCircle)  :
        (y >= 442 && y <= 574 && onHover != btnEllipse) ? onHover = ButtonEvents(True, btnEllipse) :
        (y >= 575 && y <= 707 && onHover != btnPolygon) ? onHover = ButtonEvents(True, btnPolygon) : NONE ;
    /* Botones Inferiores */
    else if (x >= 100 && x <= 850 && y >= 720 && y <= 755)
        (x >= 100 && x <= 400 && onHover != btnImages)  ? onHover = ButtonEvents(True, btnImages)  :
        (x >= 450 && x <= 550 && onHover != btnXor)     ? onHover = ButtonEvents(True, btnXor)     :
        (x >= 600 && x <= 850 && onHover != btnHule)    ? onHover = ButtonEvents(True, btnHule)    :
        (x >  400 && x <  450 || x > 550 && x < 600)    ? onHover = NONE                           : NONE ;
    /* Boton Lateral Izquierdo */
    else if (x >= 3 && x <= 50 && y >= 40 && y <= 707)
        (onHover != btnRestore)                         ? onHover = ButtonEvents(True, btnRestore) : NONE ;
    /* Botones Superiores */
    else if (x >= 1 && x <= 1022 && y >= 1 && y <= 22)
        (x >= 1    && x <= 20   && onHover != btnExit)  ? onHover = ButtonEvents(True, btnExit)    :
        (x >= 1002 && x <= 1022 && onHover != btnClean) ? onHover = ButtonEvents(True, btnClean)   :
        (x >  20   && x <  1002)                        ? onHover = NONE                           : NONE ;
    else
        onHover = NONE;

    /* Si se Selecciona otro Boton */
    if (onHover != onChange)
    {
        ButtonEvents(False, onChange);
        onChange = onHover;
    }

    return onHover;
}

/* Funcion que Contiene el Marco Principal */
void Frame(void)
{
    Relleno(Solido, 23);
    bar(0, 0, 2, 708);       /* Parte Izquierda */
    bar(900,40,1024,768);    /* Parte Derecha */
    bar(0,0,1024,40);        /* Parte Arriba */
    bar(0,708,1024,768);     /* Parte Abajo */

    /* Parte Central */
    Relleno(Solido,15) , Linea(Continua, Gruesa, 0) ;
    bar(53, 41, 897, 707) , rectangle(50, 40, 900, 707) ;

    /*Botones de Eleccion de Figura*/
    DrawButton(900,  40, 1020, 173, False, btnLine);
    DrawButton(900, 173, 1020, 308, False, btnRec);
    DrawButton(900, 308, 1020, 441, False, btnCircle);
    DrawButton(900, 441, 1020, 574, False, btnEllipse);
    DrawButton(900, 574, 1020, 707, False, btnPolygon); 

    /* Boton Restaurar */
    DrawButton(3, 40, 50, 707, False, btnRestore);

	/*Botones de Barra de Modificacion*/
    DrawButton(100, 720, 400, 755, False, btnImages);
	DrawButton(450, 720, 550, 755, False, btnXor);
	DrawButton(600, 720, 850, 755, False, btnHule);

    /*Exit and Clean*/
    DrawButton(   1, 1,   20, 22, False, btnExit);
    DrawButton(1002, 1, 1022, 22, False, btnClean);
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