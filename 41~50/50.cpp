#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int primes[N], st[N], cnt;

int main() {
    for (int i = 2; i < N; i ++ ) {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; i * primes[j] < N; j ++ ) {
            st[i * primes[j]] = 1;
            if (i % primes[j] == 0) break;
        }
    }
    int ans = 0, tot = 0;
    for (int i = 100; i < cnt; i ++ ) {
        int l = 0, r = i;
        int res = accumulate(primes, primes + r, 0);
        if (res > N) break;
        for (; r < cnt; l ++ , r ++ ) {
            res += primes[r];
            if (res > N) break;
            if (!st[res]) {
                if (tot < r - l + 1) {
                    tot = r - l + 1;
                    ans = res;
                }
            }
            res -= primes[l];
        }
    }
    cout << ans << " " << tot << "\n";
    return 0;
}
