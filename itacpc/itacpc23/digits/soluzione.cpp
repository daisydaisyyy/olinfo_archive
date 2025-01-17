// @check-accepted: task

#include <iostream>
#include <cinttypes>

using namespace std;

int get_digit_sum(int num) {
    if (num < 10) return num;
    return (num % 10) + get_digit_sum(num / 10); 
}

int main() {
    int d;
    int N;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> d >> N;

    long long res = d;

    for (int i = 2; i <= N; i++) 
        res = (2 * res) + get_digit_sum(i);

    cout << res << flush << endl;

    return 0;
}
