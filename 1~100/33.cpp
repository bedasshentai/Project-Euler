#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;

bool check(int a, int b) {
    int x1 = a % 10, x2 = a / 10;
    int y1 = b % 10, y2 = b / 10;
    if (!y1 || !y2 || !x1 || !x2) return 0;
    if (a * y1 == b * x1 && x2 == y2) return 1;
    if (a * y2 == b * x1 && x2 == y1) return 1;
    if (a * y1 == b * x2 && x1 == y2) return 1;
    if (a * y2 == b * x2 && x1 == y1) return 1;
    return 0;
}

int main() {
    ll a = 1, b = 1;
    for (int i = 10; i <= 99; i ++ ) {
        for (int j = i + 1; j <= 99; j ++ ) {
            if (check(i, j)) {
                a *= i;
                b *= j;
                cout << i << " " << j << "\n";
            }
        }
    }
    cout << b / __gcd(a, b);
    return 0;
}
