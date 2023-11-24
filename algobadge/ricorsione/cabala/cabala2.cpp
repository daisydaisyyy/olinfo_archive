#include <stdio.h>
#include <assert.h>
#include <fstream>
#include <iostream>

using namespace std;

/*
Giorgio vuole entrare nella setta Oli-3, in cui si studiano numeri occulti e misteriosi con cui dominare
il mondo. Per essere ammesso, gli viene richiesto di provare il suo valore individuando il numero della
cabala C. Dopo lunghe e dicoltose ricerche, Giorgio è riuscito a scoprire che questo numero:
• ha al più N cifre;
• tutte le sue cifre sono multiple di 3 (ma nessuna è zero);
• non vi sono due cifre adiacenti uguali;
• il resto di C modulo un certo numero M è più grande possibile.
Aiuta Giorgio a trovare il numero della Cabala ed entrare quindi nella agognata setta!
*/

// N = numero cifre 
// M = modulo
//La funzione dovrà restituire il massimo resto per un numero C che rispetta i vincoli nel testo modulo M
long long maxR = -1; // massimo resto trovato

long long occulta(long long N, long long M, long long currentNumber, long long currR, long long counter) {
    // base case: raggiunte max cifre, aggiorna il massimo resto
    if (counter >= N) {
        maxR = max(maxR, currR);
        return maxR;
    }

    // Prova tutte le combinazioni di [3, 6, 9] x [1, ..., N]
    for (int digit = 9; digit >= 3 ; digit -= 3) {
        if(digit != currentNumber % 10) { // check che le cifre non siano uguali
            int nextNumber = currentNumber * 10 + digit;
            int nextResto = (currR * 10 + digit) % M;
            occulta(N, M, nextNumber, nextResto, counter + 1);
        }

    }
}


int main() {
    FILE *fr, *fw;
    int T, N, M, i;

    fr = fopen("input2.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &T));
    for (i=0; i<T; i++) {
        assert(2 == fscanf(fr, "%d %d", &N, &M));
        occulta(N, M, 0, 0, 0);
        fprintf(fw, "%d ", maxR);
        maxR = -1;
    }

    fprintf(fw, "\n");
    fclose(fr);
    fclose(fw);
    return 0;
}