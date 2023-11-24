# Falsificazione dei dadi

**Ultima sottoposizione:** 2 ore fa ([tutte le sottoposizioni](https://gara.territoriali.olinfo.it/task/dadi/submissions))

---

> **Attenzione**: Questo task ha un tempo limite di 10 minuti per l'invio della soluzione. Una volta richiesto un input, il timer partirà in automatico, e dopo la scadenza non sarà più possibile inviare una soluzione per quell'input. _È sempre possibile richiedere un nuovo input_, per cui non preoccuparti se il timer scade: dovrai semplicemente richiedere e scaricare un nuovo input.
> 
> _Per aiutarti con questo task, abbiamo preparato delle **tracce di soluzione**, che includono solo le parti di lettura dell'input e scrittura dell'output (da tastiera e su schermo). Puoi decidere se leggere/scrivere su file decommentando le opportune righe di codice._
> 
> -   _Scarica la traccia in C: [dadi.c](https://gara.territoriali.olinfo.it/files//statements/UJruDMWcPnqfPcQj/dadi/dadi.c)_
> -   _Scarica la traccia in C++: [dadi.cpp](https://gara.territoriali.olinfo.it/files//statements/UJruDMWcPnqfPcQj/dadi/dadi.cpp)_
> -   _Scarica la traccia in Python: [dadi.py](https://gara.territoriali.olinfo.it/files//statements/UJruDMWcPnqfPcQj/dadi/dadi.py)_
> -   _Scarica la traccia in Java: [dadi.java](https://gara.territoriali.olinfo.it/files//statements/UJruDMWcPnqfPcQj/dadi/dadi.java)_
> -   _Scarica la traccia in C#: [dadi.cs](https://gara.territoriali.olinfo.it/files//statements/UJruDMWcPnqfPcQj/dadi/dadi.cs)_
> -   _Scarica la traccia in JavaScript: [dadi.html](https://gara.territoriali.olinfo.it/files//statements/UJruDMWcPnqfPcQj/dadi/dadi.html)_

## Descrizione del problema

Giorgio è un appassionato di giochi di società, ma dopo serate e serate passate a giocare a Risiko si è stufato e vuole provare qualcosa di diverso. Decide quindi creare un nuovo gioco da tavolo: "OII: Ottantamila Incredibili Imprese", e di provarlo assieme a Dario.

!["Dario, l'avversario di Giorgio"](https://gara.territoriali.olinfo.it/files//statements/UJruDMWcPnqfPcQj/dadi/dadi.jpg "Dario, l'avversario di Giorgio")

Come in ogni gioco che si rispetti, a ogni turno si tirano tantissimi dadi tetraedrali (ossia con 4 facce). Il punteggio di un'azione è la somma dei dadi tirati. Dario non sopporta che Giorgio vinca sempre, e approfitta di ogni sua distrazione: se Giorgio dopo un tiro si distrae per K secondi, Dario ha tempo di girare al massimo KK dadi, scegliendo a piacere la nuova faccia visibile, in modo da massimizzare il proprio punteggio.

Determina, per ciascuno dei TT turni di gioco di Dario, qual è il suo punteggio dopo che ha girato i propri dadi!

## Dati di input

La prima riga del file di input contiene un intero TT, il numero di casi di test. Seguono TT casi di test, numerati da 11 a TT. Ogni caso di test è preceduto da una riga vuota.

Ogni caso di test è composto come segue:

-   la prima riga contiene l'intero KK.
-   La seconda riga contiene gli interi A,B,C,DA,B,C,D: rispettivamente, il numero di dadi la cui faccia visibile è 1, 2, 3 e 4.

## Dati di output

Il file di output deve contenere la risposta ai casi di test che sei riuscito a risolvere. Per ogni caso di test che hai risolto, il file di output deve contenere una riga con la dicitura:

```
Case #t: x
```

dove `t` è il numero del caso di test (a partire da 11) e il valore `x` è il massimo punteggio che Dario può ottenere.

## Assunzioni

-   T=10T=10, nei file di input che scaricherai saranno presenti esattamente 1010 casi di test.
-   1≤A,B,C,D≤1001≤A,B,C,D≤100
-   0≤K≤A+B+C+D0≤K≤A+B+C+D

Nei primi 22 casi di test vale K=1K=1 e non ci sono dadi con facce 11 o 22. Nei successivi 22 casi di test vale K=1K=1. Nei successivi 22 casi di test non ci sono dadi con facce 11 o 22.

## Esempi di input/output

---

**Input:**

```
3

1
1 1 1 1

2
1 1 1 1

3
0 1 0 4
```

---

**Output:**

```
Case #1: 13
Case #2: 15
Case #3: 20
```

---

## Spiegazione

Nel **primo caso d'esempio**, Dario può girare il dado che mostra 11, rendendolo un 44. Il punteggio finale è quindi 2+3+4+4=132+3+4+4=13.

Nel **secondo caso d'esempio**, Dario può girare il dado che mostra 11, rendendolo un 44; poi può girare il dado che mostra 22, rendendolo un altro 44. Il punteggio finale è quindi 3+4+4+4=153+4+4+4=15.

Nel **terzo caso d'esempio**, Dario può girare il dado che mostra 22, rendendolo un 44. A questo punto ha ancora 22 mosse rimaste, ma non c'è modo di aumentare ancora il punteggio. Il punteggio finale è quindi 4+4+4+4+4=204+4+4+4+4=20.