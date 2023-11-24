#include <iostream>
#include <vector>
#include <string>
#include<fstream>
using namespace std;

//int pulisci(int N, int M, vector<string> S);


vector<vector <int>> m;
int i,j,t=0;
bool check=true;
int pulisci(int N, int M, vector<string> s) {
  while(check){
    check=false;
    for(i=0;i<s.size();i++){
      //controllo riga
      for(j=1;j<s[i].size()&&s[i][j]==s[i][0];j++){

      }
      if(j==s[i].size()&&s[i][j-1]==s[i][0]){ //accettabile
        check=true;
        s[i].erase();
        t++;
      }
    }

    //controllo colonne
    for(j=0;j<s[0].size();j++){
      for(i=0;i<s.size()&&s[i][j]==s[0][j];i++){

      }
      if(i==s.size()&&s[i-1][j]==s[0][j]){ //accettabile
        check=true;
        // for(auto& r : s) r.erase(r.begin()+j);
        // s[i][j].erase();
        for(i=0;i<s.size();i++){
          s[i][j].erase();
        }
        t++;
      }


    }
  }


  //stampa
  for(auto it: s){
    cout<<it<<endl;
  }
  return t;
}

int main() {
  int N, M;
  // ios::sync_with_stdio(false);
  // ifstream cin("input0.txt");
  cin >> N >> M;

  vector<string> S(N);
  // m.resize(N);
  for(int i = 0; i < N; i++) {
    cin >> S[i];
  }

  cout << pulisci(N, M, S) << endl;

  return 0;
}




//creo matrice
    // //cout<<"S[i][j]: "<<S[0][0]<<endl;
    // for(i=0;i<N;i++){
    //     for(j=0;j<M;j++){
    //         m[i].push_back(S[i][j]);
    //         // cout<<"S[i][j]: "<<S[i][j]<<endl;
    //     }
    // }

    // for(i=0;i<N;i++){
    //   for(j=0;j<M;j++){
    //     cout<<m[i][j]<<"\t";
    //   }
    //   cout<<endl;
    // }
    // // for(auto it: m){
    // //     cout<<it<<endl;
    // // }
    // //trova riga/colonna con tutti 0 o 1