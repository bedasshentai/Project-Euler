#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int p[N], mod = 1e6;

int f(int x, int i) {
    return x * (x * 3 + (i & 1 ? 1 : -1)) / 2;
}

int main() {
    p[0] = 1;
    for (int i = 1; i < N; i ++ ) {
        for (int j = 0; f(j >> 1, j) <= i; j ++ ) {
            if (j & 2) p[i] += p[i - f(j >> 1, j)];
            else p[i] += mod - p[i - f(j >> 1, j)];
            p[i] %= mod;
        }
        if (!p[i]) cout << i << "\n";
    }
    return 0;
}