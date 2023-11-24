#include <stdio.h>
#include <assert.h>
#include <vector>
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
int maxResto = -1; // massimo resto trovato

long long occulta(long long N, int M) {
    
    long long ans = 0; 
    long long d = 0;
    
    for(int i = 0; i < N; i++) {
        if(i % 2 == 0)d = d * 10 + 9; 
        else d = d * 10 + 6; 
    }
    
    long long dummy = stoll(d); 
    
    while(d > 0) {
    //     string d = to_string(dummy); 
        bool check = true; 
        // for(long long i = 0; i < N; i++) 
        //     if(c != '3' && c != '6' && c != '9') {
        //         //if(c == '0') c = '9'; 
        //         check = false; 
        //         break; 
        //     }
        for(int i = 1; i < d.size() && check; i++) 
            if(d[i] == d[i-1]) 
                {check = false; break; }
        if(check) 
            ans = max(dummy % M, ans); 
        dummy-=3; 
    }
    
    return ans; 
}


// long long occulta(int N, int M) {
//     // base case: 

// }


int main() {
    FILE *fr, *fw;
    int T, N, M, i;
    cout << "start: ";
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &T));
    
    for (i=0; i<T; i++) {
        assert(2 == fscanf(fr, "%d %d", &N, &M));
        fprintf(fw, "%d ", findMaxResto(N, M, 0, 0));
    }

    fprintf(fw, "\n");
    fclose(fr);
    fclose(fw);
    return 0;
}