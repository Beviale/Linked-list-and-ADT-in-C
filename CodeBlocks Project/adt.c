/**
 * @file adt.c
 * @authors Alessandro Bevilacqua, Michele Como, Vito De Tommaso.
 * @brief File implementativo del tipo di dato astratto e relative operazioni.
 * @version 1.0
 * @date 2022-07-27
 */



#include"adt.h"
#include"file.h"
#include"controlli.h"
#include<stdlib.h>
#include<string.h>

/**
    @brief Verifica la diversita' di un un elemento della lista rispetto a tutti dell'altra.
    @return 1 se un elemento del primo elenco è diverso da tutti gli elementi del secondo, altrimenti 0.
    @param ADT del primo elenco, ADT del secondo elenco.
*/
int diversi(ListaPtr, ListaPtr);


/**
    @brief Struttura tipo di dato astratto.
*/
struct lista
{
    ///Numero identificativo del corso.
    int Identificativo;
    ///Nome del corso.
    char NomeCorso[SIZE];
    ///Cognome del docente del corso.
    char NomeDocente[SIZE];
    ///Numero dei crediti previsti dal corso.
    int NumeroCFU;
    ///Numero degli studenti attualmente iscritti al corso.
    int NumeroStudenti;
    ///Puntatore ricorsivo per la realizzazione della lista.
    struct lista *proxPtr;
};

typedef struct lista Lista;





/**
    @brief Inserisce un nuovo nodo alla lista concatenata.
    @pre puntatore alla testa allocato, campi della struct lista avvalorati.
    @post corretto inserimento del nuovo elemento alla lista.
*/
ListaPtr* inseriscinodo(int identificativo, char nomecorso[SIZE], char nomedocente[SIZE], int numerocfu, int numerostudenti, ListaPtr *tPtr)
{
    ///Creazione puntatori ai nodi della lista concatenata.
    ListaPtr nuovoPtr, precPtr, corrPtr;
    nuovoPtr = malloc(sizeof(Lista));
    if(nuovoPtr!=NULL)
    {
        nuovoPtr->Identificativo=identificativo;
        strcpy(nuovoPtr->NomeCorso, nomecorso);
        strcpy(nuovoPtr->NomeDocente, nomedocente);
        nuovoPtr->NumeroCFU=numerocfu;
        nuovoPtr->NumeroStudenti=numerostudenti;
        nuovoPtr->proxPtr=NULL;
        precPtr=NULL;
        corrPtr=*tPtr;
        while(corrPtr!=NULL && identificativo>corrPtr->Identificativo) // Per ordine crescente
        {
            precPtr=corrPtr;
            corrPtr=corrPtr->proxPtr;   // Effettuo lo scorrimento finchè non soddisfo le condizionio del ciclo
        }
        if(precPtr==NULL) // Se l'elemento da inserire deve essere il primo della lista
        {
            nuovoPtr->proxPtr=*tPtr; // Il prossimo puntatore del nuovo puntatore è l'attuale puntatore testa
            *tPtr=nuovoPtr; // Il nuovo puntatore testa è il nuovo puntatore creato
        }
        else // Se non è il primo elemento della lista
        {
            precPtr->proxPtr=nuovoPtr;
            nuovoPtr->proxPtr=corrPtr;
        }
    }
    else
    {
        ///PROGRAMMAZIONE DIFENSIVA COLLEZIONE DATI: una mancata allocazione dell'elemento in memoria provoca un errore.
        printf("%s", "Numero non inserito. Manca la memoria.\n");
        return NULL;
    }
    return tPtr;
}

/**
    @brief ritorna la dimensione del tipo di dato astratto.
*/
int dimensione()
{
    return sizeof(struct lista);
}



