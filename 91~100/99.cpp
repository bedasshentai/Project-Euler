#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<double, int> mp;

int main() {
    int n = 1000;
    for (int i = 0; i < n; i ++) {
        ll a, b;
        scanf("%lld,%lld", &a, &b);
        mp[b * log2(a)] = i + 1;
    }
    for (auto items : mp) {
        cout << items.first << " " << items.second << "\n";
    }
    return 0;
}