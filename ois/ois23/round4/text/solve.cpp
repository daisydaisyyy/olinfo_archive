// NOTE: it is recommended to use this even if you don't understand the following code.

#include <bits/stdc++.h>

using namespace std;

#define MAXK 100000

// input data
int N, K;
vector<string> S;
int occurr[MAXK][26];



int main() {
//  uncomment the following lines if you want to read/write from files
	ifstream cin("input0.txt");
//  ofstream cout("output.txt");
    ios::sync_with_stdio(false);
    cin >> N >> K;
    S.resize(N);
    for (auto &s : S) {
        cin >> s;
		for(int i = 0; i < K; i++) 
			occurr[i][s[i] - 'a']++;
	}

    // insert your code here
	int curr_max = INT_MIN, idx; 
	for(int j = 0; j < N; j++) { // j = curr string
		int curr = 0; 
		for(int i = 0; i < K; i++) 
			curr += occurr[i][S[j][i] - 'a']; // count distance of letters in pos i

		if(curr > curr_max) {
			curr_max = curr;
			idx = j;
		}
	}


    cout << idx << endl; // print the result
    return 0;
}
