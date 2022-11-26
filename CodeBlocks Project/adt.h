/**
 * @file adt.h
 * @authors Alessandro Bevilacqua, Michele Como, Vito De Tommaso.
 * @brief File contenente interfaccia del tipo di dato astratto e prototipi di funzione delle relative operazioni.
 * @version 1.0
 * @date 2022-07-27
 */

#ifndef ADT_H_INCLUDED
#define ADT_H_INCLUDED
#define SIZE 50
#include<stdio.h>
/**
    @brief Creazione tipo di dato astratto. Visibilità garantita solo all'interfaccia e non alla struttura interna(tipo opaco).
*/
typedef struct lista* ListaPtr;






/**
    @brief ritorna la dimensione del tipo di dato astratto.
    @return dimensione ADT.
*/
int dimensione();
/**
    @brief Inserisce un nuovo nodo alla lista concatenata.
    @param campi della struct lista.
    @param puntatore alla testa della lista.
    @return puntatore alla nuova testa della lista.
*/
ListaPtr* inseriscinodo(int, char *, char*, int, int, ListaPtr*);
/**
    @brief Stampa degli elementi di un ADT.
    @param puntatore alla testa della lista.
*/
void stampa(ListaPtr *);
/**
    @brief Crea una nuova variabile ADT contenente i corsi dell'elenco A che hanno un docente condiviso con l'elenco B.
    @return nuovo ADT.
    @param ADT relativo all'elenco A, ADT relativo all'elenco B.
*/
ListaPtr* estrai(ListaPtr*, ListaPtr*);
/**
    @brief Stampa dell'intero ADT su un file.
    @param file su cui scrivere.
    @param ADT da cui prendere i corsi.
*/
void stampa_su_file(FILE*, ListaPtr*);
/**
    @brief Crea una nuova variabile ADT contenente i corsi dell'elenco A e dell'elenco B senza duplicati.
    @param ADT relativo all'elenco A, ADT relativo all'elenco B.
    @return nuovo ADT.
*/
ListaPtr* fondi(ListaPtr*, ListaPtr*);
/**
    @brief Scrive su file il nome dei corsi duplicati tra i due ADT passati in ingresso.
    @return numero dei corsi duplicati.
    @param file su cui scrivere.
    @param ADT relativo all'elenco A, ADT relativo all'elenco B.

*/
int duplicati(FILE*, ListaPtr*, ListaPtr*);



#endif // ADT_H_INCLUDED*
