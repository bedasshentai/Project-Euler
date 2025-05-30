#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10, M = 5e7;
int primes[N], cnt;
bool st[N], is[M];

int main() {
    for (int i = 2; i < N; i ++ ) {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; i * primes[j] < N; j ++ ) {
            st[i * primes[j]] = 1;
            if (i % primes[j] == 0) break;
        }
    }
    for (int i = 0; ; i ++ ) {
        int a = primes[i] * primes[i];
        if (a >= M) break;
        for (int j = 0; ; j ++ ) {
            int b = primes[j] * primes[j] * primes[j];
            if (a + b >= M) break;
            for (int k = 0; ; k ++ ) {
                int c = primes[k] * primes[k] * primes[k] * primes[k];
                if (a + b + c >= M) break;
                is[a + b + c] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 2; i < 5e7; i ++ ) 
        if (is[i]) ans ++ ;
    cout << ans;
    return 0;
}