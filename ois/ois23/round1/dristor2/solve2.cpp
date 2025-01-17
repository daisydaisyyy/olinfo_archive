// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
#define MAXN 14
#define MAXM 100 
#define MOD 10e9 + 7
int N, M;
int dp[1 << MAXN][MAXM][MAXN+1];

int main() {
    //  uncomment the following lines if you want to read/write from files
    ifstream cin("input0.txt");
    //  ofstream cout("output.txt");
	cin >> N >> M;


	vector<int> L(M);
	bool sub1 = true; 

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
			int temp; 
			cin >> temp; 
			sub1 *= temp; 
			L[j] = (L[j] << 1) | temp; // set as true if more n see it
        }
    }

	vector<int> taken(N);
	if(sub1) {
		long long res=1;
		for(int i = N; i > 0; i--) res = (res*i) % MOD;
		cout << res << endl;
		return 0;
	}

	for (int taken = 0; taken < (1 << N); taken++) {
        int takeable = L[M - 1] & ~taken;
        dp[taken][M - 1][0] = 1;
        for (int mask = 1; mask < (1 << N); mask <<= 1) {
            if (mask & takeable)
                dp[taken][M - 1][1]++;   
        }
    }

	for(int m = M - 2; m >= 0; M --) {
		for(int taken = 0; taken < (1 << N); taken++) {
			int cantake = L[m] & ~taken; 
			for(int n = 0; n <= M; n++) 
				dp[taken][m][n] = dp[taken][m+1][n];
			
			for(int c = 1; c < (1 << N); mask <<= 1) {
				if(takeable & c) 
					for(int n = 1; n <= N; n++) 
						dp[taken][m][n] += (dp[taken][m][n] + dp[taken | mask][m+1][n-1] % MOD;
			}
		}
	}

	int i = N;
    while (!dp[0][0][i]) i--;




    cout << dp[0][0][i] << endl; // print the result

    return 0;
}
