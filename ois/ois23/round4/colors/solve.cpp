// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
constexpr int MOD = 1e9 + 7;

int main() {
    // uncomment the following lines if you want to read/write from files
	ifstream cin("input0.txt");
    // ofstream cout("output.txt");

    int N, K;
    cin >> N >> K;
	ll sol = 1;
    vector<int> V(N);
	vector<int> hats(N+1);
	hats[0] = K;
    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }

	// on hats[0], we can have any color. 
	// starting from 1, we can distribute the colors to the next positions 
	for(int i = 0; i < N; i++) {
		sol = (sol * hats[V[i]]) % MOD;
		hats[V[i]]--;
		hats[V[i] + 1]++;
	}

	cout << sol << endl;

    return 0;
}
