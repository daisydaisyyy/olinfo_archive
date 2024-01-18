// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
vector<int> A;
vector<int> B;

bool ifchange(const vector<int>& A, const vector<int>& B) {
    // Check if A can be transformed into B
    for (int i = 0; i < A.size(); i++) {
        if(A[i] != B[i]) return false;
    }
    return true;
}

bool zero() {
     for (int i = 0; i < A.size(); i++) {
        if(A[i] != 0) return false;
    }
    return true;
}

int solve() {
    int c = 0;
    int op = 0;
    bool a = true;
    do {
        c  = 0;
        for (int i = 1; i < A.size() - 1; i++) {
            if (A[i] != B[i]) {
                // cout << "op" << endl;
                c++; // counter
                A[i] = -(A[i - 1] + A[i] + A[i + 1]);
                op++;
            }
        }
        a = zero();
    } while (c != 0);
   
    
     if(a == true) {
        return op;
     }
    else return -1;

}

int main() {
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input.txt");
    // ofstream cout("output.txt");

    cin >> N;
    
    A.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    
    B.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> B[i];
    
    int ans = 0;
    
    
    // INSERT YOUR CODE HERE


    ans = solve();
    
    cout << ans << endl;

    return 0;
}
