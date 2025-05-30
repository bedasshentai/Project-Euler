#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int is[N];

int maxk = 12000;

// number, factors sum, number of numbers, factor
void dfs(int num, int sum, int cnt, int p) {
    int k = num - sum + cnt;
    if (k > maxk) return;
    if (num < is[k]) is[k] = num;
    for (int i = p; i * num <= maxk * 2; i ++ ) {
        dfs(num * i, sum + i, cnt + 1, i);
    }
}

int main() {
    memset(is, 0x3f, sizeof is);
    for (int i = 2; i <= maxk; i ++ ) dfs(i, i, 1, i);
    sort(is + 2, is + maxk + 1);
    int ed = unique(is + 2, is + maxk + 1) - is;
    int ans = 0;
    for (int i = 2; i < ed; i ++ ) ans += is[i];
    cout << ans;
    return 0;
}