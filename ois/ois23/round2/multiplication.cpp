// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// input data
int N;
vector<int> K;

int main() {
//  uncomment the following lines if you want to read/write from files
//  ifstream cin("input.txt");
//  ofstream cout("output.txt");

    cin >> N;
    K.resize(N);
    for (int i=0; i<N; i++)
        cin >> K[i];

    for(int i = 0; i < N; i++){
		int mult;	
		bool check = false;
        int res = 1;
		vector<bool> V(10, false);
        for(res = 1; !check; res++){
            mult = K[i] * res;
            while(mult){
                V[mult%10] = true;
                mult/=10;
            }
            check = V[0] && V[1] && V[2]&& V[3]&& V[4]&& V[5]&& V[6]&& V[7]&& V[8] && V[9];
        }
        cout << res-1 << endl;
    }

    return 0;
}
