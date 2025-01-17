// NOTE: it is recommended to use this even if you don't understand the following code.

#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;
int main() {
    // uncomment the two following lines if you want to read/write from files
    //ifstream cin("input0.txt");
    // ofstream cout("output.txt");

    int N, M;
    cin >> N >> M;

    vector<int> T(N);
    for (int i = 0; i < N; ++i)
        cin >> T[i];

    vector<int> P(N);
    for (int i = 0; i < N; ++i)
        cin >> P[i];

    int K = 0;


    // INSERT YOUR CODE HERE
	int tot_time = accumulate(T.begin(),T.end(),0);
	vector<ll> best(tot_time + 1,0); 
	best[0] = 0;


	for(int i = 0; i < N; i ++) {
		for(int j = T[i]; j <= tot_time; j++) { // for every time unit, calc if it's best to repeat the job 
			best[j] = max(best[j], P[i] + best[j - T[i]]);
		}
	}
	if(M <= tot_time) {
		cout << best[M] << endl; 
		return 0; // already computed max time best 
	}

	long long fitting = -1; 
	int rem = M - tot_time; // remaining time to compute 
	for(int i = 0; i  < N; i++) {
		int cnt = (rem + T[i] - 1) / T[i]; // set remaining time units per T[i]
		fitting = max(fitting, (ll) cnt * P[i] + best[M - cnt * T[i]]); // find best fitting setup for remaining time
	}

    cout << fitting << endl;

    return 0;
}
