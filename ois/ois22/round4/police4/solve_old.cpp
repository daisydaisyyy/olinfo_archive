// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
#define INF 1000
// input data
int N, R, T, L;
vector<int> X;
//vector<vector<int>> dp; // semaphore, skips
vector<int> dp;
int solve(int s, int time, int skips, bool skipped) {
	cout << "s: " << s << "\ttime: " << time << "\tskips: " << skips << "\ts: " << s << endl;
	//if(s > N) return -1; 

	
	if( s == N) {
		cout << "endtime: " << time << "\tL: " << L << endl;
		return time + (L - X[s-1]);
	} 

	int currtime = s != 0 or N == 1 ? time + (X[s] - X[s-1]) : X[s+1];
	cout << "x: " << X[s] << "\tcurrtime: " << currtime << endl;

	// check if red or not 
	bool red = (currtime / T) % 2 != 0; // if time/T odd, then red 
	cout << "status: " << (currtime / T) << "\tRed: " << red << endl;

	if(red) {
		// skip it 
		int skipped = INF;
		if(skips > 0) {
			cout << "RED, skipping to: " << currtime << " in: " << s << endl;
			skipped = solve(s+1, currtime, skips-1, true);	
		}

		// wait 
		int wait = T - (currtime % T);  
		cout << "wait time: " << wait << "\nNexttime: " << currtime + wait << endl;
		int taken = solve(s+1, wait + currtime, skips, false);
		dp[s] = min(taken, skipped);
	} else { 
		cout << "green semaphore, skipping to: " << currtime << endl;
		dp[s] = solve(s+1,time,skips, false);
	}
	return dp[s];
}


int main() {
//  uncomment the following lines if you want to read/write from files
	ifstream cin("input0.txt");

//  ofstream cout("output.txt");
    cin >> N >> R >> T >> L;
    X.resize(N);
    for (int i=0; i<N; i++)
        cin >> X[i];

	dp.assign(N, -1);

  
	// insert your code here
	// N semafori in pos x_i , t = 0 : green for T seconds, red from T to T+T seconds etc 
	// R times can pass with red 
	//cout << endl  << N << endl << R << endl << T << endl << L;

    cout << solve(0,0,R, true) << endl; // print the result
    return 0;
}
