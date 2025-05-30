#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll, ll> value;
vector<string> sqr[15];

int main() {
    for (ll i = 1; i <= 1e6; i ++ ) {
        ll x = i * i;
        string p = "", q = "";
        while (x) {
            p += x % 10 + '0';
            x /= 10;
        }
        reverse(p.begin(), p.end());
        sqr[p.size()].push_back(p);
        value[i * i] = 1;
    }

    vector<string> ary = {/* file.txt */};
    vector<string> ary_copy = ary;
    for (auto &items : ary) sort(items.begin(), items.end());
    sort(ary.begin(), ary.end());
    
    ll ans = 0;
    vector<string> useful;
    for (int k = 0; k + 1 < ary.size(); k ++ ) {
        if (ary[k] == ary[k + 1]) {
            while (k + 1 < ary.size() && ary[k] == ary[k + 1]) k ++ ;
            for (int i = 0; i < ary_copy.size(); i ++ ) {
                string it = ary_copy[i];
                sort(it.begin(), it.end());
                if (it == ary[k]) useful.push_back(ary_copy[i]);
            }
            for (int i = 0; i < useful.size(); i ++ ) {
                for (int j = i + 1; j < useful.size(); j ++ ) {
                    for (auto items : sqr[useful[i].length()]) {
                        unordered_map<char, ll> rep;
                        unordered_map<ll, char> r_rep;
                        int pd = 1;
                        for (int l = 0; l < items.length(); l ++ ) {
                            ll x = items[l] - '0';
                            if (rep.count(useful[i][l]) && rep[useful[i][l]] != x) {
                                pd = 0;
                                break;
                            }
                            if (r_rep.count(x) && rep[x] != useful[i][l]) {
                                pd = 0;
                                break;
                            }
                            rep[useful[i][l]] = x;
                            r_rep[x] = rep[useful[i][l]];
                        }
                        if (!pd) continue;
                        if (rep[useful[j][0]] == 0) continue;
                        ll x = 0;
                        for (int l = 0; l < useful[j].length(); l ++ ) {
                            x = x * 10 + rep[useful[j][l]];
                        }
                        if (value.count(x)) {
                            // cout << useful[i] << " " << useful[j] << " " << x << "\n";
                            ans = max(ans, x);
                        }
                    }
                }
            }
            useful.clear();
        }
    }
    cout << ans;
    return 0;
}
