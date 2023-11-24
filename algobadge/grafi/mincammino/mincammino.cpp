#include <vector>
using namespace std;
//N=numero nodi M=num archi
//x=partenza, y=arrivo, p=peso
//d=contiene i cammini da 0 a ogni nodo


class Graph{
    int N;
    vector <list<int>> adj;

public:
    Graph(int N);
    void addEdge(int a,int b);

    void minCammini(int s);
};

Graph::Graph(int N){
    this->N=N;
    adj.resize(N);
}

void Graph::addEdge(int a,int b){
    adj[a].push_back(b);
}

void Graph::minCammini(int s){
    vector<bool> visited;
    list<int> queue;
    visited.resize(N,false);
    visited[s]=true;
    queue.push_back(s);


    while(!queue.empty()){
        s=queue.front();
        queue.pop_front();

        for(auto adjecent: adj[s]){
            if(!visited[adjecent]){
               visited[adjecent]=true;
               queue.push_back(adjecent);
            }
        }
    }
}



void mincammino(int N, int M, vector<int> X, vector<int> Y, vector<int> P, vector<int> &D) {
    // Inserisci il codice qui...
    for(int i = 0; i < N; i++) {
        D[i] = 42;
    }
}
