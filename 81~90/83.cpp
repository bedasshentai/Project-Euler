#include<bits/stdc++.h>
using namespace std;
const int N = 1010, INF = 0x7f7f7f7f;
int a[N][N], dp[N][N], st[N][N];

int main() {
    freopen("matrix.txt", "r", stdin);
    int n = 80;
    for (int i = 1; i <= n; i ++ ) {
        string s;
        cin >> s;
        s += ',';
        int p = 0;
        for (int j = 1; j <= n; j ++ ) {
            int t = 0;
            while (s[p] != ',') t = t * 10 + s[p] - '0', p ++ ;
            p ++ ;
            a[i][j] = t;
        }
    }
    memset(dp, 0x7f, sizeof dp);
    dp[1][1] = a[1][1];
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= n; j ++ ) {
            int px = 0, py = 0, minn = INF;
            for (int s = 1; s <= n; s ++ ) {
                for (int t = 1; t <= n; t ++ ) {
                    if (!st[s][t] && dp[s][t] < minn) {
                        minn = dp[s][t];
                        px = s, py = t;
                    }
                }
            }
            st[px][py] = 1;
            for (int k = 0; k < 4; k ++ ) {
                int x = px + dx[k], y = py + dy[k];
                if (!x || !y || x > n || y > n) continue;
                if (dp[x][y] > minn + a[x][y]) {
                    dp[x][y] = dp[px][py] + a[x][y];
                }
            }
            if (dp[n][n] != INF) break;
        }
    }
    cout << dp[n][n];
    return 0;
}