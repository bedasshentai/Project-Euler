#include<bits/stdc++.h>
using namespace std;
int dp[110];

int main() {
    dp[0] = 1;
    for (int i = 1; i < 100; i ++ ) {
        for (int j = i; j <= 100; j ++ ) {
            dp[j] += dp[j - i];
        }
    }
    cout << dp[100];
    return 0;
}