/* Libreria que Contiene Funciones Gracias Para Figuras en Modo XOR */

/* Circulo XOR */
void DrawCircle(ControlEje x, ControlEje y, short radio)
{
    short i = 0, dm = radio;

    for (; i < radio; i++)
    {
        if (dm < 0)
            dm += (2 * i + 1);
        else {
            radio--;
            dm += (2 * i) - (2 * radio);
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

/* Triangulo XOR */
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

/* Ellipse XOR 

for (int y = -radio; y < radio; ++y)
{
    for (int x = -radio; x <= radio; ++i)
    {
        if (x*x+y*y <= radio*radio)
        {
            putpixel(ox+x,oy+y);
        }
    }
}



for (int y = -height; y < height; ++y)
{
    for (int x = -width; x <= width; ++i)
    {
        if (x*x*height*height + y*y*width*width <= height*height*width*width)
        {
            putpixel(ox+x,oy+y);
        }
    }
}


/* Poligono XOR */