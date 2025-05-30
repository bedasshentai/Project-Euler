#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
set<int> s;
vector<int> ans = {1, 2, 3, 4, 0};

void calc(vector<double> num) {
    if (num.size() == 1) {
        if (abs(num[0] - round(num[0])) < eps) {
            s.insert(round(num[0]));
        }
        return;
    }
    for (int i = 0; i < num.size(); i ++ ) {
        for (int j = i + 1; j < num.size(); j ++ ) {
            vector<double> _num, __num;
            for (int k = 0; k < num.size(); k ++ ) {
                if (k == i || k == j) continue;
                _num.push_back(num[k]);
            }
            __num = _num;
            __num.push_back(num[i] + num[j]), calc(__num), __num.pop_back();
            __num.push_back(num[i] - num[j]), calc(__num), __num.pop_back();
            __num.push_back(num[j] - num[i]), calc(__num), __num.pop_back();
            __num.push_back(num[i] * num[j]), calc(__num), __num.pop_back();
            __num.push_back(num[i] / num[j]), calc(__num), __num.pop_back();
            __num.push_back(num[j] / num[i]), calc(__num), __num.pop_back();
        }
    }
}

void generator(int a, int b, int c, int d) {
    vector<int> num = {a, b, c, d};
    s.clear();
    vector<double> _num;
    for (auto c : num) _num.push_back((double)c);
    calc(_num);
    for (int i = 1; ; i ++ ) {
        if (!s.count(i)) {
            if (i - 1 > ans[4]) {
                ans = vector<int>{num[0], num[1], num[2], num[3], i - 1};
            }
            break;
        }
    }
}

int main() {
    for (int d = 4; d <= 10; d ++ ) {
        for (int c = 3; c < d; c ++ ) {
            for (int b = 2; b < c; b ++ ) {
                for (int a = 1; a < b; a ++ ) {
                    generator(a, b, c, d);
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < 4; i ++ ) cout << ans[i];
    cout << "\n" << ans[4];
    return 0;
}