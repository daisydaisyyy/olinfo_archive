/*
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>
#define MAXN 500
#define MAXH 2002

using namespace std;
constexpr int INF = 2e9;
// input data
int N;
vector<int> H;
int dp[MAXN][MAXH][2];
// dp[i][h][0] = condizione prendo elemento a destra i-1 
// dp[i][h][1] = condizoine prendo elemento i+1

int main() {
//  uncomment the following lines if you want to read/write from files
ifstream cin("input0.txt");
//  ofstream cout("output.txt");

    cin >> N;
    H.resize(N);
    for (int i=0; i<N; i++) {
        cin >> H[i];
	}

    // insert your code here
	
	// calcola monete per tutti i possibili decrementi/incrementi di altezza
	for(int h = 0; h < MAXH; h++) {  
		dp[N-1][h][0] = dp[N-1][h][1] = (H[N-1] - h) * (H[N-1] - h);
	}

	for(int i = N-2; i >= 0; i--) { // parto dal fondo 
		// se decremento l'altezza
		dp[i][0][0] = INF; // primo elemento 
		dp[i][MAXH-1][1] = INF; // ultimo elemento 
		int best = INF;
		for(int h = 1; h < MAXH; h++) {
			best = min(best, dp[i+1][h-1][1]);
			dp[i][h][0] = best + (H[i] - h) * (H[i] - h);
		}

		best = INF;
		// se incremento l'altezza
		for(int h = MAXH - 2; h >= 0; h--) {
			best = min(best, dp[i+1][h+1][0]);
			dp[i][h][1] = best + (H[i] - h) * (H[i] - h);
		}
	}

	int ans = INF;
	for(int h = 0; h < MAXH; h++) {
		ans = min({ans, dp[0][h][0], dp[0][h][1]});
		cout << ans << endl;
	}




    cout << ans << endl; // print the result
    return 0;
}
