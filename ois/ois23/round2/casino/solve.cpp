// NOTE: it is recommended to use this even if you don't understand the following code.

#include <bits/stdc++.h>
using namespace std;

int N, M;

vector<int> solve(string s) {
	vector<int> C(M), P(M); // p = position of the words
	vector<int> cnt(max(M, 26));
	for(int i = 0; i < M; i++) cnt[s[i]-'a']++;
	for(int i = 0; i < cnt.size(); i++) cnt[i] += cnt[i-1];
	for(int i = 0; i < M; i++) P[--cnt[s[i]-'a']] = i; // assegna un indice a ciascuna lettera in base a quando appare nella stringa 

	int groups = 0; 

	for(int i = 1; i < M; i ++) { // create groups for different letters
		if(s[P[i]] != s[P[i]-1]) groups++;
		C[P[i]] = groups;
	}

	for(int size=1; size < M; size*=2) { // store string 1 from 0-size, 2 from size-...
		vector<int> Pn(M), Cn(M); 
		for(int i = 0; i  < M; i ++) {
			Pn[i] = P[i] - size;
			if(Pn[i] < 0) Pn[i] += M; 
		}

		fill(cnt.begin(),cnt.end(), 0); 
		for(int i = 0; i < M; i++) cnt[C[Pn[i]]]++;
		for(int i = 0; i < cnt.size(); i++) cnt[i] += cnt[i-1]; 
		for(int i = M-1; i >= 0; i--) P[--cnt[C[Pn[i]]]] = Pn[i]; 
		groups = 0;
		Cn[P[0]]=0; 

		for(int i = 0; i < M; i++) {
			pair<int,int> curr = {C[P[i]], C[P[i]+size % M]};
			pair<int,int> prev = {C[P[i-1]], C[P[i-1]+size % M]};
			if(curr != prev) groups++; 
			Cn[P[i]] = groups;
		}
		C = Cn;
	}
	return P;
}


string r(string s) {
	int a = solve(s)[0]; 
	return s.substr(a) + s.substr(0, a);
}


int main() {
    // uncomment the following lines if you want to read/write from files
    ifstream cin("input0.txt");
    // ofstream cout("output.txt");
    cin >> N >> M;
    map<string, int> repr;
    while(N--){
        string S; cin >> S;
        repr[r(S)]++;
    }

    long long tot = 0;
    for (auto [_, am]: repr) tot += am * (am - 1) / 2;
    cout << tot << endl;
    
    return 0;
}
