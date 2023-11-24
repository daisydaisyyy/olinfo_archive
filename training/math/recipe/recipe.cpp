/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <iostream>
#include <vector>

using namespace std;

// input data
int N, M;
vector<vector<int>> P;
vector<double> R;

int main() {
//  uncomment the following lines if you want to read/write from files
 // freopen("input2.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    cin >> N >> M;
    P.resize(N);
    R.resize(N);
    for (int i=0; i<N; i++)
        P[i].resize(M);
    for (int j=0; j<M; j++)
        for (int i=0; i<N; i++)
            cin >> P[i][j];

    // for (int j=0; j<M; j++)
    //     for (int i=0; i<N; i++)
    //         cout<< P[i][j]<<"\t";




    //R[0] = 42; // insert your code here
    //riporto a 1kg
    int i,j;
    double sum=0;
    for (int j=0; j<M; j++){
        for (int i=0; i<N; i++){
            //somma
            // cout<<endl<<"i: "<<i;
            // cout<<endl<<"j: "<<j;
            sum+=P[i][j];
            // cout<<endl<<"P[i][j]: "<<P[i][j];
            // cout<<endl<<"sum: "<<sum;
        }
        // cout<<endl<<"Fsum: "<<sum;
        sum=1000000/sum;
        // cout<<endl<<"sum: "<<sum;

        //converto in 1 kg
        if(sum!=1){
            for (int i=0; i<N; i++){
                P[i][j]*=sum;
                // cout<<endl<<"P[i][j]: "<<P[i][j];
            }
        }
        sum=0;
    }
    // cout<<endl;

    for(i=0;i<N;i++){
        for(j=0;j<M;j++){ //scorro sulle colonne
            sum+=P[i][j];
            // cout<<endl<<"sum: "<<sum;
        }
        R[i]=sum/M;
        sum=0;
    }


    // cout<<endl;
    for (int i=0; i<N; i++)
        cout << (int)R[i] << " "; // print the result
    cout << endl;
    return 0;
}
