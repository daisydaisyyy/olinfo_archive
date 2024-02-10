// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input0.txt");
    // ofstream cout("output.txt");

    long long N;
    cin >> N;
    long long i = N;
    
    vector<long long> S(N);
    for (long long i = 0; i < N; ++i)
        cin >> S[i];
    
    long long A = 0;
    
    
    // INSERT YOUR CODE HERE
    sort(S.begin(), S.end());

    long long a = 0;
    long long b = 0;

    while (i != 1) {
        i--;
        if(S[i] == S[i-1]) {
            a = S[i];
            break;
        }
        
    } 
    // cout << S[i - 2] << endl << i << endl;
    i --;
    b = S[i];

    while(i!= 1) {
        i--;
         if(S[i] == S[i-1]) {
            b = S[i];
            break;
        }
        
    }

    cout << a * b << endl;


    return 0;
}
