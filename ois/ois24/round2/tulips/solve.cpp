// NOTE: it is recommended to use this even if you don't understand the following code.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
#define INF 1e8
int main() {
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input1.txt");
    // ofstream cout("output.txt");

    int N, K;
    cin >> N >> K;
    
    vector<int> A(N);
    for (auto &x : A) cin >> x;
    
    long long M = 0;
    
    
    // INSERT YOUR CODE HERE
	// \
	// strat: use stacks to handle it
	vector <ll> dp(N+1); 
	vector<ll> prev_dp(N+1, -INF);
	prev_dp[N] = 0;
	
	for(int b = 1; b <= K; b++) {
		stack<pair<ll, int>> minimum; 
		stack<pair<ll, int>> best; 

		dp[N] = -INF; 
		
		for(int i = N-1; i >= 0; i--) {
			ll curr_best = prev_dp[i+1]; 
			
			// iterate through best confs and set best 
			while(!minimum.empty() and A[minimum.top().second] >= A[i]) {
				auto [val, idx] = minimum.top(); 
				minimum.pop(); 

				if(!best.empty() and best.top().second == idx) best.pop(); // evaluating the current best, skip that element  
				curr_best = max(curr_best, val); // set best 

			}

			// build the min stack 
			minimum.emplace(curr_best, i); 

			// emplace curr best conf in best stack
			if(best.empty() or best.top().first < curr_best + A[i]) best.emplace(curr_best + A[i], i); 

			dp[i] = best.top().first; // update memo

		}
		swap(dp, prev_dp); // set next memo

	}

    cout << prev_dp[0] << endl;

    return 0;
}
