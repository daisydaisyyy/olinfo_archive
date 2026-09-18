#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;

const int INF = 1e9; // Un numero molto grande per indicare "nessuna torre trovata"

int main() {
    // Ottimizzazione I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<int> H(N);
    int max_h = -1;
    int max_idx = -1;

    for (int i = 0; i < N; ++i) {
        cin >> H[i];
        // Troviamo subito la torre più alta per escluderla dopo
        if (H[i] > max_h) {
            max_h = H[i];
            max_idx = i;
        }
    }

    // Vettori per salvare l'indice della torre più alta a sx e a dx
    vector<int> left_greater_idx(N, -1);
    vector<int> right_greater_idx(N, -1);

    // 1. Stack Monotono per trovare il PREVIOUS Greater Element (Sinistra)
    stack<int> s_left;
    for (int i = 0; i < N; ++i) {
        // Rimuovo chi è più basso di me, non serve più
        while (!s_left.empty() && H[s_left.top()] < H[i]) {
            s_left.pop();
        }
        
        if (!s_left.empty()) {
            left_greater_idx[i] = s_left.top();
        }
        
        s_left.push(i);
    }

    // 2. Stack Monotono per trovare il NEXT Greater Element (Destra)
    stack<int> s_right;
    for (int i = N - 1; i >= 0; --i) {
        while (!s_right.empty() && H[s_right.top()] < H[i]) {
            s_right.pop();
        }
        
        if (!s_right.empty()) {
            right_greater_idx[i] = s_right.top();
        }
        
        s_right.push(i);
    }

    // 3. Calcolo "Enlightenment Score"
    long long total_score = 0;

    for (int i = 0; i < N; ++i) {
        if (i == max_idx) continue; // La torre più alta va ignorata

        int dist_left = INF;
        int dist_right = INF;

        // Se esiste una torre più alta a sinistra, calcolo la distanza
        if (left_greater_idx[i] != -1) {
            dist_left = i - left_greater_idx[i];
        }

        // Se esiste una torre più alta a destra, calcolo la distanza
        if (right_greater_idx[i] != -1) {
            dist_right = right_greater_idx[i] - i;
        }

        // Prendo la minima tra le due distanze
        total_score += min(dist_left, dist_right);
    }

    cout << total_score << endl;

    return 0;
}