/**
    @brief Stampa degli elementi di un ADT.
    @pre lista concatenata piena.
    @post stampa corretta di tutti gli elementi della lista.
*/
void stampa(ListaPtr* tPtr)
{
    ///PROGRAMMAZIONE DIFENSIVA CLASSE COLLEZIONE DATI: se la lista e' vuota allora non posso stampare nulla.
    if(tPtr==NULL)
        return;
    ListaPtr corrPtr=*tPtr;
    printf("%s", "La lista e': \n");
    while(corrPtr!=NULL)
    {
        printf("%d --> ", corrPtr->Identificativo);
        printf("%s --> ", corrPtr->NomeCorso);
        printf("%s --> ", corrPtr->NomeDocente);
        printf("%d --> ", corrPtr->NumeroCFU);
        printf("%d --> ", corrPtr->NumeroStudenti);
        printf("\n");
        corrPtr=corrPtr->proxPtr;
    }
    printf("%s", "NULL\n\n");
}



/**
    @brief Crea una nuova variabile ADT contenente i corsi dell'elenco A che hanno un docente condiviso con l'elenco B.
    @pre i due ADT in ingresso devono essere avvalorati.
    @post nuovo ADT creato correttamente.
*/
ListaPtr* estrai(ListaPtr* corso_a, ListaPtr* corso_b)
{
    ///Creazione del nuovo ADT.
    ListaPtr* testa_estrazione=malloc(sizeof(struct lista));
    *testa_estrazione=NULL;
    ///Puntatore per effettuare lo scorrimento sull'elenco A.
    ListaPtr corrPtr_a=*corso_a;
    ///Puntatore per effettuare lo scorrimento sull'elenco B.
    ListaPtr corrPtr_b=*corso_b;
    if(struttura_vuota(corrPtr_a)==0 || struttura_vuota(corrPtr_b)==0)
    {
        ///PROGRAMMAZIONE DIFENSIVA CLASSE COLLEZIONE DATI: se uno dei due elenchi e' vuoto, non posso eseguire l'estrazione.
        printf("%s", "\nErrore!");
        return NULL;
    }
    ListaPtr rewind=*corso_b;
    while(corrPtr_a!=NULL)
    {
        corrPtr_b=rewind;
        while(corrPtr_b!=NULL)
        {
            if(strcmp(corrPtr_a->NomeDocente, corrPtr_b->NomeDocente)==0)
            {
                  testa_estrazione=inseriscinodo(corrPtr_a->Identificativo, corrPtr_a->NomeCorso, corrPtr_a->NomeDocente, corrPtr_a->NumeroCFU, corrPtr_a->NumeroStudenti, testa_estrazione);
            }
            corrPtr_b=corrPtr_b->proxPtr;
        }
        corrPtr_a=corrPtr_a->proxPtr;
    }

    return testa_estrazione;
}




/**
    @brief Crea una nuova variabile ADT contenente i corsi dell'elenco A e dell'elenco B senza duplicati.
    @pre i due ADT in ingresso devono essere avvalorati.
    @post nuovo ADT creato correttamente.
*/
ListaPtr*fondi(ListaPtr* corso_a, ListaPtr* corso_b)
{
    ListaPtr* testa_fusione=malloc(sizeof(struct lista));
    *testa_fusione=NULL;
    ListaPtr corrPtr_a=*corso_a;
    ListaPtr corrPtr_b=*corso_b;
    if(struttura_vuota(corrPtr_a)==0 || struttura_vuota(corrPtr_b)==0)
    {
    ///PROGRAMMAZIONE DIFENSIVA CLASSE COLLEZIONE DATI: se uno dei due elenchi e' vuoto, non posso eseguire la fusione.
        printf("%s", "\nErrore!");
        return NULL;
    }
    ///Assegniamo a rewind_b il valore del puntatore alla testa della lista del corso b.
    ListaPtr rewind_b=*corso_b;
    while(corrPtr_a!=NULL )
    {
        ///Riportiamo il puntatore alla testa della lista.
            corrPtr_b=rewind_b;
            if(diversi(corrPtr_a, corrPtr_b)==1)
            {
                    testa_fusione=inseriscinodo(corrPtr_a->Identificativo, corrPtr_a->NomeCorso, corrPtr_a->NomeDocente, corrPtr_a->NumeroCFU, corrPtr_a->NumeroStudenti, testa_fusione);
            }
        corrPtr_a=corrPtr_a->proxPtr;
    }
     while(corrPtr_b!=NULL )
    {
        testa_fusione=inseriscinodo(corrPtr_b->Identificativo, corrPtr_b->NomeCorso, corrPtr_b->NomeDocente, corrPtr_b->NumeroCFU, corrPtr_b->NumeroStudenti, testa_fusione);
        corrPtr_b=corrPtr_b->proxPtr;
    }
    return testa_fusione;
}




