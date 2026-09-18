#include<iostream>
using namespace std;
#include<vector>
vector<char> v;
int main () {
    int n; cin >> n;
    string s; cin >> s;
    int counter = 0;
    for(int i = 0; i < s.length(); i++) counter += (s[i] == 'W')? 1 : 0;

    int current = counter, maxw = counter;

    for(int i = 1; i < n; i++) {
        current -= (s[i-1] == 'W')? 1 : 0;
        current += (s[i+n-1] == 'W')? 1 : 0;
        maxw = max(maxw, current);
    }
}