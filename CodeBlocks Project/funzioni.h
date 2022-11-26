/**
 * @file funzioni.h
 * @authors Alessandro Bevilacqua, Michele Como, Vito De Tommaso.
 * @brief Libreria contenente i prototipi delle operazioni eseguite su file.
 * @version 1.0
 * @date 2022-07-27
 */

#ifndef FUNZIONI_H_INCLUDED
#define FUNZIONI_H_INCLUDED
#include"adt.h"

/**
    @brief Svolge la funzionalita' di dominio dell'acquisizione. Apre un file e salva i dati in una struttura dinamica gestita come lista.
    @return NULL se l'acquisizione non e' possibile, altrimenti ritorna il puntatore alla lista concatenata creata.
*/
ListaPtr* acquisizione();
/**
    @brief Svolge la funzionalita' di dominio dell'estrazione. Prende i dati da due file, crea una nuova variabile di tipo ADT(Lista) e genera il file estrazione.txt.
*/
void estrazione();
/**
    @brief Svolge la funzionalita' di dominio della fusione. Prende i dati da due file, crea un nuova variabile di tipo ADT (Lista) e genera  il file fusione.txt senza duplicati.
*/
void fusione();
/**
    @brief Svolge la funzionalita' di dominio della duplicazione. Prende i dati da due file e genera il file duplicazione.txt contenente i corsi duplicati per NomeCorso.
*/
void duplicazione();


#endif // FUNZIONI_H_INCLUDED
