#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int a[N][N], dp[N][N];

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
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n; i ++ ) {
        dp[i][1] = a[i][1];
    }
    for (int j = 2; j <= n; j ++ ) {
        for (int i = 1; i <= n; i ++ ) {
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + a[i][j];
        }
        for (int i = n; i; i -- ) {
            dp[i][j] = min(dp[i][j], dp[i + 1][j] + a[i][j]);
        }
    }
    int ans = 1e9;
    for (int i = 1; i <= n; i ++ ) ans = min(ans, dp[i][n]);
    cout << ans;
    return 0;
}