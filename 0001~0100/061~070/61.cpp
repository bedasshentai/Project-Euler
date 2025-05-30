#include<bits/stdc++.h>
using namespace std;
vector<int> edge[6][100];

void create() {
    for (int n = 1; n; n ++ ) {
        int p = n * (n + 1) / 2;
        if (p >= 10000) break;
        if (p / 100 == 0 || p % 100 == 0) continue;
        if (p > 1000) edge[0][p / 100].push_back(p % 100);
    }
    for (int n = 1; n; n ++ ) {
        int p = n * n;
        if (p >= 10000) break;
        if (p / 100 == 0 || p % 100 == 0) continue;
        if (p > 1000) edge[1][p / 100].push_back(p % 100);
    }
    for (int n = 1; n; n ++ ) {
        int p = n * (3 * n - 1) / 2;
        if (p >= 10000) break;
        if (p / 100 == 0 || p % 100 == 0) continue;
        if (p > 1000) edge[2][p / 100].push_back(p % 100);
    }
    for (int n = 1; n; n ++ ) {
        int p = n * (2 * n - 1);
        if (p >= 10000) break;
        if (p / 100 == 0 || p % 100 == 0) continue;
        if (p > 1000) edge[3][p / 100].push_back(p % 100);
    }
    for (int n = 1; n; n ++ ) {
        int p = n * (5 * n - 3) / 2;
        if (p >= 10000) break;
        if (p / 100 == 0 || p % 100 == 0) continue;
        if (p > 1000) edge[4][p / 100].push_back(p % 100);
    }
    for (int n = 1; n; n ++ ) {
        int p = n * (3 * n - 2);
        if (p >= 10000) break;
        if (p / 100 == 0 || p % 100 == 0) continue;
        if (p > 1000) edge[5][p / 100].push_back(p % 100);
    }
}

void search() {
    int reflection[5] = {1, 2, 3, 4, 5};
    do {
        queue<pair<int, pair<int, int>>> q;
        for (int start = 1; start < 100; start ++ ) {
            for (auto p : edge[0][start]) {
                q.push({start, {p, p}});
            }
        }
        for (int i = 0; i < 5; i ++ ) {
            queue<pair<int, pair<int, int>>> tmp;
            while (q.size()) {
                auto t = q.front(); q.pop();
                for (auto nxt : edge[reflection[i]][t.second.first]) {
                    tmp.push({t.first, {nxt, t.second.second + nxt}});
                }
            }
            swap(q, tmp);
        }
        while (q.size()) {
            auto t = q.front(); q.pop();
            if (t.first == t.second.first) cout << t.second.second * 101 << "\n";
        }
    } while (next_permutation(reflection, reflection + 5));
}

int main() {
    create();
    search();
    return 0;
}