#include<bits/stdc++.h>
using namespace std;

const int MAXN = 505;
const long long INF = 1e8;
//long long dp[MAXN][MAXN]; // max number of bricks we can remove from the worst case in any interval [l,r[
//long long bricks[MAXN];
int main() {
	ifstream cin("input2.txt"); 
	int n, h; cin >> n >> h; 

	long long dp[n][n]; // max number of bricks we can remove from the worst case in any interval [l,r[
	long long bricks[n];

	for(int i = 0; i < n; i++) {
		long long a; cin >> a; 
		bricks[i] = a;
	}

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j <= n; j++)
			dp[i][j] = -INF;

	// 2x2 bricks, so i don't have to compute start-start+1 because already covered
	for(int i = 0; i < n; i++) 
		dp[i][i+1] = 0;


	// compute subproblems iterating through all the possible intervals
	for(int len = 2; len <= n; len++) { // all possible subproblem lenght
		for(int left = 0; left + len <= n; left++) { // all possible start coords
			int right = len + left; // end of next brick
			for(int sub = left + 1; sub < right; sub++) // divide interval in [left, sub[, [sub,right[
				dp[left][right] = max(dp[left][right], dp[left][sub] + dp[sub][right]); // best of prev layer setting/sum of the subintervals
			
			// compute the max number of bricks to remove for the layer to be an acceptable structure
			// h+1 (worst case if i support all the bricks with one bricks right below until current height) 
			// - distance between the bricks at the edges / 2 (=lenght of a brick) 
			// -> can "save" to put a brick because the bricks on the interval are close enough (can leave a gap)
			// if bricks[r-1] - bricks[l] + 1 < 0 set dp to 0 (worst case)
			// ex: if bricks[r-1] - bricks[l] + 1 == 2 -> we can put only one brick instead of 2 to support
			dp[left][right] += max(0LL, h + 1 - (bricks[right - 1] - bricks[left] + 1) / 2); // update dp
		}
	}

	cout << h * n - dp[0][n] << endl; // wall of bricks - bricks to remove on the entire interval

	return 0;

}
