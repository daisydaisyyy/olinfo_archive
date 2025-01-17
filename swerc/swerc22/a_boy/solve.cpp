#include<bits/stdc++.h>
using namespace std;

constexpr int maxtime = 1440; 
constexpr int walk = 120;

void solve() {
	int n; cin >> n; 
	vector<int> v(n + 2);
	for(auto i : &v) cin >> i;
	v[n+1] = maxtime;
	int counter = 0; 
	for(int i = 0; i < n + 1; i++) {
		counter += (v[i+1] - v[i]) / walk;
	}
	cout << counter >= 2? "YES" : "NO" << endl;
}


int main() {
	ifstream cin("input0.txt"); 

	int t; cin >> t;
	while(t--) {
		solve();
	}

	return 0;

}
