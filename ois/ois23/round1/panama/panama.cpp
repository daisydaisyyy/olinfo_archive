// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// input data
int N, Q;
vector<int> V;

// void kadane(vector<int> v,int l,int r){
//     int temp_sum,max_sum;
//     for(int i=l;i<=r;i++){
//         max_sum=max(v[i],)
//     }
    
// }

int slidingWindows(int l,int r,int k) {
    // Initialize the window to the first k elements of the array.
    //vector<int> window(V.begin()+l,V.begin()+(l+k));
    vector<int> window;
    for(int i=0;i<k;i++){
        if(i%2==0) window.push_back(V[l+i]);
        else window.push_back(-V[l+i]);
    }
    cout<<"\n\nl+k: "<<l+k;
    int sub_sum=0,max_sum=0;

    // Initialize the maximum sum to the sum of the elements in the window.
   // int max_sum = std::accumulate(window.begin(), window.end(), 0);
    for(auto it: window){
        max_sum+=it;
    }
    cout<<endl<<"max sum: "<<max_sum;

    cout<<endl<<"window: "<<endl;
    for(auto it: window){
        cout<<it<<"\t";
    }
    cout<<endl;
    // Loop through the array, moving the window to the right by one element
    // at a time.
    for (int i = k; l+k+i<=r+1; i++) {
        // Update the window by removing the leftmost element and adding
        // the next element to the right.
        window.erase(window.begin());
        if((i)%2==0) window.push_back(V[l+i]);
        else window.push_back(-V[l+i]);
        cout<<"\nV[i+l]: "<<V[i+l];
        cout<<"\ni: "<<i;
        cout<<endl<<"windowC: "<<endl;
        for(auto it: window){
            cout<<it<<"\t";
        }
        cout<<endl;
        // Update the maximum sum by comparing it to the sum of the current
        // window.
        for(auto it: window){
            sub_sum+=it;
        }
        cout<<endl<<"sub sum: "<<sub_sum;
        max_sum = max(max_sum, sub_sum);
        sub_sum=0;
        cout<<endl<<"max sum: "<<max_sum;
    }

    return max_sum;
}



int panamaSum(int l,int r){
    int sum=-INT_MAX;
    for(int i=1;l+i<=r+1;i++){ //sistema window (quando fermare il ciclo)
        sum=max(sum,slidingWindows(l,r,i));
        cout<<endl<<"sum: "<<sum<<endl;
    }
    return sum;
}

int main() {
    //  uncomment the following lines if you want to read/write from files
     ifstream cin("input0.txt");
    //  ofstream cout("output.txt");

    cin >> N >> Q;
    V.resize(N + 1);
    for (int i = 1; i <= N; i++) cin >> V[i];

    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b;
            cin >> a >> b;
            // insert your code here
            V[a+1]=b;
        } else {
            int l, r;
            cin >> l >> r;
            // insert your code here
            cout<<endl<<"FIND:"<<endl;
            cout << panamaSum(l,r) << endl;
        }
    }

    return 0;
}
