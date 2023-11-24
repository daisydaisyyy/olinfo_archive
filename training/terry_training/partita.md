# Inizia la partita!

---

> **Attenzione**: Questo task ha un tempo limite di 10 minuti per l'invio della soluzione. Una volta richiesto un input, il timer partirà in automatico, e dopo la scadenza non sarà più possibile inviare una soluzione per quell'input. _È sempre possibile richiedere un nuovo input_, per cui non preoccuparti se il timer scade: dovrai semplicemente richiedere e scaricare un nuovo input.
> 
> _Per aiutarti con questo task, abbiamo preparato delle **tracce di soluzione**, che includono solo le parti di lettura dell'input e scrittura dell'output (da tastiera e su schermo). Puoi decidere se leggere/scrivere su file decommentando le opportune righe di codice._
> 
> -   _Scarica la traccia in C: [partita.c](https://gara.territoriali.olinfo.it/files//statements/UJruDMWcPnqfPcQj/partita/partita.c)_
> -   _Scarica la traccia in C++: [partita.cpp](https://gara.territoriali.olinfo.it/files//statements/UJruDMWcPnqfPcQj/partita/partita.cpp)_
> -   _Scarica la traccia in Python: [partita.py](https://gara.territoriali.olinfo.it/files//statements/UJruDMWcPnqfPcQj/partita/partita.py)_
> -   _Scarica la traccia in Java: [partita.java](https://gara.territoriali.olinfo.it/files//statements/UJruDMWcPnqfPcQj/partita/partita.java)_
> -   _Scarica la traccia in C#: [partita.cs](https://gara.territoriali.olinfo.it/files//statements/UJruDMWcPnqfPcQj/partita/partita.cs)_
> -   _Scarica la traccia in JavaScript: [partita.html](https://gara.territoriali.olinfo.it/files//statements/UJruDMWcPnqfPcQj/partita/partita.html)_

## Descrizione del problema

Dopo i vari passaggi preparativi del gioco, Dario è finalmente pronto per giocare una partita!

Questa si svolge su un percorso rettilineo formato da N+1N+1 caselle, numerate da 00 a NN. Inizialmente, Dario piazza sulla casella 00 i KK soldatini che è riuscito a ottenere in precedenza. Lo scopo del gioco è far arrivare almeno un soldatino sulla casella NN.

Finché c'è almeno un soldatino, Dario può farli avanzare dalla casella c<Nc<N su cui si trovano alla casella successiva, c+1c+1. Tuttavia, nel fare ciò uno dei soldatini va sacrificato: per cui, se, prima della mossa, Dario aveva ss soldatini, dopo la mossa ne ha s−1s−1.

Tuttavia, sul percorso sono presenti dei _rinforzi_: su ogni casella ii, con 0≤i<N0≤i<N, è presente un rinforzo che consiste di RiRi​ soldatini addizionali. Quando Dario si trova sulla casella ii, può decidere, subito prima di fare la mossa, se usare il rinforzo. In tal caso, RiRi​ soldatini vengono aggiunti a quelli che aveva già.

Ogni rinforzo costa una _gemma rara_ (sì, nel gioco ci sono le gemme rare), e pertanto Dario vuole usare il minimo numero possibile di rinforzi che gli permetta di vincere la partita. Aiuta Dario a determinare se è possibile vincere la partita, e in tal caso qual è il minimo numero di rinforzi necessari.

## Dati di input

La prima riga del file di input contiene un intero TT, il numero di casi di test. Seguono TT casi di test, numerati da 11 a TT. Ogni caso di test è preceduto da una riga vuota.

Ogni caso di test è composto come segue:

-   la prima riga contiene gli interi NN e KK.
-   la seconda riga contiene gli NN interi R0,R1,…,RN−1R0​,R1​,…,RN−1​.

## Dati di output

Il file di output deve contenere la risposta ai casi di test che sei riuscito a risolvere. Per ogni caso di test che hai risolto, il file di output deve contenere una riga con la dicitura:

```
Case #t: x
```

dove `t` è il numero del caso di test (a partire da 11) e il valore `x` è −1−1 se Dario non può vincere la partita, altrimenti il minimo numero di rinforzi che deve usare per vincere.

## Assunzioni

-   T=25T=25, nei file di input che scaricherai saranno presenti esattamente 1010 casi di test.
-   3≤N≤1000003≤N≤100000
-   1≤K≤10000001≤K≤1000000
-   0≤Ri≤10000000≤Ri​≤1000000 per ogni i=0,…,N−1i=0,…,N−1.

Nei primi 55 casi di test vale N≤1000N≤1000.

## Esempi di input/output

---

**Input:**

```
3

6 5
0 1 2 1 2 0

7 3
1 0 0 0 0 2 1

10 2
3 2 4 3 4 2 2 4 5 1
```

---

**Output:**

```
Case #1: 1
Case #2: -1
Case #3: 3
```

---

## Spiegazione

Nel **primo caso d'esempio**, Dario ha inizialmente 5 soldatini sulla casella 0 e può vincere la partita prendendo un solo rinforzo, giocando nel modo seguente:

-   Con la prima mossa avanza alla casella numero 1, rimanendo con 4 soldatini.
-   Con la seconda mossa avanza alla casella numero 2, rimanendo con 3 soldatini.
-   Usa il rinforzo nella casella numero 2, arrivando a 5 soldatini.
-   Successivamente può avanzare fino alla casella 6, arrivandoci con 1 soldatino, vincendo la partita.

Nel **secondo caso d'esempio**, Dario non può vincere la partita. Infatti, anche prendendo ogni rinforzo sulla strada, si ritroverebbe nella casella 3 con 1 soldatino e senza rinforzi da prendere. Il soldatino morirebbe avanzando alla casella 4, concludendo la partita.

Nel **terzo caso d'esempio**, la risposta è 3. Questo risultato si può ottenere prendendo i rinforzi sulle caselle 0, 2 e 4.