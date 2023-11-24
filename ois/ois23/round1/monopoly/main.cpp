// Libreria che include molte standard library di c (in questo caso viene usato iostream e vector) ma logicamente aumenta il tempo di compilazione e la dimensione del file
// (cose non importanti visto che conta solo il runtime alle olinfo)
#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;

int main() {
    // Input
    int caselle, turni;
    cin >> caselle >> turni;
    vector<LL> tabellone(caselle);
    for (int i = 0; i < caselle; ++i) {
        cin >> tabellone[i];
    }
    // Praticamente il max Long Long int (sostituibile con max long long int)
    // static e constexpr sono praticamente inutili, creano una variabile INF di tipo long long int che viene salvata dentro la memoria a compilazione del programma e non a runtime (inutile per salvare solo un intero)
    static constexpr LL INF = 1e15;
    // Memory per la programmazione dinamica (inizializzata a -INF, il caso peggiore)
    vector<LL> memory(caselle, -INF);
    // Inizializzazione di memory a 0 visto che per arrivare a l'indice 0 il costo e' 0 :)
    memory[0] = 0;
    // Vettore di backup per la memory che viene "copiato" ogni turno per tenere conto se il tiro del turno prima puo essere migliore di questo di un turno dopo
    vector<LL> backupMemory(caselle);
    while (turni--) {
        // Copio memory in backupMemory (shallow copy, in teoria)
        backupMemory = memory;
        memory.assign(caselle, -INF);
        // Calcolo per tutti i possibili tentativi di memory
        for (int i = 0; i < caselle; i++) {
            // Case per i dispari
            for (int a = 3; a < 12; a++) {
                // Calcolo indice per la memory (partenza + arrivo) mod numero di caselle (Esempio: 12 caselle, i = 6, a = 12) = 6 (indice corretto)
                int ii = (i + a) % caselle;
                // Assegno alla memory il caso migliore tra la memory precedente e il percorso che va da i (num di partenza) e ii (num di arrivo)
                memory[ii] = max(memory[ii], backupMemory[i] + tabellone[ii]);
            }
            // Case solo pari
            for (int a = 2; a <= 12; a += 2) {
                // Calcolo indice per la memory (partenza + arrivo) mod numero di caselle (Esempio: 12 caselle, i = 6, a = 12) = 6 (indice corretto)
                int ii = (i + a) % caselle;
                // Calcolo un lancio pari (a) e un lancio dispari (b)
                for (int b = 3; b < 12; b++) {
                    // Calcolo indice per la memory ii (indice di partenza pari) + b (indice dispari di fine turno) mod num caselle
                    int jj = (ii + b) % caselle;
                    // Controllo il migliore tra il lancio diretto sul dispari o effettivamente con il passaggio sul numero pari
                    memory[jj] = max(memory[jj], backupMemory[i] + tabellone[ii] + tabellone[jj]);
                }
            }
            // Case 3 turni pari (triplo lancio in un turno)
            for (int a = 2; a <= 12; a += 2) {
                for (int b = 2; b <= 12; b += 2) {
                    // Calcolo indice di a (lancio iniziale)
                    int ii = (i  + a) % caselle;
                    // Calcolo indice di b (secondo lancio)
                    int jj = (ii + b) % caselle;
                    // Ciclo per il terzo lancio (dispari o pari visto che comunque e' l'ultimo lancio)
                    for (int c = 2; c <= 12; c++) {
                        // Indice di c (b + c) mod caselle
                        int kk = (jj + c) % caselle;
                        // Trovo il migliore tra il precedente lancio nella memory o un lancio combinato di 3 lanci pari + pari + pari/dispari
                        memory[kk] = max(memory[kk], backupMemory[i] + tabellone[ii] + tabellone[jj] + tabellone[kk]);
                    }
                }
            }
        }
    }
    // max element ritorna il pointer dell'elemento piu grande in un vettore. Viene deferenziato con *
    cout << *max_element(begin(memory), end(memory)) << "\n";
}