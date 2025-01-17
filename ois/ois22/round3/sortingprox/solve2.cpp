// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// input data
int N;
vector<int> V;
void swap(int &a, int &b, int i) {
	int tmp = a; 
	V[i] = b; 
	V[i+1]=tmp;

}

int main() {
//  uncomment the following lines if you want to read/write from files
	ifstream cin("input0.txt");
//  ofstream cout("output.txt");

    cin >> N;
    V.resize(N);
    for (int i=0; i<N; i++)
        cin >> V[i];

    // insert your code here
	int res = 0,swaps;
	bool sorted = false;
	while(!sorted) {
		for(auto &x : V) cout << x << "\t"; 
		swaps = 0;
		for(int i = 0; i < N-1; i++) {
			if(V[i] > V[i+1]) {
				swap(V[i],V[i+1],i); 
				swaps++;
			}
		}
		if(swaps == 0) sorted = true;
		res += swaps;
		
		cout << endl;
	}

    cout << res << endl; // print the result
    return 0;
}
