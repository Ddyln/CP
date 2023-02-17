#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef lan_ngu
        freopen((Fname + ".inp").c_str(), "r", stdin);
        freopen((Fname + ".out").c_str(), "w", stdout);
    #endif

    // int _nt; cin >> _nt;
    int _nt = 1;
    while (_nt--) {
        ii a[100];
        a[1] = {2, 1};
        a[3] = {5, 1};
        a[2] = {3, 4};
        a[4] = a[1];
        double s = 0;
        int n = 3;
        for (int i = 1; i <= n; i++)
            s += a[i].fi * a[i + 1].se - a[i + 1].fi * a[i].se;
        s = abs(s) / 2;
        cout << s;
    }

    return 0;
}