#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
int area;

// void stampa_matrix(vector<vector<int>>& tris) {  // solamente per debugging
//     for (int i = 0; i < tris.size(); i++) {
//         for (int j = 0; j < tris[i].size(); j++) {
//             cout << tris[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << endl;
// }

bool is_safe(int x, int y, vector<vector<int>>& tris) {  // si accerta che mettendo una x, non avvenga nessun tris
    if (N - x - 1 >= 2) {

        // horizontal
        if (tris[y][x + 1] && tris[y][x + 2]) {
            return false;
        }

        // diag to right
        if (M - y - 1 >= 2) {
            if (tris[y + 1][x + 1] && tris[y + 2][x + 2]) {
                return false;
            }
            if (tris[y + 1][x] && tris[y + 2][x]) {
                return false;
            }
        }
    }
    if (y >= 2) {

        if (N - x - 1 >= 2) {
            if (tris[y - 1][x + 1] && tris[y - 2][x + 2]) {
                return false;
            }
        }
        if (x >= 2) {
            if (tris[y - 1][x - 1] && tris[y - 2][x - 2]) {
                return false;
            }
        }

        // vertical
        if (tris[y - 1][x] && tris[y - 2][x]) {
            return false;
        }
    }

    if (x >= 2) {
        if (tris[y][x - 1] && tris[y][x - 2]) {
            return false;
        }
        if (M - y - 1 >= 2) {
            if (tris[y + 1][x - 1] && tris[y + 2][x - 2]) {
                return false;
            }
            if (tris[y + 1][x] && tris[y + 2][x]) {
                return false;
            }
        }
    }

    if (M - y - 1 >= 2) {
        if (N - x - 1 >= 2) {
            if (tris[y + 1][x + 1] && tris[y + 2][x + 2]) {
                return false;
            }
            if (tris[y + 1][x - 1] && tris[y + 2][x - 2]) {
                return false;
            }
        }
        if (tris[y + 1][x] && tris[y + 2][x]) {
            return false;
        }
    }

    return true;
}

int gioca(int x, int y, vector<vector<int>>& tris, int curr, int max_found) {  // funzione recursiva
    if (x >= N) {                                                              // se è finita la riga
        return gioca(0, y + 1, tris, curr, max_found);
    }

    if (y >= M) {  // se sono finite le colonne, quindi si è visto tutto
        return curr;
    }

    int piazzate = (N * y) + x;
    if (ceil(((area - piazzate) * (float)2 / 3) + curr) < max_found) {  // ottimizzazione che ti fa fare 60 pt (avrei voluto scoprirlo prima)
        return -1;                                                      // per farla breve, se le x di questa soluzione + i 2/3 delle caselle libere < il totale che ho già trovato in un altra soluzione
    }                                                                   // non ha senso continuare
    //^ casi base

    // casi specifici
    int res = 0;

    bool safe = is_safe(x, y, tris);
   int tmp = tris[y][x]; 
    if (safe) {
        tris[y][x] = 1;
        res = gioca(x + 1, y, tris, curr + 1, max(res, max_found));
        if (!tmp) tris[y][x] = 0;                                 
    }

    if (tmp) {
        return max(res, max_found);
    } else {
        return max(res, gioca(x + 1, y, tris, curr, max(res, max_found))); 
    }
}

int main() {
    cin >> N >> M;
    assert(cin.good());

    int found = 0;
    vector<vector<int>> G(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int tmp;
            cin >> tmp;

            G[i][j] = tmp;
            if (tmp) {
                found++;  // con una variabile tengo conto delle x già presenti nell'input
            }
        }
    }

    area = N * M;  // mi serve per l'ottimizzazione

    int tmp = N;  // scambio le variabili per renderla compatibile con il codice scritto sopra
    N = M;
    M = tmp;

    int res = gioca(0, 0, G, 0, found);  //(x, y, &matrix, curr, max_found)
    cout << res - found << endl;         // al risultato tolgo quelle già trovate
}
