// NOTE: it is recommended to use this even if you don't understand the following code.

#include <bits/stdc++.h>

using namespace std;

int moves[10][10][100001];

int solve(string S) {
	for(int d = 0; d < 10; d++) {
		for(int k = 0; k < 10; k++) {
			moves[d][k][0] = 0;
		}
	}

	char old = '0'; 

	for(int i = 0; i < S.length();i++) {
		char next = S[i]; 
		int start = min(next, old) - 48; 
		int end = max(old, next) - 48; 

		for(int d = 0; d < 10; d++) {
			for(int k = d+1; k < 10; k++) {
				moves[d][k][i+1] = moves[d][k][i]; // try to swap digits
				if(d == start and k == end) moves[d][k][i]++; // make a move 
			}
		}
		old = next; 
	}


	
	// calc cost
	int pos[10];
	iota(pos, pos+10, 0);
	
	int cost = 0;
	for(int d = 0; d < 10; d++) {
		for(int k = 0; k < 10; k++) {
			cost += moves[d][k][S.length()] * abs(pos[d] - pos[k]); 
		}
	}

	for(int i = 0; i < S.length(); i++) {
		for(int a = 0; a < 10; a++) {
			for(int b = a+1; b < 10; b++) {
				int count = 0; 
				for(int d = 0; d < 10; d++) { // try to swap with anything
					for(int k = d+1; k < 10; k++) { 
						count += moves[d][k][i] * abs(pos[d] - pos[k]);
					}
				}
			
				int currpos = i > 0 ? S[i-1] - 48 : 0;
				pos[a] = b; pos[b] = a; // swapped 
				int nextpos = S[i - 48]; 
				count += abs(nextpos - currpos); 

				for(int d = 0; d < 10; d++) {
					for(int k = d+1; k < 10; k++) {
						cost += (moves[d][k][S.size()] - moves[d][k][i+1]) * abs(pos[d] - pos[k]); 
					}
				}
				pos[a] = a; pos[b] = b; 
				cost = min(cost, count);
			}
		}
	}
	return cost;
}




int main() {
    // uncomment the following lines if you want to read/write from files
	ifstream cin("input0.txt");
    // ofstream cout("output.txt");
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        string S;
        cin >> S;

        // insert your code here
	

        cout << solve(S) << endl;  // print the result
    }

    return 0;
}
