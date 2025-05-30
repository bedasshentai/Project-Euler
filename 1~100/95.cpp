#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int primes[N], p[N], d[N], st[N], cnt;
int dfn[N], low[N], timestamp;
int stk[N], in_stk[N], id[N], sz[N], top, scc_cnt;
int n = 1e6;

void tarjan(int u) {
    dfn[u] = low[u] = ++ timestamp;
    stk[ ++ top] = u, in_stk[u] = 1;
    if (d[u] <= n && !dfn[d[u]]) {
        tarjan(d[u]);
        low[u] = min(low[u], low[d[u]]);
    } else if (d[u] <= n && in_stk[d[u]]) {
        low[u] = min(low[u], dfn[d[u]]);
    }
    if (dfn[u] == low[u]) {
        ++ scc_cnt;
        int y;
        do {
            y = stk[top -- ];
            in_stk[y] = 0;
            id[y] = scc_cnt;
            sz[scc_cnt] ++ ;
        } while (y != u);
    }
}

int main() {
    for (int i = 2; i < N; i ++ ) {
        if (!st[i]) primes[cnt ++ ] = i, p[i] = d[i] = i + 1;
        for (int j = 0; i * primes[j] < N; j ++ ) {
            st[i * primes[j]] = 1;
            if (i % primes[j] == 0) {
                d[i * primes[j]] = d[i] / p[i] * (p[i] * primes[j] + 1);
                p[i * primes[j]] = p[i] * primes[j] + 1;
                break;
            }
            d[i * primes[j]] = d[i] * (primes[j] + 1);
            p[i * primes[j]] = primes[j] + 1;
        }
    }
    for (int i = 2; i < N; i ++ ) d[i] -= i;
    for (int i = 1; i <= n; i ++ ) 
        if (!dfn[i])
            tarjan(i);
    int len = 6, ans = 1;
    for (int i = 1; i <= n; i ++ ) {
        if (sz[id[i]] > len) {
            len = sz[id[i]];
            ans = i;
        }
    }
    cout << len << " " << ans << "\n";
    return 0;
}
