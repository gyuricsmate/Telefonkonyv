#include "debugmalloc.h"
#include "string.h"
#include "lancoltlista.h"
#include "kereses.h"

bool hasonlo(char *str, char* minta){
    char mintamas[50];
    strcpy(mintamas, minta);
    char *db = strtok(mintamas, "*");
    while(db != NULL){
        str = strstr(str, db);
        if(str == NULL){
            return false;
        }

        str += strlen(db);
        db = strtok(NULL, "*");
    }
    return true;
}

listaelem *keres(listaelem *eleje, char* k, enum keresesOpciok opcio){
    listaelem *mozgo = eleje;
    switch (opcio) {
        case NEV:
            while(mozgo!= NULL){
                if(hasonlo(mozgo->elem.nev, k))
                    return mozgo;
                mozgo =mozgo->kovetkezo;
            }
            return NULL;
        case TELEFONSZAM:
            while(mozgo!= NULL) {
                if (hasonlo(mozgo->elem.telefonszam, k))
                    return mozgo;
                mozgo =mozgo->kovetkezo;
            }
            return NULL; break;
        case LAKCIM:
            while(mozgo!= NULL) {
                if (hasonlo(mozgo->elem.lakcim, k))
                    return mozgo;
                mozgo =mozgo->kovetkezo;
            }
            return NULL; break;
        case EGYEB:
            while(mozgo!= NULL) {
                if (hasonlo(mozgo->elem.lakcim, k))
                    return mozgo;
                mozgo =mozgo->kovetkezo;
            }
            return NULL; break;
        default: return NULL;
    }

}