/**
 * @file controlli.h
 * @authors Alessandro Bevilacqua, Michele Como, Vito De Tommaso.
 * @brief Libreria contenente i prototipi dei controlli sui file, strutture iterative, collezioni di dati e input da tastiera.
 * @version 1.0
 * @date 2022-07-27
 */

#ifndef CONTROLLI_H_INCLUDED
#define CONTROLLI_H_INCLUDED
#include<stdio.h>
#include"adt.h"


/**
    @brief PROGRAMMAZIONE DIFENSIVA CLASSE FILE: verifica la corretta apertura del file in modalità lettura.
    @return NULL in caso di errore, puntatore di tipo FILE se l'operazione e' avvenuta correttamente.
*/
FILE* apri_file();
/**
    @brief PROGRAMMAZIONE DIFENSIVA CLASSE FILE: verifica se il file e' vuoto o meno.
    @return 0 se vuoto, 1 se avvalorato.
    @param file da verificare.
*/
int verifica_file_vuoto(FILE *);
/**
    @brief PROGRAMMAZIONE DIFENSIVA CLASSE FILE: verifica la formattazione del file.
    @param file da verificare.
    @return 0 se non formattato correttamente, 1 se formattato correttamente.
*/
int verifica_file(FILE *);
/**
    @brief Verifica se la stringa passata in ingresso contiene o meno altri caratteri oltre a quelli alfabetici.
    @param stringa da scansionare.
    @return 1 se tutti i caratteri sono alfabetici, 0 altrimenti.
*/
unsigned isstring(char *);
/**
    @brief Verifica se la stringa passata in ingresso contiene o meno altri caratteri oltre a quelli numerici.
    @param stringa da scansionare.
    @return 1 se tutti i caratteri sono numerici, 0 altrimenti.
*/
unsigned isnumber(char *);
/**
    @brief PROGRAMMAZIONE DIFENSIVA CLASSE INPUT: verifica se l'input da tastiera rientra o meno nel range dei valori ammissibili.
    @return 1 se l'input e' corrett0, 0 se non lo e'.
    @param scelta dell'utente.
    @param valore minimo ammissibile.
    @param valore massimo ammissibile
*/
int controllascelta(char *, int, int);
/**
    @brief PROGRAMMAZIONE DIFENSIVA CLASSE FILE: verifica la corretta apertura del file in modalità scrittura.
    @return NULL in caso di errore, puntatore di tipo FILE se l'operazione e' avvenuta correttamente.
    @param nome del file da aprire.
*/
FILE* apri_file_scrittura(char *);
/**
     @brief PROGRAMMAZIONE DIFENSIVA CLASSE COLLEZIONE DATI: verifica se la lunghezza della stringa è maggiore di SIZE.
     @return 1 se minore o uguale, 0 se maggiore.
     @param stringa da verificare.
*/
int controlla_lunghezza_stringa(char *);
/**
    @brief PROGRAMMAZIONE DIFENSIVA COLLEZIONE DATI: verifica se la lista concatenata e' vuota o meno.
    @param puntatore alla testa della lista.
    @return 1 se avvalorata, 0 se vuota.
*/
int struttura_vuota(ListaPtr);


#endif // CONTROLLI_H_INCLUDED
