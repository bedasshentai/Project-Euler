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
    dp[0][1] = 0;
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= n; j ++ ) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
        }
    }
    cout << dp[n][n];
    return 0;
}