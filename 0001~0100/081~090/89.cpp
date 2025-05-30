#include<bits/stdc++.h>
using namespace std;
map<char, int> mp;

int main() {
    mp['M'] = 1000, mp['D'] = 500, mp['C'] = 100, mp['L'] = 50, mp['X'] = 10, mp['V'] = 5, mp['I'] = 1;
    mp['m'] = 900, mp['d'] = 400, mp['c'] = 90, mp['l'] = 40, mp['x'] = 9, mp['v'] = 4;
    freopen("roman.txt", "r", stdin);
    string s;
    int ans = 0;
    while (cin >> s) {
        ans += s.length();
        int num = 0, cnt = 0;
        for (int i = 0; i < s.length(); i ++ ) {
            if (i < s.length() - 1 && s[i] == 'C' && s[i + 1] == 'M') num += 900, i ++ ;
            else if (i < s.length() - 1 && s[i] == 'C' && s[i + 1] == 'D') num += 400, i ++ ;
            else if (i < s.length() - 1 && s[i] == 'X' && s[i + 1] == 'C') num += 90, i ++ ;
            else if (i < s.length() - 1 && s[i] == 'X' && s[i + 1] == 'L') num += 40, i ++ ;
            else if (i < s.length() - 1 && s[i] == 'I' && s[i + 1] == 'X') num += 9, i ++ ;
            else if (i < s.length() - 1 && s[i] == 'I' && s[i + 1] == 'V') num += 4, i ++ ;
            else num += mp[s[i]];
        }
        cnt += num / 1000, num %= 1000;
        cnt += num / 900 * 2, num %= 900;
        cnt += num / 500, num %= 500;
        cnt += num / 400 * 2, num %= 400;
        cnt += num / 100, num %= 100;
        cnt += num / 90 * 2, num %= 90;
        cnt += num / 50, num %= 50;
        cnt += num / 40 * 2, num %= 40;
        cnt += num / 10, num %= 10;
        cnt += num / 9 * 2, num %= 9;
        cnt += num / 5, num %= 5;
        cnt += num / 4 * 2, num %= 4;
        cnt += num;
        ans -= cnt;
    }
    cout << ans;
    return 0;
}