#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input0.txt");
    // ofstream cout("output.txt");

    int N;
    cin >> N;

    vector<int> P(N);
    for (int i = 0; i < N; ++i)
        cin >> P[i];

    int K = 0;
//min el 
    int minIndex = min_element(P.begin(), P.end()) - P.begin();

    if (is_sorted(P.begin(), P.end())) {
        cout << 0 << endl;  // sorted
        return 0;
    }

   
    if (minIndex == 0) {
        cout << -1 << endl;  // not sortable
        return 0;
    }
    K = N - minIndex;

    cout << K << endl;

    return 0;
}
