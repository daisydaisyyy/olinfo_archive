#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if the vector is sorted
bool isSorted(vector<int>& pancakes) {
    for (int i = 1; i < pancakes.size(); ++i) {
        if (pancakes[i-1] > pancakes[i]) return false;
    }
    return true;
}

// Function to apply a rotation to a specific set of three pancakes
void rotatePancakes(vector<int>& pancakes, int i) {
    int temp = pancakes[i];
    pancakes[i] = pancakes[i + 1];
    pancakes[i + 1] = pancakes[i + 2];
    pancakes[i + 2] = temp;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> pancakes(N);
    for (int i = 0; i < N; ++i) {
        cin >> pancakes[i];
    }
    
    // Try to sort the array using rotations on groups of 3 consecutive elements
    for (int i = 0; i < N - 2; ++i) {
        while (!isSorted(pancakes)) {
            bool rotated = false;
            for (int j = 0; j < N - 2; ++j) {
                if (pancakes[j] > pancakes[j + 1] || pancakes[j + 1] > pancakes[j + 2]) {
                    rotatePancakes(pancakes, j);
                    rotated = true;
                }
            }
            if (!rotated) break;
        }
    }
    
    // Check if we have successfully sorted the array
    if (isSorted(pancakes)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

