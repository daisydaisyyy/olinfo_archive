// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


long long findClosest(long long i, vector<int> D, vector<bool> destroyed) {
    long long closest = -1;
    long long closestDistance = 1000000000000000000;
    for (int j = 0; j < D.size(); j++) {
        if (j != i && !destroyed[j]) {
            if (abs(D[j] - D[i]) < closestDistance) {
                closest = j;
                closestDistance = abs(D[j] - D[i]);
            }
        }
    }
    return closest;
}

bool lastToDestroy(vector<bool> destroyed) {
    int remaining = destroyed.size();
    for (int i = 0; i < destroyed.size(); i++) {
        if (destroyed[i]) {
            remaining--;
        }
    }
    if (remaining == 1) {
        return true;
    }
    return false;
}

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input0.txt");
    // ofstream cout("output.txt");

    int N;
    cin >> N;
    
    vector<int> D(N);
    for (int i = 0; i < N; ++i)
        cin >> D[i];
    
    vector<int> H(N);
    
    for (int i = 0; i < N; i++) {
        vector<bool> destroyed(N, false);
        destroyed[i] = true;
        long long numDestroyed = 1;
        long long currentPos = i;
        // cout << "CALCULATING " << i << endl;
        
        while (numDestroyed < N - 1) {
            // cout << "currentPos: " << currentPos << endl;
            // for (int j = 0; j < destroyed.size(); j++) {
            //     cout << destroyed[j] << " ";
            // }
            // cout << endl;

            long long closest = findClosest(currentPos, D, destroyed);

            destroyed[closest] = true;
            numDestroyed++;
            // cout << closest << endl;
            currentPos = closest;
        }

        for (int k = 0; k < N; k++) {
            if (!destroyed[k]) {
                H[i] = k;
                // cout << "Setting " << i << " to " << k << endl;
            }
        }
    }
    
    for (int i = 0; i < N; ++i)
        cout << H[i] << " ";
    cout << endl;

    return 0;
}
