/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <stdio.h>
#include <assert.h>
#include <vector>
#include <iostream>
#include <utility>
#include <queue>
#include <limits>
#include <fstream>
using namespace std;
// constraints
#define MAXN 50000
#define MAXM 100000

struct edge{
    int end; // next node
    int t0; // starting time (node weight)
    int t1; // arrival time (path weight)
};



// input data
int N, M;
int source, destination;


priority_queue<pair<int,int>> q;
// start, start time, end, end time
int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input0.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
    ifstream cin("input0.txt");

    cin >> N;
    
    cin >> source >> destination;
    cin >> M;

    vector<vector<edge>> adj(N);
    vector<int> dist(N, numeric_limits<int>::max());

    for (int i=0; i<M; i++) {
        int city1, time1, city2, time2;
        cin >> city1 >> time1 >> city2 >> time2;
        adj[city1].push_back({city2, time1, time2});
    }

        // insert your code here
        //dijkstra
        dist[source] = 0;
        q.push({-dist[source], source});

        while(!q.empty()) {
            auto t = q.top();
            q.pop();

            int w = -t.first; // weight
            int u = t.second; // end city

            for(auto e : adj[u]) {
                if(w <= e.t0) {
                    if(dist[e.end] > e.t1) {
                        dist[e.end] = e.t1;
                        q.push({-dist[e.end], e.end});
                    }
                }
            }
        }
    

    // insert more code here
    if(dist[destination] < numeric_limits<int>::max())
        cout << dist[destination] << endl;
    else
        cout << "IMPOSSIBLE\n";
    
    return 0;
}
