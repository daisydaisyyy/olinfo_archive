/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <stdio.h>
#include <assert.h>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
int R, C, K;
int i, j, value;

int main() {
//  uncomment the following lines if you want to read/write from files
 freopen("input0.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
    // ifstream cin("input0.txt");

    // assert(3 == scanf("%d %d %d", &R, &C, &K));
    scanf("%d %d %d", &R, &C, &K);
    // cout << R, cout << C, cout << K;
    
    // cin >>R, cin >> C, cin >> K;
    vector<int> max_i(K);
    vector<int> min_i(K);
    vector<int> max_j(K);
    vector<int> min_j(K);
    
    for (int k = 1; k <= K; k++) {
        min_i[k] = R;
        min_j[k] = C;
        max_i[k] = -1;
        max_j[k] = -1;
    }

    for (i=0; i < R; i++) 
        for(int j=0; j < C; j++) {
            value = scanf("%d", &value);
            if(value > 0) {
                int temp_i = R - 1 - i;

                cout << min_i[value] << endl;
                
                if (temp_i < min_i[value]) min_i[value] = temp_i;
                if (j < min_j[value]) min_j[value] = j;
                if (temp_i > max_i[value]) max_i[value] = temp_i;
                if (j > max_j[value]) max_j[value] = j; 
            }
        }
    
        
    for (i=1; i<=K; i++)
        printf("%d %d %d %d\n", min_j[i], min_i[i], max_j[i] + 1, max_i[i] + 1);

    return 0;
}
