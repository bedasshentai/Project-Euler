#include<bits/stdc++.h>
using namespace std;
pair<int, int> p[8] = {{0, 1}, {0, 4}, {0, 6}, {1, 6}, {1, 8}, {2, 5}, {3, 6}, {4, 6}};
int ans = 0;

void check(int dice1, int dice2) {
    int pd = 0;
    if (dice1 >> 9) dice1 |= 1 << 6;
    if (dice2 >> 9) dice2 |= 1 << 6;
    for (int i = 0; i < 8; i ++ ) {
        if (dice1 >> p[i].first & dice2 >> p[i].second & 1) pd |= 1 << i;
        if (dice2 >> p[i].first & dice1 >> p[i].second & 1) pd |= 1 << i;
    }
    if (pd + 1 == 1 << 8) ans ++ ;
}

void dfs(int dice1, int dice2, int cnt, int p1, int p2) {
    if (cnt == 6) return check(dice1, dice2), void();
    if (!p1 || !p2) return;
    for (int i = p1 - 1; i >= 0; i -- ) {
        for (int j = p2 - 1; j >= 0; j -- ) {
            int n1 = dice1 | (1 << i), n2 = dice2 | (1 << j);
            if (n1 > n2) continue;
            dfs(n1, n2, cnt + 1, i, j);
        }
    }
}

int main() {
    dfs(0, 0, 0, 10, 10);
    cout << ans;
    return 0;
}
