#include<bits/stdc++.h>
using namespace std;

int build(int a, int b, int c, int d, int n) {
    if (b + d > n) return 0;
    return 1 + build(a, b, a + c, b + d, n) + build(a + c, b + d, c, d, n);
}

int main() {
    int ans = build(1, 3, 1, 2, 12000);
    cout << ans << "\n";
    return 0;
}