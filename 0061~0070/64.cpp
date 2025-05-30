#include<bits/stdc++.h>
using namespace std;

int continued_fraction(int x) {
    int len = 0, fraction = 1, sqr = -sqrt(x), res = sqr;
    if (res * res == x) return 0;
    map<pair<int, int>, int> mp;
    while (1) {
        len ++ ;
        int _fraction = x - res * res;
        int d = __gcd(_fraction, fraction);
        _fraction /= d, fraction /= d;
        res = (-res * fraction % _fraction - sqr) % _fraction + sqr;
        fraction = _fraction;
        if (mp.count({res, fraction})) return len - mp[{res, fraction}];
        mp[{res, fraction}] = len;
    }
}

int main() {
    int ans = 0;
    for (int i = 1; i <= 10000; i ++ ) {
        if (continued_fraction(i) & 1) {
            ans ++ ;
        }
    }
    cout << ans << "\n";
    return 0;
}