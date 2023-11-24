// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // uncomment the following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N, M;
    cin >> N >> M;
    int coppie=0;

    vector<string> R(N);
    for (int i = 0; i < N; i++) {
        cin >> R[i];
    }

    // insert your code here
    for(int i=0;i<N;i++){ //scorre rulette
        for(int j=i+1;j<N;j++) {
            for(int k=)
            if(R[i]==R[j])
                coppie++;
            
        }



    cout << 42 << endl; // print the result
    
    return 0;
}
