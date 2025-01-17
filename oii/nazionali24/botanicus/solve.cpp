#include <bits/stdc++.h>
using namespace std;

vector<int> maxdesc, heights;
vector<vector<int>> adj;

void dist(int node, int h) {
    heights[node] = h;
    maxdesc[node] = h;
    for (auto child : adj[node]) {
        dist(child, h + 1);
        maxdesc[node] = max(maxdesc[node], maxdesc[child]);
    }
}

int pota(int N, vector<int> P) {
    // build tree
    adj.assign(N, vector<int>());
    for (int i = 1; i < N; ++i) {
        adj[P[i]].push_back(i);
    }

    heights.assign(N, 0);
    maxdesc.assign(N, 0);
    dist(0, 0);

    vector<int> source(N + 1, 0), end(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        source[heights[i]]++; // nodi validi fino a una certa altezza h
        end[maxdesc[i] + 1]++; // nodo non piu' valido dalla massima altezza raggiungibile +1
    }

    
    int curr = 0, keep = 0;
    for (int h = 0; h <= N; ++h) {
        curr += source[h] - end[h];
        keep = max(keep, curr);
    }

    return N - keep;
}


int main() {
    ifstream cin("botanicus.input0.txt");  // Lettura da file
    int N;
    cin >> N;
    vector<int> P(N);

    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    cout << pota(N, P) << endl;

    return 0;
}


