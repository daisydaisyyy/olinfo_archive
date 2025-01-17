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


long long merge(vector<int>& arr, int l, int r, int mid){
	int m1 = mid - l +1; 
	int m2 = r - mid; 
	long long counter = 0;

	vector<int> lower(m1), upper(m2);
	for(int i = 0; i < m1; i++) 
		lower[i] = arr[l + i];
	for(int i = 0; i < m2; i++) 
		upper[i] = arr[mid + i + 1];

	int i = 0, j = 0, k = l; 
	while(i < m1 and j < m2) {
		if(lower[i]  <= upper[j]) {
			arr[k] = lower[i]; 
			i++;
		} else {
			arr[k] = upper[j]; 
			j++; 
			counter += (m1 - i); // count swaps
		}
		k++;
	}

	// copy remaining 
	while(i < m1) {
		arr[k] = lower[i];
		i++; k++;
	}

	while(j < m2) {
		arr[k] = upper[j];
		j++; k++;
	}
	return counter;
}

int mergesort(vector<int>& arr, int l, int r) {
	long long counter = 0;
	if(l < r) { 
		int mid = l + (r-l)/2; 
		counter += mergesort(arr, l, mid); 
		counter += mergesort(arr, mid+1, r); 
		counter += merge(arr, l, r, mid);
	}
	return counter;
}



int main() {
//  uncomment the following lines if you want to read/write from files
	ifstream cin("input0.txt");
//  ofstream cout("output.txt");

    cin >> N;
    V.resize(N);
    for (int i=0; i<N; i++)
        cin >> V[i];

    
	// swaps 
	cout << mergesort(V, 0, N-1) << endl;
	for(auto &x : V) cout << x << "\t";

	/*

	// calc proximity
	vector<int> v2 = V; 
	int swaps = 0;
	sort(v2.begin(),v2.end()); 
	for(int i = 0; i < N; i++) 
		if(V[i] != v2[i]) swap++;
    cout << res << endl; // print the result
	*/
    return 0;
}
