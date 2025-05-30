#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
int primes[N], st[N], cnt;
int dp[100];

int main() {
    for (int i = 2; i < N; i ++ ) {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; i * primes[j] < N; j ++ ) {
            st[i * primes[j]] = 1;
            if (i % primes[j] == 0) break;
        }
    }
    dp[0] = 1;
    for (int i = 0; i < 100; i ++ ) {
        for (int j = primes[i]; j < 100; j ++ ) {
            dp[j] += dp[j - primes[i]];
        }
    }
    for (int i = 1; i < N; i ++ ) {
        if (dp[i] > 5000) {
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}