#include<bits/stdc++.h>
using namespace std;
const int N = 10;
int row[N], col[N], block[N];
int a[N * N];
int ans = 0;

int calc(int x, int y) {
    return 9 * x + y;
}

int to_block(int x, int y) {
    return x / 3 * 3 + y / 3;
}

void dfs(int pos) {
    if (pos == 81) return ans += a[0] * 100 + a[1] * 10 + a[2], void();
    if (a[pos]) return dfs(pos + 1), void();
    int x = pos / 9, y = pos % 9;
    for (int i = 0; i < 9; i ++ ) {
        if (row[x] >> i & 1) continue;
        if (col[y] >> i & 1) continue;
        if (block[to_block(x, y)] >> i & 1) continue;
        a[pos] = i + 1;
        row[x] |= 1 << i;
        col[y] |= 1 << i;
        block[to_block(x, y)] |= 1 << i;
        dfs(pos + 1);
        a[pos] = 0;
        row[x] ^= 1 << i;
        col[y] ^= 1 << i;
        block[to_block(x, y)] ^= 1 << i;
    }
}

int main() {
    string s;
    int n = 50;
    while (n -- ) {
        cin >> s >> s;
        memset(row, 0, sizeof row);
        memset(col, 0, sizeof col);
        memset(block, 0, sizeof block);
        memset(a, 0, sizeof a);
        for (int i = 0; i < 9; i ++ ) {
            cin >> s;
            for (int j = 0; j < 9; j ++ ) {
                a[calc(i, j)] = s[j] - '0';
                if (!a[calc(i, j)]) continue;
                row[i] |= 1 << a[calc(i, j)] - 1;
                col[j] |= 1 << a[calc(i, j)] - 1;
                block[to_block(i, j)] |= 1 << a[calc(i, j)] - 1;
            }
        }
        dfs(0);
    }
    cout << ans << "\n";
    return 0;
}