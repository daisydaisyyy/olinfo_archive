const int INF = 1e9; 
int main() {
    int N;
    if (!(cin >> N)) return 0;
    vector<int> H(N);
    int max_h = -1;
    int max_idx = -1;

    for (int i = 0; i < N; ++i) {
        cin >> H[i];
        if (H[i] > max_h) { // Troviamo subito la torre più alta per escluderla dopo
            max_h = H[i];
            max_idx = i;
        }
    }
    vector<int> left_greater_idx(N, -1);
    vector<int> right_greater_idx(N, -1);

    stack<int> s_left; // prev greater element (right)
    for (int i = 0; i < N; ++i) {
        while (!s_left.empty() && H[s_left.top()] < H[i]) s_left.pop();
        
        if (!s_left.empty()) left_greater_idx[i] = s_left.top();
        
        s_left.push(i);
    }

    stack<int> s_right; // next greater element (right)
    for (int i = N - 1; i >= 0; --i) {
        while (!s_right.empty() && H[s_right.top()] < H[i]) s_right.pop();
        if (!s_right.empty()) right_greater_idx[i] = s_right.top();
        s_right.push(i);
    }

    long long total_score = 0;
    for (int i = 0; i < N; ++i) {
        if (i == max_idx) continue; // La torre più alta va ignorata
        int dist_left = INF;
        int dist_right = INF;

        if (left_greater_idx[i] != -1) dist_left = i - left_greater_idx[i]; // Se esiste una torre + alta a sinistra, calcolo la distanza
        if (right_greater_idx[i] != -1) dist_right = right_greater_idx[i] - i; // a destra
        total_score += min(dist_left, dist_right);
    }
    cout << total_score << endl;
}