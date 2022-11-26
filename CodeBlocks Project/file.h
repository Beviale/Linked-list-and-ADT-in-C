/**
 * @file file.h
 * @authors Alessandro Bevilacqua, Michele Como, Vito De Tommaso
 * @brief Prototipi della libreria riguardante la gestione dei file.
 * @version 1.0
 * @date 2022-07-27
 * Con questa libreria possiamo aprire, chiudere, leggere e scrivere file ad accesso sequenziale.
 * L'acquisizione dei dati avviene mediante l'uso di una struttura dinamica a lista concatenata.
 */
#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED
#include"adt.h"
#include<stdio.h>
#include<stdlib.h>


/**
    @param file da suddividere.
    @param struttura dinamica vuota su cui salvare i dati.
    @return struttura dinamica piena.
    @brief Suddivide ogni riga del file in token in occorrenza del carattere '&' e salva i campi in una struttura dinamica gestita come lista.
*/
ListaPtr* leggi_file(ListaPtr *, FILE *);
/**
    @brief scrive sul file un corso completo di tutti i campi.
*/
void scrivi_file(FILE*, int, char*, char*, int, int, int*);
/**
    @brief scrive sul file il nome di un corso.
*/
void scrivi_nome_corso(FILE*, char *);




#endif // FILE_H_INCLUDED
