#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;

int calc(vector<int> num, int p) {
    int a = 0, b = 0, c = 0;
    if (p == 0) {
        a = num[0];
        b = num[1] * 1000 + num[2] * 100 + num[3] * 10 + num[4];
        c = num[5] * 1000 + num[6] * 100 + num[7] * 10 + num[8];
    }
    else if (p == 1) {
        a = num[0] * 10 + num[1];
        b = num[2] * 100 + num[3] * 10 + num[4];
        c = num[5] * 1000 + num[6] * 100 + num[7] * 10 + num[8];
    }
    if (a * b == c) return c;
    return 0;
}

int main() {
    vector<int> a(9), ans;
    iota(a.begin(), a.end(), 1);
    do {
        for (int i = 0; i <= 1; i ++ ) {
            if (calc(a, i)) {
                ans.push_back(calc(a, i));
                cout << calc(a, i) << "\n";
            }
        }
    } while (next_permutation(a.begin(), a.end()));
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << accumulate(ans.begin(), ans.end(), 0);
    return 0;
}