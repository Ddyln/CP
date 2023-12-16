#include <bits/stdc++.h>
using namespace std;

#define int long long

int solve(int n) {
    int tmpN = n;
    n -= (n + 1) / 2;
    int res = 0;
    for (int i = 1; (1LL << i) <= tmpN; i++) {
        int u0 = (1LL << (i - 1)), s = (1LL << i);
        
    }
    return res;
}
signed main() {
    for (int i = 2; i <= 14; i += 2) {
        for (int j = 1;; j++)
            if (i % (1 << j) == 0 && (i % (1 << (j + 1))) != 0) {
                cout << (1 << j) << ' ';
                break;
            }
    }
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifdef lan_ngu
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    int l, r; cin >> l >> r;
    cout << solve(r);// << ' ' << solve(l - 1);
    return 0;
}