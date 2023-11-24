/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include<iostream>
#include <assert.h>
#include<vector>
#include<algorithm>
using namespace std;
// constraints

// input data
int R, C, i, j;


int main() {
//  uncomment the following lines if you want to read/write from files
  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    scanf("%d %d", &R, &C);
    int M[R][C];
    for(i=0; i<R; i++)
        for (j=0; j<C; j++)
            scanf("%d", &M[i][j]);

    // insert your code here
    int count=2;
    for(i=0;i<R;i++){
        for(j=0;j<C;j++){
            if (M[i][j]>0){
                M[i][j] = count;
                if (i - 1 >= 0) {
                    if(M[i-1][j] > 1){
                        M[i][j]=M[i-1][j];
                    }
                }
                if (j - 1 >= 0) {
                    if(M[i][j-1] > 1){
                        M[i][j]=M[i][j-1];
                    }
                }

                if (j + 1 <= C-1) {
                    if(M[i][j+1] > 1){
                        M[i][j]=M[i][j+1];
                    }
                }

                if (i + 1 <= R-1) {
                    if(M[i+1][j] > 1){
                        M[i][j]=M[i+1][j];
                    }
                }

                //diagonali
                if (i - 1 >= 0&&j - 1 >= 0) {
                    if(M[i-1][j-1] > 1){
                        M[i][j]=M[i-1][j-1];
                    }
                }

                if(i - 1 >= 0&&j + 1 <= C-1){
                    if(M[i-1][j+1] > 1){
                        M[i][j]=M[i-1][j+1];
                    }
                }

                if (i + 1 <= R-1&&j - 1 >= 0) {
                    if(M[i+1][j-1] > 1){
                        M[i][j]=M[i+1][j-1];
                    }
                }


                if (i + 1 <= R-1&&j + 1 <= C-1) {
                    if(M[i+1][j+1] > 1){
                        M[i][j]=M[i+1][j+1];
                    }
                }

                count++;
                //cout<<endl<<count;

                
            }
            
        }
    }
    vector<int> visited;
    for(i=0;i<R;i++){
        for(j=0;j<C;j++){
            // if (M[i][j] > 1) {
            //     if(find(visited.begin(),visited.end(),M[i][j])==visited.end()){
            //         visited.push_back(M[i][j]);
            //     }
                
            // }
            cout<<M[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<visited.size();
    //printf("%d\n", 42); // print the result
    return 0;
}
