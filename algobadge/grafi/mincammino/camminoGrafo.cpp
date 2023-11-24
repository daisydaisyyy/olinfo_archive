#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include<limits.h>
using namespace std;

// Declaring functions
//void mincammino(int N, int M, vector<int> X, vector<int> Y, vector<int> P, vector<int> &D);

//N=numero nodi M=num archi
//x=partenza, y=arrivo, p=peso
//d=contiene i cammini da 0 a ogni nodo

vector <vector<int>> adj; //pos pari=nodi, pos dispari=archi
priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
pair <int,int> p;
void mincammino(int N, int M, vector<int> X, vector<int> Y, vector<int> P, vector<int> &D) {
    // Inserisci il codice qui...
    int j=0,min;
    adj.resize(N*2);
    //creo lista di adiacenza
    for(int i = 0; i < N*2; i++) {
        while(X[j]==i){
            // cout<<<"inizio"<<endl;<endl
            adj[i].push_back(Y[j]);
            adj[i].push_back(P[j]);
            // for(auto it: adj[i]){
            //     cout<<endl<<"\nit: "<<it;
            // }
            j++;
            // cout<<endl;
        }
    }
    //inizializzo le distanze
    // D[0]=0;
    for(int k=0;k<N;k++){
        D[k]=INT_MAX;
    }

    // for(auto it: D){
    //     cout<<endl<<"\nit: "<<it;
    // }
    // cout<<endl<<endl;

    //algoritmo
    q.push({0,0});
    int y;
    while(q.size()>0){
        p=q.top();
        q.pop();
        if(p.first>=D[p.second]) continue;
        D[p.second]=p.first;
        for(int pos=0;pos<adj[p.second].size();pos+=2){
            y=p.first+adj[p.second][pos+1];
            if(y<D[adj[p.second][pos]]){
                q.push({y,D[adj[p.second][pos]]});
            }
        }
    }

    for(int r=0;r<D.size();r++){
        if(D[r]==INT_MAX)   D[r]=-1;
    }

}



int main() {
    ios::sync_with_stdio(false);

    // Uncomment the following lines if you want to read/write from files
    ifstream cin("input1.txt");
    // ofstream cout("output.txt");

    // Reading input
    int N, M;
    cin >> N >> M;
 
    vector<int> X(M), Y(M), P(M), D(N);
    for (int i = 0; i < M; i++) {
        cin >> X[i] >> Y[i] >> P[i];
    }

    // Calling functions
  
    mincammino(N, M, move(X), move(Y), move(P), D);

    // Writing output
    for(int d : D) {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}
