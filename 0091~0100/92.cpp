#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;
int n = 1e7, p[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    for (int i = 1; i <= n; i ++ ) p[i] = i;
    for (int i = 1; i <= n; i ++ ) {
        int t = 0, x = i;
        while (x) t += (x % 10) * (x % 10), x /= 10;
        p[find(i)] = find(t);
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (find(i) == find(89)) ans ++ ;
    }
    cout << ans;
    return 0;
}
