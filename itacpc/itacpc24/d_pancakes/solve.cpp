#include<bits/stdc++.h>

using namespace std;

// inversions == number of permutation to do to obtain sorting
// shifting 3 element doesnt change the parity of the permutation 
// if even = sortable 
// if odd = not sortable 
// A 3-cycle can be thought of as performing two swaps
// Because a 3-cycle is an even permutation, 
// applying this operation preserves the parity of the permutation. 
// This means that:
//    If you start with an even permutation, 
//    every 3-cycle move will keep the permutation even.
//    If you start with an odd permutation, 
//    no matter how many 3-cycle moves you make, the permutation will remain odd.
int solve(vector<int>& pancakes) {
    int invs = 0;
    int n = pancakes.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (pancakes[i] > pancakes[j]) {
                invs++;
            }
        }
    }
    return invs;
}

int main() {
    ifstream cin("1.in"); 
    int n;
    cin >> n;
    vector<int> pancakes(n);
    for (int i = 0; i < n; ++i) {
        cin >> pancakes[i];
    }

    int invs = solve(pancakes);

    if (invs % 2 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

