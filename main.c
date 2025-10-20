#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *titoloCanzone;
    char *nomeArtista;
    int minutiDurata;
    int secondiDurata;
}Canzone;

void insermento(Canzone **canzoni, int index) {

    canzoni[index] = malloc(sizeof(Canzone));
    if (!canzoni[index]) {
        perror("Errore malloc canzoni[index]");
        exit(1);
    }

    canzoni[index]->titoloCanzone = malloc(40);
    canzoni[index]->nomeArtista = malloc(40);

    getchar(); // consuma '\n' rimasto da scanf
    printf("Inserisci titoloCanzoneIn: ");
    fgets(canzoni[index]->titoloCanzone, 40, stdin);
    canzoni[index]->titoloCanzone[strcspn(canzoni[index]->titoloCanzone, "\n")] = '\0'; // rimuove newline

    printf("Inserisci nomeArtistaIn: ");
    fgets(canzoni[index]->nomeArtista, 40, stdin);
    canzoni[index]->nomeArtista[strcspn(canzoni[index]->nomeArtista, "\n")] = '\0';

    printf("Inserisci minutiDurataIn: ");
    scanf("%d", &canzoni[index]->minutiDurata);

    printf("Inserisci secondiDurataIn: ");
    scanf("%d", &canzoni[index]->secondiDurata);
}

void visualizza(Canzone **canzoni, int index) {
    Canzone *canzone = canzoni[index];
    printf("TitoloCanzone: %s, Nome artista: %s, Durata: %d:%d \n", canzone->titoloCanzone, canzone->nomeArtista, canzone->minutiDurata, canzone->secondiDurata );
}

int main(void) {

    int scelta;
    int index = 0;

    Canzone **canzoni = (Canzone **) malloc(sizeof(Canzone*));

    printf("Benvenuto su spotify!\n");

    do {
        scelta = 0;

        printf("/////////////////////\n");
        printf("1 -> Aggiungi canzone\n");
        printf("2 -> Visualizza librerie\n");
        printf("3 -> Esci\n");

        printf("la tua scelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1:
                insermento(canzoni, index);
                index++;
                canzoni = (Canzone **) realloc(canzoni, (index+1) * sizeof(Canzone*));
                break;

            case 2:
                if (index == 0) {
                    printf("Nessuna canzone nella libreria\n");
                } else {
                    for (int i = 0; i < index; i++) {
                        visualizza(canzoni, i);
                    }
                }
                break;

            case 3:

                printf("ucita\n");
                break;

            default:
                printf("errore, input errato\n");
                break;
        }

        getchar();
    }while(scelta != 3);

    free(canzoni); // libera la memoria

    return 0;
}
