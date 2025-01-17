#include <iostream>
using namespace std;
#include <algorithm>



int main() {
	int N,K;
	cin >> N >> K;

	vector<int> v(N);
	for(int i = 0; i < N; i ++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int best;
	for(int i = 0; i < N-K+1; ++i) 
		best = min(best, v[i+K-1] - v[i]);

	cout << best << endl;


}
