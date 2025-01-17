#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <climits>
using namespace std;

int N, K;
vector<vector<long long>> dp;
vector<int> A;
vector<int> B;

long long solve(int counter, int idx) {
    if(counter == K || idx == N) {
        return 0;
    }

    if(dp[idx][counter] != -1)
        return dp[idx][counter];
    
    
    int str = B[idx];
    for(; idx + 1 < N; ++idx) {
        if(A[idx] < A[idx + 1]) {
            str += B[idx + 1];
        } else {
            break;
        }
    }

    long long exclude = solve(counter, idx + 1);
    long long include = solve(counter + 1, idx + 1) + str;
    cout << "idx: " << idx << " counter: " << counter << " include: " << include << " exclude: " << exclude << endl;
    dp[idx][counter] = max(include, exclude);
    cout << "res: " << dp[idx][counter] << endl; 
    return dp[idx][counter];
}


int main() {
    // Uncomment the two following lines if you want to read/write from files
    ifstream cin("input0.txt");
    // ofstream cout("output.txt");

    cin >> N >> K;
    A.resize(N);
    B.resize(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }

    dp.assign(N, vector<long long>(K + 1, -1));

    cout << "solve: " << solve(0,0) << endl;

    return 0;
}
