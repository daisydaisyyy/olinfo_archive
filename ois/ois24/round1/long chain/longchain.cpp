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
    
    vector<int> u(N - 1), v(N - 1);
    for (int i = 0; i < N - 1; ++i)
        cin >> u[i] >> v[i];
    
    int len = 0;
    
    
    // INSERT YOUR CODE HERE
    
    
    cout << len << endl;

    return 0;
}
