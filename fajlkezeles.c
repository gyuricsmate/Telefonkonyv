#include "debugmalloc.h"
#include "lancoltlista.h"
#include <stdio.h>
#include <stdlib.h>
#include "bejegyzes.h"

listaelem* beolvasas(){
    listaelem* lista = NULL;
    FILE* fileolvas;
    fileolvas = fopen("kontaktok.nevjegy", "r");
    if (fileolvas != NULL) {
        char tmp1[50], tmp2[50], tmp3[50], tmp4[50];
        int sz = 0;
        sz += fscanf(fileolvas," %[^\n]s",tmp1);
        sz += fscanf(fileolvas," %[^\n]s",tmp2);
        sz += fscanf(fileolvas," %[^\n]s",tmp3);
        sz += fscanf(fileolvas," %[^\n]s",tmp4);
        while(sz == 4){
            bejegyzes temp;
            strcpy(temp.nev, tmp1);
            strcpy(temp.telefonszam, tmp2);
            strcpy(temp.lakcim, tmp3);
            strcpy(temp.egyeb, tmp4);
            lista = hatra_beszur(lista, temp);

            sz = 0;
            sz += fscanf(fileolvas," %[^\n]s",tmp1);
            sz += fscanf(fileolvas," %[^\n]s",tmp2);
            sz += fscanf(fileolvas," %[^\n]s",tmp3);
            sz += fscanf(fileolvas," %[^\n]s",tmp4);
        }
    }
    else {
        perror("Nem sikerült megnyitni a fájlt!");
        return NULL;
    }
    fclose(fileolvas);
    return lista;
}


void kiiras(listaelem *lista){
    FILE* fileolvas;
    fileolvas = fopen("kontaktok.nevjegy", "w");
    listaelem* mozgo = lista;
        if (fileolvas != NULL) {
            while(mozgo != NULL){
                fprintf(fileolvas, "%s\n", mozgo->elem.nev);
                fprintf(fileolvas, "%s\n", mozgo->elem.telefonszam);
                fprintf(fileolvas, "%s\n", mozgo->elem.lakcim);
                fprintf(fileolvas, "%s\n", mozgo->elem.egyeb);
                mozgo = mozgo->kovetkezo;
            }
        }
        else {
            perror("Nem sikerült megnyitni a fájlt!");
            return;
        }

        fclose(fileolvas);
}