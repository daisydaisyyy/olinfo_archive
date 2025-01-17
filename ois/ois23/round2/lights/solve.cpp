// NOTE: it is recommended to use this even if you don't understand the
// following code.


#include <bits/stdc++.h> 
using namespace std;

int main() {
    // uncomment the following lines if you want to read/write from files
    ifstream cin("input1.txt");
    // ofstream cout("output.txt");

    int N, C;
    cin >> N >> C;
    vector<int> L(N);
    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }

    // insert your code here 
	map<int,int> lights; // color, occurrences;
	int r = 0, minl = INT_MAX; // right, min lenght
	for(int l = 0; l < N; ) {
		while(r < N and lights.size() < C) {
			lights[L[r]]++; // increment occurrence 
			r++;
		}
		if(lights.size() < C) break; // not found every color 

		while(lights.size() == C) { // until you find a color woth only one occurrence 
			// if color ocurs 1 time, delete from the mapping since i wont need it for next intervals 
			if(--lights[L[l]] == 0 ) lights.erase(L[l]);
			l++;
		}

		minl = min(minl, r - l + 1); // r-l+1 leaves only the part with colors that have (in best case) only one occurrence

		if(r == N) break; // checked all colors 
	
	}


    cout << minl << endl;  // print the result
    return 0;
}
