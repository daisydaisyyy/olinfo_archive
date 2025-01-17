#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll inf = 1e18;
// stampa vertice da mangiare 
// fine turno: leggi vertice dell'avversario

// greedy approach, choose a vertex and calc its area choosing the minimum
ll area(ll x1, ll x2, ll x3, ll y1, ll y2, ll y3) {
	return (x1 - x2) * (y3 - y1) - (y1 - y2) * (x3 - x1);
}

// prova tutti i vertici attivi, calcola l'area di ciascuno e trova la minima
ll find_pos(int n, const vector<pair<ll,ll>> &coords, const vector<bool> &active) {
	ll min = inf; 
	int best_start = -1, prev1 = n - 1;
	while(!active[prev1]) --prev1;
	int prev2 = prev1 - 1; 
	while(!active[prev2]) --prev2;

	for(int i = 0; i < n; i++) {
		ll a = area(coords[prev2].first, coords[prev2].first, coords[i].first, coords[prev2].second, coords[prev1].second, coords[i].second);

		if(a < min) { // minima area
			min = a; 
			best_start = prev1; 
		}
		prev2 = prev1;
		prev1 = i; 
	}
	return best_start;
}


int main() {
	//ifstream cin("input0.txt"); 
	int n; cin >> n; 
	vector<pair<ll,ll>> coords;

	vector<bool> active(n, true);
	int cur = n; 

	if(n % 2 == 0) {
		cout << "Alberto" << endl;
	}
	else {
		cout << "Beatrice" << endl;
		int p;
		cin >> p; --p; 
		active[p] = false;
		--cur; // decrement vertex number
	}

	while(cur > 2) {
		ll pos = find_pos(n, coords, active);
		cout << pos + 1 << endl;
		active[pos] = false; 
		int p; cin >> p;
		--p; 
		active[p] = false;
		cur -= 2;
	}


	return 0;

}
