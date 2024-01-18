// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N;
    long long K;
    cin >> N >> K;
    
    vector<long long> P(N);
    for (int i = 0; i < N; ++i)
        cin >> P[i];
    
    long long C = 0;
    
    
    // INSERT YOUR CODE HERE
    
    
    cout << C << endl;

    return 0;
}
