#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
	ifstream cin("input0.txt");
    cin >> n;

	// A to B in reversed order
	for(int i = 0; i < n/2; i++)  
		cout << "1 0 1" << endl; 
	
	cout << (n + 1) / 2 << " 0 1" << endl; // remaining books from A to B, wrong order (moving an interval of books, not reversing the prev order)
	for(int i = 0; i < (n+1) / 2; i++) 
		cout << "1 1 0" << endl; // B to A with cost 0 in reversed order 
	
	cout << ((n + 1) / 2) << " 0 1" << endl; // A to B in correct order (reversed) (same order as prev instruction because moving an interval of books)

}
