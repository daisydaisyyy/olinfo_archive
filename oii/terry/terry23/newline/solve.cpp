#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long long int ll;
void solve(int t) {
    int N;
    cin >> N;

    vector<int> W(N);
	//vector<int> s(N,0);
	//vector<int> sm(N,0);
	ll j = 0, curr = -1, currm = 10e9;
	ll s=0, sm=10e9;
	for (auto &x : W) cin >> x;
	

    for (int i = 0; i < N; i++) {
        
		//cout << W[i] << endl;
		if (W[i] == -1 or i == N-1) {
			if(i == N-1 and W[i] != -1) {
				s += W[i];
				//sm = s ;
			}
			//cout << "s: " << s << endl;
			curr = max(curr, s);
			if(W[i] == -1) {
				sm = s + W[i+1]-1;
				//cout << "i+1: " << W[i+1] << endl;
			}
			//cout << "sm: " << sm << endl;
			currm = min(currm, sm);
			s = 0; sm = 10e9;
		} else s += W[i] + 1;

    }

    // aggiungi codice...
    int K1 = curr, K2 = currm;

    cout << "Case #" << t << ": " << K1 << " " << K2 << "\n";
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("in0.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}
