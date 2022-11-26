/**
 * @file main.c
 * @authors Alessandro Bevilacqua, Michele Como, Vito De Tommaso.
 * @brief File contenente il programma principale e menu utente di selezione.
 * @version 1.0
 * @date 2022-07-27
 */


#include"adt.h"
#include"controlli.h"
#include"funzioni.h"
#include<stdio.h>
#include<stdlib.h>


/**
 * @brief Procedura per la selezione delle operazioni tramite menu utente.
 */
void menu();



/**
 * @brief Programma principale.
 */
int main()
{
    menu();
    printf("%s", "\nFine esecuzione!");

    return 0;
}



void menu()
{
    /// Rappresenta l'input da tastiera per la selezione del menu utente.
    char scelta[SIZE];
    /// Rappresenta l'input da tastiera: se =1 effettua la ripetizione del menu, se =0 effettua la terminazione del programma.
    char ripeti[SIZE];
    do
    {
        do
        {
            printf("%s", "\nBENVENUTO! Seleziona l'operazione desiderata: \n");
            printf("%s", "\n1. Acquisizione.");
            printf("%s", "\n2. Estrazione.");
            printf("%s", "\n3. Fusione.");
            printf("%s", "\n4. Duplicazione.");
            printf("%s", "\n5. Termina il programma.\n");
            scanf("%s", scelta);
        }while(controllascelta(scelta, 1, 5)==0);
        switch(atoi(scelta))
        {
            case 1:
            /// Funzionalità di dominio: acquisizione.
            stampa(acquisizione());
            break;
            case 2:
            /// Funzionalità di dominio: estrazione.
            estrazione();
            break;
            case 3:
            /// Funzionalità di dominio: fusione.
            fusione();
            break;
            case 4:
            /// Funzionalità di dominio: duplicazione.
            duplicazione();
            break;
            default:
            return;
        }
        do
        {
        printf("%s", "\nVuoi effettuare un'altra operazione? 1=SI, 0=NO\n");
        scanf("%s", ripeti);
        }while(controllascelta(ripeti, 0, 1)==0);
    }while(atoi(ripeti)==1);
    return;

}
