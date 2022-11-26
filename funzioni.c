/**
 * @file funzioni.c
 * @authors Alessandro Bevilacqua, Michele Como, Vito De Tommaso.
 * @brief File contenente le definizione delle operazioni eseguite sui file.
 * @version 1.0
 * @date 2022-07-27
 */

#include"funzioni.h"
#include"controlli.h"
#include"file.h"
#include<stdlib.h>
#include<stdio.h>

/**
    @pre il file deve esistere, deve essere aperto correttamente, non deve essere vuoto e deve essere nel formato corretto.
    @post lista concatenata non vuota.
    @brief Svolge la funzionalita' di dominio dell'acquisizione. Apre un file e salva i dati in una struttura dinamica gestita come lista.
*/
ListaPtr* acquisizione()
{
    FILE *fp=apri_file();
    if(fp==NULL)
    {
        /// Se file non aperto correttamente, restituisci NULL;
        return NULL;
    }
    if(verifica_file_vuoto(fp)==0)
    {
        fclose(fp);
        /// Se file vuoto, restituisci NULL;
        return NULL;
    }
    if(verifica_file(fp)==0)
    {
        fclose(fp);
        /// Se file non formattato correttamente, restituisci NULL;
        return NULL;
    }
    ///Creazione struttura dinamica gestita come lista, creazione del tipo di dato astratto Lista;
    ListaPtr* tPtr=malloc(dimensione());
    *tPtr=NULL;
    return leggi_file(tPtr, fp);
}


/**
    @pre i due elenchi (corso a e corso b) devono essere acquisiti dai due file.
    @post estrazione.txt generata correttamente.
    @brief Svolge la funzionalita' di dominio dell'estrazione. Prende i dati da due file, crea una nuova variabile di tipo ADT e genera il file estrazione.txt.
*/
void estrazione()
{
    ///Struttura dinamica relativa al primo elenco.
    ListaPtr* corso_a=acquisizione();
    if(corso_a!=NULL)
    {
            ///Struttura dinamica relativa al secondo elenco.
           ListaPtr* corso_b=acquisizione();
            if(corso_b!=NULL)
            {
                   ///Creazione nuova variabile di tipo Lista, creazione nuova struttura dinamica.
                   ListaPtr* testa_estrazione=estrai(corso_a, corso_b);
                    if(testa_estrazione!=NULL)
                    {
                        ///Creazione file estrazione.txt
                        FILE *file_estrazione=apri_file_scrittura("estrazione.txt");
                         if(file_estrazione!=NULL)
                            {
                                ///Inserimento in estrazione.txt di testa_estrazione
                                stampa_su_file(file_estrazione, testa_estrazione);
                                fclose(file_estrazione);
                                printf("%s", "\nEstrazione eseguita correttamente!");
                                return;
                            }
                    }
            }

    }
    ///PROGRAMMAZIONE DIFENSIVA: se l'acquisizione non è avvenuta correttamente oppure se il file estrazione.txt non e' stato generato correttamente, allora errore.
    printf("%s", "\nNon e' possibile completare la richiesta!");
    return;
}



/**
    @pre  i due elenchi (corso a e corso b) devono essere acquisiti dai due file.
    @post fusione.txt generata correttamente.
    @brief Svolge la funzionalita' di dominio della fusione. Prende i dati da due file, crea un nuova variabile di tipo ADT (Lista) e genera  il file fusione.txt senza duplicati.
*/
void fusione()
{
    ///Struttura dinamica relativa al primo elenco.
    ListaPtr* corso_a=acquisizione();
    if(corso_a!=NULL)
    {
            ///Struttura dinamica relativa al secondo elenco.
           ListaPtr* corso_b=acquisizione();
            if(corso_b!=NULL)
            {
                    ///Creazione nuova variabile di tipo Lista, creazione nuova struttura dinamica.
                   ListaPtr* testa_fusione=fondi(corso_a, corso_b);
                    if(testa_fusione!=NULL)
                    {
                        ///Creazione file fusione.txt
                        FILE *file_fusione=apri_file_scrittura("fusione.txt");
                         if(file_fusione!=NULL)
                            {
                                    ///Inserimento in fusione.txt di testa_fusione
                                    stampa_su_file(file_fusione, testa_fusione);
                                    fclose(file_fusione);
                                    printf("%s", "\nFusione eseguita correttamente!");
                                    return;
                            }
                    }
            }

    }
        ///PROGRAMMAZIONE DIFENSIVA: se l'acquisizione non è avvenuta correttamente oppure se il file fusione.txt non e' stato generato correttamente, allora errore.
    printf("%s", "\nNon e' possibile completare la richiesta!");
    return;
}




/**
    @brief Svolge la funzionalita' di dominio della duplicazione. Prende i dati da due file e genera il file duplicazione.txt contenente i corsi duplicati per NomeCorso.
    @pre i due elenchi (corso a e corso b) devono essere acquisiti dai due file.
    @post duplicazione.txt generata correttamente.
*/
void duplicazione()
{
    ///Struttura dinamica relativa al primo elenco.
     ListaPtr* corso_a=acquisizione();
    if(corso_a!=NULL)
    {
            ///Struttura dinamica relativa al secondo elenco.
           ListaPtr* corso_b=acquisizione();
            if(corso_b!=NULL)
            {
                ///Creazione file duplicazione.txt
                FILE *file_duplicazione=apri_file_scrittura("duplicazione.txt");
                if(file_duplicazione!=NULL)
                {
                       if(duplicati(file_duplicazione, corso_a, corso_b)==0)
                       {
                           printf("%s", "\nNon sono stati trovati duplicati per NomeCorso!");
                       }
                        fclose(file_duplicazione);
                        printf("%s", "\nDuplicazione eseguita correttamente!");
                        return;
                }
              }
        }
    ///PROGRAMMAZIONE DIFENSIVA: se l'acquisizione non è avvenuta correttamente oppure se il file duplicazione.txt non e' stato generato correttamente, allora errore.
    printf("%s", "\nNon e' possibile completare la richiesta!");
    return;
}


