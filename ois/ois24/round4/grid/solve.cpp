// NOTE: it is recommended to use this even if you don't understand the following code.

#include <bits/stdc++.h>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input1.txt");
    // ofstream cout("output.txt");

    int N, M, R, G, B;
    cin >> N >> M >> R >> G >> B;
    
	if(max(R,max(G,B)) > (N*M + 1)/2) cout << "NO" << endl;

	else {
    vector<string> grid(N, string(M, 'R'));
    bool ans = true;
    
    
    // INSERT YOUR CODE HERE
	int memo[N][M], x;
	memo[0][0]=1;
	memo[1][0] = 2;
	memo[N-1][M-1] = 1;
	//cout << 2<<endl;
	for(int i = 0; i < N-1; i++) {
		for(int j = 0; j < M-1; j++) {
			x = (memo[i][j] == 3)? 1 : (memo[i][j]+1) % 4;
			memo[i][j+1] = memo[i+1][j] = x;	
		}

	}
	if(memo[N-2][M-1] == (memo[N-1][M-1]) or memo[N-1][M-2] == (memo[N-1][M-1]))
		ans = false;

	/*
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cout << memo[i][j] << " "; 
		}
		cout << endl;

	}
	*/


    
        cout << "YES" << endl;
        for (int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				if(memo[i][j] == 1) {
					grid[i][j] = 'R';
				} else if(memo[i][j] == 3) {
					grid[i][j] = 'G';
				} else if(memo[i][j] == 2) {
					grid[i][j] = 'B';
			}
		}
            cout << grid[i] << endl;
		}
	}
   

    return 0;
}
