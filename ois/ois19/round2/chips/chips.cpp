/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <assert.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
int A, C, r, g, b;
int score(int A, int C, int n1,int n2,int n3) {
  return A * (n1 * n1 + n2 * n2 + n3 * n3) + C * min(n1,min(n2,n3));
}
int greens, blues, reds;

int main() {
  //  uncomment the following lines if you want to read/write from files
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
  // ifstream cin("input0.txt");
  int T;

  cin >> T;
  while(T--) {
    cin >> A, cin >> C, cin >> r, cin >> g, cin >> b;
    // insert your code here

    // cout << solve();
    reds = score(A, C, r+1, g, b);
    blues = score(A, C, r, g, b+1);
    greens = score(A, C, r, g+1, b);
    int sol = max(reds, max(blues, greens));
    if (reds == sol)
      printf("RED\n");
    else if (greens == sol)
      printf("GREEN\n");
    else if (blues == sol)
      printf("BLUE\n");

  }
  return 0;
}
