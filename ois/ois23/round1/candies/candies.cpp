// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {
	// uncomment the following lines if you want to read/write from files
	//ifstream cin("input0.txt");
	// ofstream cout("output.txt");

    int N;
    cin >> N;

    vector<int> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    // insert your code here
    long long int c=1,inc=1;
    sort(S.begin(),S.end());

  
    for(long long int i=1;i<S.size();i++){
        if(S[i]>S[i-1]){
            inc++;
        }
        c+=inc;   
    }
    cout << c << endl; // print the result
    return 0;
}
