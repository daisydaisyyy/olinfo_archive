// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Hi = A[i] * B[j]
// find max of local heights (A[i] must be > of all A[i+1], A[i-1] and same for B[j] > B[j-1], B[j] > B[j+1])
// peaks is where max A and max B intersect (numPeaks = maxA * maxB, cartesian product)
// number of ways to pick a local maxA and a local maxB -> maxA * maxB

long long N, M;
vector<long long> A;
vector<long long> B;

long long findMax(const vector<long long>& arr, long long len) { // count peaks num in adj cells (only in one direction, rows or columns)
    if(len == 1) return 1; 
    long long c = 0; 
    for(long long i = 0; i < len; i++) {
        if((i == 0 || arr[i] > arr[i - 1]) && (i == len - 1 || arr[i] > arr[i + 1])) {
            c++;
        }
    }
    return c;
}


long long solve() {
    long long maxR = findMax(A, N); // rows
    long long maxC = findMax(B, M); // columns
    return maxR * maxC; 
}


int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input1.txt");
    // ofstream cout("output.txt");

    
    cin >> N >> M;
    
    A.resize(N);
    for (long long i = 0; i < N; ++i)
        cin >> A[i];
    
    B.resize(M);
    for (long long i = 0; i < M; ++i)
        cin >> B[i];
    
    // INSERT YOUR CODE HERE
    cout << solve() << endl;

    return 0;
}
