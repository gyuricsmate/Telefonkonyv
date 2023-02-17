#include "menu.h"
#include "debugmalloc.h"
#include "kereses.h"
#include "lancoltlista.h"
#include "bejegyzes.h"

listaelem *fomenu(listaelem* lista){
    int valasztottMenupont = 0;
    printf("->");
    printf("A fõmenüben vagy, válassz menüpontot!\n[1] Új névjegy létrehozása\n"
           "[2] Meglévõ névjegy szerkeszése\n[3] Névjegy törlése\n[4] Keresés\n[9] Kilépés a programból\n");
    scanf(" %d", &valasztottMenupont);
    while (valasztottMenupont != 9) {
        switch (valasztottMenupont) {
            case 1: lista = ujnevjegy(lista); break;
            case 2: lista = szerkesztes(lista); break;
            case 3: lista = torles(lista); break;
            case 4: kereses(lista); break;
            case 9: /*mindent_torol(lista); exit(0);*/ break;
            default: printf("Nincs ilyen menüpont!\n"); break;
        }
        printf("A fõmenüben vagy, válassz menüpontot!\n[1] Új névjegy létrehozása\n"
               "[2] Meglévõ névjegy szerkeszése\n[3] Névjegy törlése\n[4] Keresés\n[9] Kilépés a programból\n");
        printf("->");
        scanf(" %d", &valasztottMenupont);
    }
    return lista;
}

listaelem *ujnevjegy(listaelem* lista){
    printf("Új névjegy hozzáadása enterrel elválasztva:\n");
    printf("Példa: Kiss Béla    06701234567    8764, Szeged, József Antal u. 23    Egyéb adat(ok)\n");
    bejegyzes bejegyzes;
    scanf(" %[^\n]s", bejegyzes.nev);
    scanf(" %[^\n]s", bejegyzes.telefonszam);
    scanf(" %[^\n]s", bejegyzes.lakcim);
    scanf(" %[^\n]s", bejegyzes.egyeb);
    lista = hatra_beszur(lista, bejegyzes);
    return lista;
}

listaelem *szerkesztes(listaelem* lista){
    printf("Ebben a menüpontban szerkesztheted egy névjegy adatait.\nEzután visszatérhetsz a fõmenübe, vagy kiléphetsz a programból.\nAdd meg, melyik adat alapján szeretnél keresni!\n [1] Név \n [2] Telefonszám \n [3] Lakcím \n [4] egyéb\n");
    int str;
    scanf("%d", &str);
    char str2[50];
    printf("Add meg a keresett értéket!\n");
    scanf(" %[^\n]s", str2);
    listaelem* edited = keres(lista, str2, str);
    if(edited != NULL){
        printf("Találat: %s\t%s\t%s\t%s \n",edited->elem.nev,edited->elem.telefonszam,edited->elem.lakcim,edited->elem.egyeb);
        lista = torol(lista, edited);
        printf("Add meg az elem új adat 4-esét!\n");
        bejegyzes bejegyzes;
        scanf(" %[^\n]s", bejegyzes.nev);
        scanf(" %[^\n]s", bejegyzes.telefonszam);
        scanf(" %[^\n]s", bejegyzes.lakcim);
        scanf(" %[^\n]s", bejegyzes.egyeb);
        lista = hatra_beszur(lista, bejegyzes);
        printf("A programból való kilépéskor lesz elmentve a kiválasztott elem módosított változata! \n \n");
    } else {
        printf("Nincs megfelelõ találat :(\n\n");
    }
    return lista;
}

listaelem *torles(listaelem* lista){
    printf("Ebben a menüpontban törölhetsz egy névjegyet.\nEzután visszatérhetsz a fõmenübe, vagy kiléphetsz a programból.\nAdd meg, melyik adat alapján szeretnél keresni!\n [1] Név \n [2] Telefonszám \n [3] Lakcím \n [4] egyéb\n");
    int str;
    scanf("%d", &str);
    char str2[50];
    printf("Add meg a keresett értéket!\n");
    scanf(" %[^\n]s", str2);
    listaelem* eredmeny = keres(lista, str2, str);
    if(eredmeny==NULL){
        printf("Nincs ilyen nevjegy!\n\n");
    }else{
        printf("A talált névjegy:\n");
        printf("\n%s\t%s\t%s\t%s \n", eredmeny->elem.nev, eredmeny->elem.telefonszam, eredmeny->elem.lakcim, eredmeny->elem.egyeb);
        lista = torol(lista, eredmeny);
        printf("\nA programból való kilépéssel törlõdik a kiválasztott elem! \n \n");
    }
    return lista;
}

void kereses(listaelem* lista){
    printf("Ebben a menüpontban kilistázhatod a kívánt névjegy adatait.\nEzután visszatérhetsz a fõmenübe, vagy kiléphetsz a programból.\nAdd meg, melyik adat alapján szeretnél keresni!\n [1] Név \n [2] Telefonszám \n [3] Lakcím \n [4] egyéb\n");
    int str;
    scanf("%d", &str);
    char str2[50];
    printf("Add meg a keresett értéket!\n");
    scanf(" %[^\n]s", str2);
    listaelem* eredmeny = keres(lista, str2, str);
    if(eredmeny==NULL){
        printf("Nincs ilyen nevjegy!");
    }else{
        printf("%s\t%s\t%s\t%s \n", eredmeny->elem.nev, eredmeny->elem.telefonszam, eredmeny->elem.lakcim, eredmeny->elem.egyeb);
    }
}
