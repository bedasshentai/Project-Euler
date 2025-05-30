#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll p1(ll x) {return x * (x + 1) / 2;}
ll p2(ll x) {return x * (3 * x - 1) / 2;}
ll p3(ll x) {return x * (2 * x - 1);}

int main() {
    int t1 = 286, t2 = 166, t3 = 144;
    while (p1(t1) != p2(t2) || p2(t2) != p3(t3)) {
        if (p1(t1) < p2(t2)) t1 ++ ;
        if (p1(t1) > p2(t2)) t2 ++ ;
        if (p3(t3) < p2(t2)) t3 ++ ;
        if (p3(t3) > p2(t2)) t2 ++ ;
    }
    cout << p1(t1) << "\n";
    return 0;
}