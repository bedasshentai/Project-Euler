#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int primes[N], st[N], cnt;

void init() {
    for (int i = 2; i < N; i ++ ) {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] * i < N; j ++ ) {
            st[primes[j] * i] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}

bool check1(int x) {
    if (!x) return 1;
    if (st[x]) return 0;
    return check1(x / 10); 
}

bool check2(int x) {
    if (!x) return 1;
    if (st[x]) return 0;
    int len = 1; while (len * 10 <= x) len *= 10;
    return check2(x % len);
}

int main() {
    init(), st[1] = 1;
    int ans = 0;
    for (int i = 10; i < N; i ++ ) {
        if (check1(i) && check2(i)) ans += i, cout << i << "\n";
    }
    cout << ans;
    return 0;
}