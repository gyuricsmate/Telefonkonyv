#ifndef NAGY_HAZI_LANCOLTLISTA_H
#define NAGY_HAZI_LANCOLTLISTA_H
#include "bejegyzes.h"
#include "debugmalloc.h"


typedef struct listaelem{
    bejegyzes elem;
    struct listaelem *kovetkezo;
} listaelem;


//F�ggv�ny defin�ci�k

//El�re besz�r�s
//Menet k�zben j�ttem r�, hogy ebben a feladatban nem sz�ks�ges a f�jl elej�re besz�r�s, de ha m�r dolgoztam vele itt hagyom :)
listaelem *elore_beszur(listaelem* meglevoListaElsoEleme, bejegyzes ujelem);

//H�tra besz�r�s
listaelem *hatra_beszur(listaelem* meglevoListaElsoEleme, bejegyzes ujelem);

//Komplett t�rl� algoritmus
listaelem *torol(listaelem *megLevoListaElsoEleme, listaelem *toroltelem);

listaelem *mindent_torol(listaelem *eleje);

#endif