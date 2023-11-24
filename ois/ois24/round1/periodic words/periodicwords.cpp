// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N;
    cin >> N;
    
    string S;
    cin >> S;
    
    int Q;
    cin >> Q;
    
    vector<int> l(Q), r(Q);
    for (int i = 0; i < Q; ++i)
        cin >> l[i] >> r[i];
    
    vector<string> ans(Q);
    
    
    // INSERT YOUR CODE HERE
    
    
    for (int i = 0; i < Q; ++i)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}
