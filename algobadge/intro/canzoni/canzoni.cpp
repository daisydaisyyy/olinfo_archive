#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <numeric>

using namespace std;

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T, t;
    cin >> T;

    for (t = 1; t <= T; t++) {
        int N, F, C;
        
        // scrivi in queste variabili la risposta
        int nf = 0, nc = 0;

        cin >> N >> F >> C;

        // RISOLVI QUI IL PROBLEMA!!
        int c = N;
        nf = N / F;

        //remaining space
        if(N - (nf * F) > C) {
            nc = (N - (nf * F)) / C;
        }

        cout << "Case #" << t << ": " << nf << " " << nc << endl;
    }
}

