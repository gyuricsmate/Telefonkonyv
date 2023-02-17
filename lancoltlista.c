#include "lancoltlista.h"
#include "debugmalloc.h"

//Egy újabb listaelem fájl elejére történõ beszúrását végzõ függvény
listaelem *elore_beszur(listaelem* meglevoListaElsoEleme, bejegyzes ujelem){
    listaelem *ujelemPtr = (listaelem*)malloc(sizeof(listaelem));
    ujelemPtr->elem = ujelem;
    ujelemPtr->kovetkezo = meglevoListaElsoEleme;
    return ujelemPtr;
}

//Egy újabb listaelem fájl végére történõ beszúrását végzõ függvény
listaelem *hatra_beszur(listaelem* meglevoListaElsoEleme, bejegyzes ujelem){

    listaelem *ujelemPtr = (listaelem*) malloc(sizeof(listaelem));
    ujelemPtr->elem = ujelem;
    ujelemPtr->kovetkezo = NULL;
    if (meglevoListaElsoEleme == NULL){
        return ujelemPtr;
    }


    listaelem *utolsoElem = meglevoListaElsoEleme;

    while (utolsoElem->kovetkezo != NULL){
        utolsoElem = utolsoElem->kovetkezo;
    }

    utolsoElem->kovetkezo = ujelemPtr;

    return meglevoListaElsoEleme;
}

listaelem *mindent_torol(listaelem *eleje){
    while(eleje != NULL) {
        listaelem *kovi = eleje->kovetkezo;
        free(eleje);
        eleje = kovi;
    }
}

//Komplett törlõ algoritmus
listaelem *torol(listaelem *megLevoListaElsoEleme, listaelem *toroltelem){
    if (megLevoListaElsoEleme == NULL)
        return  NULL;

    //Elsõ elem törlése
    if (megLevoListaElsoEleme == toroltelem){
        listaelem *kovetkezoElem = megLevoListaElsoEleme->kovetkezo;
        free(megLevoListaElsoEleme);
        return kovetkezoElem;
    }

    //Elsõtõl különbözõ elem törlése
    listaelem *lemarado = NULL;
    listaelem *mozgo = megLevoListaElsoEleme ;
    while (mozgo != toroltelem){
        lemarado = mozgo;
        mozgo = mozgo->kovetkezo;
    }

    listaelem *kovetkezoElem = toroltelem->kovetkezo;
    free(toroltelem);
    lemarado->kovetkezo = kovetkezoElem;
    return megLevoListaElsoEleme;
}