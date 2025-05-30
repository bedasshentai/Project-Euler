#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int primes[N], d[N], p[N], cnt;
bool st[N];
int dp[N];
int n = 28123;

int main() {
    for (int i = 2; i <= n; i ++ ) {
        if (!st[i]) primes[cnt ++ ] = i, d[i] = p[i] = i + 1;
        for (int j = 0; primes[j] * i <= n; j ++ ) {
            st[i * primes[j]] = 1;
            if (i % primes[j] == 0) {
                d[i * primes[j]] = d[i] / p[i] * (p[i] * primes[j] + 1);
                p[i * primes[j]] = p[i] * primes[j] + 1;
                break;
            }
            d[i * primes[j]] = d[i] * d[primes[j]];
            p[i * primes[j]] = primes[j] + 1;
        }
    }
    for (int i = 2; i <= n; i ++ ) d[i] -= i;
    vector<int> num;
    for (int i = 2; i <= n; i ++ ) {
        if (d[i] > i) {
            num.push_back(i);
        }
    }
    unordered_map<int, int> mp;
    for (int i = 0; i < num.size(); i ++ ) {
        for (int j = i; j < num.size(); j ++ ) {
            if (num[i] + num[j] > n) break;
            mp[num[i] + num[j]] = 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++ ) ans += mp[i] ? 0 : i;
    cout << ans;
    return 0;
}