#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


void precalculateMatches(int A, int B) {
    if (A < 33 || B < 33) {
        cout << "-1 -1" << endl;
        return;
    }

    for (int sets = 0; sets < 3; ++sets) {
        int scoreA, scoreB;
        if (sets < 2) {
            scoreA = min(A - sets * 11, 11);
            scoreB = min(B - sets * 11, 11);
        } else {
            scoreA = min(A - 2 * 11, 11);
            scoreB = min(B - 2 * 11, 11);
        }

        if (scoreA >= 0 && scoreB >= 0) {
            cout << scoreA << " " << scoreB << endl;
            A -= scoreA;
            B -= scoreB;
        } else {
            cout << "-1 -1" << endl;
            return;
        }
    }
}


int main() {
    ifstream cin("input0.txt");
    //ofstream cout("output.txt");
    int T;
    cin >> T;

    while (T--) {
        int A, B;
        cin >> A >> B;

        precalculateMatches(A, B);
    }

    return 0;
}