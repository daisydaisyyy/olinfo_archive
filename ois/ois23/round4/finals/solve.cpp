// NOTE: it is recommended to use this even if you don't understand the following code.

#include <bits/stdc++.h>
using namespace std;

int main() {
    // uncomment the following lines if you want to read/write from files
    ifstream cin("input1.txt");
    // ofstream cout("output.txt");

    int N, P;
    cin >> N >> P;
    vector<int> sums;
    int a, b, c;
    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c; 
		sums.push_back(a + b + c);
    }

	sort(sums.begin(), sums.end());

	// difference between highest overall score (Davide) and the 2nd highest 
    cout << (max(0, sums[N - 2] + P * 100 - sums[N-1] + 1)) << endl; // print the result
    
    return 0;
}
