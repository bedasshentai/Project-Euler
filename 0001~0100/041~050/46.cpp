#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int primes[N], st[N], cnt;
int is[N];

int main() {
    st[1] = 1;
    for (int i = 2; i < N; i ++ ) {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; i * primes[j] < N; j ++ ) {
            st[i * primes[j]] = 1;
            if (i % primes[j] == 0) break;
        }
    }
    for (int i = 9; i < N; i += 2) {
        if (!st[i]) continue;
        int flag = 0;
        for (int j = 1; j * j * 2 < i; j ++ ) {
            if (!st[i - j * j * 2]) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            cout << i << "\n";
            break;
        }
    }
    return 0;
}
