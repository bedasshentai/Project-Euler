#include<bits/stdc++.h>
using namespace std;
const int N = 10010;
int st[N], primes[N], d[N], p[N], cnt;

int main() {
    d[1] = 1;
    for (int i = 2; i < N; i ++ ) {
        if (!st[i]) p[i] = d[i] = i + 1, primes[cnt ++ ] = i;
        for (int j = 0; i * primes[j] < N; j ++ ) {
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
    for (int i = 1; i < N; i ++ ) d[i] -= i;
    int n = 10000, ans = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (d[i] != i && i == d[d[i]]) {
            ans += i;
        }
    }
    cout << ans;
    return 0;
}