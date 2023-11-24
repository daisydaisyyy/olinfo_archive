// NOTE: it is recommended to use this even if you don't understand the
// following code.

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    //  uncomment the following lines if you want to read/write from files
      //ifstream cin("input1.txt");
      ofstream cout("output.txt");

    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int N, Q;
        cin >> N >> Q;
        
        vector<int> P(N), L(Q);
        for (int i = 0; i < N; i++) {
            cin >> P[i];
        }
        for (int i = 0; i < Q; i++) {
            cin >> L[i];
        }


        // insert your code here
        bool hacker = false;
        int sum=0,i=0;

        while(sum>=0&&i<Q){
            if(L[i]>=0)  sum+=L[i];
            else    sum-=P[((L[i])*(-1))-1];
            i++;
        }
        if(sum<0)   hacker=true;


        // while(sum>=0&&i<Q){
        //     sum+=L[i];
        //     i++;
        // }
        // if(sum<0)   hacker=true;

        // print the result
        if (hacker) {
            cout << "HACKER" << endl;
        } else {
            cout << "OK" << endl;
        }
    }
}
