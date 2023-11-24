// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input0.txt");
    // ofstream cout("output.txt");

    int N;
    cin >> N;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    
    string ans = "";
    
    // INSERT YOUR CODE HERE
    
    // Count if the sum of the values of A is even or odd
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i];
    }
    
    if (sum % 2 != 0) {
        // cout << "ODD" << endl;
        cout << -1 << endl;
        return 0;
    }

    long long currentOpenBrackets = 0;

    for (int i = 0; i < N; i++) {
        if (currentOpenBrackets == 0) {
            for (int j = 0; j < A[i]; j++) {
                ans += "(";
            }
            currentOpenBrackets = A[i];
        } else {
            if (currentOpenBrackets >= A[i]) {
                for (int j = 0; j < A[i]; j++) {
                    ans += ")";
                }
                currentOpenBrackets -= A[i];
            } else if (currentOpenBrackets < A[i]) {
                for (int j = 0; j < A[i]; j++) {
                    ans += "(";
                }
                currentOpenBrackets += A[i];
            }
        }
    }

    if (currentOpenBrackets != 0) {
        // cout << ans << endl;
        cout << -1 << endl;
        return 0;
    }

    cout << ans << endl;

    return 0;
}
