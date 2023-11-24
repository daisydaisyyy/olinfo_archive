#include <bits/stdc++.h>
#define MAXM 200000
#define MAXN 100000
using namespace std;
/*
the index of the pool where most of the people will arrive
N = junctions
M = slides
P = pools
The launch pad has index 0, the ending pools have a number between N − P and N − 1. 
The next M lines contain two integers Ai , Bi each: the starting and ending junction of each slide (respectively).
start = curr slide, end = next slide
pool: N - P < pool < N - 1
*/

vector<int> paths[MAXN]; // ci metto i possibili nuovi scivoli dove va a finire uno scivolo
vector<bool> visited;
vector<int> graph;
vector<double> distr;

// int i = 0;

double abs_pos(double x) {
    return x < 0 ? -x : x;
}


void build_graph(int u) {
    if(visited[u]) 
        return;
    visited[u] = true;
    for(int v : paths[u]) 
        build_graph(v);
    
    graph.push_back(u);

}


int find_pool(int N, int M, int P, int A[], int B[]) {
    for(int i = 0; i < M; i++) 
        paths[A[i]].push_back(B[i]); // fill the paths
    
    graph.reserve(N);
    visited.resize(N, 0);
    build_graph(0);
    reverse(graph.begin(), graph.end());

    //find best path for every node
    distr.resize(N);
    distr[0] = double(1);

    for (int i = 0; i < N; i++) {
        int u = graph[i];
        auto frac = distr[u] / paths[u].size(); // probabilita' di ogni path in base al n di paths
        for (int v : paths[u])
            distr[v] += frac; // per ogni strada (new slide) aggiungo la frazione
    }

    int sol = N-P;
    for (int i = N-P+1; i < N; i++) { // check n of all pools
        if (distr[sol] < distr[i]) 
            sol = i; // pool with max num of people
    }

    for (int i = N-P; i < N; i++) 
        assert(i == sol || abs_pos(distr[sol] - distr[i]) > 0.0001);
    
    return sol;
}

int A[MAXM];
int B[MAXM];

int main() {
    FILE *fr, *fw;
    int N, M, P, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(3 == fscanf(fr, "%d %d %d", &N, &M, &P));
    for(i=0; i<M; i++)
        assert(2 == fscanf(fr, "%d %d", &A[i], &B[i]));

    fprintf(fw, "%d\n",find_pool(N, M, P, A, B));
    fclose(fr);
    fclose(fw);
    return 0;
}
