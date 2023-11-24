// NOTE: it is recommended to use this even if you don't understand the
// following code.
#include<iostream>
#include<vector>
#include<fstream>
#include<climits>

using namespace std;

// void sliding(vector<int> v,int k,){

// }
int main() {
    // uncomment the following lines if you want to read/write from files
    //ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N, C;
    cin >> N >> C;
    vector<int> L(N);
    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }
    int res = N;
    for(int k = C; k < N; k++){
        bool check = true;
        for(int i = 0; i < N - k; i++){
            check = true;
            vector<bool> colors(C,false);
            for(int j = i; j < i + k; j++){
                colors[L[j]] = true;
            }
            for(int j = 0; j < colors.size(); j++){
                check = check && colors[j];
            }
            if(check){
                res = k;
                break;
            }
        } 
        if(check)
            break;  
    }
    
   
    cout << res << endl;  // print the result
    return 0;
}
