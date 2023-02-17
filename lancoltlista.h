#ifndef NAGY_HAZI_LANCOLTLISTA_H
#define NAGY_HAZI_LANCOLTLISTA_H
#include "bejegyzes.h"
#include "debugmalloc.h"


typedef struct listaelem{
    bejegyzes elem;
    struct listaelem *kovetkezo;
} listaelem;


//Függvény definíciók

//Elõre beszúrás
//Menet közben jöttem rá, hogy ebben a feladatban nem szükséges a fájl elejére beszúrás, de ha már dolgoztam vele itt hagyom :)
listaelem *elore_beszur(listaelem* meglevoListaElsoEleme, bejegyzes ujelem);

//Hátra beszúrás
listaelem *hatra_beszur(listaelem* meglevoListaElsoEleme, bejegyzes ujelem);

//Komplett törlõ algoritmus
listaelem *torol(listaelem *megLevoListaElsoEleme, listaelem *toroltelem);

listaelem *mindent_torol(listaelem *eleje);

#endif