#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> V;

long long merge(vector<int>& arr, int l, int r, int mid) {
    int m1 = mid - l + 1;
    int m2 = r - mid;
    long long inv_count = 0;

    vector<int> left(m1), right(m2);
    for (int i = 0; i < m1; i++) left[i] = arr[l + i];
    for (int i = 0; i < m2; i++) right[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < m1 && j < m2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            inv_count += (m1 - i);
        }
    }

    while (i < m1) arr[k++] = left[i++];
    while (j < m2) arr[k++] = right[j++];

    return inv_count;
}

long long mergesort(vector<int>& arr, int l, int r) {
    long long inv_count = 0;
    if (l < r) {
        int mid = l + (r - l) / 2;
        inv_count += mergesort(arr, l, mid);
        inv_count += mergesort(arr, mid + 1, r);
        inv_count += merge(arr, l, r, mid);
    }
    return inv_count;
}

long long calculateSortingProximity(vector<int>& arr) {
    vector<int> temp = arr;
    return mergesort(temp, 0, temp.size() - 1);
}

long long calculateSwapEffect(int i, int j) {
    if (i == j) return 0;

    vector<int> V_copy = V;
    swap(V_copy[i], V_copy[j]);
    return calculateSortingProximity(V_copy);
}

int main() {
    ifstream cin("input1.txt");
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    V.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }

    long long initial_proximity = calculateSortingProximity(V);
    long long min_proximity = initial_proximity;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            long long new_proximity = calculateSwapEffect(i, j);
            min_proximity = min(min_proximity, new_proximity);
        }
    }

    cout << min_proximity << endl;

    return 0;
}

