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
    int ans = 0;
    double maxx = 0;
    for (int i = 2; i <= int(1e6); i ++ ) {
        if ((double)i / phi[i] > maxx) {
            maxx = (double)i / phi[i];
            ans = i;
        }
    }
    cout << ans << " " << maxx << "\n";
    return 0;
}