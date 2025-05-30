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
    int flag = 0;
    for (int x = 2; x < N; x ++ ) {
        int t = x, cnt = 0;
        for (int j = 0; primes[j] * primes[j] <= t; j ++ ) {
            if (t % primes[j] == 0) {
                cnt ++ ;
                while (t % primes[j] == 0) t /= primes[j];
            }
        }
        if (t > 1) cnt ++ ;
        if (cnt == 4) flag ++ ;
        else flag = 0;
        if (flag == 4) {
            cout << x - 3 << "\n";
            break;
        }
    }
    return 0;
}