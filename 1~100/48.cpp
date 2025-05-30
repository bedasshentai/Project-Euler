#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e10;

ll qpow(__int128 a, ll k) {
    __int128 res = 1;
    while (k) {
        if (k & 1) res = res * a % mod;
        k >>= 1;
        a = a * a % mod;
    }
    return res;
}

int main() {
    ll ans = 0;
    for (int i = 1; i <= 1000; i ++ ) (ans += qpow(i, i)) %= mod;
    cout << ans << "\n";
    return 0;
}