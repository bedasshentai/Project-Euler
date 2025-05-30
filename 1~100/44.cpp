#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> P;
unordered_map<ll, ll> mp, exist;

int main() {
    for (ll i = 1; i; i ++ ) {
        ll now = i * (3 * i - 1) / 2;
        for (auto t : P) {
            if (exist.count(now - t)) {
                mp[now + t] = now - t;
            }
        }
        exist[now] = 1;
        P.push_back(now);
        if (mp.count(now)) return cout << mp[now] << "\n", 0;
    }
    return 0;
}