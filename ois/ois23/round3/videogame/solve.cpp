// NOTE: it is recommended to use this even if you don't understand the following code.

#include <bits/stdc++.h>
using namespace std;

int main() {
    // uncomment the following lines if you want to read/write from files
    ifstream cin("input0.txt");
    // ofstream cout("output.txt");
	
	int T;
	cin >> T;
	
    int N;
    cin >> N;
	
	vector<pair<int,int>> me(N); 
	for (auto &x: me) cin >> x.first >> x.second; 
	
	int M;
	cin >> M;
	


	vector<pair<int,int>> hano(M);
	for (auto &x: hano) cin >> x.first >> x.second;
	
	sort(me.begin(),me.end()); 
	sort(hano.begin(), hano.end());

	long long tot = 0; 
	int last, pos_hano = 0;
	for(auto [start, end]: me) {
		last = start; 

		while(hano[pos_hano].second < start and pos_hano < M) pos_hano++; // reach my start of break 

		if(pos_hano == M) break;

		while(hano[pos_hano].first <= end and pos_hano < M) {
			if(hano[pos_hano].first - last > T) break;
			last = hano[pos_hano].second; 
			tot += min(end, hano[pos_hano].second) - max(start, hano[pos_hano].first) + 1; 
			pos_hano++;
		} 
		pos_hano--;

	}

    cout << tot << endl; // print the result
    return 0;
}
