/* Libreria que Contiene Funciones Gracias Para Figuras en Modo XOR */

/* Midpoint Algorithm Applied to Generate Circle and Ellipse */

/* Verifica si Esta Fuera del Marco de Trabajo */
Boolean IsOutsideWorkArea(ControlEje x, ControlEje y)
{
    if (x > 53 && x < 895 && y > 41 && y < 707)
        return False;
    else
        return True;
}

/* Cursor XOR */
void DrawCursor(ControlEje x, ControlEje y)
{
    PixelXor(x, y);                   /* Centro */
    PixelXor(x, y - 10); /* Arriba */
    PixelXor(x + 10, y); /* Derecha */
    PixelXor(x, y + 10); /* Abajo */
    PixelXor(x - 10, y); /* Izquierda */
}

/* Circulo XOR */
void DrawCircle(ControlEje x, ControlEje y, short radio)
{
    short i = 0, dm = radio;

    for (; i < radio; i++)
    {
        if (dm < 0)
            dm += 2 * i + 1;
        else {
            radio--;
            /* dm += (2 * i) - (2 * radio);    Calculo Rapido, Perdida de Precision en Valores */
            dm += 2 * (i - radio) + 1;      /* Calculo Algo lento, Mejoria De Precision Considerable */
        }

        PixelXor(x + i, y + radio);
        PixelXor(x - radio, y - i);
        PixelXor(x + radio, y - i);
        PixelXor(x - radio, y + i);
        PixelXor(x + radio, y + i);
        PixelXor(x - i, y - radio);
        PixelXor(x + i, y - radio);
        PixelXor(x - i, y + radio);
    }
}

/* Linea XOR */
void DrawLine(ControlEje x, ControlEje y, unsigned short largo)
{
    Iteracion i=0;

    PixelXor(x, y);         /* Centro */

    for (i = 0; i < largo; ++i)
    {
        PixelXor(x + i, y); /* Derecha */
        PixelXor(x - i, y); /* Izquierda */
    }
}

/* Poligono: Triangulo XOR */
void DrawTriangle(ControlEje x, ControlEje y, unsigned short Perimetro)
{
    Iteracion i=0;

    PixelXor(x, y);                 /* Punta */

    for (i = 0; i < Perimetro; ++i)
    {
        PixelXor(x + i, y + i);     /* Lateral Izquierdo */
        PixelXor(x - i, y + i);     /* Lateral Derecho */
    }

    DrawLine(x, y + i, Perimetro);  /* Base */
}

/* Rectangulo XOR */
void DrawRectangle(ControlEje x, ControlEje y, unsigned short Perimetro)
{
    Iteracion i=0;
    y -= Perimetro / 2;

    DrawLine(x, y, Perimetro);          /* Arriba */

    for (i = 0; i < Perimetro; ++i)
    {
        PixelXor(x - Perimetro, y + i); /* Lateral Izquierdo*/
        PixelXor(x + Perimetro, y + i); /* Lateral Derecho */
    }

    DrawLine(x, y + (i - 1), Perimetro); /* Abajo */
}

/* Ellipse XOR */
void DrawEllipse(ControlEje x, ControlEje y, short xRadio, short yRadio)
{
    long xRadioPow = pow(xRadio, 2);
    long yRadioPow = pow(yRadio, 2);

    long xRadioPowDouble = 2 * xRadioPow;
    long yRadioPowDouble = 2 * yRadioPow;

    long dmX = 0;
    long dmY = xRadioPowDouble * yRadio;
    long dm = (long) (0.5 + yRadioPow - (xRadioPow * yRadio) + (0.25 * xRadioPow));

    for (xRadio = 0; dmX < dmY; ++xRadio, dmX += yRadioPowDouble)
    {
        if (dm < 0)
            dm += yRadioPow + dmX;
        else {
            yRadio--;
            dmY -= xRadioPowDouble;
            dm += yRadioPow + dmX - dmY;
        }

        PixelXor(x + xRadio, y + yRadio);
        PixelXor(x - xRadio, y + yRadio);
        PixelXor(x + xRadio, y - yRadio);
        PixelXor(x - xRadio, y - yRadio);
    }

    /* Calculando Cierre de Ellipse */
    dm = (long)(0.5 + yRadioPow * (xRadio + 0.5) * (xRadio + 0.5) +
                      xRadioPow * (yRadio - 1) * (yRadio - 1) - xRadioPow * yRadioPow);

    for (; yRadio > 0; --yRadio, dmY -= xRadioPowDouble)
    {
        if (dm > 0)
                dm += xRadioPow - dmY;
        else {
            xRadio++;
            dmX += yRadioPowDouble;
            dm += xRadioPow - dmY + dmX;
        }

        PixelXor(x + xRadio, y + yRadio);
        PixelXor(x - xRadio, y + yRadio);
        PixelXor(x + xRadio, y - yRadio);
        PixelXor(x - xRadio, y - yRadio);
    }
}