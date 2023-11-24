// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>
#include<algorithm>
using namespace std;
vector<vector<int>> adj;

void setRelationships(vector<int> X,vector<int> Y,int N){
    // cout<<Y[0]<<endl;
    //salvo le stelle adiacenti su 4 lati
    for(int i=0;i<N;i++){
        adj[Y[i]].push_back(X[i]); //salvo tutte le stelle sulla stessa riga (adj[k]=riga,[Y[i]]=posizione sulla riga)
        // cout<<adj[X[i]][Y[i]]<<endl;

       
    }
    
     //stampa
        for(int k=0;k<adj.size();k++){
            cout<<"riga "<<k<<": ";
            for(int j=0;j<adj[k].size();j++){
                cout<<adj[k][j]<<" ";
            }
            cout<<endl;
        }
}



int findConstellation(vector<int> X,vector<int> Y,int N){
    int link=0,c=0; //conta collegamenti, c conta costellazioni
    bool dir; //true se devo andare nella stessa riga, false altrimenti
    for(int i=0;i<adj.size();i++){
        //controllo adiacenti
        if(adj[i].size()==0) continue;
        for(int j=0;j<adj[i].size();j++){ //scorro una riga
            if(j!=adj[i].size()-1&&dir){
                link++;
            }
            else{
                
            }
        }
    }


}
int main() {
//  uncomment the following lines if you want to read/write from files
  ifstream cin("input0.txt");
//  ofstream cout("output.txt");

    int N;
    cin >> N;

    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    // insert your code here

    //determino numero righe
    adj.resize(*max_element(Y.begin(),Y.end())+1);


    cout<<"size: "<<adj.size()<<endl;
    for(auto it: X){
        cout<<it<<endl;
    }
    cout<<endl<<endl;
    for(auto it: Y){
        cout<<it<<endl;
    }
    

    setRelationships(X,Y,N);
    // cout << 42 << endl; // print the result
    
    return 0;
}
