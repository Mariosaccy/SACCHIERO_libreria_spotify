#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Canzone {
    char *titoloCanzone;
    char *nomeArtista;
    int minutiDurata;
    int secondiDurata;
};

void insermento(struct Canzone **canzoni, int index) {

    char *titoloCanzoneIn;
    char *nomeArtistaIn;
    int minutiDurataIn;
    int secondiDurataIn;

    printf("Insert titoloCanzoneIn: ");
    fgets(titoloCanzoneIn, 40, stdin);
    printf("Insert nomeArtistaIn: ");
    fgets(nomeArtistaIn, 40, stdin);
    printf("Insert minutiDurataIn: ");
    scanf("%d", &minutiDurataIn);
    printf("Insert secondiDurataIn: ");
    scanf("%d", &secondiDurataIn);

    canzoni[index]->titoloCanzone = titoloCanzoneIn;
    canzoni[index]->nomeArtista = nomeArtistaIn;
    canzoni[index]->minutiDurata = minutiDurataIn;
    canzoni[index]->secondiDurata = secondiDurataIn;
}

int main(void) {

    int scelta;

    struct Canzone **canzoni = (struct Canzone **) malloc(sizeof(struct Canzone*));
    int index = 0;

    do {
        printf("Benvenuto su spotify!\n");
        printf("1 -> Aggiungi canzone\n");
        printf("2 -> Visualizza libreria\n");
        printf("3 -> Esci\n");

        printf("la tua scelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1:
                insermento(canzoni, index);
                index++;
                canzoni = (struct Canzone **) realloc(canzoni, (index+1) * sizeof(struct Canzone*));
                break;

            case 2:

                break;

            case 3:

                break;

            default:
                printf("errore, input errato\n");
                break;
        }

    }while(scelta != 3);



    return 0;
}
