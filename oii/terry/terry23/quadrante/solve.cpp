#include<bits/stdc++.h>


using namespace std;

// le citta' a partire da un idx i in poi non sono visitabili
// binary search per trovare quell'idx, poi controlla ad ogni iterazione se il range ha coordinate y crescenti
// k = 1 << 20 perche 1≤N≤10^5
void solve(int t) {
    int N;
    cin >> N;

    vector<pair<int,int>> coords(N);
    for(auto &x : coords) cin >> x.first >> x.second;
    

    int risposta = 0;
	 
	for(int k = 1 << 20; k; k/=2) {
		//cout << k << endl;
		int best = risposta + k; 
		if(best > N) continue; 
		vector<pair<int,int>> curr(coords.begin(), coords.begin() + best); 
		sort(curr.begin(), curr.end()); 
		bool valid = true;
		for(int i = 1; i < best; ++i) { 
			if(curr[i].second < curr[i-1].second) valid = false; 
		}
		if(valid) risposta = best;
	}


    cout << "Case #" << t << ": " << risposta << "\n";
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("in2.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}

