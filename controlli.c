/**
 * @file controlli.c
 * @authors Alessandro Bevilacqua, Michele Como, Vito De Tommaso.
 * @brief File contenente l'implementazione dei controlli sui file, strutture iterative, collezioni di dati e input da tastiera.
 * @version 1.0
 * @date 2022-07-27
 */

#include"controlli.h"
#include"adt.h"
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>

/**
    @brief PROGRAMMAZIONE DIFENSIVA CLASSE FILE: verifica la corretta apertura del file in modalità scrittura.
*/
FILE* apri_file_scrittura(char nomefile[SIZE])
{
    FILE *file;
    if((file=fopen(nomefile, "w"))==NULL)
    {
        printf("%s", "\nNon e' stato possibile aprire il file!");
        /// PROGRAMMAZIONE DIFENSIVA: errore nell'apertura del file.
        return NULL;
    }
    /// File aperto correttamente.
    return file;
}


/**
    @brief PROGRAMMAZIONE DIFENSIVA CLASSE FILE: verifica la corretta apertura del file in modalità lettura.
*/
FILE* apri_file()
{
    ///Nome del file da inserire da tastiera.
    char nomefile[SIZE];
    printf("%s", "\nInserisci il nome del file: ");
    scanf("%s", nomefile);
    FILE *file;
    if((file=fopen(nomefile, "r"))==NULL)
    {
        printf("%s", "\nNon e' stato possibile aprire il file!Assicurati di averlo scritto correttamente!\n");
        /// PROGRAMMAZIONE DIFENSIVA: errore nell'apertura del file.
        return NULL;
    }
    /// File aperto correttamente.
    return file;
}



/**
    @brief PROGRAMMAZIONE DIFENSIVA CLASSE FILE: verifica se il file e' vuoto o meno.
    @pre file aperto correttamente.
*/
int verifica_file_vuoto(FILE *file)
{
    fseek(file, 0, SEEK_END);
    ///size è la dimensione in byte del file.
    long size = ftell(file);
    if(size==0)
    {
        printf("%s", "\nIl file e' vuoto!");
        return 0;
    }
    return 1;
}





/**
    @brief PROGRAMMAZIONE DIFENSIVA CLASSE FILE: verifica la formattazione del file.
    @pre file aperto correttamente.
*/
int verifica_file(FILE *file)
{
    rewind(file);
     /// Stringa relativa ad ogni riga del file (quindi ad ogni corso).
    char string[SIZE];
    /// Riga del file suddivisa in occorenza del carattere '#'.
    char *tokenPtr;
    while(!feof(file))
    {
        fgets(string, SIZE, file);
        if(controlla_lunghezza_stringa(string)==0)
        {
            ///PROGRAMMAZIONE DIFENSIVA CLASSE FILE: se la stringa è fuori range del vettore, allora non posso continuare la verifica della formattazione.
            printf("\n%s", "Dimensione stringa eccessiva!");
            return 0;
        }
        /// Conta il numero di token suddivisi per ciascuna riga.
        unsigned cont=0;
        tokenPtr=strtok(string,"&");
        ///PROGRAMMAZIONE DIFENSIVA: array su cui copio la stringa di ciascun token e ne verifico il tipo di valore (numerico o alfabetico).
        char controlla[SIZE];
        while(tokenPtr != NULL)
        {
            cont++;
            strcpy(controlla, tokenPtr);
            switch(cont)
            {
                case 1:
                /// Mi aspetto che il primo token sia un numerico (Identificativo).
                if(isnumber(controlla)==0)
                {
                    printf("%s", "\nFormato1 file non corretto!");
                    return 0;
                }
                break;
                case 2:
                /// Mi aspetto che il secondo token sia alfabetico (NomeCorso).
                if(isstring(controlla)==0)
                {
                    printf("%s", "\nFormato2 file non corretto!");
                    return 0;
                }
                break;
                case 3:
                /// Mi aspetto che il terzo token sia alfabetico (NomeDocente).
                if(isstring(controlla)==0)
                {
                    printf("%s", "\nFormato3 file non corretto!");
                    return 0;
                }
                break;
                case 4:
                /// Mi aspetto che il quarto token sia numerico (NumeroCFU).
                if(isnumber(controlla)==0)
                {
                    printf("%s", "\nFormato4 file non corretto!");
                    return 0;
                }
                break;
                case 5:
                /// Mi aspetto che il quinto token sia numerico (NumeroStudenti).
                if(isnumber(controlla)==0)
                {
                    printf("%s", "\nFormato5 file non corretto!");
                    return 0;
                }
                break;
            }
                tokenPtr = strtok(NULL, "&");
            }
            /// PROGRAMMAZIONE DIFENSIVA: ogni riga deve essere suddivisa in 5 token, altrimenti formato non corretto.
            if(cont!=5)
            {
                printf("%s", "\nFormato6 file non corretto!");
                return 0;
            }
    }
    return 1;
}



/**
    @brief Verifica se la stringa passata in ingresso contiene o meno altri caratteri oltre a quelli alfabetici.
*/
unsigned isstring(char * controlla)
{
    for(int i=0; controlla[i]!='\0'; i++)
    {
        if(!isalpha(controlla[i]))
        {
            return 0;
        }
    }
    return 1;
}



/**
    @brief Verifica se la stringa passata in ingresso contiene o meno altri caratteri oltre a quelli numerici.
*/
unsigned isnumber(char * controlla)
{
    for(int i=0; controlla[i]!='\0'; i++)
    {
        if(!isdigit(controlla[i]))
        {
            if(controlla[i]!=10)
            return 0;
        }
    }
    return 1;
}


/**
    @brief PROGRAMMAZIONE DIFENSIVA CLASSE INPUT: verifica se l'input da tastiera rientra o meno nel range dei valori ammissibili.
    @pre scelta gia' effettuata da parte dell'utente.
*/
int controllascelta(char controlla[SIZE], int minimo, int massimo)
{
    if(controlla_lunghezza_stringa(controlla)==1)
        if(isnumber(controlla)==1)
            if(atoi(controlla)>=minimo && atoi(controlla)<=massimo)
                return 1;
    printf("%s", "ERRORE!Ritenta l'inserimento!");
    return 0;
}




/**
     @brief PROGRAMMAZIONE DIFENSIVA CLASSE COLLEZIONE DATI: verifica se la lunghezza della stringa è maggiore di SIZE.
*/
int controlla_lunghezza_stringa(char controlla[SIZE])
{
    if(strlen(controlla)>SIZE)
        return 0;
    return 1;
}



/**
    @brief PROGRAMMAZIONE DIFENSIVA COLLEZIONE DATI: verifica se la lista concatenata e' vuota o meno.
*/
int struttura_vuota(ListaPtr controlla)
{
    if(controlla==NULL)
        return 0;
    return 1;
}



