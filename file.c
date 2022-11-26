/**
 * @file file.c
 * @authors Alessandro Bevilacqua, Michele Como, Vito De Tommaso
 * @brief Implementazione della libreria riguardante la gestione dei file.
 * @version 1.0
 * @date 2022-07-27
 * Con questa libreria possiamo aprire, chiudere, leggere e scrivere file ad accesso sequenziale.
 * L'acquisizione dei dati avviene mediante l'uso di una struttura dinamica a lista concatenata.
 */
#include"file.h"
#include"controlli.h"
#include<string.h>




/**
 * @brief apre un file in modalità lettura.
 * @return file aperto oppure puntatore NULL se l'operazione non è andata a buon fine.
 */


 /**
     @brief Suddivide ogni riga del file in token in occorrenza del carattere '&' e salva i campi in una struttura dinamica gestita come lista.
     @pre lista vuota e file aperto correttamente.
     @post lista piena.

 */
ListaPtr* leggi_file(ListaPtr* tPtr, FILE * file)
{
    int identificativo;
    char nomecorso[SIZE];
    char nomedocente[SIZE];
    int numerocfu;
    int numerostudenti;
    rewind(file);
    /// Stringa relativa ad ogni riga del file (quindi ad ogni corso).
    char string[SIZE];
    /// Riga del file suddivisa in occorenza del carattere '&'.
    char *tokenPtr;
    while(!feof(file))
    {
        fgets(string, SIZE, file);
        /// Conta il numero di token suddivisi per ciascuna riga.
        unsigned cont=0;
        tokenPtr=strtok(string,"&");
        while(tokenPtr != NULL)
        {
            cont++;
            switch(cont)
            {
                case 1:
                identificativo=atoi(tokenPtr);
                break;
                case 2:
                ///PROGRAMMAZIONE DIFENSIVA CLASSE ARRAY: nomecorso deve avere lunghezza massima SIZE.
                if(controlla_lunghezza_stringa(nomecorso)==0)
                return NULL;
                strcpy(nomecorso, tokenPtr);
                break;
                case 3:
                ///PROGRAMMAZIONE DIFENSIVA CLASSE ARRAY: nomedocente deve avere lunghezza massima SIZE.
                if(controlla_lunghezza_stringa(nomedocente)==0)
                return NULL;
                strcpy(nomedocente, tokenPtr);
                break;
                case 4:
                numerocfu=atoi(tokenPtr);
                break;
                case 5:
                numerostudenti=atoi(tokenPtr);
                break;
            }
            tokenPtr = strtok(NULL, "&");
            }
            ///Inserisco un nuovo elemento al nodo della lista.
            tPtr=inseriscinodo(identificativo, nomecorso, nomedocente, numerocfu, numerostudenti, tPtr);
     }
     fclose(file);
     return tPtr;
}


/**
    @brief scrive sul file un corso completo di tutti i campi.
    @pre file aperto correttamente, struttura passata piena e avvalorata.
    @post corretta scrittura del file.

*/
void scrivi_file(FILE* file, int identificativo, char nomecorso[SIZE], char nomedocente[SIZE], int numerocfu, int numerostudenti, int*a_capo)
{
    if(*a_capo==0)
    {
        fprintf(file, "%d&%s&%s&%d&%d", identificativo, nomecorso, nomedocente, numerocfu, numerostudenti);

    }
    else
    {
        fprintf(file, "\n%d&%s&%s&%d&%d", identificativo, nomecorso, nomedocente, numerocfu, numerostudenti);
    }
    return;
}

/**
    @brief scrive sul file il nome di un corso.
    @pre file aperto correttamente, stringa nomecorso avvalorata e non fuori range(lunghezza<SIZE).
*/
void scrivi_nome_corso(FILE* file, char nomecorso[SIZE])
{
    fprintf(file, "%s\n", nomecorso);
    return;
}













