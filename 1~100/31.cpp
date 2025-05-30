#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;

int main() {
    vector<ll> f(201);
    int d[] = {1, 2, 5, 10, 20, 50, 100, 200};
    f[0] = 1;
    for (int i = 0; i < 8; i ++ ) {
        for (int j = d[i]; j <= 200; j ++ ) {
            if (j >= d[i]) {
                f[j] += f[j - d[i]];
            }
        }
    }
    cout << f[200];
    return 0;
}