#include<bits/stdc++.h>
#define int long long
using namespace std;
map<int, int> len;

int dfs(int x) {
    if (len.count(x)) return len[x];
    if (x & 1) return len[x] = dfs(3 * x + 1) + 1;
    return len[x] = dfs(x >> 1) + 1;
}

signed main() {
    len[1] = 1;
    int ans = 0;
    for (int i = 2; i < 1e6; i ++ ) {
        if (len.count(i)) ans = max(ans, len[i]);
        else ans = max(ans, dfs(i));
    }
    for (auto c : len) {
        if (c.second == ans) {
            cout << c.first << "\n";
        }
    }
    return 0;
}