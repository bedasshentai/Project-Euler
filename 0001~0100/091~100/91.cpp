#include<bits/stdc++.h>
using namespace std;

int main() {
    int ans = 0, N = 50;
    for (int x = 1; x <= N; x ++ ) {
        for (int y = 1; y <= N; y ++ ) {
            int d = __gcd(x, y);
            ans += min((N - x) * d / y, y * d / x);
        }
    }
    cout << ans * 2 + N * N * 3;
    return 0;
}
