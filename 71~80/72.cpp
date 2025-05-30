#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int primes[N], st[N], cnt;
int phi[N];

int main() {
    phi[1] = 1;
    for (int i = 2; i < N; i ++ ) {
        if (!st[i]) primes[cnt ++ ] = i, phi[i] = i - 1;
        for (int j = 0; i * primes[j] < N; j ++ ) {
            st[i * primes[j]] = 1;
            if (i % primes[j] == 0) {
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            }
            phi[i * primes[j]] = phi[i] * (primes[j] - 1);
        }
    }
    long long ans = 0;
    for (int i = 2; i <= 1e6; i ++ ) ans += phi[i];
    cout << ans;
    return 0;
}
