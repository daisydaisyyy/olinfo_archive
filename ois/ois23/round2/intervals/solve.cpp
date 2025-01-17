// NOTE: it is recommended to use this even if you don't understand the following code.

#include <bits/stdc++.h>
using namespace std;

// input data
int N;
vector<int> A, B;

int main() {
    //  uncomment the following lines if you want to read/write from files
    //ifstream cin("input1.txt");
    //  ofstream cout("output.txt");

    cin >> N;
    A.resize(N);
    B.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    // insert your code here
	sort(A.begin(),A.end()); 
	sort(B.begin(),B.end());
	int time=0;
	for(auto x:A) {
		while(B[time] < x) time++; // current shows finishes before the start of the other  
		if(B[time] == x) {
			N--; 
			time++;
		} 
	}
    cout << N << endl;  // print the result
    return 0;
}
