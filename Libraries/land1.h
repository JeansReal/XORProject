/*first landscape*/


void landscape1() 	{



/*Fondo de la imagen */
Relleno(Solido,2);
bar(876, 621,118, 129);
/*Cielo*/
Relleno(Solido,53);
bar(118, 129,876,200);
/*Relleno(Solido,25);
bar(118,200,876,222);*/
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
/*Relleno(Solido,54);
Draw(piedra1);
Relleno(Solido,54);
Draw(piedra2);
Relleno(Solido,54);
Draw(piedra3);*/

getch();
}