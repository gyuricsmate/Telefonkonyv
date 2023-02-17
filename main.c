#include "lancoltlista.h"
#include "fajlkezeles.h"
#include "menu.h"
#include "kereses.h"
#include "debugmalloc.h"
#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif

int main() {
    #ifdef _WIN32
        SetConsoleCP(1250);
        SetConsoleOutputCP(1250);
    #endif

    listaelem *lista;
    lista = beolvasas();
    lista = fomenu(lista);
    bejegyzes elem;
    kiiras(lista);

    mindent_torol(lista);
    return 0;
}