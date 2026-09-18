#include<iostream>
using namespace std;
#include<cmath>
#include<algorithm>
unsigned long long int N;
#include<vector>
vector<pair<int,int>> v;

#define MOD 1000000007
vector<long long> primes;

int count_primes(int n) {
    const int S = 10000;
    int nsqrt = sqrt(n);
    vector<char> is_prime(nsqrt + 2, true);
    for (int i = 2; i <= nsqrt; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= nsqrt; j += i)
                is_prime[j] = false;
        }
    }

    int result = 0;
    vector<char> block(S);
    for (int k = 0; k * S <= n; k++) {
        fill(block.begin(), block.end(), true);
        int start = k * S;
        for (int p : primes) {
            int start_idx = (start + p - 1) / p;
            int j = max(start_idx, p) * p - start;
            for (; j < S; j += p)
                block[j] = false;
        }
        if (k == 0)
            block[0] = block[1] = false;
        for (int i = 0; i < S && start + i <= n; i++) {
            if (block[i])
                result++;
        }
    }
    return result;
}


vector<pair<long long, long long>> trial_division4(long long n) {
    vector<pair<long long,long long>> factorization; // number, occurrences
    for (long long d : primes) {
        if (d * d > n)
            break;
        while (n % d == 0) {
            if(!factorization.empty() && factorization.back().first == d) factorization.back().second++;
            else factorization.push_back({d,1});
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back({n,1});
    return factorization;
}


int main()
{
	int num_factors = 1;
	
	cin >> N;
	count_primes(N);
    trial_division4(N);
    vector<pair<long long,long long>> factors = trial_division4(N);
    
    for(auto &x:factors) num_factors *= (x.second + 1)% MOD;
    cout << num_factors << endl;
   
	
	return 0;
}