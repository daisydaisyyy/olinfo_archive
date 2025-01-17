#include <bits/stdc++.h>
using namespace std;

void solve(int t) {
    int K;
    cin >> K;
    int A, B, C, D;
    cin >> A >> B >> C >> D;

	int x = A;
	
	
		while (x-- and K != 0) { A--; D++; K--;}

		x = B; 
		while (x-- and K != 0) { B--; D++; K--;}

	
		x = C; 
		while (x-- and K != 0) { C--; D++; K--;}

	
    // aggiungi codice...
	//cout << A << " " << B << " " << C << " " << D << endl;
    int risposta = A + B * 2 + C * 3 + D * 4;

    cout << "Case #" << t << ": " << risposta << "\n";
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("in.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}

