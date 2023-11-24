// lucach
// Greedy approach: firstly sort both the vector of prices and vouchers.
// We consider the cheapest event and find the smallest voucher that covers it,
// and then we iterate the same process moving to the second-cheapest event and so on,
// until either there are no more vouchers available or events to cover.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N, V;
    cin >> N >> V;
    vector<int> prices(N), vouchers(V);
    for (int i = 0; i < N; i++)
        cin >> prices[i];
    for (int i = 0; i < V; i++)
        cin >> vouchers[i];
    sort(prices.begin(), prices.end());
    sort(vouchers.begin(), vouchers.end());
    int matched = 0;
    for (int prices_idx = 0, vouchers_idx = 0; prices_idx < N && vouchers_idx < V; vouchers_idx++) {
        if (vouchers[vouchers_idx] >= prices[prices_idx]) {
            matched++;
            prices_idx++;
        }
    }
    cout << matched << endl;
}
