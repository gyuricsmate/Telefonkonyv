#include "lancoltlista.h"
#include "debugmalloc.h"

//Egy �jabb listaelem f�jl elej�re t�rt�n� besz�r�s�t v�gz� f�ggv�ny
listaelem *elore_beszur(listaelem* meglevoListaElsoEleme, bejegyzes ujelem){
    listaelem *ujelemPtr = (listaelem*)malloc(sizeof(listaelem));
    ujelemPtr->elem = ujelem;
    ujelemPtr->kovetkezo = meglevoListaElsoEleme;
    return ujelemPtr;
}

//Egy �jabb listaelem f�jl v�g�re t�rt�n� besz�r�s�t v�gz� f�ggv�ny
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

//Komplett t�rl� algoritmus
listaelem *torol(listaelem *megLevoListaElsoEleme, listaelem *toroltelem){
    if (megLevoListaElsoEleme == NULL)
        return  NULL;

    //Els� elem t�rl�se
    if (megLevoListaElsoEleme == toroltelem){
        listaelem *kovetkezoElem = megLevoListaElsoEleme->kovetkezo;
        free(megLevoListaElsoEleme);
        return kovetkezoElem;
    }

    //Els�t�l k�l�nb�z� elem t�rl�se
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