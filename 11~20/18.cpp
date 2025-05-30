#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N][N], dp[N][N];

int main() {
    int n = 100;
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= i; j ++ ) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= i; j ++ ) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++ ) ans = max(ans, dp[n][i]);
    cout << ans;
    return 0;
}