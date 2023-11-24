## Campo da soldatini

**Ultima sottoposizione:** 5 minuti fa ([tutte le sottoposizioni](https://gara.territoriali.olinfo.it/task/soldatini/submissions))

---

> **Attenzione**: Questo task ha un tempo limite di 10 minuti per l'invio della soluzione. Una volta richiesto un input, il timer partirà in automatico, e dopo la scadenza non sarà più possibile inviare una soluzione per quell'input. _È sempre possibile richiedere un nuovo input_, per cui non preoccuparti se il timer scade: dovrai semplicemente richiedere e scaricare un nuovo input.
> 
> _Per aiutarti con questo task, abbiamo preparato delle **tracce di soluzione**, che includono solo le parti di lettura dell'input e scrittura dell'output (da tastiera e su schermo). Puoi decidere se leggere/scrivere su file decommentando le opportune righe di codice._
> 
> -   _Scarica la traccia in C: [soldatini.c](https://gara.territoriali.olinfo.it/files//statements/UJruDMWcPnqfPcQj/soldatini/soldatini.c)_
> -   _Scarica la traccia in C++: [soldatini.cpp](https://gara.territoriali.olinfo.it/files//statements/UJruDMWcPnqfPcQj/soldatini/soldatini.cpp)_
> -   _Scarica la traccia in Python: [soldatini.py](https://gara.territoriali.olinfo.it/files//statements/UJruDMWcPnqfPcQj/soldatini/soldatini.py)_
> -   _Scarica la traccia in Java: [soldatini.java](https://gara.territoriali.olinfo.it/files//statements/UJruDMWcPnqfPcQj/soldatini/soldatini.java)_
> -   _Scarica la traccia in C#: [soldatini.cs](https://gara.territoriali.olinfo.it/files//statements/UJruDMWcPnqfPcQj/soldatini/soldatini.cs)_
> -   _Scarica la traccia in JavaScript: [soldatini.html](https://gara.territoriali.olinfo.it/files//statements/UJruDMWcPnqfPcQj/soldatini/soldatini.html)_

## Descrizione del problema

Il nuovo gioco di Giorgio presenta 22 tipi di pedine, i soldatini e i muri.

!["Il campo sognato da Valerio"](https://gara.territoriali.olinfo.it/files//statements/UJruDMWcPnqfPcQj/soldatini/soldatini.jpg "Il campo sognato da Valerio")

Inizialmente sono presenti NN pedine disposte lungo una riga, identificate da una stringa SS di lunghezza NN, dove SiSi​ è 11 se la pedina ii è di tipo soldatino e 00 se è di tipo muro per 0≤i≤N−10≤i≤N−1. Dario sta provando il gioco e ha notato che avere un grande gruppo di soldatini è molto utile per vincere una partita, dove un gruppo di soldatini è un insieme di pedine consecutive di tipo soldatino. Per garantirsi la vittoria Dario può sostituire una pedina di tipo muro con una pedina di tipo soldatino. Questa operazione può essere eseguita una sola volta, altrimenti rischierebbe di essere scoperto. Aiuta Dario a calcolare qual è la dimensione massima di un gruppo di soldatini che può ottenere.

## Dati di input

La prima riga del file di input contiene un intero TT, il numero di casi di test. Seguono TT casi di test, numerati da 11 a TT. Ogni caso di test è preceduto da una riga vuota.

Ogni caso di test è composto come segue:

-   la prima riga contiene l'intero NN.
-   la seconda riga contiene la stringa SS.

## Dati di output

Il file di output deve contenere la risposta ai casi di test che sei riuscito a risolvere. Per ogni caso di test che hai risolto, il file di output deve contenere una riga con la dicitura:

```
Case #t: x
```

dove `t` è il numero del caso di test (a partire da 11) e il valore `x` è dimensione massima di un gruppo di soldatini che Dario può ottenere.

## Assunzioni

-   T=10T=10, nei file di input che scaricherai saranno presenti esattamente 1010 casi di test.
-   2≤N≤3000002≤N≤300000
-   La stringa SS ha lunghezza NN e contiene solo caratteri 00 e 11.

Nei primi 55 casi di test vale N≤8000N≤8000.

## Esempi di input/output

---

**Input:**

```
2

5
11001

7
0110111
```

---

**Output:**

```
Case #1: 3
Case #2: 6
```

---

## Spiegazione

Nel **primo caso d'esempio**, può sostituire il muro in posizione 22 con un soldatino, ottenendo un gruppo di 3 soldatini e un gruppo di 1 soldatino. La dimensione massima di un gruppo di soldatini è quindi 33.

Nel **secondo caso d'esempio**, può sostituire il muro in posizione 33 con un soldatino, ottenendo un unico gruppo di 6 soldatini.