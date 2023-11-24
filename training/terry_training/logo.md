# Cambia il logo

---

> **Attenzione**: Questo task ha un tempo limite di 10 minuti per l'invio della soluzione. Una volta richiesto un input, il timer partirà in automatico, e dopo la scadenza non sarà più possibile inviare una soluzione per quell'input. _È sempre possibile richiedere un nuovo input_, per cui non preoccuparti se il timer scade: dovrai semplicemente richiedere e scaricare un nuovo input.
> 
> _Per aiutarti con questo task, abbiamo preparato delle **tracce di soluzione**, che includono solo le parti di lettura dell'input e scrittura dell'output (da tastiera e su schermo). Puoi decidere se leggere/scrivere su file decommentando le opportune righe di codice._
> 
> -   _Scarica la traccia in C: [logo.c](https://gara.territoriali.olinfo.it/files//statements/UJruDMWcPnqfPcQj/logo/logo.c)_
> -   _Scarica la traccia in C++: [logo.cpp](https://gara.territoriali.olinfo.it/files//statements/UJruDMWcPnqfPcQj/logo/logo.cpp)_
> -   _Scarica la traccia in Python: [logo.py](https://gara.territoriali.olinfo.it/files//statements/UJruDMWcPnqfPcQj/logo/logo.py)_
> -   _Scarica la traccia in Java: [logo.java](https://gara.territoriali.olinfo.it/files//statements/UJruDMWcPnqfPcQj/logo/logo.java)_
> -   _Scarica la traccia in C#: [logo.cs](https://gara.territoriali.olinfo.it/files//statements/UJruDMWcPnqfPcQj/logo/logo.cs)_
> -   _Scarica la traccia in JavaScript: [logo.html](https://gara.territoriali.olinfo.it/files//statements/UJruDMWcPnqfPcQj/logo/logo.html)_

## Descrizione del problema

Poco prima della pubblicazione, Giorgio ha deciso di fare un'ultima modifica al logo del gioco.

Il logo consiste in una griglia N×MN×M, in cui ogni quadratino può essere bianco o nero. Giorgio ha già scelto il colore di ogni quadratino nel logo finale, e sa che per farlo è sufficiente incollare un adesivo nero rettangolare sopra al logo attuale, parallelo ai lati della griglia.

Tuttavia, per risparmiare materiale, vorrebbe usare un adesivo della minima area possibile.

Quanto vale quest'area?

## Dati di input

La prima riga del file di input contiene un intero TT, il numero di casi di test. Seguono TT casi di test, numerati da 11 a TT. Ogni caso di test è preceduto da una riga vuota.

Ogni caso di test è composto come segue:

-   la prima riga contiene gli interi NN e MM.
-   le NN righe seguenti contengono MM caratteri ognuna, che possono essere 'N' per un quadratino nero e 'B' per uno bianco, nel logo iniziale.
-   le ulteriori NN righe seguenti rappresentano nello stesso modo il logo finale.

## Dati di output

Il file di output deve contenere la risposta ai casi di test che sei riuscito a risolvere. Per ogni caso di test che hai risolto, il file di output deve contenere una riga con la dicitura:

```
Case #t: x
```

dove `t` è il numero del caso di test (a partire da 11) e il valore `x` è l'area minima di un adesivo che Giorgio può usare per apportare la modifica al logo, o 00 se non è necessaria alcuna modifica.

## Assunzioni

-   T=14T=14, nei file di input che scaricherai saranno presenti esattamente 1414 casi di test.
-   1≤N,M≤3000001≤N,M≤300000
-   1≤N×M≤3000001≤N×M≤300000

Nei primi 55 casi di test vale N,M≤100N,M≤100 e N×M≤100N×M≤100.

## Esempi di input/output

---

**Input:**

```
2

3 4
BNBN
BBBN
BBNN
BNBN
BNNN
BNNN

2 2
BN
NB
BN
NB
```

---

**Output:**

```
Case #1: 4
Case #2: 0
```

---

## Spiegazione

Nel **primo caso d'esempio** per poter cambiare il logo è sufficiente applicare un adesivo 2×22×2, con un'area di 44. Con adesivi più piccoli non si riuscirebbe.

![](https://gara.territoriali.olinfo.it/files//statements/UJruDMWcPnqfPcQj/logo/asy/fig1.png)

In figura sono mostrati il logo iniziale, l'adesivo applicato (in grigio) e il logo finale.

Nel **secondo caso d'esempio** il logo finale è uguale a quello iniziale, quindi non è necessario applicare alcuno sticker.