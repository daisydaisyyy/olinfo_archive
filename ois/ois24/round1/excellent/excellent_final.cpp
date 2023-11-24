// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <vector>
#include<cmath>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

long long sumCipher(vector<int> cipher) {
    long long result = 0;
    for (int i = 0; i < cipher.size(); i++) {
        result += cipher[i];
    }
    return result;
}

int main() {
    // uncomment the following lines if you want to read/write from files
    // ifstream cin("input0.txt");
    // ofstream cout("output.txt");

    // int N;
    // cin >> N;
    
    // insert 
    // vector<int> v(1,N);

    // int a = 5;
    // int e = 1 * N;
    // int c = 0;
    // while((e % 3 != 0) && c != N) {
    //     cout << "id: " << N-c-1 << endl;
    //     v[N-c-1] = 5;
    //     v[N-c-2] = 1;
    //     cout << v[1] << endl;
    //     cout << v[0] << endl;
    //     c++;
    //     e += 4;

    //     if(e % 3 != 0)  {
    //         cout << e << endl;
    //         if((e + 4) % 3 != 0) {
    //             e += 4;
    //             v[N-c-1] = 5;
    //         }
    //     }
    //     else {
    //         break;
    //     }
        
    // }

    // std::stringstream ss;

    // for(int i = 0; i < v.size() + 1; i++) {
    //     if(i != 0)
    //         ss << "";
    //     ss << v[i];

    // }
          
    // std::string s = ss.str();
    // cout << s << endl;
    // return 0;



    
    int N;
    cin >> N;
    vector<int> v(N,1);

    for (int i = N - 1; i >= 0; i--) {
        // cout << i << endl;
        // cout << "SUM: " << sumCipher(v) << endl;
        // Print vector
        // for (int j = 0; j < v.size(); j++) {
        //     cout << v[j];
        // }
        cout << endl;

        if (sumCipher(v) % 3 != 0) {
            // cout << "IMPOSTO 5 a " << i << endl;
            v[i] = 5;
        }
        else {
            // print the number created by the vector
            for (int j = 0; j < v.size(); j++) {
                cout << v[j];
            }
            return 0;
        }
    }

    cout << -1;
}
