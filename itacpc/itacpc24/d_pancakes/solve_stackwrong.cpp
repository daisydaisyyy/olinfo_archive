#include <bits/stdc++.h>
using namespace std;

// Function to rotate three elements to the left
void rotateLeft(deque<int>& dq, int i) {
    if (i + 2 < dq.size()) {
        int temp = dq[i];
        dq[i] = dq[i + 1];
        dq[i + 1] = dq[i + 2];
        dq[i + 2] = temp;
    }
}

// Function to rotate three elements to the right
void rotateRight(deque<int>& dq, int i) {
    if (i + 2 < dq.size()) {
        int temp = dq[i + 2];
        dq[i + 2] = dq[i + 1];
        dq[i + 1] = dq[i];
        dq[i] = temp;
    }
}

// Function to check if the deque is sorted
bool isSorted(deque<int>& dq) {
    for (int i = 1; i < dq.size(); ++i) {
        if (dq[i - 1] > dq[i]) return false;
    }
    return true;
}

// Function to determine if the stack can be sorted using allowed rotations
bool canSortWithRotations(vector<int>& pancakes) {
    deque<int> dq(pancakes.begin(), pancakes.end());
    int n = dq.size();
    bool changed;
    int iterations = 0; // Counter to prevent infinite loop

    do {
        changed = false;
        for (int i = 0; i < n - 2; ++i) {
            if (dq[i] > dq[i + 1] || dq[i + 1] > dq[i + 2]) {
                if (dq[i] > dq[i + 1] && dq[i + 1] > dq[i + 2]) {
                    rotateLeft(dq, i);
                } else {
                    rotateRight(dq, i);
                }
                changed = true;
            }
        }
        iterations++;
        if (iterations > n * n) break; // Break loop if too many iterations
    } while (changed);

    return isSorted(dq);
}

int main() {
    ifstream cin("2.in");
    int n;
    cin >> n;
    vector<int> pancakes(n);
    for (int i = 0; i < n; ++i) {
        cin >> pancakes[i];
    }

    if (canSortWithRotations(pancakes)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
