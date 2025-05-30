#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
int primes[N], st[N], cnt;
int phi[N];

bool check(int x) {
    string s = to_string(x), t = to_string(phi[x]);
    sort(s.begin(), s.end()), sort(t.begin(), t.end());
    return s == t;
}

int main() {
    phi[1] = 1;
    for (int i = 2; i < N; i ++ ) {
        if (!st[i]) primes[cnt ++ ] = i, phi[i] = i - 1;
        for (int j = 0; i * primes[j] < N; j ++ ) {
            st[i * primes[j]] = 1;
            if (i % primes[j] == 0) {
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            }
            phi[i * primes[j]] = phi[i] * (primes[j] - 1);
        }
    }
    int ans = 0;
    double maxx = 1e9;
    for (int i = 2; i < int(1e7); i ++ ) {
        if ((double)i / phi[i] < maxx && check(i)) {
            maxx = (double)i / phi[i];
            ans = i;
        }
    }
    cout << ans << " " << maxx << "\n";
    return 0;
}
