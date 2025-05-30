#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int primes[N], st[N], cnt;

void init() {
    for (int i = 2; i < N; i ++ ) {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] * i < N; j ++ ) {
            st[primes[j] * i] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}

bool check(int x, int ori) {
    if (st[x]) return 0;
    int len = 1; while(len * 10 <= x) len *= 10;
    if (x % len < len / 10) return 0;
    x = x % len * 10 + x / len;
    if (x == ori) return 1;
    return check(x, ori);
}

int main() {
    init(), st[1] = 1;
    int ans = 0;
    for (int i = 2; i < N; i ++ ) {
        if (check(i, i)) ans ++ , cout << i << "\n";
    }
    cout << ans;
    return 0;
}