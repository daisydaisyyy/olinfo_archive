// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;
const ll p = 31;

// strat: string hashing (see cp algorithms)

int main() {
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input0.txt");
    // ofstream cout("output.txt");

    int N;
    cin >> N;
    string S;
    cin >> S; 
    
	// precompute hashes and pows
	vector<ll> hashes(N+1); 
	vector<ll> pows(N+1,1);
	for(int i = 0; i < N; i++) {
		hashes[i + 1] = hashes[i] * p + S[i] - 'a'; // calc partial hash
		pows[i + 1] = p * pows[i]; // increment exp
	}

	vector<vector<int>> divs(N+1);
	
    for(int i = 2; i <= N; i++) {
		if(!divs[i].empty()) continue;
		for(int j = i; j <= N; j += i) 
			divs[j].push_back(j / i);
	}
    
	auto range_hash = [&](int l, int r) {
		return hashes[r] - (hashes[l] * pows[r - l]);
	};

	int Q;
	cin >> Q;
	while(Q--) {
		int l, r; 
		cin >> l >> r;
		r++;

		bool pal = false; 
		for(auto div: divs[r-l]) {
			if(div == r - l) continue; 
			ll h1 = range_hash(l, r - div); 
			ll h2 = range_hash(l + div, r); 

			if(h1 == h2) {
				pal = true; 
				break;
			}
		}
		if(pal) cout << "YES" << endl; 
		else cout << "NO" << endl;
	}

    
    return 0;
}
