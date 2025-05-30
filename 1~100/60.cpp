#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 20010;
int primes[N], st[N], len[N], cnt;
vector<int> possible_prime[N];
unordered_map<int, int> exist[N];

int n, k;
vector<int> vec, ans;

ll qpow(ll a, ll k, ll mod) {
    ll res = 1;
    while (k) {
        if (k & 1) res = res * a % mod;
        k >>= 1;
        a = a * a % mod;
    }
    return res;
}

vector<int> base = {2, 7, 61};

bool check(ll a, ll p) {
    ll d = p - 1, r = 0;
    while (!(d & 1)) r ++ , d >>= 1;
    ll now = qpow(a, d, p);
    if (now == 1) return 1;
    while (r -- ) {
        if (now == p - 1) return 1;
        now = now * now % p;
    }
    return 0;
}

bool Miller_Rabin(int x) {
    if (x < n) return !st[x];
    for (auto a : base) if (!check(a, x)) return 0;
    return 1;
}

void init(int n) {
    st[1] = len[0] = 1;
    for (int i = 2; i < n; i ++ ) {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; i * primes[j] < n; j ++ ) {
            st[i * primes[j]] = 1;
            if (i % primes[j] == 0) break;
        }
    }
    for (int i = 1; i < n; i ++ ) len[i] = len[i / 10] * 10;
    for (int i = 1; i < cnt; i ++ ) {
        for (int j = i + 1; j < cnt; j ++ ) {
            if (!Miller_Rabin(primes[i] * len[primes[j]] + primes[j])) continue;
            if (!Miller_Rabin(primes[j] * len[primes[i]] + primes[i])) continue;
            possible_prime[i].push_back(j);
            exist[i][j] = 1;
        }
    }
}

void dfs(int now, int d) {
    if (d == k) {
        int res = 0;
        for (int i : vec) res += primes[i];
        return ans.push_back(res), void();
    }
    for (int nxt : possible_prime[now]) {
        int flag = 0;
        for (int num : vec) {
            if (!exist[num].count(nxt)) {
                flag = 1;
                break;
            }
        }
        if (flag) continue;
        vec.push_back(nxt);
        dfs(nxt, d + 1);
        vec.pop_back();
    }
}

void solve() {
    init(n);
    // for (int i = 1; i < cnt; i ++ ) {
    //     cout << "prime = " << primes[i] << "\n";
    //     if (possible_prime[i].size()) cout << "next primes: ";
    //     for (int num : possible_prime[i]) {
    //         cout << primes[num] << " \n"[num == possible_prime[i].back()];
    //     }
    // }
    for (int i = 1; i < cnt; i ++ ) vec = {i}, dfs(i, 1);
    sort(ans.begin(), ans.end());
    for (auto i : ans) cout << i << "\n";
}

int main() {
    cin >> n >> k;

    // clock_t start, end;
    // start = clock();

    solve();

    // end = clock();
    // cout << "time = " << (double)(end - start) * 1000 / CLOCKS_PER_SEC << "ms" << "\n";
    return 0;
}
