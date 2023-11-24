// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// input data
int N;
vector<int> S;

int main() {
//  uncomment the following lines if you want to read/write from files
  ifstream cin("input.txt");
//  ofstream cout("output.txt");

    cin >> N;
    S.resize(N);
    for (int i=0; i<N; i++)
        cin >> S[i];

    // insert your code here
    for(int i = 1; i < N; i++){
        if(S[i] > S[i-1]){
            S.erase(S.begin() + (i-1));
            i = 0;
        }
    }

    cout << S.size() << endl; // print the result
    return 0;
}
