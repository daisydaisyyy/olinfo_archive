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
        for(int j=i+1;j<N;j++){
            if(Y[i]==Y[j]||X[j]==X[i]){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
        //if(adj[i].push_back(X[i])); //salvo tutte le stelle sulla stessa riga (adj[k]=riga,[Y[i]]=posizione sulla riga)
        // cout<<adj[X[i]][Y[i]]<<endl;

       
    }
    
     //stampa
        for(int k=0;k<adj.size();k++){
            cout<<"stella "<<k<<": ";
            for(int j=0;j<adj[k].size();j++){
                cout<<adj[k][j]<<" ";
            }
            cout<<endl;
        }
}

//sistema trade già visitate
int findConstellation(vector<int> X,vector<int> Y,int N){
    int link=0,c=0;
    for(int i=0;i<adj.size();i++){
        for(int j=0;j<adj[i].size();j++){
            if(X[adj[i][j]]==X[i]){ //scorro in basso/alto
               // link++;
                for(int k=0;k<adj[j].size();k++){
                    c++;
                }
            }


            if(Y[adj[i][j]]==Y[i]){ //scorro a destra/sinistra
                // link++;
                for(int k=0;k<adj[j].size();k++){
                    if(X[adj[j][k]]==X[j]){ //scorro in basso/alto
                        // link++;
                        for(int h=0;h<adj[k].size();h++){
                            c++;
                        }
                    }
                   
                }
            }
        }
        
    }
    return c;
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
    adj.resize(N);


    cout<<"size: "<<adj.size()<<endl;
    for(auto it: X){
        cout<<it<<endl;
    }
    cout<<endl<<endl;
    for(auto it: Y){
        cout<<it<<endl;
    }
    

    setRelationships(X,Y,N);
    cout<<endl<<endl<<findConstellation(X,Y,N);
    // cout << 42 << endl; // print the result
    
    return 0;
}
