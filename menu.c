#include "menu.h"
#include "debugmalloc.h"
#include "kereses.h"
#include "lancoltlista.h"
#include "bejegyzes.h"

listaelem *fomenu(listaelem* lista){
    int valasztottMenupont = 0;
    printf("->");
    printf("A f�men�ben vagy, v�lassz men�pontot!\n[1] �j n�vjegy l�trehoz�sa\n"
           "[2] Megl�v� n�vjegy szerkesz�se\n[3] N�vjegy t�rl�se\n[4] Keres�s\n[9] Kil�p�s a programb�l\n");
    scanf(" %d", &valasztottMenupont);
    while (valasztottMenupont != 9) {
        switch (valasztottMenupont) {
            case 1: lista = ujnevjegy(lista); break;
            case 2: lista = szerkesztes(lista); break;
            case 3: lista = torles(lista); break;
            case 4: kereses(lista); break;
            case 9: /*mindent_torol(lista); exit(0);*/ break;
            default: printf("Nincs ilyen men�pont!\n"); break;
        }
        printf("A f�men�ben vagy, v�lassz men�pontot!\n[1] �j n�vjegy l�trehoz�sa\n"
               "[2] Megl�v� n�vjegy szerkesz�se\n[3] N�vjegy t�rl�se\n[4] Keres�s\n[9] Kil�p�s a programb�l\n");
        printf("->");
        scanf(" %d", &valasztottMenupont);
    }
    return lista;
}

listaelem *ujnevjegy(listaelem* lista){
    printf("�j n�vjegy hozz�ad�sa enterrel elv�lasztva:\n");
    printf("P�lda: Kiss B�la    06701234567    8764, Szeged, J�zsef Antal u. 23    Egy�b adat(ok)\n");
    bejegyzes bejegyzes;
    scanf(" %[^\n]s", bejegyzes.nev);
    scanf(" %[^\n]s", bejegyzes.telefonszam);
    scanf(" %[^\n]s", bejegyzes.lakcim);
    scanf(" %[^\n]s", bejegyzes.egyeb);
    lista = hatra_beszur(lista, bejegyzes);
    return lista;
}

listaelem *szerkesztes(listaelem* lista){
    printf("Ebben a men�pontban szerkesztheted egy n�vjegy adatait.\nEzut�n visszat�rhetsz a f�men�be, vagy kil�phetsz a programb�l.\nAdd meg, melyik adat alapj�n szeretn�l keresni!\n [1] N�v \n [2] Telefonsz�m \n [3] Lakc�m \n [4] egy�b\n");
    int str;
    scanf("%d", &str);
    char str2[50];
    printf("Add meg a keresett �rt�ket!\n");
    scanf(" %[^\n]s", str2);
    listaelem* edited = keres(lista, str2, str);
    if(edited != NULL){
        printf("Tal�lat: %s\t%s\t%s\t%s \n",edited->elem.nev,edited->elem.telefonszam,edited->elem.lakcim,edited->elem.egyeb);
        lista = torol(lista, edited);
        printf("Add meg az elem �j adat 4-es�t!\n");
        bejegyzes bejegyzes;
        scanf(" %[^\n]s", bejegyzes.nev);
        scanf(" %[^\n]s", bejegyzes.telefonszam);
        scanf(" %[^\n]s", bejegyzes.lakcim);
        scanf(" %[^\n]s", bejegyzes.egyeb);
        lista = hatra_beszur(lista, bejegyzes);
        printf("A programb�l val� kil�p�skor lesz elmentve a kiv�lasztott elem m�dos�tott v�ltozata! \n \n");
    } else {
        printf("Nincs megfelel� tal�lat :(\n\n");
    }
    return lista;
}

listaelem *torles(listaelem* lista){
    printf("Ebben a men�pontban t�r�lhetsz egy n�vjegyet.\nEzut�n visszat�rhetsz a f�men�be, vagy kil�phetsz a programb�l.\nAdd meg, melyik adat alapj�n szeretn�l keresni!\n [1] N�v \n [2] Telefonsz�m \n [3] Lakc�m \n [4] egy�b\n");
    int str;
    scanf("%d", &str);
    char str2[50];
    printf("Add meg a keresett �rt�ket!\n");
    scanf(" %[^\n]s", str2);
    listaelem* eredmeny = keres(lista, str2, str);
    if(eredmeny==NULL){
        printf("Nincs ilyen nevjegy!\n\n");
    }else{
        printf("A tal�lt n�vjegy:\n");
        printf("\n%s\t%s\t%s\t%s \n", eredmeny->elem.nev, eredmeny->elem.telefonszam, eredmeny->elem.lakcim, eredmeny->elem.egyeb);
        lista = torol(lista, eredmeny);
        printf("\nA programb�l val� kil�p�ssel t�rl�dik a kiv�lasztott elem! \n \n");
    }
    return lista;
}

void kereses(listaelem* lista){
    printf("Ebben a men�pontban kilist�zhatod a k�v�nt n�vjegy adatait.\nEzut�n visszat�rhetsz a f�men�be, vagy kil�phetsz a programb�l.\nAdd meg, melyik adat alapj�n szeretn�l keresni!\n [1] N�v \n [2] Telefonsz�m \n [3] Lakc�m \n [4] egy�b\n");
    int str;
    scanf("%d", &str);
    char str2[50];
    printf("Add meg a keresett �rt�ket!\n");
    scanf(" %[^\n]s", str2);
    listaelem* eredmeny = keres(lista, str2, str);
    if(eredmeny==NULL){
        printf("Nincs ilyen nevjegy!");
    }else{
        printf("%s\t%s\t%s\t%s \n", eredmeny->elem.nev, eredmeny->elem.telefonszam, eredmeny->elem.lakcim, eredmeny->elem.egyeb);
    }
}
