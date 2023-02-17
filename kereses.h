#ifndef NAGY_HAZI_KERESES_H
#define NAGY_HAZI_KERESES_H

enum keresesOpciok{
    NEV = 1, TELEFONSZAM = 2, LAKCIM = 3, EGYEB = 4
};

bool hasonlo(char *str, char* minta);
listaelem *keres(listaelem *eleje, char* k, enum keresesOpciok opcio);

#endif