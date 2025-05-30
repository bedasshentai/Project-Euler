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

int sum(vector<int> &a) {
    return a[0] + a[1] + a[2];
}

vector<int> mul(vector<int> &a, vector<vector<int>> &b) {
    vector<int> tmp(3);
    for (int i = 0; i < 3; i ++ ) {
        for (int j = 0; j < 3; j ++ ) {
            tmp[i] += a[j] * b[i][j];
        }
    }
    return tmp;
}

#define PII pair<int, int>

int maxn = 5e6;
vector<int> ans(maxn + 1);
queue<vector<int>> triangles;
unordered_map<int, int> st, cnt;
priority_queue<PII, vector<PII>, greater<PII>> heap;

void init() {
    triangles.push(O);
    while (!triangles.empty()) {
        vector<int> ori = triangles.front(); triangles.pop();
        st[sum(ori)] ++ ;
        vector<int> nxtA = mul(ori, A), nxtB = mul(ori, B), nxtC = mul(ori, C);
        if (sum(nxtA) <= maxn) triangles.push(nxtA);
        if (sum(nxtB) <= maxn) triangles.push(nxtB);
        if (sum(nxtC) <= maxn) triangles.push(nxtC);
    }
    int res = 0;
    for (auto [x, y] : st) heap.push({x, x});
    for (int i = 12; i <= maxn; i ++ ) {
        while (heap.size() && heap.top().first <= i) {
            auto t = heap.top(); heap.pop();
            int now = t.first, add = t.second, num = st[t.second];
            if (!cnt.count(now) && num == 1) res ++ ;
            else if (cnt[now] == 1) res -- ;
            cnt[now] += num;
            if (now + add <= maxn) heap.push({now + add, add});
        }
        ans[i] = res;
    }
}

void solve() {
    int n; cin >> n;
    cout << ans[n] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    init();
    int T = 1;
    cin >> T;
    while (T -- ) solve();
    return 0;
}