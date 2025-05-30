#include<bits/stdc++.h>
using namespace std;

string to_c(int t) {
    if (t == 10) return "10";
    string s = "";
    s += char(t + '0');
    return s;
}

string trans(int *a) {
    string s = "";
    for (int i = 0; i < 5; i ++ ) {
        s += to_c(a[i * 2 + 1]);
        s += to_c(a[i * 2]);
        s += to_c(a[(i + 1) * 2 % 10]);
    }
    return s;
}

int main() {
    int a[10];
    iota(a, a + 10, 1);
    string ans = "";
    do {
        if (a[0] + a[1] != a[3] + a[4]) continue;
        if (a[2] + a[3] != a[5] + a[6]) continue;
        if (a[4] + a[5] != a[7] + a[8]) continue;
        if (a[6] + a[7] != a[9] + a[0]) continue;
        if (a[8] + a[9] != a[1] + a[2]) continue;
        if (a[1] > min(a[3], min(a[5], min(a[7], a[9])))) continue;
        string s = trans(a);
        if (s.length() == 16 && s > ans) ans = s;
    } while(next_permutation(a, a + 10));
    cout << ans << "\n";
    return 0;
}
