#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> A = {{1, -2, 2},
                         {2, -1, 2},
                         {2, -2, 3}};
vector<vector<int>> B = {{1, 2, 2},
                         {2, 1, 2},
                         {2, 2, 3}};
vector<vector<int>> C = {{-1, 2, 2},
                         {-2, 1, 2},
                         {-2, 2, 3}};
vector<int> O = {3, 4, 5};

int sum(vector<int> a) {
    return accumulate(a.begin(), a.end(), 0);
}

vector<int> mul(vector<int> a, vector<vector<int>> b) {
    vector<int> tmp(3);
    for (int i = 0; i < 3; i ++ ) {
        for (int j = 0; j < 3; j ++ ) {
            tmp[i] += a[j] * b[i][j];
        }
    }
    return tmp;
}

int maxn = 1500000;
queue<vector<int>> triangles;
unordered_map<int, int> st, cnt;

void solve() {
    triangles.push(O);
    while (!triangles.empty()) {
        vector<int> ori = triangles.front(); triangles.pop();
        st[sum(ori)] ++ ;
        vector<int> nxtA = mul(ori, A), nxtB = mul(ori, B), nxtC = mul(ori, C);
        if (sum(nxtA) <= maxn) triangles.push(nxtA);
        if (sum(nxtB) <= maxn) triangles.push(nxtB);
        if (sum(nxtC) <= maxn) triangles.push(nxtC);
    }
    int ans = 0;
    for (auto [x, y] : st) {
        for (int d = x; d <= maxn; d += x) {
            cnt[d] += y;
        }
    }
    for (auto [x, y] : cnt) if (y == 1) ans ++ ;
    cout << ans << "\n";
}

int main() {
    clock_t start = clock();
    solve();
    clock_t end = clock();
    double cpu_time_used = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    cout << "CPU time used: " << cpu_time_used << " s\n";
    return 0;
}