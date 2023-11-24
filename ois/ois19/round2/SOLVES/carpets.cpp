// Scansiona una volta la matrice e man mano che incontra un valore
// aggiorna le coordinate massime/minime a cui lo ha trovato.
// Complessità: O(R*C) 
// Lineare in memoria (NON memorizza tutto l'input)

#include <iostream>
#include <fstream>
using namespace std;
#define MAXK 10000+1

int R, C, K;
int min_i[MAXK], max_i[MAXK], min_j[MAXK], max_j[MAXK];

int main() {
    ifstream cin("input0.txt");
    cin >> R >> C >> K;
    
    for (int k = 1; k <= K; k++) {
        min_i[k] = R;
        min_j[k] = C;
        max_i[k] = -1;
        max_j[k] = -1;
    }
    
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            int val;
            cin >> val;
            if (val > 0) {
                int real_i = R-1-i;
                cout << min_i[val] << endl;
                if (real_i < min_i[val]) min_i[val] = real_i;
                if (j < min_j[val]) min_j[val] = j;
                if (real_i > max_i[val]) max_i[val] = real_i;
                if (j > max_j[val]) max_j[val] = j;
            }
        }
    
    for (int k = 1; k <= K; k++)
        std::cout << min_j[k] << " " << min_i[k] << " " << max_j[k]+1 << " " << max_i[k]+1 << std::endl;
    
    return 0;
}
