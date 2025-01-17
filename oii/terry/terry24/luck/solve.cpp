// NOTA: si raccomanda di usare questo template anche se non lo si capisce completamente.

#include <bits/stdc++.h>

using namespace std;


vector<int> find_divs(int N) {
	vector<int> divs;
	for(int i = 1; i * i <= N; i++) {
		if(N % i == 0) {
			divs.push_back(i);
			if(i != N / i) { 
				divs.push_back(N / i);
			}
		}
	
	}
	return divs;

}


int solve(int N, const vector<int>& R) {
	vector<int> divs = find_divs(N); 
	int count = 0; 

	for(int K : divs) {
		bool found = true; 
		for(int i = 0; i < N; i++) {
			if(R[i] != R[(i+K) % N]) {
				found = false; 
				break;
			}
		}
		if(found) ++count;

	}
	return count;


}



int main() {
    // decommenta le due righe seguenti se vuoi leggere/scrivere da file
    //ifstream cin("in1.txt");
    //ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N;
        cin >> N;

        vector<int> R(N);
        for (int i = 0; i < N; ++i)
            cin >> R[i];

        int x = 0;


        // INSERISCI IL TUO CODICE QUI
		




        cout << "Case #" << test << ": ";
        cout << solve(N,R) << endl;
    }

    return 0;
}