/**
    @brief Verifica la diversita' di un un elemento della lista rispetto a tutti dell'altra.
*/
int diversi(ListaPtr corrPtr_a, ListaPtr corrPtr_b)
{
    while(corrPtr_b!=NULL)
    {
          if(corrPtr_a->Identificativo==corrPtr_b->Identificativo)
            {
                if(strcmp(corrPtr_a->NomeCorso, corrPtr_b->NomeCorso)==0)
                {
                    if(strcmp(corrPtr_a->NomeDocente, corrPtr_b->NomeDocente)==0)
                    {
                        if(corrPtr_a->NumeroCFU==corrPtr_b->NumeroCFU)
                        {
                            if(corrPtr_a->NumeroStudenti==corrPtr_b->NumeroStudenti)
                            {
                                return 0;
                            }
                        }
                    }
                }
            }
            corrPtr_b=corrPtr_b->proxPtr;
    }

    return 1;
}




/**
    @brief Stampa dell'intero ADT su un file.
    @pre file aperto correttamente, struttura piena.
    @post corretta scrittura di tutti gli elementi della lista.

*/
void stampa_su_file(FILE* file, ListaPtr* tPtr)
{
    ///Per evitare che la prima riga del file venga mandata a capo.
    int verifica_a_capo=0;
    ListaPtr corrPtr=*tPtr;
    if(struttura_vuota(corrPtr)==0)
    {
        ///PROGRAMMAZIONE DIFENSIVA CLASSE COLLEZIONE DATI: se struttura vuota, allora non posso stampare niente sul file.
        printf("%s", "\nErrore!");
        return;
    }
    while(corrPtr!=NULL)
    {
        scrivi_file(file, corrPtr->Identificativo, corrPtr->NomeCorso, corrPtr->NomeDocente, corrPtr->NumeroCFU, corrPtr->NumeroStudenti, &verifica_a_capo);
        corrPtr=corrPtr->proxPtr;
        verifica_a_capo=1;
    }
    return;
}


/**
    @brief Scrive su file il nome dei corsi duplicati tra i due ADT passati in ingresso.
    @pre file aperto correttamente, ADT dell'elenco A e ADT dell'elenco B avvalorati.
    @post corretta scrittura dei corsi duplicati per il campo NomeCorso della struct.

*/
int duplicati(FILE *file, ListaPtr* corso_a, ListaPtr* corso_b)
{
    int cont=0;
    ListaPtr corrPtr_a=*corso_a;
    ListaPtr corrPtr_b=*corso_b;
    ///Assegniamo a rewind_b il valore del puntatore alla testa della lista del corso b.
    ListaPtr rewind=*corso_b;
    if(struttura_vuota(corrPtr_a)==0 || struttura_vuota(corrPtr_b)==0)
    {
        printf("%s", "\nErrore!");
        return 0;
    }
    while(corrPtr_a!=NULL)
    {
        ///Riportiamo il puntatore alla testa della lista.
        corrPtr_b=rewind;
        while(corrPtr_b!=NULL)
        {
            if(strcmp(corrPtr_a->NomeCorso, corrPtr_b->NomeCorso)==0)
            {
                cont++;
                scrivi_nome_corso(file, corrPtr_a->NomeCorso);

            }
            corrPtr_b=corrPtr_b->proxPtr;
        }
        corrPtr_a=corrPtr_a->proxPtr;
    }

    return cont;

}


