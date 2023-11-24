// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <list>

using namespace std;

typedef pair<int, int> nodoPesato;

// input data
int N;
vector<int> V;
vector<int> A;
vector<int> B;

int main() {
	// uncomment the following lines if you want to read/write from files
	ifstream cin("input.txt");
	// ofstream cout("output.txt");

    cin >> N;
    V.resize(N + 1);
    A.resize(N);
    B.resize(N);
    for (int i = 1; i <= N; i++)
        cin >> V[i];
    for (int i = 1; i < N; i++)
        cin >> A[i] >> B[i];


    // relazioni
    int iniziofine[2] = {-1, -1};

//    Calcolo inizio e fine
    for (int i = 1; i < N + 1; i++) {
        int conta = 0;
        for (int j = 1; j < N; j++) {
            if (A[j] == i || B[j] == i) {
                conta++;
            }
        }
        if (conta == 1) {
            if (iniziofine[0] == -1) {
                iniziofine[0] = i;
            }
            else {
                iniziofine[1] = i;
            }
        }
    }

//    cout << iniziofine[0] << " " << iniziofine[1] << endl;

    int current = iniziofine[0];
    bool finished = false;
    vector<int> strada(N, 0);
    int c = 0;
    while (!finished) {
        if (current == iniziofine[1])
            break;

        // trovare relazioni di current
        if (current == iniziofine[0]) {
            // Primo ciclo
            int rel = -1;
            for (int i = 0; i < N; i++) {
                if (A[i] == current) {
                    rel = B[i];
                }
                else if (B[i] == current) {
                    rel = A[i];
                }
            }

            strada[c++] = current;
            strada[c++] = rel;
            //cout << "rel" << rel << endl;
            current = rel;
        }
        else {
            int rel = -1;
            for (int i = 0; i < N; i++) {
                if (A[i] == current && B[i] != strada[c - 2]) {
                    rel = B[i];
                }
                else if (B[i] == current && A[i] != strada[c - 2]) {
                    rel = A[i];
                }
            }
            strada[c++] = rel;
            current = rel;
        }
    }

    long long int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
//            cout << strada[i] << "->" << strada[j] << endl;
            int mcd = __gcd(V[strada[i]], V[strada[j]]);

            if (mcd != 1) {
                // Strada fattibile
                for (int k = i; k < j + 1; k++) {
                    sum += V[strada[k]];
                }
            }
        }
    }


    cout << sum << endl; // print the result
    return 0;
}
