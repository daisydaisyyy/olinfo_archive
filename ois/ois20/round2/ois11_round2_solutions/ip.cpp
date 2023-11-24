#include <iostream>
#include <string>
using namespace std;

int A[4], B[4];

int main() {
    scanf("%d", &A[0]);
    for (int i=1; i<4; i++) scanf(".%d", &A[i]);
    scanf("\n%d", &B[0]);
    for (int i=1; i<4; i++) scanf(".%d", &B[i]);

    long long p256[4] = {1};
    for (int i=1; i<4; i++) p256[i] = 256 * p256[i - 1];

    long long sum = 0;
    for (int i=0; i<4; i++) sum += (B[i] - A[i]) * p256[4 - i - 1];

    cout << sum + 1 << endl;
}
