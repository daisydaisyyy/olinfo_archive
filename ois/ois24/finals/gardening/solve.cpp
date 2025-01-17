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

    int N, Q;
    cin >> N >> Q;

    vector<int> P(N);
    for (int i = 0; i < N; ++i)
        cin >> P[i];

    vector<int> C(N);
    for (int i = 0; i < N; ++i)
        cin >> C[i];

    vector<int> S(N);
    for (int i = 0; i < N; ++i)
        cin >> S[i];
    
    vector<int> ans(Q);
    for (int i = 0; i < Q; ++i) {
        int M;
        cin >> M;
        
        vector<int> A(M);
        for(int j = 0; j < M; ++j) {
            cin>>A[j];
        }

        ans[i] = 42; // INSERT YOUR CODE HERE
    }


    for (int i = 0; i < Q; ++i)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}
