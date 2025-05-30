#include<bits/stdc++.h>
using namespace std;
int fact[10], ans;
int ring[2200000], nxt[2200000];
int d[2200000], st[2200000];

int get_sum(int x) {
    string s = to_string(x);
    int t = 0;
    for (auto c : s) t += fact[c - '0'];
    return t;
}

int get_len(int x, int dep) {
    st[x] = 1;
    if (st[nxt[x]]) return dep;
    return get_len(nxt[x], dep + 1);
}

void dfs(int x, int dep) {
    if (ring[x]) {
        if (dep + ring[x] == 60) ans ++ ;
        return;
    }
    dfs(nxt[x], dep + 1);
}

void solve() {
    fact[0] = 1;
    for (int i = 1; i < 10; i ++ ) fact[i] = fact[i - 1] * i;
    for (int i = 1; i < 2200000; i ++ ) nxt[i] = get_sum(i), d[nxt[i]] ++ ;
    queue<int> q;
    for (int i = 1; i < 2200000; i ++ ) if (!d[i]) q.push(i);
    while (q.size()) {
        int t = q.front(); q.pop();
        d[nxt[t]] -- ;
        if (!d[nxt[t]]) q.push(nxt[t]);
    }
    for (int i = 1; i < 2200000; i ++ ) {
        if (d[i] && !st[i]) {
            int len = get_len(i, 1), x = nxt[i];
            ring[i] = len;
            while (x != i) ring[x] = len, x = nxt[x];
        }
    }
    for (int i = 1; i <= 1000000; i ++ ) dfs(i, 0);
    cout << ans << "\n";
}

int main() {
    clock_t start = clock();
    solve();
    clock_t end = clock();
    double cpu_time_used = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    cout << "CPU time used: " << cpu_time_used << " s\n";
    return 0;
}
