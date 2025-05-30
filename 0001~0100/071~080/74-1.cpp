#include<bits/stdc++.h>
using namespace std;
int fact[10];

int get_sum(int x) {
    string s = to_string(x);
    int t = 0;
    for (auto c : s) t += fact[c - '0'];
    return t;
}

int main() {
    fact[0] = 1;
    for (int i = 1; i < 10; i ++ ) fact[i] = fact[i - 1] * i;
    int ans = 0;
    for (int i = 1; i <= 1000000; i ++ ) {
        unordered_map<int, int> mp;
        int len = 0, x = i;
        while (!mp.count(x) && len <= 60) mp[x] = 1, len ++ , x = get_sum(x);
        if (len == 60) ans ++ ;
    }
    cout << ans << "\n";
    return 0;
}
