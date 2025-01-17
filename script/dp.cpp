// dp example, dp has dimension space = states of the problem i need to track
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MAXN 1001

// input data
int N, K;
vector<int> T;
ll dp[MAXN][MAXN][3]; // cell, turns, doubles


ll solve(int cell, int doubles, int turn) {
	if(turn == K) return 0; // base case
	if (doubles == 3) return solve(cell, 0, turn + 1); // three double throws, go to next turn

	if(dp[cell][turn][doubles] != -1) return dp[cell][turn][doubles]; // already memorized

	ll max_score = LONG_LONG_MIN; 
	for(int first_d = 1; first_d <= 6; ++first_d) { // first and second dice
		for(int second_d = 1; second_d <= 6; ++second_d) {
			int next_cell = (first_d + second_d + cell) % N; // calc next cell position
			if(first_d == second_d) max_score = max(max_score, solve(next_cell, doubles+1, turn) + T[next_cell]); // double throw, continue the turn
			else max_score = max(max_score, solve(next_cell, 3, turn) + T[next_cell]); // not doubles, go to next turn 	
		}
	}
	dp[cell][turn][doubles] = max_score; 
	return dp[cell][turn][doubles];

}


int main() {
    //  uncomment the following lines if you want to read/write from files
    //ifstream cin("input1.txt");
    //  ofstream cout("output.txt");

	int turns, cells; 
    cin >> N >> K;
    T.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }

    // insert your code here
	memset(dp, -1, sizeof dp);

    cout << solve(0, 0, 0) << endl;  // print the result
    return 0;
}

