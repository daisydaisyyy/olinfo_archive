// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

/*
array of length N , such that L ≤ ai ≤ R for every element in the array, and
the sum of all elements in the array modulo M is equal to K
the number of different arrays that satisfy this property
*/

const int MOD = 1e9 + 7;
long long N;
int M, L, R, K;



int main() {
    // uncomment the following lines if you want to read/write from files
    ifstream cin("input0.txt");
    // ofstream cout("output.txt");
    cin >> N >> M >> L >> R >> K;

    // insert your code here
	vector<long long int> curr(M);

	for(int i = 0; i < M; i++) {
		// find (L, R | M ) +1
		int l = L / M * M + i; 
		int r = R / M * M + i;
		if(l < L) l += M; 
		if(r <= R) r += M;

		curr[i] =  (r-l) / M;
	}

	vector<long long int> ans(M); 
	ans[0] = 1;

	for(; N; N >>= 1) {
		// set new result
		if(N & 1) {
			vector<long long> nans(M); 
			for(int m = 0; m < M; m++) {
				for(int i = 0; i < M; i++) { 
					nans[m] = (nans[m] + ans[i] * curr[(m - i + M) % M]) % MOD; // set new elem of the array
				}
			}
			ans = nans;
		}

		vector<long long> ncurr(M); 
		for(int m = 0; m < M; m++) {
			for(int i = 0; i < M; i++) {
				ncurr[m] = (ncurr[m] + curr[i] * curr[(m - i + M) % M]) % MOD;
			}
		}
		curr = ncurr;
	}
    cout << ans[K] << endl; // print the result
    return 0;
}
